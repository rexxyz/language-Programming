#include <stdio.h>

int main()
{
    int year;
    printf("Enter a Year You Want Check It Is Leap Year Or Not\n");
    scanf("%d", &year);
    if (year % 400 == 0)
    {
        printf("%d is a Leap Year", year);
    }
    else if (year % 100 == 0)
    {
        printf("%d is Not a Leap Year", year);
    }
    else if (year % 4 == 0)
    {
        printf("%d is a Leap Year", year);
    }
    else
    {
        printf("%d is Not a Leap Year", year);
    }
    return 0;

    // Pull By khushbu078
}
