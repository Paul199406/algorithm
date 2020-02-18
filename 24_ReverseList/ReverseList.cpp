//author:lijiwei
//date:2020/2/12
// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
#include <iostream>
#include <cstdio>
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
void DestroyList(ListNode* pHead)
{
    ListNode* pNode = pHead;
    while(pNode != nullptr)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

void PrintList(ListNode* pHead)
{
    ListNode* p = pHead;
    while(p != nullptr)
    {
        cout << p->m_nValue << "->" ;
        p = p->m_pNext;
    }
    cout << "NULL" << endl;
}




//反转链表
ListNode* ReverseList(ListNode* pHead)
{
    if ( pHead == nullptr )
    {
        return nullptr;
    }

    ListNode* pBefore=nullptr;//原链表前一个结点
    ListNode* pNow=pHead;
    ListNode* pFront;//原链表后一个结点

    while( pNow != nullptr )
    {
        if ( pNow->m_pNext != nullptr )//如果当前结点不是尾结点
        {
            pFront = pNow->m_pNext;
            
            pNow->m_pNext = pBefore;
            pBefore = pNow;
            pNow = pFront;
        }
        else
        {
            pNow->m_pNext = pBefore;
            break;
        }
    }
   
   return pNow;
}




// ====================测试代码====================
ListNode* Test(ListNode* pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode* pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);

    ListNode* pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入空链表
void Test3()
{
    Test(nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}


