//C Program to merge two sorted arrays
#include <stdio.h>
int main()
{
  //declaring variables
    int i,n,j,k,arr1[n],arr2[k];
  //Taking input for 1st array
    printf("Enter the size of the first array:\n");
    scanf("%d",&n);
    printf("Enter the elements of the first array:\n");
    for (i=0;i<n;i++)
    {
        scanf("%d",&arr1[i]);
    }
  //Taking input for 2nd array
    printf("Enter the size of the second array: ");
    scanf("%d", &k);
    printf("Enter the elements of the second array: \n");
    for (j=0;j<k;j++)
    {
        scanf("%d",&arr2[j]);
    }
  //For merging 1st and 2nd array
    int arr3[n+k];
    i=0;
    j=0;
    int z;
    for (z=0;z<n+k;z++)
    {
        if (i<n&&j< k)
        {
            if (arr1[i]<arr2[j])
            {
                arr3[z]=arr1[i];
                i++;
            }
            else
            {
                arr3[z]=arr2[j];
                j++;
            }
        }
        else if (i < n)
        {
            arr3[z]=arr1[i];
            i++;
        }
        else
        {
            arr3[z]=arr2[j];
            j++;
        }
    }
  //Displaying the result
    printf("The merged array is: \n");
    for (z= 0;z<n+k;z++)
    {
        printf("%d\t",arr3[z]);
    }
    printf("\n");
    return 0;
}