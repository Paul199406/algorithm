//author:lijiwei
//date:2020/2/10
// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

#include <iostream>
#include <vector>

using namespace std;

//顺序
int MinInOrder(const vector<int> &v)
{
    int result = v[0];
    int pos    = 0;
    for(int i=0; i<v.size(); ++i)
    {
        if ( v[i] < result )
        {
            result = v[i];
            pos = i;
        }
    }

    return pos;
}
//二分法
int Min(const vector<int> &v)
{
    int index1=0;
    int index2=v.size()-1;

    int indexMid=index1;//防止为递增数组

    while ( v[index1] >= v[index2] )
    {
        if ( (index1+1) == index2 )//两个指针相邻,结束
        {
            indexMid = index2;//因为index2的值最小
            break;
        }
        
        indexMid = (index1+index2)/2;

        if ( (v[index1]==v[indexMid]) && (v[index1]==v[index2]) 
           &&(v[indexMid]==v[index2]) ) //防止三者相等,二分失效
        {
            indexMid = MinInOrder(v);
            break;  
        }
       
        if ( v[index1] >= v[indexMid]  ) //中间指针和index之间为递增
        {
            index2 = indexMid;
        }
        else
        {
            index1 = indexMid;
        }
    }
    return v[indexMid];
}


void Display(const vector<int> &v)
{
    cout << "vector:" ;
    for(int i=0; i<v.size(); ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int a1[]={3,5,6,0,1,2};
    vector<int>  v1(a1,a1+6);

    int a2[]={1,0,1,1,1,1};
    vector<int>  v2(a2,a2+6);

    int a3[]={0,1,2,3,4,5};
    vector<int>  v3(a3,a3+6);
   
    Display(v1);
    cout << "Min:" << Min(v1) << endl;

    Display(v2);
    cout << "Min:" << Min(v2) << endl;

    Display(v3);
    cout << "Min:" << Min(v3) << endl;



    return 0;
}

