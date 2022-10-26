#include<stdio.h>

// Checking if a number is Armstrong or not

int main()
{
    int n, sum = 0, temp, rem;
    printf("Enter any 3-digits number: ");
    scanf("%d", &n);
    temp = n;

    while(n > 0)
    {
        rem = n % 10;
        sum = sum + rem * rem * rem;
        n = n / 10;
    }

    if(temp == sum) {
        printf("The number %d is an Armstrong number!", temp);
    }
    else {
        printf("The number %d is not an Armstrong number!", temp);
    } 

    return 0;
}
