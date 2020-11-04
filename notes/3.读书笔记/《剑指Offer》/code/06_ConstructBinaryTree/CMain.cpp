#include <iostream>
using namespace std;

struct BinaryTreeNode
{
    int m_nValue;
    BinaryTreeNode *m_pLeft;
    BinaryTreeNode *m_pRight;
};

BinaryTreeNode *ConstructCore(
    int *startPreorder, int *endPreorder,
    int *startInorder, int *endInorder)
{
    // 前序遍历序列的第一个数字是根节点的值
    int rootValue = startPreorder[0];
    BinaryTreeNode *root = new BinaryTreeNode();
    root->m_nValue = rootValue;
    root->m_pLeft = root->m_pRight = NULL;

    if (startPreorder == endPreorder)
    {
        if (startInorder == endInorder && *startPreorder == *startInorder)
            return root;
        throw "Invalid input.";
    }

    // 在中序遍历中找到根节点的值
    int *rootInorder = startInorder;
    while (rootInorder <= endInorder && *rootInorder != rootValue)
        ++rootInorder;

    if (rootInorder == endInorder && *rootInorder != rootValue)
        throw "Invalid input.";

    int leftLength = rootInorder - startInorder;
    int *leftPreorderEnd = startPreorder + leftLength;
    if (leftLength > 0)
        root->m_pLeft = ConstructCore(startPreorder + 1, leftPreorderEnd, startInorder, rootInorder - 1); // 构建左子树
    if (leftLength < endPreorder - startPreorder)
        root->m_pRight = ConstructCore(leftPreorderEnd + 1, endPreorder, rootInorder + 1, endInorder); // 构建右子树

    return root;
}

BinaryTreeNode *Construct(int *preorder, int *inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length <= 0)
        return NULL;
    return ConstructCore(preorder, preorder + length - 1, inorder, inorder + length - 1);
}

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

int main()
{
    int preOrderSeq[] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inOrderSeq[] = {4, 7, 2, 1, 5, 3, 8, 6};
    BinaryTreeNode *root = Construct(preOrderSeq, inOrderSeq, 8);

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