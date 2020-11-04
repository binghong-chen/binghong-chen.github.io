<font style="font-size:72px;">$\theta$</font>

## EM算法

### 简介
是一种参数估计方法

用于含有隐变量(hidden variable)的概率模型参数的极大似然估计,或极大后验概率估计.

EM算法是一种迭代算法,迭代过程分为两步 E步 求期望(exception);M步,求极大(maximization)

### EM算法流程
1. E步:求 完全数据的对数似然函数 $\log P(Y,Z|\theta)$ 关于$P(Z|Y,\theta^{(i)})$ 的数学期望 ,记为$Q(\theta, \theta^{(i)})$,即:
$$
    Q(\theta, \theta^{(i)})=E_{Z|Y,\theta^{(i)}}[\log P(Y,Z|\theta)]
$$

2. M步:对E步的结果求极值

### 案例:EM算法求解三硬币模型

#### 三硬币模型

假设有 $3$ 枚硬币,分别记作 $A,B,C$.这些硬币正面出现的概率分别是$π,p,q$, 进行如下掷硬币实验:先掷硬币 $A$,根据其结果选出硬币 $B$ 或 $C$,正面选 $B$,反面选 $C$,然后掷选出的硬币,掷硬币的结果,出现正面记作 $1$,反面记作 $0$;独立重复$n$次实验,观测记为$Y=y_1,y_2,...,y_n$.

#### EM算法求解
##### 变量记号解释
* $y_j$为第$j$次实验的观测
* $Z$为隐变量,表示掷硬币 $A$ 出现的结果.该变量只有两个取值 $0,1$
* $z_j$为第$j$次实验时,掷硬币 $A$ 出现的结果,同样的,$z_j=1$表示硬币 $A$ 掷出正面
* $θ$表示参数集合$π,p,q$
* $θ^{(i)}$为第$i$次迭代时,$π,p,q$的估计值

##### E-step
完全数据的对数似然函数为:
$$
    \begin{aligned}
        \log P(Y,Z|\theta)&=\log(\prod_{j=1}^n p(y_j,z_j|\theta))\\
        &=\sum_{j=1}^n\log(p(y_j,z_j|\theta))
    \end{aligned}
$$

期望为:
$$
    \begin{aligned}
        Q(\theta,\theta^{(i)})&=E_{Z|Y,\theta^{(i)}}[\log P(Y,Z|\theta)]\\
        &=\sum_{j=1}^n\sum_{z_j}[p(z_j|y_j,\theta^{(i)})\log(p(y_j,z_j|\theta))]\\
        &=\sum_{j=1}^n\left\{\begin{aligned}
           &[p(z_j=1|y_j,\theta^{(i)})\log(p(y_j,z_j=1|\theta))]\\
           +\\
           &[p(z_j=0|y_j,\theta^{(i)})\log(p(y_j,z_j=0|\theta))]
        \end{aligned}\right\}\qquad(1)
    \end{aligned}
$$
对于后验概率$p(z_j|y_j,\theta^{(i)})$,此时$\theta^{(i)}$是一个常量,所以后验概率$p(z_j|y_j,\theta^{(i)})=p(z_j|y_j)$
$$
    \begin{aligned}
        &\mu_j^{(i+1)}=p(z_j=1|y_j,\theta^{(i)})=p(z_j|y_j)\\
        &=\frac{p(y_j,z_j=1)}{p(y_j)}=\frac{p(y_j|z_j=1)p(z_j=1)}{\sum_{z_j}p(y_j,z_j)}\\
        &=\frac{p(y_j|z_j=1)p(z_j=1)}{p(y_j,z_j=1)+p(y_j,z_j=0)}\\
        &=\frac{\pi^{(i)}(p^{(i)})^{y_j}(1-p^{(i)})^{1-y_j}}{\pi^{(i)}(p^{(i)})^{y_j}(1-p^{(i)})^{1-y_j}+(1-\pi^{(i)})(q^{(i)})^{y_j}(1-q^{(i)})^{1-y_j}}\qquad(2)
    \end{aligned}
