//author:lijiwei
//date:2020/2/7
//题目：输入一个表示整数的字符串，把该字符串转换成整数并输出
//需要考虑的问题：
//1 输入的形参为空指针
//2 起始位置非法 如 abc123
//3 正数与负数
//4 整数范围过大
//5 非法输入:123abc

#include<iostream>
#include<limits>
#include<string>

using namespace std;


int StrToInt(char * str)
{
    bool IsPoNu=true;
    int num=0;

    if ( str == NULL )//空指针
    {
        return 0;
    }
    else if ( (*str) == '+'   )//正数
    {
        IsPoNu=true;
        str++;
    }
    else if ( (*str) == '-'  )  //负数
    {
        IsPoNu=false;
        str++;
    }
    else if ((*str)<'0' || (*str)>'9' )//非数字
    {
        return 0;
    }
    

   //处理字符串
    while( (*str) != '\0' )
    {
       
        if ((*str)<'0' || (*str)>'9' )
        {
            return 0;
        }
        else 
        {
            if ( IsPoNu )  //正数且没有溢出
            {
                if ( (num*10+(*str)-'0')<=std::numeric_limits<int>::max()  )
                {
                     num = num*10+(*str)-'0';
                }
                else
                {
                    return 0;
                }
            }
            else//负数
            {
                if( (-(num*10+(*str)-'0') ) >=std::numeric_limits<int>::min()  )//没有溢出
                {   
                     num = num*10+(*str)-'0';
                }
                else
                {
                    return 0;
                }

            }
       }
       str++;      
   }

   
   return IsPoNu ? num : -num;    
   
}


int main()
{
    std::string str;
    std::cin >> str;
    
    int num = StrToInt(const_cast<char*>(str.c_str()));

    std::cout << num << std::endl;

    return 0;

}
