//author:lijiwei
//date:2020/2/12
// 面试题25：合并两个排序的链表
// 题目：输入两个递增排序的链表，合并这两个链表并使新链表中的结点仍然是按
// 照递增排序的。

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



ListNode * Merge(ListNode* pHead1,ListNode* pHead2)
{
    if ( pHead1 == nullptr )//链表1空
    {
        return pHead2;
    }
    else  if (pHead2 == nullptr )
    {
        return pHead1;
    }

    ListNode* pNewHead=nullptr;
    ListNode* pNode=nullptr;
    while( pHead1!=nullptr && pHead2!=nullptr  )
    {
        if ( pHead1->m_nValue <= pHead2->m_nValue  )//第一个链表数值小于第二个
        {
            if ( pNewHead==nullptr )//当前新链表为空
            { 
                pNode=pNewHead = pHead1;
            }
            else
            {
                pNode->m_pNext = pHead1;
                pNode = pNode->m_pNext;
            }
            pHead1 = pHead1->m_pNext;
            
        }
        else
        {
            if ( pNewHead==nullptr )//当前新链表为空
            { 
                pNode = pNewHead = pHead2;
            }
            else
            {
                pNode->m_pNext = pHead2;
                pNode = pNode->m_pNext;
            }
            pHead2 = pHead2->m_pNext;
            
        }
 
    }
    
    if ( pHead1 == nullptr )
    {
        pNode->m_pNext = pHead2;
    }
    else if ( pHead2 == nullptr)
    {
        pNode->m_pNext = pHead1;
    }
    return pNewHead;
}



// ====================测试代码====================
ListNode* Test(char* testName, ListNode* pHead1, ListNode* pHead2)
{
    if(testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    PrintList(pHead1);

    printf("The second list is:\n");
    PrintList(pHead2);

    printf("The merged list is:\n");
    ListNode* pMergedHead = Merge(pHead1, pHead2);
    PrintList(pMergedHead);
    
    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(2);
    ListNode* pNode4 = CreateListNode(4);
    ListNode* pNode6 = CreateListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test1", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表中有重复的数字
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pNode2 = CreateListNode(1);
    ListNode* pNode4 = CreateListNode(3);
    ListNode* pNode6 = CreateListNode(5);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode* pMergedHead = Test("Test2", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 两个链表都只有一个数字
// list1: 1
// list2: 2
void Test3()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode2 = CreateListNode(2);

    ListNode* pMergedHead = Test("Test3", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// 一个链表为空链表
// list1: 1->3->5
// list2: 空链表
void Test4()
{
    ListNode* pNode1 = CreateListNode(1);
    ListNode* pNode3 = CreateListNode(3);
    ListNode* pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode* pMergedHead = Test("Test4", pNode1, nullptr);

    DestroyList(pMergedHead);
}

// 两个链表都为空链表
// list1: 空链表
// list2: 空链表
void Test5()
{
    ListNode* pMergedHead = Test("Test5", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}


