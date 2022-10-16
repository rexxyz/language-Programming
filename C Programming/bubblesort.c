#include <stdio.h>

int main(){

    int arr[50], num, x, y, temp;    

    printf("Please Enter the Number of Elements you want in the array: ");

    scanf("%d", &num);    

    printf("Please Enter the Value of Elements: ");

    for(i = 0; i < num; i++)

        scanf("%d", &arr[i]);

    for(i = 0; i < num - 1; i++){       

        for(y = 0; y < num - i - 1; y++){          

            if(arr[y] > arr[y + 1]){               

                temp = arr[y];

                arr[y] = arr[y + 1];

                arr[y + 1] = temp;

            }

        }

    }

    printf("After implementing bubble sort: ");

    for(i = 0; i < num; i++){

        printf("%d  ", arr[i]);

    }

    return 0;

}
