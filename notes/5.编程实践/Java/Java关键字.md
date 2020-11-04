## Java关键字
与C#比较,关注与C#不同的地方

### 访问修饰符

#### public

#### protected

#### private

### 方法,类,属性,和变量修饰符

#### final

final可以修饰非抽象变量,非抽象方法,非抽象类  

final修饰的类:

final类不能被继承  
final类中的变量和方法默认是final的  
final修饰的变量:  

final变量即常量,不可被赋值  
final变量(如果不是private的)可以被继承  
final修饰的方法:  

final方法(如果不是private的)可以被继承  
final方法不可以被复写  
(private方法默认是final的,因为private方法不可以被继承,不可以被复写.但是你可以对private方法增加final修饰符,但是这并没有意义)  

##### 1.修饰类 对应于C#中的 sealed
表示这个类不能被继承

##### 2.修饰变量  对应C#中的 readonly 和 const
必须要赋初始值,而且是只能初始化一次

final修饰基本数据类型的变量时,必须赋予初始值且不能被改变,修饰引用变量时,该引用变量不能再指向其他对象
相当于C#中的readonly,初始化后不能再改变.但C#不要求声明时必须初始化,可以在其他地方初始化,但只能初始化赋值一次.

只读关键字初始化列表:

|修饰符     |局部变量|全局变量  |构造方法|全局变量和构造方法关系
|:-         |:-     |:-         |:-     |:-
|Const      |支持   |支持       |不支持 |————————————
|Readonly   |不支持 |支持       |支持   |同一全局变量同时初始化后以构造方法为准
|Final      |支持   |支持       |支持   |同一全局变量只能在两者之间选一处进行初始化

##### 3.修饰方法 对应于C#中的 sealed
被final修饰的方法不能被重写.

#### static
static是在内存中分配一块区域,供整个类使用.也就是说,不管这个类有多少个实例,这些实例的static类型的变量都是共用的.

static定义的变量和方法也可以直接通过类来调用,不需要通过类的一个实例来调用.

static可以修饰变量,方法,代码块,类.(static修饰类比较特殊,static不可以修饰外部类,只可以修饰内部类)

#### synchronized 对应于C#中的 lock

#### this super  对应于C#中的 this base
this和super

this代表本对象,super代表父对象
调用本/父对象的属性和方法可以通过this./super.的形式
调用本/父类的构造方法可以用this()/super()的形式(注意:这两种形式只能出现在构造方法的首行)
静态方法中不能使用this和super.因为静态方法是类方法,不和类的具体实例打交道,而this和super是代表的对象实例.
overide和overload

#### @Override: 对应于C#中的 override 
Java使用注解(Annotation)实现的

重写

发生在父类和子类之间,子类重写父类的方法

方法的名称,参数,返回值要一模一样
#### @Overload:

重载

发生在同一个类中
方法的名称一样,参数的个数,类型,顺序不一样
(注意:返回值,方法的作用域不一样的方法不叫Overload,否则编译报错)


#### native
简单地讲,一个Native Method就是一个java调用非java代码的接口.一个Native Method是这样一个java的方法:该方法的实现由非java语言实现,比如C.这个特征并非java所特有,很多其它的编程语言都有这一机制,比如在C＋＋中,你可以用extern "C"告知C＋＋编译器去调用一个C的函数. 

标识符native可以与所有其它的java标识符连用,但是abstract除外.这是合理的,因为native暗示这些方法是有实现体的,只不过这些实现体是非java的,但是abstract却显然的指明这些方法无实现体.

#### strictfp
strictfp, 即 strict float point (精确浮点).
strictfp 关键字可应用于类,接口或方法.使用 strictfp 关键字声明一个方法时,该方法中所有的float和double表达式都严格遵守FP-strict的限制,符合IEEE-754规范.当对一个类或接口使用 strictfp 关键字时,该类中的所有代码,包括嵌套类型中的初始设定值和代码,都将严格地进行计算.严格约束意味着所有表达式的结果都必须是 IEEE 754 算法对操作数预期的结果,以单精度和双精度格式表示.
如果你想让你的浮点运算更加精确,而且不会因为不同的硬件平台所执行的结果不一致的话,可以用关键字strictfp.

#### transient
变量修饰符,如果用transient声明一个实例变量,当对象存储时,它的值不需要维持.
Java的serialization提供了一种持久化对象实例的机制.当持久化对象时,可能有一个特殊的对象数据成员,我们不想用serialization机制来保存它.为了在一个特定对象的一个域上关闭serialization,可以在这个域前加上关键字transient.当一个对象被序列化的时候,transient型变量的值不包括在序列化的表示中,然而非transient型的变量是被包括进去的.

#### volatile
就象大家更熟悉的const一样,volatile是一个类型修饰符(type specifier).它是被设计用来修饰被不同线程访问和修改的变量.如果没有volatile,基本上会导致这样的结果:要么无法编写多线程程序,要么编译器失去大量优化的机会.


### 类,接口,实例化

#### class

#### interface

#### abstract

#### implements

#### extends

#### new

### 包

#### import 对应于C#中的 using

#### package 对应于C#中的 namespace

### 数据类型

#### byte
#### char
#### boolean
#### short
#### int
#### float
#### long
#### double
#### void
#### null
#### true
#### false

### 条件循环
#### if
#### else
#### while
#### for
#### switch
#### case
#### default
#### do
#### break
#### continue
#### instanceof


### 异常

#### try

#### catch

#### finally

#### throw 和 throws
throw是你执行的动作.比如你觉得可能有异常,那么就抱出去 如:
``` java
String a; 
if(a == null) {
    throw new exception("a为null");
}
```
所以throw是一个抛出去的动作

throws只用在一个方法的末端,表示这个方法体内部如果有异常,这抛给它的调用者. 如: 
``` java
public void add(int a, int b) throws Exception(); 
```
这个方法表示,在执行这个方法的时候,可能产生一个异常,如果产生异常了,那么谁调用了这个方法,就抛给谁.


 
### 保留关键字

#### const
用于修改字段或局部变量的声明.它指定字段或局部变量的值是常数,不能被修改

#### goto
指定跳转到标签,找到标签后,程序将处理从下一行开始的命令.

