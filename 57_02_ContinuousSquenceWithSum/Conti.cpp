// author:lijiwei
// date:2020/2/17
// 面试题57（二）：为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
// 例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
// 4～6和7～8。

#include <cstdio>
#define nullptr 0

void PrintContinuousSequence(int small, int big)
{
    printf("%d~%d\n",small,big);
}

//打印和为sum的连续正数序列
void FindContinuousSequence(int sum)
{
    if ( sum < 3 )
        return ;

    int small = 1;
    int big   = 2;
    int NowSum = 3;

    int mid   = (sum+1) / 2;//如果small=mid,将不会有连续正整数 mid + mid + 1 >sum
    
    while ( small < mid )
    {
        if ( NowSum == sum )
        {
            PrintContinuousSequence(small,big);
            NowSum -= small;
            small++;//继续查找
        }     
        else if ( NowSum < sum)
        {
            big ++;
            NowSum += big;
        }
        else
        {
            NowSum -= small;
            small ++;
        }
 
    }



}


/*
void PrintContinuousSequence(int small, int big);

void FindContinuousSequence(int sum)
{
    if(sum < 3)
        return;

    int small = 1; 
    int big = 2;
    int middle = (1 + sum) / 2;
    int curSum = small + big;

    while(small < middle)
    {
        if(curSum == sum)
            PrintContinuousSequence(small, big);

        while(curSum > sum && small < middle)
        {
            curSum -= small;
            small ++;

            if(curSum == sum)
                PrintContinuousSequence(small, big);
        }

        big ++;
        curSum += big;
    }
}

void PrintContinuousSequence(int small, int big)
{
    for(int i = small; i <= big; ++ i)
        printf("%d ", i);

    printf("\n");
}
*/
// ====================测试代码====================
void Test(const char* testName, int sum)
{
    if(testName != nullptr)
        printf("%s for %d begins: \n", testName, sum);

    FindContinuousSequence(sum);
}

int main(int argc, char* argv[])
{
    Test("test1", 1);
    Test("test2", 3);
    Test("test3", 4);
    Test("test4", 9);
    Test("test5", 15);
    Test("test6", 100);

    return 0;
}

