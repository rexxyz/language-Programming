#include<stdio.h>
#include<string.h>
void main(){
int i,n;
char a[20];
puts("Enter the name\n");
gets(a);
for(i=0;a[i]!='\0';i++);
;
printf("Length= %d\n",i);
n=i;
while(n>=0){
	printf("%c",a[n]);
	n--;
}
}
