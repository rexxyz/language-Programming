//By default the stack contains a '{' and we put a '#' at the end of the infix expression.Since we are using a string 
//we could use '\0' instead of #.
#include<stdio.h>
#include<string.h>
#define SIZE 20
enum precedence{lparen, rparen, plus, minus ,times ,divide ,mod , operand};
int stack[SIZE];
char EXP[SIZE];
char string[SIZE];//The expression is also made global.
int TOP =-1;
void push (int c);
int pop (void);
void printToken(void);
int getToken(char c);//Return what kind of token ,the character is?
void postfix(int token);//The argument is a string which is also a numerical constant.
int main()
{
	int token,temp1,temp2,spare;
	postfix(lparen);
	printf("%d",stack[TOP]);
	printf("please enter the expression\n");
	scanf("%s",string);
	for (int i = 0; string[i]!='\0'; ++i)
	{
		token=getToken(string[i]);
		if(token==operand)
  	    {printf("%c",string[i]);continue;}
		postfix(token);
	}
	postfix(rparen);
	printf("\n");
	printf("please enter the expression you want to evaluate\n");
	scanf("%s",EXP);
	for (int i = 0; EXP[i]!='\0'; ++i)
	{
		token=getToken(EXP[i]);
		if (token==operand)
		{
			spare =(int)EXP[i]-48;
			push(spare);
		}
		else
		{
			temp1=pop();
			temp2=pop();
			switch(token)
			{
        case plus:push(temp2+temp1);break;
        case minus:push(temp2-temp1);break;
        case mod:push(temp2%temp1);break;
        case times:push(temp2*temp1);break;
        case divide:push(temp2/temp1);break;
			}
		}
	}
	printf("%d\n",pop() );
	return 0;

}
void push (int c)
{
	if(TOP==SIZE-1)
	{
		printf("stack overflow\n");
	}
	else
	{
		TOP++;
    stack[TOP]=c;
	}
}
int pop(void)
{ int temp;
	if(TOP==-1)
	{
		printf("stack underflow\n");
		return 0;
	}
	else
	{  
	  temp=stack[TOP];
		TOP--;
		return temp;
	}
}
void postfix(int token)
{ int i;
  int in_stack_precedence[]={0,19,12,12,13,13,13};
  int incoming_precedence[]={20,19,12,12,13,13,13};
  if (token==rparen)
  {
  	while(stack[TOP]!=lparen){printToken();}
  	pop();
  	return ;//poping the left braces.
  }
  if(in_stack_precedence[stack[TOP]]<incoming_precedence[token]&&(token!=rparen))
  { 
    push(token);return;
  }
 
  if(in_stack_precedence[stack[TOP]]>=incoming_precedence[token])//very beautiful implementation.
  { 
  	while(in_stack_precedence[stack[TOP]]>=incoming_precedence[token])
    {printToken();}
    push(token);
  }


}
int getToken(char character)
{
  switch(character)
  {
  	case '(':return lparen;
  	case ')':return rparen;
  	case '+':return plus;
  	case '-':return minus;
  	case '/':return divide;
  	case '*':return times;
  	case '%':return mod;
  	default :return operand;
  }
}
void printToken(void)
{   
	int temp;
	temp=pop();
	switch(temp)
  { case plus:printf("+");break;
  	case minus:printf("-");break;
  	case divide:printf("/");break;
  	case times:printf("*");break;
  	case mod:printf("%");break;
  	
  }
}//The enum are just variable with numerical value.