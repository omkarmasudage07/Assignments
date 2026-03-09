#include<iostream>
using namespace std;

int main()
{
    int *arr = (int*) malloc(5*sizeof(int));
    for(int i = 0 ; i< 5 ;i++)
    {
      cin>>arr[i];
    }

    for(int i = 0 ; i < 5 ; i++)
    {
        cout<<arr[i]<<" ";
    }

    free(arr);
}