#include<conio.h>
#include<stdio.h>
void main()
{
	int a[10];
	int i,j,n=5,temp;

	clrscr();

	printf("\n Enter Any Five Value :-");
	for(i=0; i<n; i++)
	{
	  scanf("%d",&a[i]);
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	printf("\n\n AFTER BUBBLE SORT..\n\n");
	for(i=0; i<n; i++)
	{
		printf("%d, ",a[i]);
	}
	getch();
}