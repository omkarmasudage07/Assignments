#include<stdio.h>

int main()
{
    int n = 10; //4
    short int s = 1; //2
    long int l = 45;//4
    unsigned int u = 2; //4
    float f = 1.2; //4
    double d = 44;  //8
    long double ld = 44; //12
    char c = 'a';  //1

    printf("int = %d\n" ,sizeof(n));
    printf("short int = %d\n",sizeof(s));
    printf("lond int = %d\n" , sizeof(l));
    printf("unsigned int +%d\n",sizeof(u));
    printf("float = %d\n",sizeof(f));
    printf("double = %d\n", sizeof(d));
    printf("long double = %d\n", sizeof(ld));
    printf("char = %d",sizeof(c));

}