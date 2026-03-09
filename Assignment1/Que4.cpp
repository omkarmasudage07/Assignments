#include<iostream>
using namespace std;
void findMinMax(int a, int b , int c , int &lo , int &hi);
int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    int lo;
    int hi;

    findMinMax(a,b,c,lo,hi);
    // printf("%d\n",hi);
    // printf("%d",lo);

    cout<<"higest"<<hi<<endl;
    cout<<"lowest"<<lo;
}
void findMinMax(int a, int b , int c , int &lo , int &hi){
    hi= a>b ? ((a>c)? a:c) :((b>c)?b:c);
    lo = a<b ? ((a<c)?a:c) : ((b<c)?b:c);
}