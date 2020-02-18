//author:lijiwei
//date:2020/2/10


#include<iostream>
#include<vector>

using namespace std;

int max(int a,int b)
{
    return (a>=b)?a:b;
}
int CuttingRope(int len)
{
    if ( len < 2 )
    {
        return 0;
    }
    else if ( len == 2 )
    {
        return 1;
    }
    else if ( len == 3 )
    {
        return 2;
    }
    
    vector<int> v(len+1,1);//初始化乘积最大值为1

    v[0] = 0;
    v[1] = 1;
    v[2] = 2;
    v[3] = 3;
 
    for(int i=4; i<=len; ++i)
    {
        for(int j=1; j<=i/2;++j)
        {
            v[i] = max(v[i-j] * v[j],v[i] );
        }
    }
    
    return v[len];
}

int main()
{
    for(int i=0; i<10;i++)
    {
        cout << "len:" << i << ",MaxValue:" << CuttingRope(i) << endl;
    }
    return 0;
}
