#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<stdlib.h>
int a[30],count=0;
int place(int pos)
 {
	int i;
	for (i=1;i<pos;i++) 
	{
		if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
		   return 0;
	}
	return 1;
}
void print_sol(int n)
 {
	int i,j;
	count++;
	printf("\n\n->Solution #%d:\n",count);
	for (i=1;i<=n;i++) 
	{
		for (j=1;j<=n;j++) 
		{
			if(a[i]==j)
			{
			    printf("\tQ\t"); 
			}
			else
			{
			    printf("\t*\t");
			}
		}
		printf("\n");
	}
}

void queen(int n)
 {
	int k=1;
	a[k]=0;
	while(k!=0)
	 {
		a[k]=a[k]+1;
		while((a[k]<=n)&&!place(k))
		   a[k]++;
		if(a[k]<=n) 
		{
			if(k==n)
			    print_sol(n);
			 else 
			 {
				k++;
				a[k]=0;
			 }
		}
		 else
		   k--;
	}
}

void main()
 {
	int c,n;
	l:system("cls");
	count=0;
	printf("-->Enter the number of Queens\n");
	scanf("%d",&n);
	queen(n);
	printf("\n-->Total possible solutions=%d",count);
	printf("\n-->Enter 1 to for again or any key for exit:-\n");
	scanf("%d",&c);
	switch(c)
	{
		case 1:goto l;
				break;
		default:printf("-->Program is exited Sucessfully"); 
				exit(0);
	}
}
