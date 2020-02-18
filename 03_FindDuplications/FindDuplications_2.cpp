//author:lijiwie
//date:2020/2/8
//// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
// 少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
// 数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
// 输出是重复的数字2或者3。

#include <iostream>
#include <vector>
using namespace std;

//返回array中元素值在[start,end]范围的个数
int countRange(const vector<int> array,int start, int end)
{
    int count = 0;
    for(int i=0; i<array.size(); ++i)
    {
        if ( array[i]>=start && array[i]<=end )
             count++;
    }

    return count;
}


// 返回值:             
//        正数  - 输入有效，并且数组中存在重复的数字，返回值为重复的数字
//        负数  - 输入无效，或者数组中没有重复的数字
int getDuplication(const vector<int> & ar )
{
    int len = ar.size();
   

    
    int start = 1;
    int end   = len-1;

    while ( start <= end )
    {
        int mid = (end+start)>>1;
        
        int count = countRange(ar,start,mid);


        if ( start == end )//结束
        {
            if ( count > 1 )
            {
                return start;
            } 
            else
            {
                break;
            }
        }

        if ( count > (mid-start+1)  )//[start,mid]存在重复
        {
            end = mid;
        }
        else
        {
            start=mid+1;
        }

        
    }    
    return -1;
}




int main()
{
    int len;
    vector<int> array;
    cout << "Please input array len:" << endl;
    cin >> len;


    cout << "Please input array member:" << endl;
    int num;
    for(int i=0; i<len; ++i)
    {
        cin >> num;
        array.push_back(num);
    }

    if ( getDuplication(array) != -1)
    {
        cout << "Exist:" << getDuplication(array) << endl;
    }
    else
        cout << "No exist" << endl;
}
