import sys 
sys.path.append("..") 

from BaseClass import BaseClass

class Class1(BaseClass):
    def count(self, setence):
        self.word_count = dict()
        for word in setence:
            self.word_count.setdefault(word, 0)
            self.word_count[word] += 1
    def print(self):
        print(self.word_count)

if __name__ == "__main__":
    instance = Class1()
    instance.hello("我是中国人我爱中国")
    instance.count("我是中国人我爱中国")
    instance.print()
    