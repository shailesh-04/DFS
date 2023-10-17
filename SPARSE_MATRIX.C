#include<conio.h>
#include<stdio.h>
void main()
{

	int m[5][5];
	int ps[25][3];
	int i,j,k=0;

	clrscr();
	printf("\n Enter Value Of 3 X 3 Matrix Valur :-");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			scanf("%d",&m[i][j]);
			//m[i][j]= rand() % 9;
		}
	}
	 clrscr();
	printf("\n\n");
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			printf(" %d",m[i][j]);
		}
		printf("\n");
	}
  //Convert Parse Matrix

	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(m[i][j] != 0)
			{
				ps[k][0] = i;
				ps[k][1] = j;
				ps[k][2] = m[i][j];
				k++;
			}
		}
	}
//   print parses Matrix
	printf("\n\n");
	for(i=0; i<k; i++)
	{
		for(j=0; j<3; j++)
		{
			printf(" %d",ps[i][j]);
		}
		printf("\n");
	}

 //Parses Matrix To Full Matrix

 printf("\n\n");

	k=0;
	for(i=0; i<3; i++)
	{
		for(j=0; j<3; j++)
		{
			if(ps[k][0] == i && ps[k][1] == j)
			{
				printf(" %d",ps[k][2]);
				k++;
			}
			else
			{
				printf(" 0");
			}
		}
		printf("\n");
	}

	getch();
	printf("MADE BY SHAILESH");
}