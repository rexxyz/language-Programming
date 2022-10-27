#include <stdio.h>
int fibrecur(int);
int n3 = 0, i = 0;
int n1 = 0, n2 = 1;
int main()
{
     int number;
     printf("Enter The Number of Elements\n");
     scanf("%d", &number);
     printf("\n%d %d ",n1,n2);
     fibiter(number);
     return 0;
     // pull by khushbu078
}
int fibiter(int number)
{
     for (int i = 2; i < number; i++)
     {
          n3 = n1 + n2;
          printf("%d ",n3);
          n1 = n2;
          n2 = n3;
     }
}
