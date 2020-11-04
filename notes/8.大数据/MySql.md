
### RDBMS
关系型数据库
SQL

MySQL

模式 schema

表 table

create table

select

insert

update

delete

truncate table table_name;

drop table table_name;

查看列:
desc 表名;

添加列
alter table 表名 add column 列名 列的数据类型;

删除列
alter table 表名 drop column 列名;

修改列名
alter table bbb change 老列名 新列名 int;

修改列属性:
alter table 表名 modify 列名 列的数据类型;

视图 view

索引 index

存储过程

函数

元数据

事务
ACID
atomicity 原子性
consistency 一致性
isolation 隔离性
durability 持久性


OLTP 联机事务处理 实时 线上事务

OLAP 联机分析处理 离线报表 BI


### 其他类型数据库
层次性数据库
图数据库
key-value数据库

NoSQL Not only SQL

Redis
HBase
MongDB

一致性
强一致性
最终一致性

Eric Brewer CAP定理

分布式数据库
集群
扩展性
横向扩展
竖直扩展