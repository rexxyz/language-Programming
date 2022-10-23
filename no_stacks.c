#include <stdio.h>
#include<string.h>

void WritePostfixBrackets(char expr[]);
void PostNoBrackets(char expr[], int start, int end);
void GetLeftOperand(char expr[], char left[], int pos, int start);
void GetRightOperand(char expr[], char right[], int pos, int end);
void WritePostfix(char expr[], int startIndex, char left[], char right[], char op);

int converted[50];

int main()
{
    char expr[50];
    printf("Enter infix expression \n");
    scanf("%s",expr);
    char st[52];
    st[0]='(';
    st[1]='\0';
    strcat(st,expr);
    strcpy(expr,st);
    st[0]=')';
    st[1]='\0';
    strcat(expr,st);
    int l =strlen(expr);
    int i;
    for(i=0; i<l; i++)
    {
        converted[i]=0;
    }
    WritePostfixBrackets(expr);
    return 0;
}


void WritePostfixBrackets(char expr[])
{
    
    int l = strlen(expr),i,startIndex,endIndex,k=0;
    do
    {
        i=0;
        int c=0;
        startIndex=0;
        endIndex = l;
        while(i<l && expr[i]!=')')
        {
            if(expr[i]=='(')
            {
                c=1;
                startIndex = i+1;
                i++;
            }

            else
                ++i;
        }
        if(c==1)
        {
            i=0;
            while(i<l)
            {
                if(expr[i]==')')
                {
                  endIndex=i-1;
                PostNoBrackets(expr, startIndex, endIndex);
                expr[startIndex-1]=expr[endIndex+1]='#';
                converted[startIndex-1]=converted[endIndex+1]=1;
                c=0;
                break;  
                }
                i++;
            }
        }
    }while(startIndex!=0);

    char newExp[50];
    for(i=0; i<l; i++)
    {
        if(expr[i]!='#')
        {
            newExp[k++]=expr[i];
        }
    }
    newExp[k]='\0';

    printf("Equivalent postfix expression = %s",newExp);
}

void PostNoBrackets(char expr[], int start, int end)
{
    int i,l;
    char left[30];
    char right[30];

    for(i=end; i>=start; i--)
    {
        if (expr[i] == '^' && converted[i] != 1)
			{
                converted[i]=1;
                converted[i-1]=converted[i+1]=1;
                GetLeftOperand(expr, left, i, start);
                GetRightOperand(expr, right, i, end);
                l=strlen(left);
                WritePostfix(expr, i-l, left, right, expr[i]);
            }
    }

    for(i=start; i<=end; i++)
    {
        if ((expr[i] == '*' || expr[i] == '/') && converted[i] != 1)
            {
                converted[i]=1;
                converted[i-1]=converted[i+1]=1;
                GetLeftOperand(expr, left, i, start);
                GetRightOperand(expr, right, i, end);
                l=strlen(left);
                WritePostfix(expr, i-l, left, right, expr[i]);
            } 
    }

    for(i=start; i<=end; i++)
    {   
        if ((expr[i] == '+' || expr[i] == '-') && converted[i] != 1)
            {
                converted[i]=1;
                converted[i-1]=converted[i+1]=1;
                GetLeftOperand(expr, left, i, start);
                GetRightOperand(expr, right, i, end);
                l=strlen(left);
                WritePostfix(expr, i-l, left, right, expr[i]);
            }

    }

}


void GetLeftOperand(char expr[], char left[], int pos, int start)
{
    left[0]='\0';
    int i = pos-1;int j,d;
	while ( i>= start && converted[i] != 0)
		{   char st[20];
            st[0]=expr[i];
            st[1]='\0';
            strcat(st,left);
            strcpy(left,st);
            i = i-1;
        }
}

void GetRightOperand(char expr[], char right[], int pos, int end)
{
    right[0]='\0';
    int i = pos+1;
	while ( i<= end && converted[i] != 0)
		{
            char st[2];
            st[0]=expr[i];
            st[1]='\0';
            strcat(right, st);
		    i = i+1;
        }
}

void WritePostfix(char expr[], int startIndex, char left[], char right[], char op)
{
    int i = 0;
	while (i < strlen(left))
	{
    	expr[startIndex+i] = left[i];
		i = i+1;
    }

    int j = 0;
	while (j < strlen(right))
	{	
        expr[startIndex+i+j] = right[j];
		//converted[i+j] = 1;
		j = j+1;
    }

    expr[startIndex+i+j] = op;

}