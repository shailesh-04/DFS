#include<conio.h>
#include<stdio.h>
struct Queue
{
	int data;
	struct Queue *next;
};
struct Queue *first=NULL,*end=NULL,*temp;
void Enque()
{
	temp = (struct Queue *)malloc(sizeof(struct Queue));
	temp ->next = NULL;
	printf("\n Enter Value Of Data :-");
	scanf("%d",&temp->data);
	if(first == NULL)
		first = temp;
	else
		end->next = temp;
	end = temp;

}
void Deque()
{
	if(first == NULL)
		printf(" The Queue Are Empty");
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
		printf(" The Queue Are Empty");
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
		printf("\n~~~~~~~~~~~~~~~~~~~QUEUE~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
		printf("\n #) EXIT");
		printf("\n 1) Enque()");
		printf("\n 0) Display()");
		printf("\n 2) Deque()");
		printf("\n Enter Your Choice :-");
		ch = NULL;
		ch = getch();
		printf("\n___________________________________________\n");
		switch(ch)
		{
			case '1': Enque(); break;
			case '0': Display(); getch(); break;
			case '2': Deque(); getch(); break;
		}
	}
}