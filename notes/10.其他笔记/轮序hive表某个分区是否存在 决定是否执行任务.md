## 【SQLboy必备】轮序hive表某个分区是否存在 决定是否执行任务
做特征工程的小伙伴们,你们是否遇到过类似这样的情况:你要算的特征依赖于其他人生成的表,但是你的任务又没法和他的合并在一起形成依赖关系.一下脚本实现的的功能是检查某一天的分区是否有数据,如果有则执行下面的程序,如果没有则重试,超过一定次数报错退出

转至[【SQLboy必备】轮询hive表某个分区是否存在决定是否执行任务](https://www.bilibili.com/read/cv6027010)

``` sh
if [ $# -eq 1 ]; then
    today=$1
else
    today=`date-d"0 day ago" + %Y-%m-%d`
if

yesterday=`date-d"1 day ago $today" + %Y-%m-%d`
echo $today $yesterday

n=0
max_retries=5
path="/user/datastar/dac/one/warehouse/dac_one_dev/uo_gg_label/"
echo "max_retries:${max_retries}"

until [ $n -ge $max_retries ]
do
    hadoop fs -test -s ${path}ds=${yesterday}/000000_* && break
    n=$[$n+1]
    echo "$path not ready"
    sleep 1
done

echo "LAST ITER: $n"
if [ $n -eq $max_retries ]; then
    echo "$path max retries met, fail!!!!!"
    exit 1
else
    echo "$path OK at ${n}th try"
fi

echo "run"

sql=""

echo $sql
hive -e "$sql"
```