$$
对于联合概率$p(z_j,y_j|\theta)$
$$
    \begin{aligned}
        &p(y_j,z_j=1|\theta)=p(z_j=1|\theta)p(y_j|z_j=1,\theta)=\pi p^{y_j}(1-p)^{1-y_j}\\
        &p(y_j,z_j=0|\theta)=p(z_j=0|\theta)p(y_j|z_j=0,\theta)=(1-\pi)q^{y_j}(1-q)^{1-y_j}\qquad(3)
    \end{aligned}
$$
将$(2),(3)$带入$(1)$,得到期望的最终表达式:
$$
    \begin{aligned}
        Q(\theta,\theta^{(i)})&=E_{Z|Y,\theta^{(i)}}[\log P(Y,Z|\theta)]\\
        &=\sum_{j=1}^n\left\{\begin{aligned}
           &[p(z_j=1|y_j,\theta^{(i)})\log(p(y_j,z_j=1|\theta))]+ \\
           &[p(z_j=0|y_j,\theta^{(i)})\log(p(y_j,z_j=0|\theta))]
        \end{aligned}\right\}\\
        &=\sum_{j=1}^n\left\{\begin{aligned}
           &\mu_j^{(i+1)}\log\big[\pi p^{y_j}(1-p)^{1-y_j}\big]+ \\
           &\big[1-\mu_j^{(i+1)}\big]\log\big[(1-\pi)q^{y_j}(1-q)^{1-y_j}\big]
        \end{aligned}\right\}
    \end{aligned}
$$

##### M-step
对$Q(\theta, \theta^{(i)})$求极值,即$\frac{\partial Q}{\partial\theta}=0$,在三硬币模型中,$\theta=(\pi,p,q)$

即:$\frac{\partial Q}{\partial\pi}=0,\frac{\partial Q}{\partial p}=0,\frac{\partial Q}{\partial q}=0$

1 $\frac{\partial Q}{\partial\pi}=0$
$$
    \begin{aligned}
        \frac{\partial Q}{\partial\pi}&=\sum_{j=1}^n\left\{\mu_j^{(i+1)}\times\frac{1}{\pi}-\big[1-\mu_j^{(i+1)}\big]\times\frac{1}{1-\pi}\right\}\\
        &=\sum_{j=1}^n\left\{\frac{\pi-\mu_j^{(i+1)}}{\pi(1-\pi)}\right\}\\
        &=\frac{n\pi-\sum_{j=1}^n\mu_j^{(i+1)}}{\pi(1-\pi)}\\
        &=0
    \end{aligned}
$$
解得:
$$
    \pi=\frac{1}{n}\sum_{j=1}^n\mu_j^{(i+1)}
$$


2 $\frac{\partial Q}{\partial p}=0$
$$
    \begin{aligned}
        \frac{\partial Q}{\partial p}&=\frac{\partial}{\partial p}\sum_{j=1}^n\left\{\mu_j^{(i+1)}\log\big[\pi p^{y_j}(1-p)^{1-y_j}\big]\right\}\\
        &=\frac{\partial}{\partial p}\sum_{j=1}^n\left\{\mu_j^{(i+1)}\times[(\log\pi)+(y_j\log p)+((1-y_j)\log(1-p))]\right\}\\
        &=\frac{\partial}{\partial p}\sum_{j=1}^n\left\{\mu_j^{(i+1)}\times[(y_j\log p)+((1-y_j)\log(1-p))]\right\}\\
        &=\sum_{j=1}^n\left\{\mu_j^{(i+1)}\times[\frac{y_j}{p}-\frac{1-y_j}{1-p}]\right\}\\
        &=\sum_{j=1}^n\left\{\mu_j^{(i+1)}\times\frac{y_j-p}{p(1-p)}
        \right\}\\
        &=0
    \end{aligned}
$$
解得:
$$
    p=\frac{\sum_{j=1}^n\mu_j^{(i+1)}y_j}{\sum_{j=1}^n\mu_j^{(i+1)}}
$$



