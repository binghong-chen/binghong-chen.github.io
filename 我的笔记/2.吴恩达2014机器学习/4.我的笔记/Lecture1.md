我们以后会讲一个算法,叫支持向量机,里面有
一个巧妙的数学技巧,能让计算机处理无限多个特征.

鸡尾酒宴算法(Cocktail party problem algorithm):
$[W,s,v]=svd((repmat(sum(x.^*x,1),size(x,1),1).^*x)^*x')$

更多内容看:  
[1. ICA](../3.机器学习总结/ICA.md)
[2. 机器学习】【ICA-2】ICA独立成分分析的原理 + ICA前的预处理(中心化+漂白)](https://blog.csdn.net/u012421852/article/details/80500940)
[3. 独立成分分析(Independent Component Analysis)](https://www.cnblogs.com/jerrylead/archive/2011/04/19/2021071.html)
[4. 独立成分(ICA)分析](https://www.jianshu.com/p/de396e8cce15)
[5. 因子分析,主成分分析(PCA),独立成分分析(ICA)——斯坦福CS229机器学习个人总结(六)](https://blog.csdn.net/sinat_37965706/article/details/71330979)