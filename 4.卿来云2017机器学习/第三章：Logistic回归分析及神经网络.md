## 第三章:Logistic回归分析及神经网络
课程网址: http://edu.csdn.net/huiyiCourse/detail/539

### 学习要点
1. 损失函数:logistic损失;
2. 优化算法:IRLS(梯度下降,牛顿法),BP算法;
3. 正则化:L1/ L2;
4. 复习模型评估. 
案例:Otto商品分类.包含内容——用Logistic回归和神经网络实现Otto商品分类. 
课程目标:理解分类任算法Logistic回归和神经网络原理,复习数据集探索,并学会用sklearn用Logistic回归和(浅层)神经网络实现分类任务. 
非常像线性回归 但是用于分类  当然是有监督学习
Logistic回归基本原理(对数几率回归)
Logistic回归模型(亦被称为logit回归,最大熵分类(MaxEnt)或者log线性分类器)也是一个线性模型

二项分布/伯努利分布模型

sigmoid函数将

$$
μ=wTx → y=1/(1+exp(-μ))               (-∞,+∞)→(0,1)
$$

替代 单位阶跃函数(unit-step function),因为它不连续对数几率

$$
    ln(y/1-y)=w^Tx
$$

损失函数 的推导损失函数最小值的牛顿法 梯度g(w)=0求根梯度二阶Hessian矩阵牛顿法 比梯度下降法更好的方法,用到了二阶信息本质是IRLS(Iteratively Reweighted Least Square) 迭代再加权最小二乘回顾最小二乘解释加权最小二乘:做多次物理实验,测量一个物理量,但多次实验用到的仪器精度不一样,测量的可靠性也就不一样,需要加权.迭代算法牛顿法比一般的梯度下降法收敛更快但是计算量大,计算二阶偏导复杂度大拟牛顿法(Quasi-Newton Methods)构造近似Hessian矩阵(或者Hessian矩阵的逆矩阵)的正定对称阵BFGS/LBFGS/Newton-CG(有兴趣可以参考优化方面的书)正则化的Logistic回归 对上面的损失函数

$$
    J(w)=\sum-[y\log(μ)+(1-y)\log(1-μ)]
$$

加上正则项L1正则或者L2正则然后再用梯度下降法 或者 牛顿法求解最小值Logistic回归学习得到的分类面是线性的

多类Logistic回归
上面介绍了两类分类的Logistic回归对于多类分类 有两种方式1.OvR学习多种一对二的分类器  一对所有(One-vs-all/One-vs-rest)  OvR下面的例子分三次学习,得到三个模型,每个模型有三个参数w1,w2,w0截距项,共有9个参数

如何预测新来的数据是哪一类?    

缺点:OvR把O作为正例,把R作为反例,如果多类中每类数量差不多的话,则会 正例O太少,反例R太多  类别不平衡问题

2.Softmax回归直接从概率模型的角度来看,抛硬币→掷骰子   Softmax回归    从sigmoid函数(对应二项分布)扩展到softmax函数(对应多项分布 Cat)  Cat就是 Category 
分类模型的评价
sklearn 提供三种不同的API,用于评估模型预测的性能:
-Estimator score method:模型自带的分数方法(score函数)提供一个缺省的评估标准
-Scoring parameter:采用交叉验证的模型评估工具    (model selection.cross_val_score and model selection.GridSearchCV,以及一些xxxCV类)有scoring参数(最佳参数为最大scroing模型对应的参数)
-Metric functions:metrics模块提供评价预测误差的功能分类模型性能评价(Classification metrics)
* 损失函数(log_loss, zero_one_loss, hinge_loss)
* logistic/负log似然损失(log_loss):

    * -logloss=

Scikit learn 中的Logistic回归实现模型选择与参数调优

案例分析
