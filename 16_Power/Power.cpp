//author:lijiwe
//date:2020/2/11

// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
// 次方。不得使用库函数，同时不需要考虑大数问题。
//考虑的问题:
//1.底数为0且指数为负数时,返回0,并应该提示错误
//2.底数为1时,返回1
//3.指数为负数时
//4.乘方的快速算法

#include <iostream>

using namespace std;

int baseindex[100]={0};//记忆型,最大是base的99次方

int CalPower(double base,int exponent)
{
    
    if ( baseindex[exponent] != 0  )
    {
        return baseindex[exponent];
    }
    if ( base == 0 )
    {
        return 1;
    }
    
    if ( exponent == 0 )
    {
        return 1;
    }
    else if ( exponent == 1 )
    {
        return base;
    }
    else if ( exponent == 2 )
    {
        return base*base;
    }

    if ( (exponent&0x01) == 0  )//偶数
    {
        baseindex[exponent]=CalPower(base,exponent>>1)*CalPower(base,exponent>>1);
        return baseindex[exponent];
    }
    else
    {
        baseindex[exponent]=CalPower(base,exponent>>1)*CalPower(base,exponent>>1)*base;
        return baseindex[exponent];
    }
}

double Power(double base,int exponent)
{
    if ( (base==0)&&(exponent<0) )//底数为0时,指数为负数,
    {
        cout << "illegal input " << endl;
        return 0;
    }    

    bool bIsNeg = false;//指数是否为负数
    if ( exponent < 0 )
    {
        bIsNeg = true;
        exponent *= -1;
    }

    
    double result = CalPower(base,exponent);
    
    return bIsNeg ? 1.0/result : result;
    
}

int main()
{
    cout << "0的0次方:" << Power(0,0) << endl;
    cout << "0的-1次方:" << Power(0,-1) << endl;
    cout << "0的1次方:" << Power(0,1) << endl;

    cout << "1的-1次方:" << Power(1,-1) << endl;
    cout << "1的1次方:" << Power(1,-1) << endl;

    cout << "2的-1次方:" << Power(2,-1) << endl;
    cout << "2的1次方:" << Power(2,-1) << endl;

    cout << "-2的-1次方:" << Power(-2,-1) << endl;
    cout << "-2的1次方:" << Power(-2,1) << endl;
    cout << "2的1次方:" << Power(2,-1) << endl;
    cout << "2的-10次方:" << Power(2,-10) << endl;
    cout << "2的10次方:" << Power(2,10) << endl;
    cout << "2的0次方:" << Power(2,0) << endl;
       
    return 0;
}
