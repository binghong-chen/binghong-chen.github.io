## python基础

### 基本数据结构
`list`,`tuple`,`dict`,`set`

为什么有 `tuple`

分片

### 函数

#### 作用域
##### global
##### nonlocal

#### 序列中的映射函数:
##### map
##### reduce
##### filter

### 迭代器
`for`
`range`
`dict` 为什么可以直接 `sorted`
`iter` `next`

文件迭代器

### 模块

### OOP

#### 常见的内置类属性
当创建一个类之后,系统就自带了一些属性,叫内置类属性.

##### `__file__`
在pycharm中,__file__会返回当前文件的绝对路径,而在终端直接运行时,则返回的是文件本身(这是个坑..在IDE开发的时候运行正常,上线就出问题).

pycharm中运行:
`demo.py`
``` py
print(__file__)
```
会输出:`F:/test_demo/demo.py`

终端运行: 
```
python demo.py
```
会输出 `demo.py`

所以要使用绝对路径的话,推荐使用 os.path.abspath(__file__),这种写法在终端与pycharm中输出的都是绝对路径.
##### `__module__`
__module__: 类定义所在的模块(类的全名是'__main__.className',如果类位于一个导入模块mymod中,那么className.__module__ 等于 mymod)
##### `__name__`
表示当前模块的名称,如果为main,表示为顶层模块,能够调用其他非main的模块,并且可运行.如果为非main,则无法运行,只能用来做导入使用(相信大多数同学都试过,在启动项目时,通常只有入口文件可以启动,单独运行项目中其他某个py文件,是无法运行的,而且,在入口文件中,不能存在相对导入包的方式,就是因为该文件为顶层模块,而项目的其他py文件可以存在相对导包的方式).

还可以用来返回类,实例,函数名等(这个没啥用~,了解即可):
``` py
class B:
    pass
 
print(B.__name__) # B

def a():
    pass
 
print(a.__name__) # a
```
##### `__class__`
返回所在的类.

用法:实例或者函数.__class__,

如果是类名.__name__则返回元类 'type'

##### `__doc__`
返回注释信息(注意,必须是三引号的注释,其他类型的注释不会被识别进行返回)
`test.py`
``` py
def a(a,b):
    """
    this is a demo test
    :param a:
    :param b:
    :return: 
    """
    c = a + b
    return c

print(a.__doc__)
```
```
>>> python test.py
>>> 
    this is a demo test
    :param a:
    :param b:
    :return:
```
##### `__dir__` 和 `__dict__`
`__dir__()`以列表形式返回对象的全部属性名和方法名
`__dict__`以字典形式返回对象的全部属性和方法
``` py
print(obj.__dir__())
print(obj.__dict__)
```
##### `__base__`
返回父类
##### `__mro__`
返回继承顺序:
`test.py`
``` py
class B(object):
    pass
 
class A(B):
    pass
 
print(A.__mro__)
```
```
python test.py
(<class '__main__.A'>, <class '__main__.B'>, <class 'object'>)
```

如果只是单继承,继承层次不深的话很好理解,但其实并不是单纯的从下到上的顺序 .
TODO 搞清楚多继承
##### `__metaclass__`
元类

##### `__str__` 和 `__repr__`
`test.py`
``` py
class Test():
    def __init__(self, name):
        self.name = name

    def __repr__(self):
        return  '这个类的名字是: % s' % self.name
```
python执行 `test.py` 时:
```
python
>>> from test import Test
>>> Test('科学')
这个类的名字是: 科学
>>>
```
`__repr__` 用于命令交互时的一些回馈显示.

`__str__` 是在 `print` 函数调用时才被调用,并且它返回的字符串对终端用户更友好,比如一些常见字段的显示

