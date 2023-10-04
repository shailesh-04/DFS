#include<conio.h>
#include<stdio.h>
struct Stack
{
	int data;
	struct Stack *next;
};
struct Stack *first=NULL,*temp;

void Push()
{
	temp = (struct Stack *)malloc(sizeof(struct Stack));
	temp ->next = first;
	printf("\n Enter Value Of Data :-");
	scanf("%d",&temp->data);
	first = temp;
}
void Pop()
{
	if(first == NULL)
		printf(" The Stack Are Empty");
	else
	{
		temp = first;
		first = temp->next;
		free(temp);
		printf("\n  Successfully Delete... ");
	}
}
void Display()
{
	if(first == NULL)
		printf(" The Stack Are Empty");
	else
	{
		for(temp = first; temp!=NULL; temp=temp->next)
			printf(" %d->",temp->data);
		printf("NULL");
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
		printf("\n 0) Display()");
		printf("\n 1) Puch()");
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