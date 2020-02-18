//author:lijiwei
//date:2020/2/9
// 面试题18（一）：在O(1)时间删除链表结点
// 题目：给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该
// 结点。
//考虑的问题:
//1 空链表
//2 只有一个结点
//3 要删除的结点是最后的结点

#include <iostream>

using namespace std;

#define nullptr 0

struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
};

ListNode* CreateListNode(int value)
{
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;

    return pNode;
}

void ConnectListNodes(ListNode* pCurrent, ListNode* pNext)
{
    if(pCurrent == nullptr)
    {
        cout << "Error to connect two nodes." << endl;
        return;
    }

    pCurrent->m_pNext = pNext;
}


void DeleteNode(ListNode* &pListHead, ListNode* pToBeDeleted)
{
    //空链表或非法
    if ( pListHead == nullptr || pToBeDeleted == nullptr )
    {
        cout << "delete node error" << endl;
        return ;
    }
     
    //链表只有一个结点
    if ( (pListHead==pToBeDeleted) && (pToBeDeleted->m_pNext==nullptr) )
    {
        pListHead = nullptr;
        delete pToBeDeleted;
        return ;
    }
   
    //如果是链表的最后一个结点
    if ( pToBeDeleted->m_pNext == nullptr )
    {
        ListNode * pBefore=pListHead;
        while( pBefore->m_pNext != pToBeDeleted )
        {
            pBefore = pBefore->m_pNext;
        }
   
        pBefore->m_pNext = pBefore->m_pNext->m_pNext;
        delete pToBeDeleted;
    }
    else
    {
        pToBeDeleted->m_nValue = pToBeDeleted->m_pNext->m_nValue;
        ListNode * p = pToBeDeleted->m_pNext;
        
        pToBeDeleted->m_pNext = pToBeDeleted->m_pNext->m_pNext;
        delete p;
    }
    
}

void DisplayList(ListNode* pHead)
{
    ListNode* p = pHead;
    while(p != nullptr)
    {
        cout << p->m_nValue << "->" ;
        p = p->m_pNext;
    }
    cout << "NULL" << endl;
}

int main()
{
    ListNode * pNode1;
    ListNode * pNode2;
    ListNode * pNode3;

    pNode1 = CreateListNode(1);
    pNode2 = CreateListNode(2);
    pNode3 = CreateListNode(3);
 
 
    //list1:1->2->3
    ConnectListNodes(pNode1,pNode2);
    ConnectListNodes(pNode2,pNode3);
    cout << "List1:1->2->3"  << endl;
    
    cout << "After delete 2:" << endl;
    DeleteNode(pNode1,pNode2);
    DisplayList(pNode1);

    cout << "After delete 3:" << endl;
    DeleteNode(pNode1,pNode2);
    DisplayList(pNode1);

    cout << "After delete 1:" << endl;
    DeleteNode(pNode1,pNode1);
    DisplayList(pNode1);
    
    cout << "delete empty list:" << endl;
    DeleteNode(pNode1,pNode1);
    DisplayList(pNode1);

    return 0;
}




