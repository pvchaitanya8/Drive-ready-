#include<stdio.h>
char c[10];
int isym=0,flag=0;
main()
{
//clrscr();
	printf("\n enter the input string");
	scanf("%s",c);
	E();
	if(flag==1)
		printf("notvalid");
	else
		printf("valid");
//getch();
}
E()
{
	T();
	eprime();
}
eprime()
{
	if(c[isym]=='+')
	{
		advance();
		T();
		eprime();
	}
}
T()
{
	F();
	tprime();
}
F()
{
	if(c[isym]=='i')
	{
		advance();
		if(c[isym]=='i')
		error();
	}
	else if(c[isym]=='c')
	{
		advance();
		E();
		if(c[isym]==')')
			advance();
		else
			error();
	}
	else
		error();
}
tprime()
{
	if(c[isym]=='*')
	{
		advance();
		F();
		tprime();
	}
}
advance()
{
	isym++;
}
error()
{
	flag=1;
}

/*
output:-
enter the input stringi*i+i
valid
enter the input stringi(i)
valid
enter the input stringi*i+c
notvalid
*/
