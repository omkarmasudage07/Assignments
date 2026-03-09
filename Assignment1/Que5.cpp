#include<iostream>
using namespace std;

void doubleIt(int &n)
{
    n = n*2;
    cout<<"inside of fun double it:"<<n <<endl;
}
int main()
{
    int n = 7;
    cout<<"before fun call:"<<n<<endl;
    doubleIt(n);

    cout<<"in main after call:"<<n;
}