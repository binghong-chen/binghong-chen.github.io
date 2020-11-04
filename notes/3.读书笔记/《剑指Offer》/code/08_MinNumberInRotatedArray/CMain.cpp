#include<iostream>

using namespace std;

/*
查找和排序

查找
1. 顺序查找
2. 二分查找
3. 哈希表查找
4. 二叉排序树查找

排序
1. 插入排序
2. 冒泡排序
3. 归并排序
4. 快速排序
*/

int RandomInRange(int start, int end)
{
    srand ( time(NULL) );
    return rand() % (end-start+1) + start; 
}

void Swap(int* p1, int* p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Partition函数，Partition就是分区的意思，即这个函数的作用是把输入的数组分成左右两部分，返回一个下标；
// 左边的数都比下标对应的数小，右边的数都比下标对应的数大。对于一个算法理解过程最重要，注意细节能够让代码精致。
int Partition(int data[], int length, int start, int end)
{
    if(data == NULL || length <= 0 || start < 0 || end >= length)
        throw "Invalid Parameters";
        // throw new exception("Invalid Parameters");

    // 随机从[start, end]中选一个下标，该下标对应的数字用作分隔
    // 目的是：把所有比它小的数字挪到它前面，比它大的数字挪到它后面。
    int index = RandomInRange(start, end);
    // 先把所选数字放与最后一个数字交换，先把它放到最后，不参与接下来的比较，将要比较的数字连成一串[start, end-1]
    Swap(&data[index], &data[end]);
    /*
    Small指针指向的是最后一个比最后一个元素还要小的元素，small左边的元素都比end指向的元素小；
    index指向当前需要审查的元素
    small和index之间 （不包括边界）的元素都是比end指向的元素大的元素；
    函数执行的原则是用index遍历数组，一旦审查元素比end指向的元素小，就把它放在small指向的那部分的左边；
    如果比end指向的元素大，就先放留在small和index之间。
    这种换位置的方法就是使用small指向小元素和大元素的交界处，当待查元素是小元素时，与small指向的元素的下一个元素互换，并更新small和index的位置；
    整个过程其实像是三个共享一段内存的栈，small指向小元素栈的栈顶，只能push，而index指向的是待查元素的栈，只能Pop,pop出来的如果比end元素小泽push进small栈，
    被挤掉的大元素放在空出来的位置，这样大元素栈的元素数量不变；如果大，大元素是一个从右边进左边出的队列；
    */
    int small = start - 1;
    for(index = start; index < end; ++index)
    {
        if(data[index] < data[end])
        {
            ++small;
            if(small != index)  //说明small与index之间有大于data[end]的元素；
                Swap(&data[index], &data[small]);   //其实不用判断，直接交换就可以了;
        }
    }
    // 循环结束后 small就是最后一个 比 所选数字 小的数字的下标
    ++small;
    // small现在就是第一个 比 所选元素 大的数字的下标
    // 而且该数字及其以后的所有数字都比 所选数字 大
    // 将该数字与所选数字交换
    // 得：所选数字 后边的数字都比它大
    Swap(&data[small], &data[end]);

    return small;
}

void QuickSort(int data[], int length, int start, int end)
{
    if(start == end) return;
    int index = Partition(data, length, start, end);
    if(index > start) QuickSort(data, length, start, index - 1);
    if(index < end) QuickSort(data, length, index + 1, end);
}

/*
性能分析：
时间复杂度分析
快排在最好情况下时间复杂度为O(nlogn).最坏情况下为O(n^2),平均时间复杂度为O(nlogn)，就平均时间而言，快排是所有排序算法中最优的。快排的排序趟数和初试序列有关。

空间复杂度分析
空间复杂度为O(),快排是递归的，需要栈的调用，因此他需要的辅助空间比较多
 */

int main()
{
    int data[] = {2,7,3,9,5,8,4,0,6,1};
    QuickSort(data, 10, 0, 9);
    for(int i=0;i<10;i++)
        cout << data[i] << "\t";

    return 0;
}