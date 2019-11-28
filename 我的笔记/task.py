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

pages_dir = '../pages/'
shutil.rmtree(pages_dir)
os.mkdir(pages_dir)

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
        with open(full_path, 'r') as fr:
            content = fr.read()
            for r in rMap:
                content = content.replace(r, rMap[r])
            countWords = len(content)
            print('{0} 字数为: {1}'.format(full_path, countWords))
            totalWords += countWords
            with open(full_path, 'w') as fw:
                fw.write(content)
        if full_path.count('/') > 1:
            cat = full_path.split('/')[1]
            cats.add(cat)
            content = '### [' + file.split('.')[0] + '](../我的笔记/' + cat + '/' + file + ')'
            with open(pages_dir + cat + '.md', 'a+') as fw:
                fw.write(content)
        else:
            index_content.append('<div><a href="我的笔记/' + file + '">' + file.split('.')[0] + '</a>')
print('总字数: {0}'.format(totalWords))
sorted_cats = ['<li><a href="pages/' + cat + '.md">'  + cat + '</a></li>' for cat in sorted(list(cats), key=lambda cat: int(cat.split('.')[0]))] 
with open('../_index.html', 'r') as fr:
    content = fr.read()
    content = content.replace('@header@', '<ul>' + '\r\n'.join(sorted_cats) + '</ul>').replace('@content@', '\r\n'.join(index_content))
    with open('../index.html', 'w') as fw:
        fw.write(content)

