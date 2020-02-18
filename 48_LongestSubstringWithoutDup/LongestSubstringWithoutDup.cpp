// author:lijiwei
// date:2020/2/16
// 面试题48：最长不含重复字符的子字符串
// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
// 字符串的长度。假设字符串中只包含从'a'到'z'的字符。

#include <string>
#include <iostream>
#include <cstring>
#define nullptr 0

//返回最大长度 且给出起点nStart,终点nEnd
int longestSubstringWithoutDuplication_2(const std::string& str,int & nStart,int&  nEnd)
{
    int maxLength = 0;//最大长度
   
    int len = str.size();
    int *maxLen = new int[len];
    memset(maxLen,0,len*sizeof(int));

    int* position = new int[26];
    memset(position,-1,26*sizeof(int));

    nEnd = 0;

    for(int i = 0; i < len; ++i)
    {
        int prevIndex = position[str[i] - 'a'];//查找该字符有没有出现过
        if ( prevIndex == -1 )//之前没有出现过
        {
            if ( i==0 )//首个字符
            {
                maxLen[i] = 1;
            }           
            else
            {
                maxLen[i] = maxLen[i-1]+1;
            }
        }        
        else
        {
            int dist = i-prevIndex;//这次出现与上次出现的距离
            if ( dist > maxLen[i-1] )//距离比i-1结尾的最长无重复数组还长
            {
                maxLen[i] = maxLen[i-1]+1;
            }
            else
            {
                maxLen[i] = dist;
            }
        }

        if ( maxLen[i] > maxLength)
        {
            maxLength = maxLen[i];
            nEnd = i;
        }
      
        position[str[i] - 'a'] = i;
   }

    nStart = nEnd-maxLength+1;
    delete[] position;
    delete[] maxLen;
    return maxLength;
}


// 动态规划:原版
int longestSubstringWithoutDuplication_22(const std::string& str)
{
    int curLength = 0;//用于记录f(i)的长度
    int maxLength = 0;//最大长度

    int* position = new int[26];
    for(int i = 0; i < 26; ++i)
        position[i] = -1;

    for(int i = 0; i < str.length(); ++i)
    {
        int prevIndex = position[str[i] - 'a'];
        if(prevIndex < 0 || i - prevIndex > curLength)//如果之前没有出现过 或d>f(i-1)
            ++curLength;//f(i) = f(i-1)+1
        else//出现过且d<=f(i-1)
        {
            if(curLength > maxLength)//更新最大长度
                maxLength = curLength;

            curLength = i - prevIndex;//f(i) = d
        }
        position[str[i] - 'a'] = i;//更新位置
    }

    if(curLength > maxLength)
        maxLength = curLength;

    delete[] position;
    return maxLength;
}

// ====================测试代码====================

void testSolution2(const std::string& input, int expected)
{
    int nStart=0;
    int nEnd  =0;
    int output = longestSubstringWithoutDuplication_2(input,nStart,nEnd);
    std::cout << "INPUT:" << input << std::endl;
    std::cout << "expected:" << expected << ",Maxlen:" << output << ",begin:" << nStart << ",end:" << nEnd << std::endl; 
    if(output == expected)
        std::cout << "PASSED" << std::endl;
    else
        std::cout << "FAILED" <<std::endl;
    std::cout << std::endl;
}

void test(const std::string& input, int expected)
{
 //   testSolution1(input, expected);
    testSolution2(input, expected);
}

void test1()
{
    const std::string input = "abcacfrar";
    int expected = 4;
    test(input, expected);
}

void test2()
{
    const std::string input = "acfrarabc";
    int expected = 4;
    test(input, expected);
}

void test3()
{
    const std::string input = "arabcacfr";
    int expected = 4;
    test(input, expected);
}

void test4()
{
    const std::string input = "aaaa";
    int expected = 1;
    test(input, expected);
}

void test5()
{
    const std::string input = "abcdefg";
    int expected = 7;
    test(input, expected);
}

void test6()
{
    const std::string input = "aaabbbccc";
    int expected = 2;
    test(input, expected);
}

void test7()
{
    const std::string input = "abcdcba";
    int expected = 4;
    test(input, expected);
}

void test8()
{
    const std::string input = "abcdaef";
    int expected = 6;
    test(input, expected);
}

void test9()
{
    const std::string input = "a";
    int expected = 1;
    test(input, expected);
}

void test10()
{
    const std::string input = "";
    int expected = 0;
    test(input, expected);
}

int main(int argc, char* argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();
    test10();

    return 0;
}

