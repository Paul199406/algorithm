//author:lijiwei
//date:2020/2/8
//title:面试题3（一）：找出数组中重复的数字
//题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

#include<iostream>
#include<vector>

using namespace std;


//数组不合法 返回false
//数组合法  成功找到 返回true,dup中为重复元素,没有重复元素,dup为-1
bool duplication(vector<int> &ar,int &dup)
{
    int len = ar.size();
    dup = -1;//默认没有重复

    for (int i=0; i<len; ++i)
    {
        if ( ar[i]<0 || ar[i] >= len  )//所有数字必须在0-len-1之间
        {
            return false;//不合法的数组
        }
    }

    for(int i=0; i<len; ++i)
    {
        while( ar[i] != i  )//该位置的元素值与下标不相等
        {
            if ( ar[i] == ar[ar[i]]    )//该位置的元素值与下标为a[i]的数组元素值相同
           {
               dup = ar[i];
               return true;
           }
           else //不同则交换
           {
               int tmp = ar[i];
               ar[i] = ar[ar[i]];
               ar[tmp] = tmp;
           }
        }
    }
    return true;
}
int main()
{
    int len;//数组长度
    vector<int>  array;//数组名称

    cout << "Please input array len:" << endl;
    cin >> len;
   
    cout << "Please input array  every number :" << endl;
    for(int i=0; i<len; ++i)
    {
        int num;
        cin >> num;
        array.push_back(num);
    }

    int dup;//存储其中的一个重复数字
    if ( duplication(array,dup)   )
    { 
        if ( dup != -1  )
            cout << "Find Duplications:" << dup << endl;
        else
            cout << "no exist" << endl;
    }
    else
    {
        cout <<"illegal array" << endl;
    }
    
    return 0;
    
}
