//author:lijiwei
//date:2020/2/9
// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。



#include <iostream>
#include <vector>

using namespace std;

bool Find(const vector<vector<int> > &array,int num)
{
    int row = array.size();
    int col;
    if ( row > 0 )//非空二维数组
    {
        col = array[0].size();
    }
    
    int rowPos = 0;//查找开始的位置:右上角,即第一行,最后一列
    int colPos = col-1;

    while( rowPos<=(row-1) && colPos>=0 )
    {
        if ( num == array[rowPos][colPos] )//该位置的元素与查找的元素相等
        {
            return true;
        }
        else if ( num < array[rowPos][colPos] )//查找的元素小于位置的元素
        {
            colPos--;
        }
        else //查找的元素大于位置的元素
        {
            rowPos++;
        }
    }
    
    return false;
}

int main()
{
    int row,col;//数组的行与列
    cout << "Please input array row:" << endl;
    cin >> row;
    cout << "Please input array col:" << endl;
    cin >> col;


    vector<vector<int> > array;
    int num;
    cout << "Please input array number:" << endl;
    for(int i=0; i<row; ++i)
    {   
        vector<int>  rowArray;//存储每一行的元素
        for(int j=0; j<col; ++j)
        {
            cin >> num;
            rowArray.push_back(num);
        }
        array.push_back(rowArray);
    }

    cout << "Please input find number:" << endl;
    cin >> num;
    
    if ( Find(array,num) )
    {
        cout << "success find" << endl;
    }
    else
    {
        cout << "No exist" << endl;
    }
    return 0;
}
