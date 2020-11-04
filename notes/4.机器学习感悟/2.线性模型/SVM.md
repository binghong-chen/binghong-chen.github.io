## SVM

### 目标函数

### 拉格朗日对偶性

#### 原始问题

带约束的问题

为什么系数$\alpha_i\geq0$?

$$
    \theta_{_P}(x)=\max_{\alpha,\beta:\alpha_i\geq0}L(x,\alpha,\beta)
$$

考虑极小化$\theta_{_P}(\alpha,\beta)$
$$
    \min_x\theta_{_P}(x)=\min_x\max_{\alpha,\beta:\alpha_i\geq0}L(x,\alpha,\beta)
$$



极小极大问题

#### 对偶问题

先考虑极小化
定义
$$
    \theta_{_D}(\alpha,\beta)=\min_xL(x,\alpha,\beta)
$$

再考虑极大化$\theta_{_D}(\alpha,\beta)$,即
$$
    \max_{\alpha,\beta:\alpha_i\geq0}\theta_{_D}(\alpha,\beta)=\max_{\alpha,\beta:\alpha_i\geq0}\min_xL(x,\alpha,\beta)
$$

极大极小问题

#### 原始问题与对偶问题的关系

d* ≤ p* 

### 求解与解的意义