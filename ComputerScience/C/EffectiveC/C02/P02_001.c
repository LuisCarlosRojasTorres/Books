#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void swap_by_value(int, int);
void swap_by_reference(int *pa, int *pb);

int main()
{
    int a = 3;
    int b = 4;

    printf("main: a= %d, b= %d\n",a,b);

    swap_by_value(a,b);

    printf("main: a= %d, b= %d\n",a,b);

    swap_by_reference(&a,&b);

    printf("main: a= %d, b= %d\n",a,b);
    return EXIT_SUCCESS;
}

void swap_by_value(int a, int b){
    int t = a;
    a = b;
    b = t;
    printf("swap by value: a= %d, b= %d\n",a,b);
}

void swap_by_reference(int *pa, int *pb){
    int t = *pa;
    *pa = *pb;
    *pb = t;
    printf("swap by reference: a= %d, b= %d\n",*pa,*pb);
}