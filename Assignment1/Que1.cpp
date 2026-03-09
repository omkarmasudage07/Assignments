#include<stdio.h>

int main(){
    float m1 = 50;
    float m2 = 50;
    float m3 = 50;
    float m4 = 50;
    float m5 = 50;

    float total = m1+m2+m3+m4+m5;

    float percentage = (total/500)*100;
    printf("%f\n%f\n%f\n%f\n%f\n",m1,m2,m3,m4,m5);
    printf("Total marks : %f \n" , total);
    printf("Total percentage : %f \n" , percentage);
    printf(percentage>= 75 ? "A" : percentage >= 60 ? "B" : percentage >= 45 ? "C" : "fail");
}