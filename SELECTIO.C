#include<conio.h>
#include<stdio.h>
void main()
{
	int a[20],i,k,j,n=7,temp;
	clrscr();
	printf("\n Enter Any	Value For Arry :-");
	for(i=0; i<n; i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	printf("\n After Selection Sort ..,\n\n");
	for(i=0; i<n; i++)
	{
		printf(" %d ,",a[i]);
	}
	getch();
}