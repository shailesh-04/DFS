#include<conio.h>
#include<stdio.h>
void main()
{
	int a[5]={59,34,53,37,15},n=5;
	int gap=0,swap=0,i,t;

	clrscr();
	gap = n/2;
	do
	{
		do
		{
			swap = 0;
			for(i=0; i<n-gap; i++)
			{
				if(a[i] > a[i+gap])
				{
					t =a[i];
					a[i] = a[i+gap];
					a[i+gap] = t;
					swap = 1;
				}
			}
		}while(swap>0);
		gap = gap/2;
	}while(gap>0);
	for(i=0; i<n; i++)
		printf(" %d,",a[i]);

	getch();
}