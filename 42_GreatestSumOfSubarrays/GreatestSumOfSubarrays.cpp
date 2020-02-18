//author:lijiwei
//date:2020/2/15
// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
// 数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。

#include <cstdio>
#define nullptr 0
bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
    if((pData == nullptr) || (nLength <= 0))
    {
        g_InvalidInput = true;
        return 0;
    }

    g_InvalidInput = false;

    int nCurSum = 0;
    int nGreatestSum = 0x80000000;//即-1
    for(int i = 0; i < nLength; ++i)
    {
        if(nCurSum <= 0)
            nCurSum = pData[i];
        else
            nCurSum += pData[i];

        if(nCurSum > nGreatestSum)
            nGreatestSum = nCurSum;
    }

    return nGreatestSum;
} 

//返回最大子数组值,且给出起始位置和结束位置 nBegin nEnd
int FindGreatestSumOfSubArray(int *pData, int nLength,int & nBegin,int & nEnd)
{
    if((pData == nullptr) || (nLength <= 0))
    {
        g_InvalidInput = true;
        return 0;
    }

    if ( nLength == 1)
        return pData[0];

    g_InvalidInput = false;

    int nCurSum = pData[0];
    int nGreatestSum = pData[0];

    nBegin = 0;//记录最大子数组的起始位置（在数组中的下标）
    nEnd = 0;
    
    int nTmp=0;//每次的新起点
    for(int i = 1; i < nLength; ++i)
    {
        if(nCurSum <= 0)
        {
            nCurSum = pData[i];
            nTmp  = i;//记录新的起始位置
        }
        else
        {
            nCurSum += pData[i];
        }
        if(nCurSum > nGreatestSum)
        {
            nGreatestSum = nCurSum;
            nBegin = nTmp;
            nEnd = i;//记录最大值结束位置
       }
    }

    return nGreatestSum;
} 


// ====================测试代码====================
void Test(char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    int nBegin=0;
    int nEnd  =0;
    int result = FindGreatestSumOfSubArray(pData, nLength,nBegin,nEnd);

    printf("array:");
    for(int i=0; i<nLength; ++i)
    {
        printf("%d\t",pData[i]);
    }
    printf("\n");
    
    printf("MaxSubSum:%d,begin:%d,end:%d\n",result,nBegin,nEnd);

    if(result == expected && expectedFlag == g_InvalidInput)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// 所有数字都是负数
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// 所有数字都是正数
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// 无效输入
void Test4()
{
    Test("Test4", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}


