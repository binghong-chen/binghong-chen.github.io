#include <iostream>
#include <map>
using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

void preOrderVisit_Recursively(BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    cout << root->m_nValue;
    preOrderVisit_Recursively(root->m_pLeft);
    preOrderVisit_Recursively(root->m_pRight);
}

void inOrderVisit_Recursively(BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    inOrderVisit_Recursively(root->m_pLeft);
    cout << root->m_nValue;
    inOrderVisit_Recursively(root->m_pRight);
}

void postOrderVisit_Recursively(BinaryTreeNode *root)
{
    if (root == NULL)
        return;
    postOrderVisit_Recursively(root->m_pLeft);
    postOrderVisit_Recursively(root->m_pRight);
    cout << root->m_nValue;
}

int findIndex(int data[], int start, int end, int value)
{
    for (int i = start; i <= end; i++)
        if (data[i] == value)
            return i;
    return -1;
}

BinaryTreeNode *create_Recursively(int preOrderSeq[], int inOrderSeq[], int preStart, int preEnd, int inStart, int inEnd)
{
    // TODO 递归函数执行前提前判断，不用进入函数体再判断，浪费资源
    // if (preStart > preEnd || inStart > inEnd) return NULL;
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_nValue = preOrderSeq[preStart];
    int rootAtInOrder = findIndex(inOrderSeq, inStart, inEnd, root->m_nValue);
    // TODO 没有做 未找到的检测
    
    // TODO 其实不用找 rightAtPreOrder = preStart + (rootAtInOrder - inStart) + 1
    // int rightAtPreOrder = -1;
    // for (rightAtPreOrder = preStart + 1; rightAtPreOrder <= preEnd; rightAtPreOrder++)
    // {
    //     int value = preOrderSeq[rightAtPreOrder];
    //     int index = findIndex(inOrderSeq, rootAtInOrder + 1, inEnd, value);
    //     if (index != -1) break;
    // }
    // TODO 递归函数执行前提前判断，不用进入函数体再判断，浪费资源
    // root->m_pLeft = create_Recursively(preOrderSeq, inOrderSeq, preStart + 1, rightAtPreOrder - 1, inStart, rootAtInOrder - 1);
    // root->m_pRight = create_Recursively(preOrderSeq, inOrderSeq, rightAtPreOrder, preEnd, rootAtInOrder + 1, inEnd);

    int leftLength = rootAtInOrder - inStart;
    int leftEndAtPreOrder = preStart + leftLength;
    if(leftLength > 0) root->m_pLeft = create_Recursively(preOrderSeq, inOrderSeq, preStart + 1, leftEndAtPreOrder, inStart, rootAtInOrder - 1);
    if(leftLength < preEnd - preStart) root->m_pRight = create_Recursively(preOrderSeq, inOrderSeq, leftEndAtPreOrder + 1, preEnd, rootAtInOrder + 1, inEnd);

    return root;
}

BinaryTreeNode *create(int preOrderSeq[], int inOrderSeq[], int length)
{
    // TODO if (preOrderSeq == NULL || inOrderSeq == NULL) return NULL; // 没有判断 length输入是否合法
    if (preOrderSeq == NULL || inOrderSeq == NULL || length <= 0) return NULL;
    return create_Recursively(preOrderSeq, inOrderSeq, 0, length - 1, 0, length - 1);
}

int main()
{
    int preOrderSeq[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inOrderSeq[] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode *root = create(preOrderSeq, inOrderSeq, 8);

    cout << "preOrder: ";
    preOrderVisit_Recursively(root);
    cout << endl;

    cout << "inOrder: ";
    inOrderVisit_Recursively(root);
    cout << endl;

    cout << "postOrder: ";
    postOrderVisit_Recursively(root);
    cout << endl;

    return 0;
}