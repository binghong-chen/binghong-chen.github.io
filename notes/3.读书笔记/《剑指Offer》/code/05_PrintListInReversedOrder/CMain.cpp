#include<iostream>
#include<stack>
using namespace std;

struct ListNode
{
    int m_nKey;
    ListNode* m_pNext;
};


void insertAtHead(ListNode** linkList, int m_nKey)
{
    ListNode* node = new ListNode();
    node->m_nKey = m_nKey;
    node->m_pNext = *linkList;
    *linkList = node;
}

void insertAtTail(ListNode** linkList, int m_nKey)
{
    ListNode* node = new ListNode();
    node->m_nKey = m_nKey;
    if(*linkList == nullptr)
    {
        *linkList = node;
        return;
    }
    ListNode* p = *linkList;
    while(p->m_pNext != NULL)
        p = p->m_pNext;
    p->m_pNext = node;
}

void AddToTail(ListNode** pHead, int value)
{
    ListNode* pNew = new ListNode();
    pNew->m_nKey = value;
    pNew->m_pNext = NULL;
    if(*pHead == NULL)
    {
        *pHead = pNew;
    }
    else
    {
        ListNode* pNode = *pHead;
        whle(pNode->m_pNext != NULL)
            pNode = pNode->m_pNext;
        pNode->m_pNext = pNew;
    }
}

void RemoveNode(ListNode** pHead, int value)
{
    if(pHead == NULL || *pHead == NULL) return;
    ListNode* pToBeDeleted = NULL;
    if((*pHead)->m_nKey == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNod* pNode = *pHead;
        while(pNode->m_pNext != NULL && pNode->m_pNext->m_nKey != value)
            pNode = pNode->m_pNext;
        if(pNode->m_pNext != NULL && pNode->m_pNext->m_nKey == value)
        {
             pToBeDeleted = pNode->m_pNext;
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
    }
    if(pToBeDeleted != NULL)
    {
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
}

//链表的销毁
void ClearLinkList(ListNode **pHead)				//传入为二级指针，否则不能将其他节点置为nullptr
{
	if(*pHead == nullptr)					//判断是否为空链表
	{
		cout<<"This is an empty LinkList"<<endl;
		return;
	}
	ListNode *pTemNode = nullptr;
	while((*pHead)->m_pNext)					//这种情况下，包含了只有头节点的情况；
	{							//不只含有头节点时，最后*pHead指到最后的一个元素；
		pTemNode = (*pHead)->m_pNext;
		delete *pHead;
		*pHead = pTemNode;
	}							
	if((*pHead) != nullptr)					//将只有一个头节点或者最后一个节点销毁
	{
		delete *pHead;
		pHead = nullptr;
	}
	cout<<"Now LinkList has been cleared!"<<endl;
}

//链表的清空
void DestoryLinkList(ListNode **pHead)
{
	if(*pHead == nullptr)
	{
		cout<<"This is an empty LinkList!"<<endl;
		return;
	}
	if((*pHead)->m_pNext == nullptr)				//相比链表销毁，多一步判断是否只有头节点这种情况
	{							//这种情况下，直接返回，不做处理
		cout<<"The LinkList is originally empty!"<<endl;
		return;
	}
	while((*pHead)->m_pNext)
	{
		ListNode *pTemNode = (*pHead)->m_pNext;
		delete *pHead;
		*pHead = pTemNode;
	}
	if((*pHead))
	{
		delete *pHead;
		*pHead = nullptr;
	}
	cout<<"Now The LinkList has been destoryed!"<<endl;
}


void PrintListReversingly_Iteratively(ListNode* pHead)
{
    std::stack<ListNode*> nodes;

    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        nodes.push(pNode);
        pNode = pNode->m_pNext;
    }

    while(!nodes.empty())
    {
        pNode = nodes.top();
        cout << pNode->m_nKey << "\t";
        nodes.pop();
    }
    cout << endl;
}

void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead != NULL)
    {
        if(pHead->m_pNext != NULL)
        {
            PrintListReversingly_Recursively(pHead->m_pNext);
        }
        cout << pHead->m_nKey << '\t';
    }
}

int main()
{
    ListNode* linkList = NULL;
    insertAtTail(&linkList, 1);
    insertAtTail(&linkList, 2);
    insertAtTail(&linkList, 3);
    insertAtTail(&linkList, 4);
    insertAtTail(&linkList, 5);

    PrintListReversingly_Iteratively(linkList);
    PrintListReversingly_Recursively(linkList);
    cout << endl;

    return 0;
}