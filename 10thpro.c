#include<stdio.h>
#include <string.h>
char stack[30];
int top=-1;
void push(char c)
{
	top++;
	stack[top]=c;
}
char pop()
{
	char c;
	if(top!=-1)
	{
		c=stack[top];
		top--;
		return c;
	}
	return 'x';
}
void printstat()
{
	int i;
	printf("\n$");
	for(i=0;i<=top;i++)
		printf("%c",stack[i]);
}
void main()
{
	int i,j,k,len;
	char s1[20],s2[20],ch1,ch2,ch3;
	printf("LR PARSING\n");
	printf("ENTER THE EXPRESSION\n");
	scanf("%s",s1);
	len=strlen(s1);
	j=0;
	printf("$");
	for(i=0;i<len;i++)
	{
		if(s1[i]=='i' && s1[i+1]=='d')
		{
			s1[i]=' ';
			s1[i+1]='E';
			printstat(); 
			printf("id");
			push('E');
			printstat();
		}
		else if(s1[i]=='+'||s1[i]=='-'||s1[i]=='*' ||s1[i]=='/' ||s1[i]=='d')
		{
			push(s1[i]);
			printstat();
		}
	}
printstat();
len=strlen(s2);
while(len)
{
ch1=pop();
if(ch1=='x')
{
printf("\n$");
break;
}
if(ch1=='+'||ch1=='/'||ch1=='*'||ch1=='-')
{
ch3=pop();
if(ch3!='E')
{
printf("errror");
return;
}
else
{
push('E');
printstat();
}
}
ch2=ch1;
}
getch();
}
