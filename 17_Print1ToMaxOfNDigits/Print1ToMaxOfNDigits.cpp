//author:lijiwei
//date:2020/2/11
// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
// 打印出1、2、3一直到最大的3位数即999。

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <unistd.h>
using namespace std;

void PrintNumber(char* number);
bool Increment(char* number);
void Print1ToMaxOfNDigits(int n)
{
    if (n<=0)
    {
        cout << "error n" << endl;
        return;
    }
  
    char * num = new char[n+1];
    memset(num,'0',n+1);
    num[n] = '\0';

    while ( !Increment(num) )
    {
        sleep(0.1);
        PrintNumber(num);
    }
   
    delete [] num;
}

//输出数组,忽略前面的'0'
void PrintNumber(char* number)
{
    int len = strlen(number);
    bool bZero = true;


    for(int i=0; i<len; ++i)
    {
        if ( bZero && (number[i] !='0') )//找到第一个非'0'
        {
            bZero = false;
        }

        if ( !bZero  )
        {
            cout << number[i]-'0' ; 
        }
    }
    cout << endl;
    
}
//数字自增1
bool Increment(char* number)
{
    int len = strlen(number);
    
    int  nCarry = 0;//进位
    for(int i=len-1; i>=0; --i)//从最后,即个位开始+1
    {
        int nSum = number[i] - '0' + nCarry;
       
        if ( i == (len-1) )
        {
            nSum++;//个位+1
        }
        
        if ( nSum == 10 )//该位产生进位
        {
            if (i==0)//溢出,完成最大数
            {
                return true;
            }
            
            nCarry=1;
            number[i]='0';
        }
        else
        {
            number[i]='0'+nSum;
            break;
        }
    }
    return false;
}


int main()
{
    Print1ToMaxOfNDigits(2);

    return 0;
}
