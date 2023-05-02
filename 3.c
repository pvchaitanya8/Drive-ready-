#include<stdio.h>
//#include<conio.h>
#include<ctype.h>
main()
{
	int st=0,i=0,k;
	char c,b[10];
	FILE *fp;
	fp=fopen("lex.c","r");
	while(!feof(fp))
	{
		switch(st)
		{
			case 0:
				c=getc(fp);
				if(c=='(')
					st=1;
				else if(c=='>')
					st=5;
				else if(c=='=')
					st=8;
				else if(c=='+')
					st=11;
				else if(c=='-')
					st=12;
				else if(c=='*')
					st=13;
				else if(c=='%')
					st=14;
				else if (c==' ')
					st=15;
				else if (c=='\t')
					st=17;
				else if(isalpha(c))
				{
					b[i++]=c;
					st=9;
				}
				break;
			case 1:
				c=getc(fp);
				if(c=='-')
					st=2;
				else if(c=='>')
					st=3;
				else
					st=4;
					break;
			case 2:
				printf("\nis identifed");
				st=0;
				break;
			case 3:
				printf("\nNE is identifed");
				st=0;
				break;
			case 4:
				ungetc(c,fp);
				printf("\nLT is identifed");
				st=0;
				break;
			case 5:
				c=getc(fp);
				if(c=='=')
					st=6;
				else
					st=7;
					break;
			case 6:
				printf("\nGE is identifed ");
				st=0;
				break;
			case 7:
				ungetc(c,fp);
				printf("\nGT is identifed");
				st=0;
				break;
			case 8:
				printf("\nEQ is identifed");
				st=0;
				break;
			case 9:
				c=getc(fp);
				if(isalpha(c) || isdigit(c))
				{
					st=9;
					b[i++]=c;
				}
				else
				{
					st=10;
					b[i]='\0';
				}
				break;
			case 10:
				ungetc(c,fp);
				k=install_id(b);
				if(k==0)
					printf("\n%s keyword",b);
				else
					printf("\n%s identifer",b);
					st=0;
					i=0;
					break;
			case 11:
				printf("\n+ is identifed");
				st=0;
				break;
			case 12:
				printf("\n- is identified");
				st=0;
				break;
			case 13:
				printf("\n* is identified");
				st=0;
				break;
			case 14:
				printf("\n/ is identfied ");
				st=0;
				break;
			case 15:
				printf("\nmodule is identifed");
				st=0;
				break;
			case 16:
				printf("\nnew line operator is used ");
				st=0;
				break;
			case 17:
				c=fgetc(fp);
				if(c=='/')
				{
					while((c=fgetc(fp))!='\n')
					st=20;
				}
				else if (c=='*')
				{
					while((c=fgetc(fp))!=EOF)
						if(c=='*')
						{
							if((c=fgetc(fp))=='/')
							{
								st=20;
								break;		
							}
						}
				}
				else
					st=9;
					break;
			case 20:
				printf("\ncomment is identified");
				st=0;
				break;
		}
	}
	fclose(fp);
	getch();
}
int install_id(char b[])
{
	char a[20][20]={"int","char","float","switch","break","if","else","for","while","case","exit","return"};
	int i=0,k=1;
	for(i=0;i<10;i++)
	{
		if(strcmp(b,a[i])==0)
		{
			k=0;
			return k;
		}
	}
	return k;
}

/*
INPUT: (“lex.c” file contents)
A+B*C
OUTPUT:
A identifier
+ identified
B identifier
* identified
C identified

*/
