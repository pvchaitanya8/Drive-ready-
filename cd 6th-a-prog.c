#include<stdio.h>
#include<conio.h>
#include<string.h> void 
main()
{
	char t[5],nt[10],p[5][5],first[5][5],temp; 
	int i,j,not,nont,k=0,f=0;
	printf("\nEnter the no. of Non-terminals in the grammar:"); 
	scanf("%d",&nont);
	printf("\nEnter the Non-terminals in the grammar:\n"); 
	for(i=0;i<nont;i++)
	{
		scanf("\n%c",&nt[i]);
	}
	printf("\nEnter the no. of Terminals in the grammar (Enter e for epsilon): "); 
	scanf("%d",&not);
	printf("\nEnter the Terminals in the grammar:\n"); 
	for(i=0;i<not||t[i]=='$';i++)
	{
		scanf("\n%c",&t[i]);
	}
	for(i=0;i<nont;i++)
	{
		p[i][0]=nt[i];
		first[i][0]=nt[i];
	}
	printf("\nEnter the productions :\n"); 
	for(i=0;i<nont;i++)
	{
		scanf("%c",&temp);
		printf("\nEnter the production for %c ( End the production with '$' sign ):",p[i][0]);
		for(j=0;p[i][j]!='$';)
		{
			j+=1;
			scanf("%c",&p[i][j]);
		}
	}
	for(i=0;i<nont;i++)
	{
		printf("\nThe production for %c -> ",p[i][0]); 
		for(j=1;p[i][j]!='$';j++)
		{
			printf("%c",p[i][j]);
		}
	}
	for(i=0;i<nont;i++)
	{
		f=0; 
		for(j=1;p[i][j]!='$';j++)
		{
			for(k=0;k<not;k++)
			{
				if(f==1)
					break;
				if(p[i][j]==t[k])
				{
					first[i][j]=t[k]; first[i][j+1]='$'; f=1;
					break;	
				}
				else if(p[i][j]==nt[k])
				{
					first[i][j]=first[k][j];
					if(first[i][j]=='e')
						continue; 
					first[i][j+1]='$'; 
					f=1;
					break;
				}
			}
		}
	}
	for(i=0;i<nont;i++)
	{
		printf("\nThe first of %c -> ",first[i][0]); for(j=1;first[i][j]!='$';j++)
		{
			printf("%c\t",first[i][j]);
		}
	}
}

/*
Enter the no. of Non-terminals in the grammar:3
Enter the Non-terminals in the grammar: ERT
Enter the no. of Terminals in the grammar (Enter e for epsilon): 5
Enter the Terminals in the grammar: ase*+
Enter the productions :
Enter the production for E ( End the production with '$' sign ):a+s$ 
Enter the production for R ( End the production with '$' sign ):e$ 
Enter the production for T ( End the production with '$' sign ):Rs$
The production for E -> a+s 
The production for R -> e 
The production for T -> Rs
The first of E -> a 
The first of R -> e 
The first of T -> e s

*/
