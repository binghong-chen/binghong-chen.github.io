#include<iostream>
#include<vector>
using namespace std;
int rows = 2, columns = 3;

int GetSize(int data[])
{
    // 当数组作为函数参数时，其退化为一个指针
    // sizeof 取的是 这个指针的大小
    return sizeof(data);
}

void BDArr1()
{
    // 一维数组模拟二维数组
    cout << "一维数组模拟二维数组:" << endl;
    int bdArr[] = {1,2,3,4,5,6};

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout << bdArr[i*columns + j] << "\t";
        }
        cout << endl;
    }
}

void BDArr2()
{
    // 静态二维数组
    cout << "静态二维数组 一维数组字面量 {1,2,3,4,5,6}:" << endl;
    int bdArr[2][3] = {1,2,3,4,5,6};

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout << bdArr[i][j] << "\t";
        }
        cout << endl;
    }
}

void BDArr3()
{
    // 静态二维数组
    cout << "静态二维数组 二维数组字面量 {{1,2,3},{4,5,6}}:" << endl;
    int bdArr[2][3] = {
        {1,2,3},
        {4,5,6}
    };

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout << bdArr[i][j] << "\t";
        }
        cout << endl;
    }
}

void BDArr4()
{
    // 动态二维数组
    cout << "动态二维数组:" << endl;
    int** bdArr = new int*[rows];
    for(int i=0;i<rows;i++)
        bdArr[i] = new int[columns];
        
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout << bdArr[i][j] << "\t";
        }
        cout << endl;
    }

    // 释放空间
    for(int i=0;i<rows;i++)
        delete []bdArr[i];
    delete []bdArr;
}

void BDArr5()
{
    // 利用vector创建二维数组
    cout << "利用vector创建二维数组:" << endl;
    vector<vector<int> > bdArr(rows, vector<int>(columns));
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            bdArr[i][j] = i*columns + j + 1;
        }
    }

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<columns;j++)
        {
            cout << bdArr[i][j] << "\t";
        }
        cout << endl;
    }
}

int main()
{
    int size0 = sizeof(1);
    // 所有机器上 sizeof(int)=4
    cout << size0 << endl;

    int data1[] = {1, 2, 3, 4, 5};
    int size1 = sizeof(data1);

    int * data2 = data1;
    int size2 = sizeof(data2);

    int size3 = GetSize(data1);

    // 输出 20 8 8
    // 32位 机器上 sizeof(指针)=4，而64位机上 sizeof(指针)=8
    // 所有机器上 sizeof(int)=4
    // 所有机器上 sizeof(数组)=数组长度*sizeof(数组元素类型)
    cout << size1 << ", " << size2 << ", " << size3 << endl;

    cout << "二维数组:" << endl;
    BDArr1();
    BDArr2();
    BDArr3();
    BDArr4();
    BDArr5();
    
    return 0;
}