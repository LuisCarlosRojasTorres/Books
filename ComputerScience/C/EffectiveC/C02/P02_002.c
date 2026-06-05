#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
    int a = 3;
    char char_example = 'A';

    printf("main: a= %d, char= %d\n",a,char_example);
    printf("main: a= %X, char= 0x%x\n",a,char_example);
     printf("main: a= %X, char= %c\n",a,char_example);
   
    return EXIT_SUCCESS;
}