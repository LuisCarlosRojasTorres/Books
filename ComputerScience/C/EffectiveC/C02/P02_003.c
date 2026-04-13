#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main()
{
    enum day {
        SUN, MON, TUE, WED, THU, FRI, SAT
    };

    enum day today = SUN;

    printf("Day: %d\n", today);
    return EXIT_SUCCESS;
}