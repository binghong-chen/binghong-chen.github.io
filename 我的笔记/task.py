import os,shutil

fileDir = '.'
rMap = {
    '、': ',',
    '，': ',',
    '‘': '\'',
    '’': '\'',
    '。': '.',
    '“': '"',
    '”': '"',
    '？': '?',
    '！': '!',
    '（': '(',
    '）': ')',
    '；': ';',
    '：': ':',
    '( ': '(',
    ' )': ')',
}


import markdown
import codecs

css = '''
<meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
<style type="text/css">
<!-- 此处省略掉markdown的css样式，因为太长了 -->
</style>
'''
def markdown2html(name):
    in_file = '%s.md' % (name)
    out_file = '%s.html' % (name)

    input_file = codecs.open(in_file, mode="r", encoding="utf-8")
    text = input_file.read()
    html = markdown.markdown(text)

    output_file = codecs.open(out_file, "w",encoding="utf-8",errors="xmlcharrefreplace")
    output_file.write(css+html)


pages_dir = '../pages/'
shutil.rmtree(pages_dir)
os.mkdir(pages_dir)

left_item_template = ''
with open('../_left_item_template.html', 'r') as fr:
    left_item_template = fr.read()
list_item_template = ''
with open('../_list_item_template.html', 'r') as fr:
    list_item_template = fr.read()
totalWords = 0
cats = set()
index_content = []
for root, dir, files in os.walk('.'):
    for file in files:
        if file.lower() == 'readme.md':
            continue
        if(file.rfind('.md') != len(file)-3):
            continue
        full_path = os.path.join(root, file)
        file_content_head = ''
        with open(full_path, 'r') as fr:
            content = fr.read()
            for r in rMap:
                content = content.replace(r, rMap[r])
            countWords = len(content)
            print('{0} 字数为: {1}'.format(full_path, countWords))
            totalWords += countWords
            with open(full_path, 'w') as fw:
                fw.write(content)
                file_content_head = content[:100].replace('#','')
        markdown2html(full_path.replace('.md', ''))
        filetext = file.replace('.md', '')
        if full_path.count('/') > 1:
            cat = full_path.split('/')[1]
            cats.add(cat)
            content = list_item_template.format('../我的笔记/' + cat + '/' + filetext + '.html', filetext, file_content_head)
            with open(pages_dir + cat + '.html', 'a+') as fw:
                fw.write(content)
        else:
            index_content.append(list_item_template.format('我的笔记/' + filetext + '.html', filetext, file_content_head))
print('总字数: {0}'.format(totalWords))
sorted_cats = [left_item_template.format('pages/' + cat + '.html', cat.split('.')[1]) for cat in sorted(list(cats), key=lambda cat: int(cat.split('.')[0]))]
with open('../_index.html', 'r') as fr:
    content = fr.read()
    content = content.replace('@left@', '\r\n<div class="split"></div>\r\n'.join(sorted_cats)).replace('@content@', '\r\n'.join(index_content))
    with open('../index.html', 'w') as fw:
        fw.write(content)