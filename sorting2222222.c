//Merge sort algorithm
#include<stdio.h>
void merge(int a[],int l, int m, int h)
{
	int i,j,k;
	int n1 = m-l+1;
	int n2 = h-m;
	int L[n1],H[n2];
	for(i=0;i<n1;i++)
	L[i]=a[l+i];
	for(j=0;j<n2;j++)
	H[j]=a[m+1+j];
	i=0;
	j=0;
	k=l;
	while(i<n1 && j<n2)
	{
		if(L[i]<=H[j])
		{
			a[k]=L[i];
			i++;
		}
		else
		{
			a[k]=H[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		a[k]=L[i];
		i++;
		k++;
    }
    while(j<n2)
    {
    	a[k]=H[j];
    	j++;
    	k++;
	}
}
void mergeSort(int a[],int l,int h)
{
	if(l<h)
	{
		int m = l+(h-l)/2;
		mergeSort(a,l,m);
		mergeSort(a,m+1,h);
		merge(a,l,m,h);

	}
}
void print_array(int A[], int size)
{
	int i;
	for(i=0;i<size;i++)
	printf("%d ",A[i]);
	printf("\n");
}
int main()
{
	int a[]= {123,145,34,76,897,345,2345};
	int arr_size = sizeof(a)/sizeof(a[0]);
	printf("Given array is \n");
	print_array(a, arr_size);
	mergeSort(a,0,arr_size-1);
	printf("\nSorted array is \n");
	printf_array(a,arr_size);
	return 0;

}
