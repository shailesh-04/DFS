#include<stdio.h>
#include<conio.h>
#include<alloc.h>

struct LinkList
{
	int data;
	struct LinkList *next;
}*newnode,*head=NULL,*temp=NULL,*dummy=NULL;

	int se,i,nor,flag=0;
	char ch;

void Create()
{
	if(head!=NULL)
	{
		printf("\n\n Linked List Is Alrady Created...");
	}
	else
	{
		printf("\n\n How Many Do Yo Waant To Insert Data :-");
		scanf("%d",&nor);
		for(i=0; i<nor; i++)
		{
			newnode=(struct LinkList *)malloc(sizeof(struct LinkList));
			printf("\n Enter Data :-");
			scanf("%d",&newnode->data);
			newnode->next = NULL;
			if(head==NULL)
			{
				head=newnode;
				temp =head;
			}
			else
			{
				temp->next=newnode;
				temp=temp->next;

			}
		}
	}
}
void Display()
{
	if(head== NULL)
	{
		printf("\n\nThe Linked List In Not Avelable Record., Please Insert Record....");
	}
	else
	{   printf("\n\n");
		for(temp=head; temp!= NULL; temp=temp->next)
		{
			printf("%d-> ",temp->data);
		}
		printf("NULL");
	}
}
void FirstInser()
{
	newnode=(struct LinkList *)malloc(sizeof(struct LinkList));
	printf("\n\n Enter Data :-");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void LastInsert()
{
	newnode=(struct LinkList *)malloc(sizeof(struct LinkList));
	printf("\n\n Enter Data :-");
	scanf("%d",&newnode->data);
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		for(temp= head; temp->next!=NULL; temp=temp->next)
		{
		  ;
		}
		temp->next= newnode;
	}
}
void InsertAfter()
{
	flag=0;
	if(head==NULL)
	{
		printf("\n\n The Lis is Entity.......");
	}
	else
	{
		Display();
		printf("\n\n Enter Search Eliment (Were Are To Arenge after eliment) :-");
		scanf("%d",&se);
		for(temp=head; temp!=NULL; temp=temp->next)
		{
			if(temp->data==se)
			{
				flag=1;
				break;
			}
		}

		if(flag==0)
		{
			printf("\n Data Is Not Found......");
		}
		else
		{
			newnode=(struct LinkList *)malloc(sizeof(struct LinkList));
			printf("\n Enter Data :-");
			scanf("%d",&newnode->data);
			newnode->next= temp->next;
			temp->next=newnode;
		}

	}
}
void DeltFirst()
{
	if(head==NULL)
	{
		printf("\n\n Data Avelsble Data.....");
	}
	else
	{
		temp=head;
		head=temp->next;
		printf("\n\n First [%d] Data Is Succes Fully Delete  .....",temp->data);
		free(temp);
	}
}
void DeltLast()
{
	if(head==NULL)
	{
		printf("\n\n Data Is Avelable.....");
	}
	else
	{
		if(head->next==NULL)
		{
			head=NULL;
		}
		else
		{
			for(temp=head; temp->next->next!=NULL; temp=temp->next)
			{
				 ;//Do Nothing In Loop
			}
			printf("\n\n Last [%d] Data Is Succes Fully Delete  .....",temp->next->data);
			free(temp->next);
			temp->next=NULL;
			getch();
		}
	}
}
void DeltAny()
{
	if(head==NULL)
	{
		printf("\n\n Not Aveleble Data ...");
	}
	else
	{
		Display();
		printf("\n\n Enter you want Delete Eliment :-");
		scanf("%d",&se);
		if(head->data==se)
		{
			temp=head;
			head=head->next;
			printf("\n\n Data [%d] Is Succes Fully Delete  .....",temp->data);
			free(temp);
		}
		else
		{
			flag=0;
			for(temp=head; temp->next!=NULL; temp=temp->next)
			{
				if(temp->next->data==se)
				{
					flag=1;
					break;
				}
			}
			if(flag==0)
			{
					printf("\n Data Is Not Found");
			}
			else
			{
				dummy=temp->next;
				temp->next=dummy->next;
				printf("\n\n Data [%d] Is Succes Fully Delete  .....",dummy->data);
				free(dummy);
			}
		}
	}
	getch();
}
void Update()
{
	flag=0;
	if(head==NULL)
	{
		printf("\n\n Data Is Not Found....");
	}
	else
	{
		Display();
		printf("\n\n Enter You Want To Update :-");
		scanf("%d",&se);
		for(temp=head; temp!=NULL; temp=temp->next)
		{
			if(temp->data==se)
			{
				flag=1;
				break;
			}
		}
		if(flag==0)
		{
			printf("\n Data Is Not Found....");
		}
		else
		{
			printf("\n Enter Updete Data :-");
			scanf("%d",&temp->data);
		}
	}
}
void main()
{
	while(1)
	{
		clrscr();
		printf("\n\n #] Exit  ");
		printf("\n 1] Create  ");
		printf("\n 2] Display");
		printf("\n 3] First Insert");
		printf("\n 4] Last  Insert ");
		printf("\n 5] After Insert");
		printf("\n 6] Delete First");
		printf("\n 7] Delete Last");
		printf("\n 8] Deleat Any");
		printf("\n 9] Update Data");

		printf("\n \n Enter Your Choise :- ");
		ch=getch();
		printf("\n----------------------");
		switch(ch)
		{
			case'#': exit();
			case'1': Create(); 		getch(); break;
			case'2': Display();		getch(); break;
			case'3': FirstInser();  getch(); break;
			case'4': LastInsert(); 	getch(); break;
			case'5': InsertAfter(); getch(); break;
			case'6': DeltFirst();   getch(); break;
			case'7': DeltLast();    getch(); break;
			case'8': DeltAny();		getch(); break;
			case'9': Update();		getch();	break;
			default: printf(" Invalid Option........ "); getch();
		}

	}
}
