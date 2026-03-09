#include<iostream>
using namespace std;

int main()
{
    int n = 200;

    int *ptr = &n;
    int &ref = n;

    cout<<n<<endl;
    *ptr = 100;
    cout<<n<<endl;

    ref = 500;
    cout<<n<<endl;
}