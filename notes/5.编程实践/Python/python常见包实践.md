## python常见包实践

### 爬虫
#### Scrapy
#### Beautiful Soup
#### Scrapy

### 数据处理和展示
#### pandas
**概要:**
读取数据,数据概要查看
**学习资料:**
[Pandas数据分析三板斧——map,apply,applymap详解](https://www.jianshu.com/p/e76861ed1815)
[Pandas数据分析教程——盘点那些常用的函数(上)](https://www.jianshu.com/p/257ca9bd8d66)
[Pandas数据分析教程——盘点那些常用的函数(下)](https://www.jianshu.com/p/f0508675f478)
**总结:**
read_xxx():read_csv()
head()
info()
describe()
isnull()
data['ColumnName'].values 或者 data.ColumnName.values
columns
corr() co-efficient 相关系数
#### sicpy
#### numpy
#### matplotlib
**概要:**
绘图
**总结:**
matplotlib.pyplot
figure()
scatter()
title()
show()
xlabel() ylabel()
subplots()
savefig()
#### seaborn
**概要:**
基于 matplotlib,在其基础上封装,更加简单
**学习资料:**
[PYTHON可视化进阶---SEABORN1.3 分布数据可视化 - 直方图与密度图 DISPLOT() / KDEPLOT()/ RUGPLOT()](https://www.freesion.com/article/505655205/)
[Python可视化 | Seaborn5分钟入门(一)——kdeplot和distplot](https://www.jianshu.com/p/844f66d00ac1)
[Python可视化 | Seaborn5分钟入门(二)——barplot&countplot&pointplot](https://www.jianshu.com/p/8bb06d3fd21b)
[Python可视化 | Seaborn5分钟入门(三)——boxplot和violinplot](https://www.jianshu.com/p/96977b9869ac)
[Python可视化 | Seaborn5分钟入门(四)——stripplot和swarmplot](https://www.jianshu.com/p/5896a0724fc8)
[Python可视化 | Seaborn5分钟入门(五)——lmplot](https://www.jianshu.com/p/9fbcef77a0cc)
[Python可视化 | Seaborn5分钟入门(六)——heatmap热力图](https://www.jianshu.com/p/85f8089f5313)
[Python可视化 | Seaborn5分钟入门(七)——pairplot](https://www.jianshu.com/p/c50cb4f1029f)

**自己总结:**
displot() 直方图 
    #BINS ---> 箱数
    #HIST,KED ---> 是否显示箱/密度曲线
    #NORM_HIST ---> 直方图是否按照密度来显示
    #RUG ---> 是否显示数据分布情况
    #VERTICAL ---> 是否水平显示
    #COLOR ---> 设置颜色
    #LABEL ---> 图例
    #AXLABEL ---> X轴标注
kdeplot() 密度图
    一维随机变量
    二维随机变量
rugplot()
    在坐标轴上投影分布情况
countplot()

heatmap()

### 浅层机器学习
[机器学习常用算法及笔记](https://www.cnblogs.com/wj-1314/tag/%E6%9C%BA%E5%99%A8%E5%AD%A6%E4%B9%A0%E5%B8%B8%E7%94%A8%E7%AE%97%E6%B3%95%E5%8F%8A%E7%AC%94%E8%AE%B0/)
#### libsvm
#### sklearn
#### xgboost

### 深度学习
[Python机器学习笔记:XgBoost算法](https://www.cnblogs.com/wj-1314/p/9402324.html)
#### tensonflow
#### pytorch
#### keras
[Python机器学习笔记:使用Keras进行回归预测](https://www.cnblogs.com/wj-1314/p/10137184.html)

### 自然语言处理
#### NLTK
#### jieba
#### hanlp
