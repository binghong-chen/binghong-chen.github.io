## 二,单变量线性回归(Linear Regression with One Variable)

房价问题

Hypothesis:
$$
    h_\theta=\theta_0+\theta_1x
$$
Parameters:
$$
    \theta_0,\theta_1
$$
Cost Function:
$$
    J(\theta_0,\theta_1)=\frac{1}{2m}\sum_{i=1}^m\left(h_\theta(x^{(i)}-y^{(i)}\right)^2
$$
Goal:
$$
    \min_{\theta_0,\theta_1}J(\theta_0,\theta_1)
$$
Gradient descent algorithm:  
repeat until convergence {  
&ensp;&ensp;$\theta_j:=\theta_j-\alpha\frac{\partial}{\partial\theta_j}J(\theta_0,\theta_1)\;\;\;\;\;\;(for\;j=0\;and\;j=1)$  
}

正确代码:同时更新参数  
$
    temp0:=\theta_0-\alpha\frac{\partial}{\partial\theta_j}J(\theta_0,\theta_1)\\
    temp0:=\theta_0-\alpha\frac{\partial}{\partial\theta_j}J(\theta_0,\theta_1)\\
    \theta_0:=temp0\\
    \theta_1:=temp1
$

错误代码:  
$
    temp0:=\theta_0-\alpha\frac{\partial}{\partial\theta_j}J(\theta_0,\theta_1)\\
    \theta_0:=temp0\\
    temp0:=\theta_0-\alpha\frac{\partial}{\partial\theta_j}J(\theta_0,\theta_1)\\
    \theta_1:=temp1
$

<font class="todo" color="red">TODO:为什么需要同时更新参数?</font>   
>我们一般说的梯度下降算法就是指同时更新的梯度下降算法,错误代码有时也会得到局部最小值.但是和正确代码有些微小差别,具有不同的性质.

<font class="todo" color="red">TODO:如何设置学习率$\alpha$?</font>

"Batch" Gradient Descent

"Batch": Each step of gradient descent uses all the training examples.
关于梯度下降算法,可以查看[更多](../../3.机器学习自我总结/梯度下降算法.md).