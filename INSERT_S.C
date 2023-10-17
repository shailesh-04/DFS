#include<conio.h>
#include<stdio.h>
void main()
{
	int i,j,data[20],x=0,n=0;
	clrscr();

	printf("\n How Many Do You Want To Insert Record :-");
	scanf("%d",&n);

	for(i=0; i<n; i++)
	{
		printf("\n Enter Any Value :-");
		scanf("%d",&x);

		for(j=i-1; j>=0 && data[j] > x ; j--)
		{
			data[j+1] = data[j];
		}
		data[j+1] = x;
	}

	clrscr();
	printf("\n\t BELOW ELEMENT IS INSETION SHOT ...\n\t ----------------------------------------");

	for(i=0; i<n; i++)
	printf("\n\t %d",data[i]);

	getch();

}