//author:lijiwei
//date:2020/2/10
// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。

#include <iostream>

using namespace std;

long long int Fibonacci(int n)
{
    if (n<0)//非法数据
    {
        return -1;
    }
    else if (n==0)
    {
        return 0;
    }
    else if (n==1)
    {
        return 1;
    }
    else
    {
        int n1 = 0;
        int n2 = 1;
        int sum = 0;
        for(int i=2; i<=n; ++i)
        {
            sum = n2 + n1;
            n1 = n2;
            n2 = sum;
        }
        return sum;
    }
}

int main()
{
    for (int i=-1; i<10; ++i)
    {
        cout << "Fabonacci(" << i << "):"  << Fibonacci(i) <<  endl; 
    } 

    return 0;
}
