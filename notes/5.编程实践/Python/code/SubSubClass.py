from BaseClass import BaseClass
from SubClass import SubClass
from FatherClass import FatherClass
import sys
sys.path.append('word')
from class1 import Class1

class SubSubClass(SubClass, BaseClass):
    def hehe(self):
        print(self.name, 'hehe')

if __name__ == "__main__":

    instance = BaseClass()
    instance = SubClass()
    instance = SubSubClass()
    instance = FatherClass()
    instance = FatherClass()
    instance = Class1()

    print(BaseClass.caseCount)