//author:lijiwei
//date:2020/2/13
// 面试题30：包含min函数的栈
// 题目：定义栈的数据结构，请在该类型中实现一个能够得到栈的最小元素的min
// 函数。在该栈中，调用min、push及pop的时间复杂度都是O(1)。

#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

#define nullptr 0

template <typename T>
class StackWithMin
{
    stack<T>  m_data;//数据栈
    stack<T>  m_min;//辅助栈.栈顶元素为最小值

public:
    
    void push(const T & data)
    {
        m_data.push(data);//数据栈

        if (m_min.size()==0)//如果辅助栈为空
        {
            m_min.push(data);
        }
        else
        {
            T min = m_min.top();
            if (data < min)//辅助栈存入最小值
            {
                m_min.push(data);
            }
            else
            {
                m_min.push(min);
            }
        }
    }

    void pop()
    {
        m_data.pop();
        m_min.pop();
    }


    T min() const
    {
        return m_min.top();
    }

    
};

void Test(const char* testName, const StackWithMin<int>& stack, int expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(stack.min() == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

int main(int argc, char* argv[])
{
    StackWithMin<int> stack;

    stack.push(3);
    Test("Test1", stack, 3);

    stack.push(4);
    Test("Test2", stack, 3);

    stack.push(2);
    Test("Test3", stack, 2);

    stack.push(3);
    Test("Test4", stack, 2);

    stack.pop();
    Test("Test5", stack, 2);

    stack.pop();
    Test("Test6", stack, 3);

    stack.pop();
    Test("Test7", stack, 3);

    stack.push(0);
    Test("Test8", stack, 0);

    return 0;
}

