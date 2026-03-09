#include<iostream>
using namespace std;


void swapByValue(int a , int b)
{
    int temp = a;
    a = b ;
    b = temp;
}
void swapByAddress(int *a, int *b)
{
    int temp = *a;
    *a = *b ;
    *b = temp;
} 


void swapByReference(int &a, int &b)
{
    int temp = a;
    a = b ;
    b = temp;
}
int main()
{
    int a = 10;
    int b = 20;
     cout<<a<<" "<<b<<endl;
    swapByValue(a,b);
    cout<<a<<" "<<b<<endl;
    swapByAddress(&a, &b);
     cout<<a<<" "<<b<<endl;

    a = 10;
    b = 20;
    swapByReference(a,b);
     cout<<a<<" "<<b<<endl;

}