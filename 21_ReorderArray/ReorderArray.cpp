//author:lijiwei
//date:2020/2/12
// 面试题21：调整数组顺序使奇数位于偶数前面
// 题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有
// 奇数位于数组的前半部分，所有偶数位于数组的后半部分。


#include <iostream>
#include <vector>

using namespace std;

void ReorderArray(vector<int> &array)
{
    int len = array.size();

    if ( len<=1)
        return;

    int index1 = 0;
    int index2 = len-1;
    
    while(index1<index2)
    {
        while ( (index1<len) && ((array[index1]&0x01)==1) )//是奇数
        {
            index1++;
        }
        
        while ( (index2>=0) && ((array[index2]&0x01)!=1) )//偶数
        {
            index2--;
        }
   
         
        if ( index1 < index2 )
        {
            int tmp = array[index1];
            array[index1] = array[index2];
            array[index2] = tmp;
        }
    }
 
}

void DisplayArray(const vector<int>  v)
{
    int len= v.size();
    for(int i=0; i<len; ++i)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}
int main()
{
    int numbers1[] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> v1(numbers1,numbers1+7);
    DisplayArray(v1);
    cout << "After Reorder:" ;
    ReorderArray(v1);
    DisplayArray(v1);
    
    int numbers2[] = {2, 4, 6, 1, 3, 5, 7};
    vector<int> v2(numbers2,numbers2+7);
    DisplayArray(v2);
    cout << "After Reorder:" ;
    ReorderArray(v2);
    DisplayArray(v2);

    int numbers3[] = {1, 3, 5, 7, 2, 4, 6};
    vector<int> v3(numbers3,numbers3+7);
    DisplayArray(v3);
    cout << "After Reorder:" ;
    ReorderArray(v3);
    DisplayArray(v3);

    int numbers4[] = {1};
    vector<int> v4(numbers4,numbers4+1);
    DisplayArray(v4);
    cout << "After Reorder:" ;
    ReorderArray(v4);
    DisplayArray(v4);

    int numbers5[] = {2};
    vector<int> v5(numbers5,numbers5+1);
    DisplayArray(v5);
    cout << "After Reorder:" ;
    ReorderArray(v5);
    DisplayArray(v5);

    int numbers6[] = {};
    vector<int> v6(numbers6,numbers6);
    DisplayArray(v6);
    cout << "After Reorder:" ;
    ReorderArray(v6);
    DisplayArray(v6);


    return 0;
}

