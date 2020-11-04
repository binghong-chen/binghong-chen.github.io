from BaseClass import BaseClass
from FatherClass import FatherClass

import sys

sys.path.append('word')

import class1

class SubClass(FatherClass, BaseClass):
    def __init__(self):
        super().__init__()

    def hello(self, msg):
        super().hello(msg)
        print('SubClass', msg)

    def __str__(self):
        return f'name={self.name}, type={self.type}, model={self.model}';
        # return super().__str__()



if __name__ == "__main__":
    subInstance = SubClass()
    subInstance.hello("world")
    print(subInstance)

    class1 = class1.Class1()
    class1.count("我是中国人我爱中国")
    class1.print()

    print(BaseClass.caseCount)