3 $\frac{\partial Q}{\partial q}=0$
$$
    \begin{aligned}
        \frac{\partial Q}{\partial q}&=\frac{\partial}{\partial q}\sum_{j=1}^n\left\{\big[1-\mu_j^{(i+1)}\big]\times\log\big[(1-\pi)q^{y_j}(1-q)^{1-y_j}\big]\right\}\\
        &=\frac{\partial}{\partial q}\sum_{j=1}^n\left\{\big[1-\mu_j^{(i+1)}\big]\times\log\big[(1-\pi)q^{y_j}(1-q)^{1-y_j}\big]\right\}\\
        &=\frac{\partial}{\partial q}\sum_{j=1}^n\left\{\big[1-\mu_j^{(i+1)}\big]\times\big[(\log(1-\pi))+(y_j\log q)+((1-y_j)\log(1-q)\big]\right\}\\
        &=\frac{\partial}{\partial q}\sum_{j=1}^n\left\{\big[1-\mu_j^{(i+1)}\big]\times\big[(y_j\log q)+((1-y_j)\log(1-q)\big]\right\}\\
        &=\sum_{j=1}^n\left\{\big[1-\mu_j^{(i+1)}\big]\times\big[\frac{y_j}{q}-\frac{1-y_j}{1-q}\big]\right\}\\
        &=\sum_{j=1}^n\left\{\big[1-\mu_j^{(i+1)}\big]\times\big[\frac{y_j-q}{q(1-q)}\big]\right\}\\
        &=0
    \end{aligned}
$$
解得:
$$
    q=\frac{\sum_{j=1}^n\big[1-\mu_j^{(i+1)}\big]y_j}{\sum_{j=1}^n\big[1-\mu_j^{(i+1)}\big]}
$$




EM算法迭代停止条件:
$||\theta^{(i+1)}-\theta^{(i)}||<\epsilon_1$ 或者 $||Q(\theta,\theta^{(i+1)})-Q(\theta,\theta^{(i)})||<\epsilon_2$


### EM算法的导出

#### 为什么不直接使用MLE?

目标函数:观测数据(不完全数据)$Y$关于参数$\theta$的对数似然函数,即:
$$
    \begin{aligned}
        L(\theta)&=\log P(Y|\theta)\\
        &=\log(\prod_{j=1}^n p(y_j|\theta))\\
        &=\sum_{j=1}^n\log p(y_j|\theta)\\
        &=\sum_{j=1}^n\left\{\log\sum_{z_j}p(y_j,z_j|\theta)\right\}\\
        &=\sum_{j=1}^n\left\{\log\sum_{z_j}p(z_j|\theta)p(y_j|z_j,\theta)\right\}
    \end{aligned}
$$
在极大化目标函数$L(\theta)$时:
$$
    \begin{aligned}
        \frac{\partial}{\partial\theta}L(\theta)&=\frac{\partial}{\partial\theta}\sum_{j=1}^n\left\{\log\sum_{z_j}p(y_j,z_j|\theta)\right\}\\
        &=\sum_{j=1}^n\left\{\frac{1}{\sum_{z_j}p(y_j,z_j|\theta)}\times\frac{\partial}{\partial\theta}\sum_{z_j}p(y_j,z_j|\theta)\right\}\\
    \end{aligned}
$$

非常困难(不好通分,通分后有高次项$\Leftarrow$<font color=red>对数函数中有加法</font>$\Leftarrow$隐变量$Z$展开过程引入).
$$
    \log\sum_{z_j}p(y_j,z_j|\theta)
$$

用EM的思想:(找到一个可以通过迭代不断逼近$L(\theta)$的下界函数)

事实上:EM算法是通过迭代足部近似极大化$L(\theta)$的.假设在第$i$次迭代后$\theta$的估计值是$\theta^{(i)}$.我们希望新估计值$\theta$能使$L(\theta)$增加,即<font color=red>要确保$L(\theta)>L(\theta^{(i)})$</font>,逐步达到极大值.

关键点:<font color=red>在$\theta^{(i)}$的前提下找到$\theta$, 要确保$L(\theta)>L(\theta^{(i)})$</font>

为此,考虑两者的差:


收敛性
