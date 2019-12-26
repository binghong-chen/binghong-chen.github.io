import os,shutil,re,json,markdown

fileDir = '.'
rMap = {
    '，': ',',
    '、': ',',
    '‘': '\'',
    '’': '\'',
    '。': '.',
    '“': '"',
    '” ': '"',
    '？': '?',
    '！': '!',
    '(': '(',
    ')': ')',
    '；': ';',
    '：': ':',
    '（': '(',
    '）': ')',
    '|<|<': '《',
    '|>|>': '》',
}

def getindex(title):
    res = re.search(r'\d+', title)
    if(res == None):
        sum = 0
        for c in title:
         sum += ord(c)
        return sum
    return int(res.group(0))

pages_dir = 'generate_page/'
if os.path.exists(pages_dir):
    shutil.rmtree(pages_dir)
os.mkdir(pages_dir)
host = 'http://localhost:8080/myblog/'
left_item_template = ''
with open('template/_left_item_template.html', 'r', encoding='utf-8') as fr:
    left_item_template = fr.read()
list_item_template = ''
with open('template/_list_item_template.html', 'r', encoding='utf-8') as fr:
    list_item_template = fr.read()
totalWords = 0
cats = set()
pages = []
file_time_map = dict()
file_time_map_path = 'file_time_map.json'
if os.path.exists(file_time_map_path):
    with open(file_time_map_path, 'r') as fr:
        file_time_map = json.loads(fr.read())

for root, dir, files in os.walk('.'):
    for file in sorted(files, key=lambda f:getindex(f)):
        filename, filetype=os.path.splitext(file)
        full_path = os.path.join(root, file)
        if file.lower() == 'readme.md':
            continue
        if filetype != '.md':
            continue
        mtime = os.stat(full_path).st_mtime
        modified = full_path in file_time_map and file_time_map[full_path] == mtime
        file_time_map[full_path] = mtime
        if os.path.exists(full_path.replace('.md','.html')):
            os.remove(full_path.replace('.md','.html'))
        file_content_head = ''
        with open(full_path, 'r', encoding='utf-8') as fr:
            content = fr.read()
            if modified:
                for r in rMap:
                    content = content.replace(r, rMap[r])
            countWords = len(content)
            print('{0} 字数为: {1}'.format(full_path, countWords))
            if countWords == 0:
                print(full_path)
                content = '## ' + filename + '\n' + filename + '\n'
            countWords = len(content)
            totalWords += countWords
            if modified:
                with open(full_path, 'w', encoding='utf-8') as fw:
                    fw.write(content)
        content_split = content.split('\n')
        if len(content_split) < 2:
            file_content_head = ''
        else:
            file_content_head = markdown.markdown(content_split[1])
        if full_path.count('\\') > 1:
            cat = full_path.split('\\')[1]
        else:
            cat = '0.首页'
        cats.add(cat)
        if pages.count('generate_page/generate_page_' + cat + '.html') == 0:
            pages.append('generate_page/generate_page_' + cat + '.html')
        full_path = full_path.replace('./', '')
        pages.append(full_path)
        content = list_item_template.format(full_path, filename, file_content_head)
        with open('generate_page/generate_page_' + cat + '.html', 'a+', encoding='utf-8') as fw:
            fw.write(content)
print('总字数: {0}'.format(totalWords))
sorted_cats = [left_item_template.format(pages.index('generate_page/generate_page_' + cat + '.html'), cat.split('.')[1]) for cat in sorted(list(cats), key=lambda cat: int(cat.split('.')[0]))]
with open('template/_index.html', 'r', encoding='utf-8') as fr:
    content = fr.read()
    content = content.replace('_left_', '\r\n<div class="split"></div>\r\n'.join(sorted_cats)).replace('_pageMap_', json.dumps(pages,ensure_ascii=False, indent=4))
    with open('index.html', 'w', encoding='utf-8') as fw:
        fw.write(content)
with open(file_time_map_path, 'w') as fw:
    fw.write(json.dumps(file_time_map))
# print(json.dumps(pages,ensure_ascii=False, indent=4))