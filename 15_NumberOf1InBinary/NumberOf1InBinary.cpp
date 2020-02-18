//author:lijiwei
//date:2020/2/11
// 面试题15：二进制中1的个数
// 题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。例如
// 把9表示成二进制是1001，有2位是1。因此如果输入9，该函数输出2。

#include <iostream>


using namespace std;

int Numberof1InBinary(int num)
{
    int cnt=0;

    while ( num )
    {
       cnt++;
       num = num & (num-1);
    }

    return cnt;
}

int main()
{
    for(int i=-4; i<5; ++i)
    {
        cout << i <<"中二进制1的个数为:" << Numberof1InBinary(i) << endl;
    }
    return 0;
}
