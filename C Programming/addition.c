#include <stdio.h>
int main() 
{    

    int num1, num2, sum;
    
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    // calculating sum
    sum = num1 + num2;      
    
    printf("%d + %d = %d", num1, num2, sum);
    return 0;
}