可以参考 [深入理解str()和repr()的区别](https://blog.csdn.net/Watkins_OS/article/details/100042680)

一般来说在类中都应该定义__repr__()方法,而__str__()方法则为可选.

#### `__main__`

#### `__init__`

##### `__next__`

##### `__all__`
Python中一个py文件就是一个模块,"`__all__`”变量是一个特殊的变量,可以在py文件中,也可以在包的__init__.py中出现.
#### 1. 在普通模块中
在普通模块中使用时,表示一个模块中允许哪些属性可以被导入到别的模块中,

如:全局变量,函数,类.如下,`test1.py`和`main.py`

`test1.py`
``` py
__all__ = ['test']

def test():
    print('---------test-----------')

def test1():
    print('---------test1----------')
```

`main.py`
``` py
from test1 import *

def main():
    test()
    # test1() # NameError: name 'test1' is not defined

main()
```

两个文件在同一个目录下.

此时执行`python main.py`时结果如下:

但是如果放开`main.py`的注释后,如下:

那么在模块中的`__all__`变量就是为了限制或者指定能被导入到别的模块的函数,类,全局变量等,如果指定了那么只能是指定的那些可以被导入,没有指定默认就是全部可以导入,当然私有属性应该除外.

#### 2. 在包下的`__init__.py`中

`sound/effects/__init__.py` 中添加

``` py
__all__ = ["echo", "surround", "reverse"]
```

那么就会在`from sound.effects import *` 时,包含上面三个模块.当`__init__.py`为空时,只是导入这个包,并非导入模块.

`__init__.py` 中可以执行一些初始化内容,比如:

``` py
from . import test1 # 导入当前目录下的test1模块
from .. import test # 导入上一层目录下的test模块
```

因为导入包时会首先执行下 `__init__.py` 这个文件

TODO 内置属性和方法与python内置的方法的关系

### 文件读取

`read([size])` `readline()` `readlines()` 和文件迭代器

``` py
# read() 会一次性读取整个文件并加载到内存
f = open('test.txt')
content = f.read()
f.close()

# read(size) 按块读取 不会一次性加载到内存
f = open('test.txt')
print(type(line))   # <type 'str'>
while True:
    chunk = f.read(10)
    if not chunk: break
    print(chunk)
f.close()

# readline() 逐行读取 不会一次性加载到内存
f = open('test.txt')
print(type(line))   # <type 'str'>
while True:
    line = f.readline()
    if not line: break
    print(line, end='')
f.close()

# readlines() 会一次性读取整个文件并加载到内存
for line in open('test.txt').readlines():
    print(line, end='')

# 文件迭代器 是 最佳实践 不会一次性把文件全部读到内存中
# 而是 反复 readline() 和 next()
for line in open('test.txt'):
    print(line, end='')
```
因为python2.5之后已经把文件设置为一种可以迭代的类型.所以这是最高效的方法了

### 异常处理

为什么需要异常?
需要从一个程序中任意大,任意深的代码块中跳出来,是一个超级`goto`

#### finally
`finally`有什么用? 
1. `finally`一定会执行.
2. `finally`中一般做一些资源释放的工作
   
看下面的例子
``` py
def func1():
    try:
        return 1
    finally:
        return 2
 
def func2():
    try:
        raise ValueError()
    except:
        return 1
    finally:
        return 3
 
print(func1())
print(func2())
```
输出 `2` 和 `3`
为什么是这样的呢?我们先来看一段Python官网上对于finally的解释:
>A finally clause is always executed before leaving the try statement, whether an exception has occurred or not. When an exception has occurred in the try clause and has not been handled by an except clause (or it has occurred in a except or else clause), it is re-raised after the finally clause has been executed. The finally clause is also executed "on the way out"when any other clause of the try statement is left via a break, continue or return statement.

#### else
可以判断没有发生异常的情况
``` py
try:
    x = 1/0
except Exception:
    print('except')
else:
    print('else run')
print('after run')
```

`try` 后面必须跟一个 `except` 或者一个 `finally`

顺序:
`try -> except -> else -> finally`

#### raise
与C#和Java中的throw类似,抛出异常 `raise 异常类型`

TODO `raise from`

#### 其他关于异常的实践
1. 避免将程序全部抱在 `try` 中
2. 尽量写清楚异常类型:避免直接用 `Exception` 或者空捕获:
``` py
try:
    # 其他代码
    x = 1/0
    # 其他代码
except ZeroDivisionError:
    print('ZeroDivisionError')

# 不好的捕获
try:
    # 其他代码
    x = 1/0
    # 其他代码
except Exception:
    print('Exception')


# 不好的捕获
try:
    # 其他代码
    x = 1/0
    # 其他代码
except:
    print('Exception')
```
3. 在使用自定义异常类时,需要注意:
   TODO


### 装饰器

### 元类

### 常用模块
#### os
#### sys
#### time

### 多线程与多进程
#### Thread
#### Process