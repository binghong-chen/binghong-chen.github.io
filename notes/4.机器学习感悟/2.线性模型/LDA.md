## LDA(Linear Discriminant Analysis)线性判别分析
类内散度矩阵
类间散度矩阵
广义瑞利商(generalized Rayleigh quotient)
转化为待等式约束的优化问题(拉格朗日乘子法求解)

$$
    w=S_w^{-1}(\mu_0-\mu_1)
$$

考虑数值稳定性,需对 $S_w$ 做奇异值分解 $S_w=U\Sigma V^T$,$\Sigma$是一个实对角矩阵,其对角线上的元素是 $S_w$ 的奇异值,$S_w^{-1}=V\Sigma U^T$ 得到 $S_w^{-1}$

### 推广到多任务情况
全局散度矩阵

### 综述
LDA是一种经典的监督降维技术.
其他常见的降维技术有PCA,不过PCA是非监督的降维技术.