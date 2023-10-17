#include<conio.h>
#include<stdio.h>
int stack[10];
int i,top =-1;
void Push()
{
	if(top==10)
		printf("\n Stack Are Full");
	else
	{
		top++;
		printf("\n Enter Any Value :-");
		scanf("%d",&stack[top]);
	}
}
void Pop()
{
	if(top==-1)
		printf("\n The Stack Is Empty...");
	else
	{
		top--;
		printf("\n Sucsessfully Data Is Pop To the Stack...");
	}
}
void Display()
{
	if(top==-1)
		printf("\n The Stack Is Empty...");
	else
	{
		for(i=top; i>=0; i--)
			printf("%d,",stack[i
			]);
	}
}
void main()
{
	char ch;
	while(ch!='#')
	{
		clrscr();
		printf("\n~~~~~~~~~~~~~~~~~~~STACK WITH ARRY~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\n #) EXIT");
		printf("\n 1) Puch()");
		printf("\n 0) Display()");
		printf("\n 2) Pop()");
		printf("\n Enter Your Choice :-");
		ch = NULL;
		ch = getch();
		printf("\n___________________________________________\n");
		switch(ch)
		{
			case '1': Push(); break;
			case '0': Display(); getch(); break;
			case '2': Pop(); getch(); break;
		}
	}
}