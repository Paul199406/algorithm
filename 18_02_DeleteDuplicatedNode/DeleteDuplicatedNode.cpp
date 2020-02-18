//author:lijiwei
//date:2020/2/9
//面试题18（二）：删除链表中重复的结点
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

void DeleteDuplication(ListNode* &pHead)
{
    if ( (pHead==nullptr) )
    {
        cout << "empty list" << endl;
        return ;
    }

    ListNode * pNode = pHead;
    ListNode * pPreNode=nullptr;

    while( pNode != nullptr )
    {
        ListNode* pNext = pNode->m_pNext;
        
        if ( (pNext!=nullptr) && (pNode->m_nValue!=pNext->m_nValue) )//当前结点与下一个结点值不相同
        {
            pPreNode = pNode;
            pNode = pNext;
        }
        else
        {
            //删除相同的结点
            int nValue = pNode->m_nValue;
            ListNode* pToBeDeleted=pNode;
            while( (pToBeDeleted!=nullptr) && (pToBeDeleted->m_nValue==nValue) )
            {
                ListNode* pNext = pToBeDeleted->m_pNext;
                delete pToBeDeleted;
                pToBeDeleted=nullptr;
		pToBeDeleted=pNext;
            }
            
            //将前面的结点与后面的结点接上
            if ( pPreNode == nullptr )//删除了本来的头结点
            {
                pHead = pToBeDeleted;
            }
            else
            {
                pPreNode->m_pNext = pToBeDeleted;
            }
            
            pNode = pToBeDeleted;
        }
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
    ListNode * pNode4;
    ListNode * pNode5;
    ListNode * pNode6;

    pNode1 = CreateListNode(1);
    pNode2 = CreateListNode(1);
    pNode3 = CreateListNode(2);
    pNode4 = CreateListNode(3);
    pNode5 = CreateListNode(3);
    pNode6 = CreateListNode(3);
 
 
 
    //list1:1->1->2->3->3->3
    ConnectListNodes(pNode1,pNode2);
    ConnectListNodes(pNode2,pNode3);
    ConnectListNodes(pNode3,pNode4);
    ConnectListNodes(pNode4,pNode5);
    ConnectListNodes(pNode5,pNode6);

    cout << "List1:1->1->2->3->3->3->3"  << endl;
    
    cout << "After delete dupliatedNode:" << endl;
    DeleteDuplication(pNode1);
    DisplayList(pNode1);

    return 0;
}




