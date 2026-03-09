#include<iostream>
using namespace std;

const float PI = 3.14159;
float circleArea(float radius)
{
    return PI * radius*radius;
}
float circlePerimeter(float radius)
{
    return 2* PI *radius;
}
int main()
{
    float radius = 7.0;
    float area = circleArea(radius);
    cout<<"Area of circle :" << area<<endl;
    float perimeter = circlePerimeter(radius);
    cout<<"Perimeter of circle :" << perimeter<<endl;
}