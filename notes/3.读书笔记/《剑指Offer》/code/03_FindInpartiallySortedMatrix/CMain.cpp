#include <iostream>   
#include <string>     
using namespace std;

// TODO 教训：无脑编程等于没有分析解决问题的能力，不是一上来就写代码，以为这样是勤奋？是专注？往往是失败！没想好之间别动手！

// TODO 无脑编程 代码复杂 算法低效 事倍功半
// 从左上角开始找
bool MyFind(int* arr, int rows, int columns, int rl, int rh, int cl, int ch, int target)
{
    if(rl > rh || cl > ch) return false;
    int value = arr[rl*columns + cl];
    if(value == target) return true;
    if(rl == rh && cl == ch) return false;
    if(value < target) return MyFind(arr, rows, columns, rl+1, rh, cl, ch, target) || MyFind(arr, rows, columns, rl, rh, cl+1, ch, target);
    return MyFind(arr, rows, columns, rl+1, rh, cl, ch, target) || MyFind(arr, rows, columns, rl, rh, cl+1, ch, target);
}
bool MyFind(int* arr, int rows, int columns, int target)
{
    // TODO 没有做 特殊输入检测 代码鲁棒性好
    return MyFind(arr, rows, columns, 0, rows-1, 0, columns-1, target);
}

// TODO 好设计 代码简洁 算法高效 事半功倍
// 从右上角开始找
bool Find(int* matrix, int rows, int columns, int number)
{
    // 特殊输入检测 代码鲁棒性好
    if(matrix != NULL && rows > 0 && columns > 0)
    {
        int row = 0;
        int column = columns - 1;
        while(row < rows && column >= 0)
        {
            int value = matrix[row*columns + column];
            if(value == number) return true;
            if(value > number) --column;
            else ++ row;
        }
    }
    return false;
}

int main()
{
    int arr[] = {1,2,8,9,
        2,4,9,12,
        4,7,10,13,
        6,8,11,15
    };

    int rows = 4, columns = 4;

    for(int target=-10;target<20;target++)
    {
        cout << "my code: " << target << ": " << MyFind(arr, rows, columns, target) << endl;
        cout << "good code: " << target << ": " << Find(arr, rows, columns, target) << endl;
    }

    return 0;
}