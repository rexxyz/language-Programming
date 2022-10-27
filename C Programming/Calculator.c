#include <stdio.h>

int main()
{
    int a , b, result;
    char operator;
    printf("Enter The Operator\n");
    scanf("%c", &operator);
    printf("Enter The Value of a\n");
    scanf("%d", &a);
    printf("Enter The Value of b\n");
    scanf("%d", &b);
    switch (operator)
    {
    case '+':
            result = a + b;
            printf("%d", result);
            break;

    case '-':
           result = a - b;
           printf("%d", result);
           break;

    case '*':
          printf("%d", a * b); 
          break;

     case '/':
          printf("%d", a/b) ;       
          break;       
    
    default:
    printf("Enter The Correct Operator");
        break;
    }
}
