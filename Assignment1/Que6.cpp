#include<iostream>
using namespace std;

int main()
{
    int x = 10;
    int y = 20;
    int z = 30;

    int *px = &x;
    int *py = &y;
    int *pz = &z;
    cout<<"before swapping :"<<x<<" "<<y <<" "<<z<<endl;
    cout<<"before swapping add :"<<px<<" "<<py <<" "<<pz<<endl;
    int temp = *px;
    *px = *pz;
    *pz = temp;

    cout<<"After swapping :"<<x<<" "<<y <<" "<<z<<endl;
    cout<<"After swapping add :"<<px<<" "<<py <<" "<<pz<<endl;
    cout<<sizeof(py);
}