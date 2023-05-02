#include<stdio.h>
char c[10];
int i=0;
main()
{
//clrscr();
	printf("\n enter input string");
	scanf("%s",c);
	if(s()==0)
		printf("the given input string is not valid");
	else
		printf("the given input string is valid");
//getch();
}
int s()
{
	if(c[i]=='c')
	{
		advance();
		if(A())
		{
			if(c[i]=='d')
			{
				advance();
				return 1;
			}
		}
	}
	return 0;
}
advance()
{
	i=i+1;
}
int A()
{
	int isave;
	{
		isave=1;
		if(c[i]=='a');
		{
			advance();
			if(c[i]=='b')
			{
				advance();
				return 1;
			}
		}
		i=isave;
		if(c[i]=='a')
		{
			advance();
			return 1;
		}
		return 0;
	}	
}


output:-

enter input string cad
the given input string is valid
