/*
 * 扩展练习：
 * 有两个排序的数组A1和A2，合并A1和A2，而且合并后有序
 */

#include<iostream>
using namespace std;

void merge(int fromArray[], int lengthOfFromArray, int toArray[], int lengthOfToArray)
{
    if(fromArray == NULL || toArray == NULL) return;
    if(lengthOfFromArray <= 0  || lengthOfToArray <= 0) return;
    int indexOfToArray = lengthOfToArray - 1, indexOfFromArray = lengthOfFromArray - 1;
    int indexOfArray = lengthOfFromArray + lengthOfToArray - 1;
    while(indexOfFromArray >= 0 && indexOfToArray >= 0)
    {
        if(fromArray[indexOfFromArray] > toArray[indexOfToArray])
            toArray[indexOfArray--] = fromArray[indexOfFromArray--];
        else
            toArray[indexOfArray--] = toArray[indexOfToArray--];
    }
    while(indexOfFromArray >= 0)
        toArray[indexOfArray--] = fromArray[indexOfFromArray--];
}

int main()
{
    int fromArray[] = {1,2,3,3,4,5,9};
    int toArray[] = {0,1,1,5,10,12, 0, 0, 0, 0, 0, 0, 0};
    merge(fromArray, 7, toArray, 6);

    for(int i=0;i<13;i++)
    {
        cout << toArray[i] << " ";
    }

    cout << endl << "---------------" << endl;

    int fromArray2[] = {11,12,13,13,14,15,19};
    int toArray2[] = {0,1,1,5,10,12, 0, 0, 0, 0, 0, 0, 0};
    merge(fromArray2, 7, toArray2, 6);

    for(int i=0;i<13;i++)
    {
        cout << toArray2[i] << " ";
    }

    cout << endl << "---------------" << endl;

    int fromArray3[] = {1,2,3,3,4,5,9};
    int toArray3[] = {10,11,11,15,20,22, 0, 0, 0, 0, 0, 0, 0};
    merge(fromArray3, 7, toArray3, 6);

    for(int i=0;i<13;i++)
    {
        cout << toArray3[i] << " ";
    }

    return 0;
}