//C++ IMPLIMENTATION  CHECK IF GIVEN MATRIX IS SPARSE OR NOT AND PRINT IN COMPRESSED FORMAT.
#include<stdio.h>
#include<stdlib.h>

int main(){
    int n=1;
    printf("Enter a matrix to be checked:");
    printf("Enter the size for the square matrix in single digit:");
    scanf("%d",&n);
    //int **inp_arr = (int **)(malloc(n*n*sizeof(int))); //dynamic allocation of the array memory using malloc()
    int inp_arr[n][n];
    int zero_elm=0;
    printf("Enter matrix details: \n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the matrix data for position: %d %d :",i,j,"\n");
            scanf("%d",&inp_arr[i][j]);
            if(inp_arr[i][j]==0){
                zero_elm++;
            }
        }
    }

    if(zero_elm>(n*n/2)){ //Check if given matrix data is sparse of nor!
        printf("The given matrix data forms a sparse matrix !!");
        printf("Now printing the sparse matrix in compressed form: \n"); //Printing sparse matrix in compressed form!
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(inp_arr[i][j]!=0)
                {
                    printf("%d %d %d \n",i,j,inp_arr[i][j]);
                }
            }
        }
    }

    else{
        printf("The given matrix data does not form a sparse matrix !!");
        return 0;
    }


    return 0;
}
