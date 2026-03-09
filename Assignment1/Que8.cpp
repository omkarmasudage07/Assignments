#include<iostream>
using namespace std;

 
int absolute(int n)
{
    n = n >= 0 ? n : n*(-1);
    return n;
}
int clamp(int val, int lo, int hi)
{
    val = lo > val ? lo : val;
    val = val > hi ?hi : val;

    return val;
}
int main()
{
    int n  = -10;
    cout<<"n=:"<<n<<endl;
    int abs_n = absolute(n);
    cout<<"absolute n :"<<abs_n<<endl;

    int val = -15;
    int lo = -10;
    int hi  = 10;

    val = clamp(val,lo,hi);
    cout<<val;
}