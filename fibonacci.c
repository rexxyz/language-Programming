#include<stdio.h>
#include<math.h>
int fib();
int main()
{
 printf("%d \n",fib(6));
 return 0;
}
int fib(int n)
{   if(n==0)
    return 0;
    else if(n==1)
    return 1;
    int Fib = fib(n-2)+fib(n-1);
    return Fib;
}
