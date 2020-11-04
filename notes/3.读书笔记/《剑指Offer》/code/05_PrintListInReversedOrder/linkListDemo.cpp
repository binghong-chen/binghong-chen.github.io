#include<iostream>
using namespace std;

struct LinkNode
{
    int val;
    LinkNode* pNext;
};

void insertAtHead(LinkNode** linkList, int val)
{
    LinkNode* node = new LinkNode();
    node->val = val;
    node->pNext = *linkList;
    *linkList = node;
}

void insertAtTail(LinkNode** linkList, int val)
{
    LinkNode* node = new LinkNode();
    node->val = val;
    if(*linkList == nullptr)
    {
        *linkList = node;
        return;
    }
    LinkNode* p = *linkList;
    while(p->pNext != NULL)
        p = p->pNext;
    p->pNext = node;
}

//链表的销毁
void ClearLinkList(LinkNode **pHead)				//传入为二级指针，否则不能将其他节点置为nullptr
{
	if(*pHead == nullptr)					//判断是否为空链表
	{
		cout<<"This is an empty LinkList"<<endl;
		return;
	}
	LinkNode *pTemNode = nullptr;
	while((*pHead)->pNext)					//这种情况下，包含了只有头节点的情况；
	{							//不只含有头节点时，最后*pHead指到最后的一个元素；
		pTemNode = (*pHead)->pNext;
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
void DestoryLinkList(LinkNode **pHead)
{
	if(*pHead == nullptr)
	{
		cout<<"This is an empty LinkList!"<<endl;
		return;
	}
	if((*pHead)->pNext == nullptr)				//相比链表销毁，多一步判断是否只有头节点这种情况
	{							//这种情况下，直接返回，不做处理
		cout<<"The LinkList is originally empty!"<<endl;
		return;
	}
	while((*pHead)->pNext)
	{
		LinkNode *pTemNode = (*pHead)->pNext;
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

void printList(LinkNode* linkList)
{
    cout << "printList" << endl;
    if(linkList == NULL) return;
    LinkNode* p = linkList;
    while(p != NULL)
    {
        cout << p->val << "\t";
        p = p->pNext;
    }
    cout << endl;
}

void printListReverse(LinkNode* linkList)
{
    cout << "printListReverse" << endl;
    if(linkList == NULL) return;
    LinkNode* p = linkList;
    LinkNode* q = NULL;
    while(p != NULL)
    {
        insertAtHead(&q, p->val);
        p = p->pNext;
    }

    printList(q);
}

int main()
{
    LinkNode* linkList = NULL;
    insertAtHead(&linkList, 1);
    insertAtHead(&linkList, 2);
    insertAtHead(&linkList, 3);
    insertAtHead(&linkList, 4);
    insertAtHead(&linkList, 5);
    printList(linkList);
    printListReverse(linkList);

    DestoryLinkList(&linkList);
    printList(linkList);

    linkList = NULL;
    insertAtTail(&linkList, 1);
    insertAtTail(&linkList, 2);
    insertAtTail(&linkList, 3);
    insertAtTail(&linkList, 4);
    insertAtTail(&linkList, 5);
    printList(linkList);
    printListReverse(linkList);

    return 0;
}