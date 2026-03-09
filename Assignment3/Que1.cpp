#include<iostream>
using namespace std;

class Box{
    int length;
    int width;
    int height;

    public:
    Box(int length , int width , int height)
    {
        this->length = length;
        this->width = width;
        this->height = height;
    }
    void setDimension(int len , int wid,int hi)
    {
        length = len;
        width = wid;
        height = hi;
    }
    void volume()
    {
        int vol = length*width*height;
        cout<<"Volume is:"<<vol<<endl;
    }
};
int main()
{
    Box b(10,20,30);
    b.setDimension(1,2,3);
    b.volume();
}