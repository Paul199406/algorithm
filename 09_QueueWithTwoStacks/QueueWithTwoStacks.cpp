//author:lijiwei
//date:2020/2/10
// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

#include <iostream>
#include <stack>

using namespace std;

template<typename T>
class MyQueue
{
    stack<T> s1;
    stack<T> s2;
public:
    
    // 在队列末尾添加一个结点
    void appendTail(const T& node)
    {
        s1.push(node);
    }

    // 删除队列的头结点
    T deleteHead()
    {
        if ( s2.size()<= 0)//栈2空
        {
            while ( s1.size()>0 )//栈1不空,移动到栈2中
            {
                T node = s1.top();
                s1.pop();
                s2.push(node);
            }
        }
        
        if ( s2.size() == 0 )//两个栈都没元素
        {
            cout << "empty Queue" << endl; 
            return 0;
        }

        T node = s2.top();
        s2.pop();
        return node;
        
    }
};




int main()
{
    MyQueue<char> queue;

    queue.appendTail('a');
    queue.appendTail('b');
    queue.appendTail('c');
    cout << "Push: a b c" << endl;

    char head = queue.deleteHead();
    cout << "deleteHead:" << head << endl;
    head = queue.deleteHead();
    cout << "deleteHead:" << head << endl;

    queue.appendTail('d');
    cout << "Push: d"  << endl;
  
    head = queue.deleteHead();
    cout << "deleteHead:" << head << endl;
   
    head = queue.deleteHead();
    cout << "deleteHead:" << head << endl;


    head = queue.deleteHead();
    cout << "deleteHead:" << head << endl;
    return 0;
}
