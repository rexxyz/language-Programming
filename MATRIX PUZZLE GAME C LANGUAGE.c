#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void rules_of_games();
int main()
{
int a[4][4],maxtry=500;
char name[20],u;
printf("Enter your name: ");
fgets(name,20,stdin);
name[strlen(name)-1]='\0';
system("cls");
while(1)
{
    rules_of_games();
    system("cls");
    creatematrix(a);

    while(!win(a))
   {
       system("cls");
    if(!maxtry)
    break;
    printf("\n\nHello %s,           Moves Remaining : %d\n\n",name,maxtry);
    showmatrix(a);
        int c=readenteredkey();

        switch(c)
        {
            case 101:

            case 69:
            printf("\n\n\n\n                                  Thanks for playing!      \n ");
            printf(" \n                                  Hit Enter Key to exit the Game \n");
            getch();
            return 0;

            case 72:
            if(shiftUp(a))
            maxtry--;
            break;

            case 80:
             if(shiftdown(a))
              maxtry--;
             break;

            case 77:
                if(shiftRight(a))
                 maxtry--;
                break;


            case 75:
                if(shiftLeft(a))
                maxtry--;
                break;

                default:
                printf("invalid key");

        }



    }
     if(!maxtry)
        {
            printf("                              You lose\n\n\n\ ");

        }
        else
            printf("\n\n\n                    ********** congratulations %s for winning this game **********                   \n\n\n\n\n",name);
         printf("\n\n\n                       press key y to play again\n\n");
         scanf("%c",&u);
         if(u=='y'||u=='Y')
         {maxtry=500;
         continue;
         }
         else
         break;

    }




return 0;
}
void rules_of_games()
{
    printf("                                           MATRIX PUZZLE \n\n\n");
    printf("                                           RULE OF THIS GAME \n\n");
    printf("1. You can move only 1 step at a time with the arrow key.\n");
    printf("           Move Up    : by Up arrow key\n");
    printf("           Move Down  : by Down arrow key\n");
    printf("           Move Left  : by Left arrow key\n");
    printf("           Move Right : by Right arrow key\n");
    printf("2. You can move numbers at an empty position only.\n");
    printf("3. For each valid move : your total number of moves will decrease by 1.\n");
    printf("4. Winning Situation : Number in a 4*4 matrix should be in order from 1 to 15\n\n\n");
    printf("           Winning situation:\n");
    printf("-------------------------\n");
    printf("|  1  |  2  |  3  |  4  |\n");
    printf("|  5  |  6  |  7  |  8  |\n");
    printf("|  9  |  10 |  11 |  12 |\n");
    printf("| 13  |  14 |  15 |     |\n");
    printf("-------------------------\n\n");
    printf("5. you can exit the game at any time by pressing the key 'E' or 'e'\n");
    printf("so try to win in minimum number of moves\n\n\n");
    printf("                          HAPPY GAMING , GOOD LUCK \n");
    printf("press any key to continue");
    readenteredkey();
    system("cls");


}
void creatematrix(int a[][4])
{
    int n=15;
    int arr[n],i,j;
    for(i=0;i<15;i++)
        arr[i]=i+1;


    srand(time(NULL));

    int lastindex=n-1,index;

      for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(lastindex>=0)
            {
              index =  rand()%  (lastindex + 1);
               a[i][j]=arr[index];
                arr[index]= arr[lastindex--];
            }
        }
    }
    a[i-1][j-1]=0;


}
void showmatrix(int a[][4])
{

    int i,j;
    printf("---------------------\n");
    for(i=0;i<4;i++)
    {
        printf("|");
        for(j=0;j<4;j++)
        {
            if(a[i][j]!=0)
            printf(" %2d |",a[i][j]);
            else
            printf("    |");
        }
        printf("\n");
    }
    printf("---------------------\n");
}
int win(int a[][4])


{
    int i, j, k = 1;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++, k++)
            if (a[i][j] != k && k != 16)
                break;
        if (j < 4)
            break;
    }

    if (j < 4)
        return 0;
    return 1;
}



int readenteredkey()
{
    char c;
    c = getch();
    if (c == -32)
        c = getch();

    return c;

}
int shiftUp(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (i == 3)
        return 0;


    swap(&arr[i][j], &arr[i + 1][j]);
    return 1;
}
int shiftdown(int arr[][4])
{
    int i,j;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(arr[i][j]==0)
            break;
        }
        if(j<4)
        break;
    }
    if(i==0)
    return 0;
    swap(&arr[i][j], &arr[i - 1][j]);
    return 1;

}

void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
    printf("");
}
int shiftRight(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (j == 0)
    return 0;

    swap(&arr[i][j], &arr[i][j - 1]);
    return 1;
}
int shiftLeft(int arr[][4])
{
    int i, j;
    for (i = 0; i < 4; i++)
    {
        for (j = 0; j < 4; j++)
            if (arr[i][j] == 0)
                break;
        if (j < 4)
            break;
    }
    if (j == 3)
    return 0;

    swap(&arr[i][j], &arr[i][j + 1]);
    return 1;
}
