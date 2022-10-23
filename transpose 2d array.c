//program to transpose a 2d array
#include<stdio.h>
int main(){
    int i, j, m, n, a[10][10], b[10][10];
    printf("enter the number of rows and columns:");
    scanf("%d%d", &m, &n);
    printf("enter the elements of matrix a");
    for(i=0,i<m,i++){
        for (j = 0, j < n;j++){
            scanf("%d", &a[i][j]);
            
        }
    }
    for (i = 0, i < n; i++){
        for (j = 0, j < m; j++){
            b[j][i] = a[i][j];
        }
    }
    printf("the transpose of matrix a is:\n");
    for (i = 0, i < n; i++){
        for (j = 0, j < m; j++){
            printf("%d\t", b[i][j]);
        }
        printf("\n");
          //pull by GUDSKULL
    }
}
   
