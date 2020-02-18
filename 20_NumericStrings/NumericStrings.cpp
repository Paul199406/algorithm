//author:lijiwei
//date:2020/2/11
// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
// 字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
// “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

#include <cstdio>
#define nullptr 0

bool scanUnsignedInteger(const char*& str);
bool scanInteger(const char*& str);

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数
bool isNumeric(const char* str)
{
    if ( str == NULL )
    {
        return false;
    }

    bool bIsNum = false;
    bIsNum = scanInteger(str);
    
    if ( (*str)=='.'  )//如果整数部分后面是 .
    {
        str++;
         
        bIsNum = scanUnsignedInteger(str)||bIsNum;//只有正数部分,只有小数部分或都有均可 注意 函数要放前面,否则一旦bIsNum=true在先成立函数就不会执行
    }
    
    if ( (*str)=='e' || (*str)=='E' )
    {
        str++;
        bIsNum = bIsNum && scanInteger(str);//只有之前成立,且指数部分也成立
    }     
    
    return bIsNum && ((*str)=='\0');//如果是 且字符串结束
    
}


bool scanUnsignedInteger(const char*& str)
{
    const char * strBefore=str;//str记录str最初的地址

    //字符串没有结束且 '0'-'9'
    while( ((*str)!='\0') && ((*str)>='0')&&(*str)<='9' )
    {
        str++;
    }
    
    return str > strBefore;//如果遍历到数字,str向后以后,地址会变大
}
bool scanInteger(const char*& str)
{
    if ((*str)=='-'||(*str)=='+'  )
    {
        str++;
    }
    
    return scanUnsignedInteger(str);
    
}

// ====================测试代码====================
void Test(const char* testName, const char* str, bool expected)
{
    if(testName != nullptr)
        printf("%s begins: ", testName);

    if(isNumeric(str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}


int main(int argc, char* argv[])
{
    Test("Test1", "100", true);
    Test("Test2", "123.45e+6", true);
    Test("Test3", "+500", true);
    Test("Test4", "5e2", true);
    Test("Test5", "3.1416", true);
    Test("Test6", "600.", true);
    Test("Test7", "-.123", true);
    Test("Test8", "-1E-16", true);
    Test("Test9", "1.79769313486232E+308", true);

    printf("\n\n");

    Test("Test10", "12e", false);
    Test("Test11", "1a3.14", false);
    Test("Test12", "1+23", false);
    Test("Test13", "1.2.3", false);
    Test("Test14", "+-5", false);
    Test("Test15", "12e+5.4", false);
    Test("Test16", ".", false);
    Test("Test17", ".e1", false);
    Test("Test18", "e1", false);
    Test("Test19", "+.", false);
    Test("Test20", "", false);
    Test("Test21", nullptr, false);

    return 0;
}
