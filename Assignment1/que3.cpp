#include<stdio.h>

float celciousToFahrenheit(float c)
{
    return (c * (9.0/5.0)) +32;
}
float fahrenheitToCelcious(float f)
{
    return (f-32) * 5/9;
}

int main()
{
    float temp1 = 60;
    float temp = 40;

    float c = fahrenheitToCelcious(temp1);
    float f = celciousToFahrenheit(temp);
    printf("%.2f\n",c);
    printf("%.2f",f);
}