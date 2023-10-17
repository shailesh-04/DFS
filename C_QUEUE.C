#include<conio.h>
#include<stdio.h>
#define n 5
int arr[n];
int f=-1,r=-1,i;
char ch;

void Enque()
{
	if(f==-1 && r==-1)
	{
		f=0;
		r=0;
		printf("\n Enter Element Of Queue :-");
		scanf("%d",&arr[r]);
	}
	else if((r+1)%n==f)
	{
		printf("\n The Queue Are Full...");
		getch();
	}

	else
	{
		r = (r+1)%n;
		printf("\n Enter Value Of Queue :-");
		scanf("%d",&arr[r]);
	}
}
void Deque()
{
	if(f==-1 && r==-1)
		printf("\n The Queue Are Empty....");
	else
	{
		if(f==r)
			f=r=-1;
		else
			f=(f+1)%n;
		printf("\n Sucsesfuly Dequeue The Last Node");
	}
}
void Display()
{
	int i;
	if(f==-1 && r==-1)
		printf("\n The Queue Are Empty...");
	else
	{
		printf("\n The Queue Element..\n\n");
		for(i=f; i!=r; i=(i+1)%n)
		{
			printf("%d_,",arr[i]);
			ch =NULL;
			if(i==10)break;
		}
		printf("%d",arr[r]);


	}
}
void main()
{
	char ch;
	while(ch!='#')
	{
		clrscr();
		printf("\n 1) EnQue Data ...%d = (r+1)%n; ",r);
		printf("\n 2) Deque Data ...%d = (f+1)%n; ",f);
		printf("\n 0) Dispaly Data...");
		printf("\n  Enter Your choice :-");
		ch = NULL;
		ch = getch();
		printf("\n__________________\n");
		switch(ch)
		{
			case '1': Enque();break;
			case '2': Deque();getch(); break;
			case '0': Display();getch();break;
		}
	}
}
