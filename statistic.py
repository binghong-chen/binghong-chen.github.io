import os,json,re
from datetime import datetime

class Statistic:
    def __init__(self):
        self.code_lines_map = dict()
        self.note_words = 0

    def readlines(self, filepath):
        try:
            with open(filepath, 'r', encoding='utf-8') as f:
                return f.readlines()
        except:
            print('error', filepath)
            try:
                with open(filepath, 'r', encoding='gbk') as f:
                    return f.readlines()
            except:
                with open(filepath, 'r', encoding='GB18030') as f:
                    return f.readlines()

    def read(self, filepath):
        try:
            with open(filepath, 'r', encoding='utf-8') as f:
                return f.read()
        except:
            try:
                with open(filepath, 'r', encoding='gbk') as f:
                    return f.read()
            except:
                with open(filepath, 'r', encoding='GB18030') as f:
                    return f.read()

    def write(self, filepath, content, mode='w'):
        with open(filepath, mode, encoding='utf-8') as f:
            f.write(content)

    def statistic_code_lines(self, path, filetypes='c,cpp,h,java,py,js,html,css,sql,ipynb,md'.split(',')):
        if os.path.isdir(path):
            for root, dir, files in os.walk(path):
                for file in files:
                    filepath = os.path.join(root, file)
                    self.statistic_code_lines_file(filepath, filetypes)
        if os.path.isfile(path):
            self.statistic_code_lines_file(path, filetypes)

    def statistic_code_lines_file(self, filepath, filetypes='c,cpp,h,java,py,js,html,css,sql,ipynb,md'.split(',')):
        if '.' not in filepath:
            return
        filetype = filepath[filepath.rfind('.')+1:]
        if filetype not in filetypes:
            return
        line_count = 0
        if filetype == 'ipynb':
            data = json.loads(self.read(filepath))
            for cell in data['cells']:
                if cell['cell_type'] != 'code':
                    continue
                line_count += len([line for line in cell['source'] if line.strip() != ''])
        else:
            lines = [line.strip() for line in self.readlines(filepath) if line.strip() != '']
            line_count = len(lines)
            if filetype == 'md':
                # 过滤空格 Tab 换行等非文字符号
                self.note_words += len(re.compile(r'\s').sub('', ''.join(lines)))
        self.code_lines_map.setdefault(filetype, 0)
        self.code_lines_map[filetype] += line_count
        print(filepath, line_count)