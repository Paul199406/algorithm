//author:lijiwei
//date:2020/2/9

#include <iostream>
#include <stack>

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

void PrintListReversing(ListNode* pHead)
{
    if ( pHead == nullptr )
        return ;
    
    stack<int>  st;
    ListNode* pNode = pHead;
    while ( pNode != nullptr  )
    {
        st.push(pNode->m_nValue);
        pNode = pNode->m_pNext;
    }
   
    cout << "List Reversing: "  << endl;
    while( !st.empty() )
    {
        cout << st.top() << "->";
        st.pop();
    }
    cout << "NULL" <<  endl;
}
   
 
int main()
{
    ListNode * pNode1;
    ListNode * pNode2;
    ListNode * pNode3;
    ListNode * pNode4;

    pNode1 = CreateListNode(1);
    pNode2 = CreateListNode(2);
    pNode3 = CreateListNode(3);
    pNode4 = CreateListNode(4);
 
    
    //list1:1->2->3
    ConnectListNodes(pNode1,pNode2);
    ConnectListNodes(pNode2,pNode3);
    cout << "List1:1->2->3"  << endl;
    PrintListReversing(pNode1);
    cout << "List2:4" << endl;
    PrintListReversing(pNode4);
    return 0;
}




