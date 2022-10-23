#include<stdio.h>
#define SIZE 5
int FRONT[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int REAR[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int PQ[10][5];
int NP=10;
int dequeue(void);
void enqueue(int x,int p);
int main()
{
  int request,entry,priority;
  label:
  printf("****Please select from the available options***\n1.Enqueue\n2.Dequeue\n");
  scanf("%d",&request);
  switch(request)
  {
  	case 1:printf("You have selected Enqueing.Please enter  the values\n");
  	printf("entry:");scanf("%d",&entry);printf("priority:");scanf("%d",&priority);enqueue(entry,priority);
    break;
    case 2:printf("You have selected Dequeing\n");
    printf("%d\n",dequeue());break;
  } 
  printf("Do you wanna repeat.Enter 6 for continuing\n");
  scanf("%d",&request);
  if (request==6){goto label;}else return 0 ;
}

int dequeue(void)
{ 
 int i=0,temp;  
 while(FRONT[i]==-1)
 	{i++;}
 if(i==NP){printf("Empty priority queue\n");return -999;}
 else{  
    temp=PQ[i][FRONT[i]];
	if (FRONT[i]==REAR[i])
	{
	  FRONT[i]=-1;
	  REAR[i]=-1;
	}
	else{FRONT[i]=(FRONT[i]+1)%SIZE;}
	return temp;
 }
}
void enqueue(int x,int p)
{
 if(FRONT[p]==((REAR[p]+1)%SIZE)){printf("stack overflow\n");}
 else{REAR[p]=(REAR[p]+1)%SIZE;
 	PQ[p][REAR[p]]=x;
 	if(FRONT[p]==-1)FRONT[p]=0;
     }
}