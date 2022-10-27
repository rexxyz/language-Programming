#include <stdio.h>

 int main()
{
     int chemistry , physics , maths , english , computers;
     float total;

    printf("Enter Your Chemistry Marks\n");
    scanf("%d", &chemistry);
    printf("Enter Your Phyics Marks\n");
    scanf("%d", &physics);
    printf("Enter Your Maths Marks\n");
    scanf("%d", &maths);
    printf("Enter Your English Marks\n");
    scanf("%d", &english);
    printf("Enter Your Computers Marks\n");
    scanf("%d", &computers);

    total = ((chemistry + physics + maths + english + computers)/500.0)* 100;
    printf("Your Percentage is : \n");
    printf("%.4f" , total);
    return 0;
   // pull by khushbu078
}
