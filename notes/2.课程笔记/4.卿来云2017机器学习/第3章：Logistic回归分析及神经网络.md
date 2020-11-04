## 第3章:Logistic回归分析及神经网络

[课程地址](http://edu.csdn.net/huiyiCourse/detail/539)

### 学习要点

1. 损失函数:logistic损失;
2. 优化算法:IRLS(梯度下降,牛顿法),BP算法;
3. 正则化:L1/ L2;
4. 复习模型评估. 

**案例:**
Otto商品分类.包含内容——用Logistic回归和神经网络实现Otto商品分类. 
课程目标:理解分类任算法Logistic回归和神经网络原理,复习数据集探索,并学会用sklearn用Logistic回归和(浅层)神经网络实现分类任务.  

类似线性回归 但是用于分类  是有监督学习
Logistic回归基本原理(对数几率回归)

### 分类

学习从输入 $\bold{x}$ 到输出 $y$ 的映射 $f$:
$$
    \hat{y}=f(\bold{x})=\argmax_cp(y=c|\bold{x},D)
$$
其中 $y$ 为离散值,取值范围称为标签空间:$Y=\{1,2,\cdots,C\}$

#### 伯努利(Bernoulli)分布
当$C=2$时,就是两分类问题,计算出$p(y=1|\bold{x})$即可.此时分布为二项分布/伯努利(Bernoulli)分布:
$$
    p(y|\bold{x})=Ber(y|\mu(\bold{x}))=\mu(\bold{x})^y(1-\mu(\bold{x}))^{1-y}
$$
其中$\mu(\bold{x})=E(y|\bold{x})=p(y=1|\bold{x})$

<font color=red>注:二项分布/伯努利(Bernoulli)分布为:
$$
    Ber(x|\theta)=\theta^x(1-\theta)^{1-x}
$$
</font>

#### sigmoid变换和Logistic回归
Logistic回归模型(亦被称为**logit回归**,**最大熵分类(MaxEnt)** 或者 **log线性分类器**)也是一个线性模型:
$$
    \begin{aligned}
        p(y|\bold{x})=Ber(y|\mu(\bold{x}))\\
        \mu(\bold{x})=sigmoid(\bold{w}^T\bold{x})
    \end{aligned}
$$
其中sigmoid函数(S形函数)定义为:
$$
    sigmoid(z)=\frac{1}{1+e^{-z}}=\frac{e^z}{e^z+1}
$$
亦被称为logistic函数或logit函数

sigmoid函数将
$$
    \begin{aligned}
        z &\to y=\frac{1}{1+\exp(-z)}\\
        (-\infin,+\infin) &\to [0,1]
    \end{aligned}
$$
将实数$z$变换到$[0,1]$区间
- 因为概率取值在$[0,1]$

[LR为什么要用sigmoid? 与感知机,SVM的关系](../../4.机器学习感悟/2.线性模型/从感知机说起.md)

所以Logistic回归:
$$
    \begin{aligned}
        p(y|\bold{x},\bold{w})=Ber(y|\mu(\bold{x}))\\
        \mu(\bold{x})=sigmoid(\bold{w}^T\bold{x})
    \end{aligned}
$$
将$\bold{w}^T\bold{x}$变换到$[0,1]$区间,变换后的值当做概率,作为伯努利分布的参数.

#### 对数几率
$$
    \ln(\frac{\mu}{1-\mu})=\bold{w}^T\bold{x}
$$


### 极大似然估计
<font color=red>对谁做极大似然估计?是对$p(y|\bold{w},\bold{x})$做极大似然估计:</font>
令$\mu_i=\mu(x_i)$,则NLL(负log似然)为:
$$
    \def\sumi#1{\sum_{i=1}^#1}
    \begin{aligned}
        J(\bold{w})=NLL(\bold{w})&=-\sumi{N}\log\left[(\mu_i)^{y_i}\times(1-\mu_i)^{(1-y_i)}\right]\\
        &=\sumi{N}-\left[y_i\log(\mu_i)+(1-y_i)\log(1-\mu_i)\right]
    \end{aligned}
$$
其中
$$
    \def\sumi#1{\sum_{i=1}^#1}
    \sumi{N}-\left[y_i\log(\mu_i)+(1-y_i)\log(1-\mu_i)\right]
$$
称为Logistic损失,所以 **极大似然估计** 等价于 **最小Logistic损失(交叉双损失)**


然后就可以用优化算法来求极值.

#### 目标函数:
$$
    \def\sumi#1{\sum_{i=1}^#1}
    J(\bold{w})=\sumi{N}-\left[y_i\log(\mu_i)+(1-y_i)\log(1-\mu_i)\right]
$$
#### 梯度:
$$
    \def\sumi#1{\sum_{i=1}^#1}
    \bold{g}(\bold{w})=\frac{\partial J(\bold{w})}{\partial \bold{w}}=\frac{\partial}{\partial \bold{w}}\left[\sumi{N}-\left[y_i\log(\mu_i)+(1-y_i)\log(1-\mu_i)\right]\right]
$$

<font color=red>

$$
    \def\b#1{\boldsymbol{#1}}
    \def\p#1{\partial{#1}}
    \def\pp#1#2{\frac{\p{#1}}{\p{#2}}}
    \def\ppp#1#2{\frac{\p}{\p{#1}}{#2}}
    \def\pb#1{\p{\b#1}}
    \def\ewx{e^{\bold{w}^T\bold{x}}}
    \def\ewxo{\left(\ewx+1\right)}
    \def\mux{\frac{\ewx}{\ewx+1}}
    \def\muxb{\frac{\ewx}{\ewx+1}}
    \def\sumi#1{\sum_{i=1}^#1}
    \def\sumj#1{\sum_{j=1}^#1}
    \begin{aligned}
        &1. 后面推导用到的一些简单等式:\\
        &\qquad\begin{aligned}
            \pp{\bold{w}^T\bold{x}}{\bold{w}}&=\pp{\bold{x}^T\bold{w}}{\bold{w}}=\bold{x}
            \\
            \mu(\bold{x})&=\mux
            \\
            1-\mu(\bold{x})&=\muxb
        \end{aligned}
        \\
        \\
        &2. 求\frac{\partial\mu(\bold{x})}{\bold{w}}:\\
        &\qquad\begin{aligned}
            \textcolor{blue}{\pp{\mu(\bold{x})}{\bold{w}}}
            &=\frac{\left[\pp{}{\bold{w}}\ewx\right]\ewxo-\ewx\left[\pp{}{\bold{w}}\ewxo\right]}{\ewxo^2}\\
            &=\frac
            {
                \ewx\cdot\ewxo\cdot\pp{}{\bold{w}}\bold{w}^T\bold{x}
                -\ewx\cdot\ewx\cdot\pp{}{\bold{w}}\bold{w}^T\bold{x}
            }{\ewxo^2}\\
            &=\frac{\ewx}{\ewxo^2}\cdot\bold{x}\\
            &=\mux\cdot\muxb\cdot\bold{x}\\
            &=\textcolor{blue}{\mu(\bold{x})\cdot\left[1-\mu(\bold{x})\right]\cdot\bold{x}}
        \end{aligned}
        \\
        \\
        &3. 梯度推导:\\
        &\qquad\begin{aligned}
            \bold{g}(\bold{w})=\pp{J(\bold{w})}{\bold{w}}
            &=\pp{}{\bold{w}}\left[\sumi{N}-\left[y_i\log(\mu_i)+(1-y_i)\log(1-\mu_i)\right]\right]\\
            &=\sumi{N} \left[-y_i\times\frac{1}{\mu(\bold{x}_i)}
                \pp{\mu(\bold{x}_i)}{\bold{w}}+(1-y_i)\times\frac{1}{1-\mu(\bold{x}_i)}
                \pp{\mu(\bold{x}_i)}{\bold{w}}
                \right]\\
            &=\sumi{N} \left[-y_i\times\frac{1}{\mu(\bold{x}_i)}+(1-y_i)\times\frac{1}{1-\mu(\bold{x}_i)}\right]\textcolor{blue}{\pp{\mu(\bold{x}_i)}{\bold{w}}}\\
            &=\sumi{N} \left[-y_i\times\frac{1}{\mu(\bold{x}_i)}+(1-y_i)\times\frac{1}{1-\mu(\bold{x}_i)}\right]\textcolor{blue}{\mu(\bold{x}_i)(1-\mu(\bold{x}_i))\bold{x}_i}\\
            &=\sumi{N} \left[-y_i\left[1-\mu(\bold{x}_i)\right]+(1-y_i)\mu(\bold{x}_i)\right]\bold{x}_i\\
            &=\sumi{N} \left[-y_i+\mu(\bold{x}_i)\right]\bold{x}_i\\
            &=\sumi{N} \left[\mu(\bold{x}_i)-y_i\right]\bold{x}_i
        \end{aligned}
    \end{aligned}
$$
</font>

最后的形式很简单,刚好是残差 $\mu(\bold{x}_i)-y_i$ 乘以 $\bold{x}_i$ 求和

与线性回归的平方损失的梯度形式基本一致:
$$
    \def\b#1{\boldsymbol{#1}}
    \def\p#1{\partial{#1}}
    \def\pp#1#2{\frac{\p{#1}}{\p{#2}}}
    \def\ppp#1#2{\frac{\p}{\p{#1}}{#2}}
    \def\pb#1{\p{\b#1}}
    \def\ewx{e^{\bold{w}^T\bold{x}}}
    \def\ewxo{\left(\ewx+1\right)}
    \def\mux{\frac{\ewx}{\ewx+1}}
    \def\muxb{\frac{\ewx}{\ewx+1}}
    \def\sumi#1{\sum_{i=1}^#1}
    \def\sumj#1{\sum_{j=1}^#1}
    \begin{aligned}
        \bold{g}(\bold{w})&=\sumi{N}\left[f(\bold{x}_i)-y_i\right]\bold{x}_i\\
        f(\bold{x}_i)&=\bold{w}^T\bold{x}_i
    \end{aligned}
$$

<font color=red>
为什么LR要使用MLE,不像线性回归那样使用MSE?

>为什么线性回归可以使用MSE?
>>【1】线性回归用于连续函数的拟合,MSE可以反映拟合值和真值的偏离程度,具有实际的几何意义  
>>【2】线性回归的MSE的二阶导数$\geq$0,是一个凸函数,可以使用凸优化
$$
    \def\b#1{\boldsymbol{#1}}
    \def\p#1{\partial{#1}}
    \def\pp#1#2{\frac{\p{#1}}{\p{#2}}}
    \def\ppp#1#2{\frac{\p}{\p{#1}}{#2}}
    \def\pb#1{\p{\b#1}}
    \def\ewx{e^{\bold{w}^T\bold{x}}}
    \def\ewxo{\left(\ewx+1\right)}
    \def\mux{\frac{\ewx}{\ewx+1}}
    \def\muxb{\frac{\ewx}{\ewx+1}}
    \def\sumi#1{\sum_{i=1}^#1}
    \def\sumj#1{\sum_{j=1}^#1}
    \def\g#1{\nabla_{\bold{#1}}}
    \def\gg#1{\g{#1}^2}
    \begin{aligned}
      MSE&=\frac{1}{N}\sumi{N}(\bold{w}^T\bold{x}_i-y_i)^2\\
      \gg{w} MSE&=\frac{2}{N}\sumi{N}\bold{x}_i^2\geq0
    \end{aligned}
$$
</font>

<font color=red>

>为什么LR使用MLE?
>>【1】LR的模型将线性函数$\def\b#1{\boldsymbol{#1}}\bold{w}^T\bold{x}$做了一个sigmoid变换,将原来的值映射到[0,1]区间上,可以将变换后的值看做概率值.对概率值是不作MSE处理的,概率值的均方差没听过  
>>【2】变换后的值可以看做是 $y=1$ 分类的概率值,多个样本之间可设为满足iid条件,使用MLE理所当然.  
>>【3】会有梯度消失现象  
>>【4】LR的MSE的二阶导数不能保证$\geq0$,不是凸函数,不可以使用凸优化,求解最优解困难
$$
    \def\p#1{\partial{#1}}
    \def\pp#1#2{\frac{\p{#1}}{\p{#2}}}
    \def\ppp#1#2{\frac{\p}{\p{#1}}{#2}}
    \def\pb#1{\p{\b#1}}
    \def\ewx{e^{\bold{w}^T\bold{x}}}
    \def\ewxo{\left(\ewx+1\right)}
    \def\mux{\frac{\ewx}{\ewx+1}}
    \def\muxb{\frac{\ewx}{\ewx+1}}
    \def\sumi#1{\sum_{i=1}^#1}
    \def\sumj#1{\sum_{j=1}^#1}
    \def\g#1{\nabla_{\bold{#1}}}
    \def\gg#1{\g{#1}^2}
    \begin{aligned}
        MSE&=\frac{1}{N}\sumi{N}(\mu_i-y_i)^2\\
        \g{w} MSE&=\frac{2}{N}\sumi{N}\left[(\mu_i-y_i)\cdot\g{w}\mu_i\right]&(1)\\
        \gg{w} MSE&=\frac{2}{N}\sumi{N}\left[(\g{w}\mu_i)^2+(\mu_i-y_i)\cdot\gg{w} \mu_i\right]&(2)\\
        \g{w}\mu_i&=\mu_i(1-\mu_i)\bold{x_i}&(3)\\
        \gg{w} \mu_i&=\left[(1-\mu_i)\cdot\g{w}\mu_i-\mu_i\cdot\g{w}\mu_i\right]\bold{x_i}\\
        &=(1-2\mu_i)\cdot\g{w}\mu_i\cdot\bold{x_i}&(4)\\
    \end{aligned}
    \\
    \begin{aligned}
        将(3)&带入(1)式\\
            &\g{w} MSE=\frac{2}{N}\sumi{N}\left[(\mu_i-y_i)\cdot\g{w}\mu_i\right]\\
            &可见,梯度受到sigmoid函数导数的影响,\\
            &当 \mu_i 趋近于 0 时或者趋近于 1 时,\g{w} MSE 都会趋近为 0,\textcolor{blue}{造成梯度消失现象}.\\
            &使得求得的梯度很小,损失函数收敛的很慢.\\
            &\\
        将(3)&,(4)带入(2)式\\
            &\gg{w} MSE=\frac{2}{N}\sumi{N}\left[(\g{w}\mu_i)^2+(\mu_i-y_i)\cdot(1-2\mu_i)\cdot\g{w}\mu_i\cdot\bold{x_i}\right]\\
            &=\frac{2}{N}\sumi{N}\left\{\g{w}\mu_i\cdot\left[\g{w}\mu_i+(\mu_i-y_i)\cdot(1-2\mu_i)\cdot\bold{x_i}\right]\right\}\\
            &=\frac{2}{N}\sumi{N}\left\{\g{w}\mu_i\cdot\left[\mu_i\cdot(1-\mu_i)\cdot\bold{x_i}+(\mu_i-y_i)\cdot(1-2\mu_i)\cdot\bold{x_i}\right]\right\}\\
            &=\frac{2}{N}\sumi{N}\left\{\g{w}\mu_i\cdot\left[\mu_i\cdot(1-\mu_i)+(\mu_i-y_i)\cdot(1-2\mu_i)\right]\cdot\bold{x_i}\right\}\\
            &=\frac{2}{N}\sumi{N}\left\{\g{w}\mu_i\cdot\left[\mu_i-\mu_i^2+\mu_i-y_i-2\mu_i^2+2y_i\mu_i\right]\cdot\bold{x_i}\right\}\\
            &=\frac{2}{N}\sumi{N}\left\{\g{w}\mu_i\cdot\left[-3\mu_i^2+2(1+y_i)\mu_i-y_i\right]\cdot\bold{x_i}\right\}\\
            &=\frac{2}{N}\sumi{N}\left\{\mu_i(1-\mu_i)\bold{x_i}\cdot\left[-3\mu_i^2+2(1+y_i)\mu_i-y_i\right]\cdot\bold{x_i}\right\}\\
            &=\frac{2}{N}\sumi{N}\left\{\mu_i(1-\mu_i)\cdot\left[-3\mu_i^2+2(1+y_i)\mu_i-y_i\right]\cdot\bold{x_i}^2\right\}\\
            &因为\mu_i\in[0,1],故\mu_i(1-\mu_i)\geq0,而且\bold{x_i}^2\geq0,现在只需考虑-3\mu_i^2+2(1+y_i)\mu_i-y_i\\
            &当y_i=0时,\gg{w} MSE的符号由-3\mu_i^2+2\mu_i决定,-3\mu_i^2+2\mu_i的根为0和\frac{2}{3}\\
            &即其在[0,1]范围内有正有负.从而得出\gg{w} MSE有正有负,即为\textcolor{blue}{非凸函数}.\\
            &\\
            &而使用MLE得到的梯度函数为\\
            &\bold{g}(\bold{w})=\sumi{N} \left[\mu(\bold{x}_i)-y_i\right]\bold{x}_i\\
            &可以看出梯度是和当前的预测值与实际值的差有关的,没有受到sigmoid函数导数的影响,\\
            &且真实值与预测值差别越大,梯度越大,更新的速度也就越快,这正是我们想要的.\\
            &且MLE得到的NLL目标函数的二阶Hessian矩阵是正定的:\\
            &\gg{w} NLL(\bold{w})=\g{w}g(\bold{w})=\sumi{N}\g{w}\mu(\bold{x}_i)\bold{x}_i=\sumi{N}\mu(\bold{x})\cdot\left[1-\mu(\bold{x})\right]\cdot\bold{x}^2\geq0\\
            &故NLL(\bold{w})为凸函数.\\
    \end{aligned}
$$
</font>

#### 二阶Hessian矩阵
$$
    \def\sumi#1{\sum_{i=1}^#1}
    \begin{aligned}
        \bold{H}(\bold{w})
        &=\frac{\partial}{\partial \bold{w}}
        \left[\bold{g}(\bold{w})^T\right]=\sumi{N}\left(
            \frac{\partial}{\partial \bold{w}}
            \mu_i
        \right)\bold{x}_i^T\\
        &=\mu_i(1-\mu_i)\bold{x}_i\bold{x}_i^T=\bold{X}^Tdiag(\mu_i(1-\mu_i))\bold{X}
    \end{aligned}
$$

$dia\bold{g}(\mu_i(1-\mu_i))$ 是正定矩阵,可以使用凸优化.

### 牛顿法
又叫做牛顿-拉夫逊(Newton-Raphson)方法
- 牛顿在17世纪提出的一种近似求解方程的方法
- 使用函数$f(x)$的泰勒级数的前几项来寻找方程$f(x)=0$的根

在极值问题中,求$\bold{g}(\bold{w})=\frac{\partial}{\partial\bold{w}}J(\bold{w})$的根
- 对应$J(\bold{w})$取极值

<font color=red>对$\bold{g}(\bold{w})$用泰勒展开求解</font>

将梯度$\bold{g}(\bold{w})$在$\bold{w}^t$处进行泰勒展开:
$$
    0=\bold{g}(\hat{\bold{w}})=\bold{g}(\bold{w}^t)+(\hat{\bold{w}}-\bold{w})\bold{H}(\bold{w}^t)+Op(\hat{\bold{w}}-\bold{w})
$$
从而得到
$$
    \hat{\bold{w}}\approx\bold{w}^t-\bold{H}^{-1}(\bold{w}^t)\bold{g}(\bold{w}^t)
$$
所以迭代机制:
$$
    \bold{w}^{t+1}\approx\bold{w}^t-\bold{H}^{-1}(\bold{w}^t)\bold{g}(\bold{w}^t)
$$

- 也被称为 **二阶梯度下降法**,移动方向:$\bold{H}(\bold{w}^t)\bold{d}=-\bold{g}(\bold{w}^t)$
- 一阶梯度下降法,移动方向:$\bold{d}=-\bold{g}(\bold{w}^t)$

LR的MLE用牛顿法求极值本质是 **IRLS**(Iteratively Reweighted Least Square) **迭代的加权最小二乘法**

引入记号:
$$
    \begin{aligned}
        \bold{g}^t(\bold{w})&=\bold{X}^T(\bold{\mu}^t-\bold{y}),\qquad\mu_i^t=sigmoid\left((\bold{w}^t)^T\bold{x}_i\right)\\
        \bold{H}^t(\bold{w})&=\bold{X}^T\bold{S}^t\bold{X},\qquad\bold{S}^t:=diag(\mu_1^t(1-\mu_1^t),\cdots,\mu_N^t(1-\mu_N^t))
    \end{aligned}
$$

根据牛顿法的结果:
$$
    \begin{aligned}
        \bold{w}^{t+1}&=\bold{w}^t-(\bold{H}^t)^{-1}\bold{g}^t\\
        &=\bold{w}^t+\textcolor{blue}{(\bold{X}^T\bold{S^t}\bold{X})^{-1}}\bold{X}^T(\bold{y}-\bold{\mu}^t)\\
        &=\textcolor{blue}{(\bold{X}^T\bold{S^t}\bold{X})^{-1}}[(\bold{X}^T\bold{S^t}\bold{X})\bold{w}^t+\bold{X}^T(\bold{y}-\bold{\mu}^t)]\\
        &=(\bold{X}^T\bold{S^t}\bold{X})^{-1}\textcolor{blue}{\bold{X}^T}[\bold{S^t}\bold{X}\bold{w}^t+(\bold{y}-\bold{\mu}^t)]\\
        &=(\bold{X}^T\bold{S^t}\bold{X})^{-1}\bold{X}^T\bold{S}^t\textcolor{blue}{[\bold{X}\bold{w}^t+(\bold{S^t})^{-1}(\bold{y}-\bold{\mu}^t)]}\qquad where\ \bold{z}^t=\bold{X}\bold{w}^t+(\bold{S^t})^{-1}(\bold{y}-\bold{\mu}^t)\\
        &=(\bold{X}^T\bold{S^t}\bold{X})^{-1}\bold{X}^T\bold{S}^t\textcolor{blue}{\bold{z}^t}\qquad加权最小二乘问题的标准方程\\
    \end{aligned}
$$

回忆最小二乘:
$$
    \hat{\bold{w}}_{OLS}=(\bold{X}^T\bold{X})^{-1}\bold{X}^T\bold{y}
$$

可以将LR的MLE的牛顿法求解方法看做是 <font color=red>**加权最小二乘问题**</font>,权重矩阵为 $\bold{S}$.  
但是权重矩阵 $\bold{S}$ 不是常数,而是依赖参数向量 $\bold{w}$ .因此我们必须使用标准方程来迭代计算,每次使用性的权向量 $\bold{w}$ 来修正权重矩阵 $\bold{S}$.**因此该算法被称为迭代再加权最小二乘(iterative reweighted least squares, IRLS)**.

牛顿法比一般的梯度下降法收敛更快但是计算量大,计算二阶偏导复杂度大拟牛顿法(Quasi-Newton Methods)构造近似Hessian矩阵(或者Hessian矩阵的逆矩阵)的正定对称阵
BFGS/LBFGS/Newton-C\bold{g}(有兴趣可以参考优化方面的书)
正则化的Logistic回归 对上面的损失函数

$$
    J(w)=\sum-[y\log(μ)+(1-y)\log(1-μ)]
$$

加上正则项L1正则或者L2正则然后再用梯度下降法 或者 牛顿法求解最小值Logistic回归学习得到的分类面是线性的

多类Logistic回归
上面介绍了两类分类的Logistic回归对于多类分类 有两种方式1.OvR学习多种一对二的分类器  一对所有(One-vs-all/One-vs-rest)  OvR下面的例子分三次学习,得到三个模型,每个模型有三个参数 $w_1,w_2,w_0$ 截距项,共有9个参数

如何预测新来的数据是哪一类?    

缺点:OvR把O作为正例,把R作为反例,如果多类中每类数量差不多的话,则会 正例O太少,反例R太多  类别不平衡问题

Softmax回归
直接从概率模型的角度来看,抛硬币→掷骰子   
Softmax回归:从sigmoid函数(对应二项分布)扩展到softmax函数(对应多项分布 Cat)  Cat(Category )

TODO 参考 [Sigmod/Softmax变换](https://blog.csdn.net/pipisorry/article/details/77816624)

分类模型的评价
sklearn 提供三种不同的API,用于评估模型预测的性能:
- Estimator score method:模型自带的分数方法(score函数)提供一个缺省的评估标准
- Scoring parameter:采用交叉验证的模型评估工具    (model selection.cross_val_score and model selection.GridSearchCV,以及一些xxxCV类)有scoring参数(最佳参数为最大scroing模型对应的参数)
- Metric functions:metrics模块提供评价预测误差的功能分类模型性能评价(Classification metrics)
* 损失函数(log_loss, zero_one_loss, hinge_loss)
* logistic/负log似然损失(log_loss):

TODO Scikit learn 中的Logistic回归实现模型选择与参数调优

案例分析
