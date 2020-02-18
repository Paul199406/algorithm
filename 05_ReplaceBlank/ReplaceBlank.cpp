//author:lijiwei
//date:2020/2/9
//// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include <iostream>
#include <string>

using namespace std;


/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
void ReplaceBlank(char str[], int length)
{
    if ( str==NULL || length<=0 )
    {
        return;
    }

    int blankCount=0;//空格数量
    int strOrignEnd=0;//原字符串的最后一个字符位置
    int strNewEnd=0;//替换后的字符串的最后一个字符的位置
    
    int i=0;
    while ( str[i] != '\0' )//结束符
    {
        if ( str[i] == ' ' )//空格符
        {
            blankCount++;
        }
        
        strOrignEnd++;
        i++;
    }
   
    strNewEnd = strOrignEnd + blankCount*2;
    
    while( strNewEnd>=0 && (strNewEnd>=strOrignEnd ) )
    {
        if ( str[strOrignEnd] == ' ')
        {
            str[strNewEnd--] = '0';
            str[strNewEnd--] = '2';
            str[strNewEnd--] = '%';
            strOrignEnd--;
        }
        else
        {
            str[strNewEnd--] = str[strOrignEnd--];
        }
       
    }
}


int main()
{
    char s[100];
    cout << "Please input str:" << endl;
   
    cin.get(s,100);
    
    ReplaceBlank(s,100);
    string str(s);
    cout << "ReplaceBlank:" << str << endl;
 //   cout << str.size() << endl;

    
    
    return 0;
}


