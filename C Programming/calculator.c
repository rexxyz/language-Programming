# include<stdio.h>
# include<math.h>
int main()
{
int a,b,c;
printf("Enter the value of a and b :\n");
scanf("%d %d",&a,&b);

printf("Enter : \n 1 - Addition \n 2 - Subtraction \n 3-Multiplication \n 4-Division\n 5-Power 6-Exit\n\n"); 
scanf("%d",&c);
while(c==1 || c==2 || c==3 || c==4 || c==5 ||c==6)
{
    if(c==1)
    {
        printf("Addition is %d\n\n",a+b);
        printf("Enter : \n 1 - Addition \n 2 - Subtraction \n 3-Multiplication \n 4-Division\n 5-Power 6-Exit\n\n"); 
        scanf("%d",&c);
    }

    if(c==2)
    {
        printf("Subtraction is %d\n\n",a-b);
        printf("Enter : \n 1 - Addition \n 2 - Subtraction \n 3-Multiplication \n 4-Division\n 5-Power 6-Exit\n\n"); 
        scanf("%d",&c);
    }

    if(c==3)
    {
        printf("Multiplication is %d\n\n",a*b);
        printf("Enter : \n 1 - Addition \n 2 - Subtraction \n 3-Multiplication \n 4-Division\n 5-Power 6-Exit\n\n"); 
        scanf("%d",&c);
    }

    if(c==4)
    {
        printf("Division is %d\n\n",a/(b));
        printf("Enter : \n 1 - Addition \n 2 - Subtraction \n 3-Multiplication \n 4-Division\n 5-Power 6-Exit\n\n"); 
        scanf("%d",&c);
    }

    if(c==5)
    {
        printf("Power of a over b is %f\n\n",pow(a,b));
        printf("Enter : \n 1 - Addition \n 2 - Subtraction \n 3-Multiplication \n 4-Division\n 5-Power 6-Exit\n\n"); 
        scanf("%d",&c);
    }

    if(c==6) //exit
    {
        break;
    }
}

return 0;
}
