//author:lijiwei
//date:2020/2/12
// 面试题23：链表中环的入口结点
// 题目：一个链表中包含环，如何找出环的入口结点

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

ListNode* MeetingNode(ListNode * pHead)
{
    if ( pHead == nullptr )
        return nullptr;
    
    ListNode *pFast;
    ListNode *pSlow;

    if ( pHead->m_pNext != nullptr )
    {
        pSlow = pHead->m_pNext;
        pFast = pSlow->m_pNext;//初始时让快指针在慢指针的前一个,两者相等时有环
    }
    else
    {
        return nullptr;
    }
    
    while ( (pSlow!=nullptr)&&(pFast!=nullptr) )
    {
        if ( pSlow == pFast )//存在环
        {
            return pSlow;
        }
        
        pSlow = pSlow->m_pNext;
        pFast = pFast->m_pNext;

        if ( pFast!=nullptr && pFast->m_pNext!=nullptr )//快指针每次走两步
        {
            pFast = pFast->m_pNext;
        }
        else
        {
            return nullptr;
        }
    }
    return nullptr;
}

//链表中环的位置
ListNode* EntryNodeOfLoop(ListNode* pHead)
{
    if ( pHead == nullptr )
    {
        return nullptr;
    }

    ListNode* pMeet = MeetingNode(pHead);//得到环中的一个位置
    if ( pMeet == nullptr )//无环
    {
        return nullptr;
    }
   
    ListNode* pMeetInLoop = pMeet->m_pNext;
    //得到环中结点个数
    int nNodeCnt=1;
    while( pMeetInLoop != pMeet )
    {
        pMeetInLoop = pMeetInLoop->m_pNext;
        nNodeCnt++;
    }

    //找到环的位置
    ListNode* pBehind;
    ListNode* pFront;//提前走的指针
    pFront = pBehind = pHead;
    while ( nNodeCnt>0 )//先走nNodeCnt步数
    {
        pFront=pFront->m_pNext;
        nNodeCnt--;
    }

    while ( pBehind!=pFront )//
    {
        pBehind = pBehind->m_pNext;
        pFront  = pFront->m_pNext;
    }
    
    return pBehind;
}



// ==================== Test Code ====================
void Test(char* testName, ListNode* pHead, ListNode* entryNode)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(EntryNodeOfLoop(pHead) == entryNode)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}
// A list has a node, without a loop
void Test1()
{
    ListNode* pNode1 = CreateListNode(1);

    Test("Test1", pNode1, nullptr);

    DestroyList(pNode1);
}

// A list has a node, with a loop
void Test2()
{
    ListNode* pNode1 = CreateListNode(1);
    ConnectListNodes(pNode1, pNode1);

    Test("Test2", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test3()
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
    ConnectListNodes(pNode5, pNode3);

    Test("Test3", pNode1, pNode3);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test4()
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
    ConnectListNodes(pNode5, pNode1);

    Test("Test4", pNode1, pNode1);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, with a loop 
void Test5()
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
    ConnectListNodes(pNode5, pNode5);

    Test("Test5", pNode1, pNode5);

    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
}

// A list has multiple nodes, without a loop 
void Test6()
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

    Test("Test6", pNode1, nullptr);

    DestroyList(pNode1);
}

// Empty list
void Test7()
{
    Test("Test7", nullptr, nullptr);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();

    return 0;
}

