#include<stdio.h>
void merge(int arr[],int l,int m,int r)
{
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int L[25],R[25];
    for(i=0;i<n1;i++)
    {
        L[i]=arr[l+i];
    }
    for(j=0;j<n2;j++)
    {
        R[j]=arr[m+1+j];
    }
    i=0;
    j=0;
    k=1;
    while(i<n1  && j<n2)
    {
        if(L[i]<=R[j])
        {
            arr[k]=L[i];
            i++;
        }
        else
        {
            arr[k]=R[j];
            j++;
        }
        k++;

    }
    while(i<n1)
    {
        arr[k]=L[i];
        i++;
        k++;

    }
}
 void mergeSort(int arr[],int l,int r)
 {
     if(l<r)
     {
         int m=(l+r)/2;
         mergesort(arr,l,m);
         mergesort(arr,m+1,r);
         merge(arr,l,m,r);
     }
 }
  void printArray(int arr[],int n)
  {
      int i;
      for(i=0;i<n;i++)
      {
          printf("%d",arr[i]);
      }
      printf("\n");
  }
int main()
{
    int arr[]={ 67,65,34,45,98,78,18};
    mergeSort(arr,0,7);
    printArray(arr,8);
    

    
     return 0;
}
