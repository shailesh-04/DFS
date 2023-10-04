/*

										 D-LINK LIST OPRATION
===============================____________________===========================
	|                       |                       |                      |
	|      INSERT NODE      |       DELETE NODE     |    OTHER OPRATION    |
	|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~~|~~~~~~~~~~~~~~~~~~~~~~|
	|  1) CREATE            |  6) DELETE_FIRST()    |  #) EXIT()           |
	|  2) INSERT_LAST()     |  7) DELETE_LAST()     |  0) DISPLAY()        |
	|  3) INSERT_FIRST()    |  8) DELETE_ANY()      |  9) UPDATE()         |
	|  4) INSERT_AFTER()    |                       |                      |
	|  5) INSERT_BEFAUR()   |                       |                      |
	|                       |                       |                      |
	************************************************************************

*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<graphics.h>
void Error_NoData();
void AutoRand();
struct Link
{
	struct Link *Perv;
	int no;
	char name;
	struct Link *Next;

}*Front=NULL,*Temp=NULL,*End=NULL,*NewNode=NULL;

int se,i;
char c;

//=================Insert Larst==========

void InsertLast()
{
	//create Memory Block
	Temp = (struct Link *)malloc(sizeof(struct Link));
	printf("\n Enter Any Last Data :-");
	scanf("%d",&Temp->no);

	Temp->Next=NULL;
	Temp->Perv = End;
	if(Front == '\0')
		Front = Temp;
	else
		End->Next = Temp;
	End = Temp;
}
//=================Insert Firsat==========
void InsertFirst()
{

	Temp = (struct Link *)malloc(sizeof(struct Link));
	printf("\n Enter Any First Data :-");
	scanf("%d",&Temp->no);

	Temp->Perv = NULL;
	Temp->Next = Front;
	if(Front == '\0')
		Front = Temp;
	else
		Front->Perv = Temp;
	Front = Temp;
}
void DeleteFirst()
{
	if(Front == NULL)
		Error_NoData();
	else
	{
		if(Front->Next == NULL)
			Front =End= NULL;
		else
		{
			Temp = Front;
			Front = Temp->Next;
			Front->Perv = NULL;
			free(Temp);
		}
		printf("\n FIRST NODE IS SUCESSESFULY DELETE....!");
	}
}
void DeleteLast()
{
	if(Front == NULL)
		Error_NoData();
	else
	{
		if(Front->Next==NULL)
			Front=End=NULL;
		else
		{
			Temp = End;
			End = Temp->Perv;
			End->Next=NULL;
			free(Temp);
		}
		printf("\n LAST NODE IS SUCSESSFULLY DELETE...!");
	}
}
void Create()
{
	int i,n;
	char ch;
	printf("\n________________MULTIPLE NODE INSER~~~~~~~~~~~~~~~~~\n");
	printf("\n1) Insert Lasst");
	printf("\n2) Insert Firt");
	printf("\n3) Random Insert");
	printf("\n  Enter Choice :-");
	ch=getch();
	printf("\n_________________________________\n");
	switch(ch)
	{
		case '1': printf("\n How Many Do You Want To Insert Node [LAST] :-");
					 scanf("%d",&n);
					 for(i=0; i<n; i++)
						InsertLast();
					 break;
		case '2': printf("\n How Many Do You Want To Insert Node [FIRST] :-");
					 scanf("%d",&n);
					 for(i=0; i<n; i++)
						InsertFirst();
					 break;
		case '3': printf("\n How Many Do You Want To Insert Node [LAST] :-");
					 scanf("%d",&n);
					 for(i=0; i<n; i++)
						AutoRand();
	}
}
void AutoRand()
{
	//create Memory Block
	Temp = (struct Link *)malloc(sizeof(struct Link));
	Temp->no =  rand() % 100;
	Temp->Next=NULL;
	Temp->Perv = End;
	if(Front == '\0')
		Front = Temp;
	else
		End->Next = Temp;
	End = Temp;
}
void InsertBefore()
{
	if(Front == NULL)
		Error_NoData();
	else
	{
		se=0;
		printf("\n Which Befour Do You Want To Insert NewNode :-");
		scanf("%d",&se);

		for(Temp=End; Temp!=NULL && se!=Temp->no; Temp=Temp->Perv)
		;
		if(se==Temp->no)
		{
			printf("\n\1\1 SEARCH ELIMENT IS IS FOUND.....\n");
			if(Temp->Perv==NULL)
				InsertFirst();
			else
			{
				NewNode = (struct Link *)malloc(sizeof(struct Link));
				printf("\n Enter New_Node Data :-");
				scanf("%d",&NewNode->no);

				NewNode->Next = Temp;
				Temp->Perv = NewNode;

				NewNode->Perv = Temp->Perv;
				Temp->Perv->Next = NewNode;

			}
		}
		else
			printf("\n SEARCH ELEMENT IS NOT FOUND...");
		getch();
	}
}
void InsertAfter()
{
	if(Front == NULL)
		Error_NoData();
	else
	{
		se=0;
		printf("\nWhich After Do You Want To Insert NewNode :-");
		scanf("%d",&se);
		for(Temp=Front; Temp!=NULL && se!=Temp->no; Temp=Temp->Next);

		if(se==Temp->no)
		{
			printf("\n\1\1 SEARCH ELEMENT IS FOUND.....\n");
			if(Temp->Next ==NULL)
				InsertLast();
			else
			{
				NewNode = (struct Link *)malloc(sizeof(struct Link));
				printf("\n Enter new_Node Data :-");
				scanf("%d",&NewNode->no);

				NewNode->Next = Temp->Next;
				NewNode->Perv = Temp;

				Temp->Next->Perv = NewNode;
				Temp->Next = NewNode;
			}
		}
		else
			printf("\n\n SEARCH ELEMENT IS NOT FOUND...");
		getch();
	}
}
void DeletAny()
{
	struct Link *Dummy;

	if(Front == NULL)
		Error_NoData();
	else
	{
		se=0;
		printf("\nEnter Do You Want To Delet Node->Data :-");
		scanf("%d",&se);

		if(Front->no == se)
			DeleteFirst();
		else if(End->no == se)
			DeleteLast();
		else
		{
			for(Temp=Front; Temp->Next!=NULL && se!=Temp->Next->no; Temp=Temp->Next);
			if(se==Temp->Next->no)
			{
				NewNode = Temp->Next;
				Temp->Next = Dummy->Next;
				Temp = Dummy->Next->Perv;
				printf("\n SUCSESSFULY DELETE SEARCH NODE	->[ %d ]",Dummy->no);
				free(Dummy);
			}
			else
				printf("\n SEARCH ELEMENT IS NOT FOUND.. \n");
		}
		getch();
	}
}
void Update()
{
	if(Front == NULL)
		Error_NoData();
	else
	{
		se=0;
		printf("\n Which Node Do You Want To Update :-");
		scanf("%d",&se);
		for(Temp=Front; Temp!=NULL && se!=Temp->no; Temp=Temp->Next) ;
		if(se==Temp->no)
		{
			printf(" Node->[ %d ] Is Update! Enter Data :-",Temp->no);
			scanf("%d",&Temp->no);
			printf("\n SUCSSSFULLY UPDATE DATA......");
		}
		else
			printf("\n SEARCH NODE IS NOTE FOUND....");
		getch();
	}
}
void ShortData()
{
	int tmp;

	if(Front == NULL)
		Error_NoData();
	else
	{
		if(Front->Next == NULL)
		{
			textcolor(YELLOW);
			gotoxy(3,17);cprintf(" MUST BE ONE MORETHAN DATA AVALABLE IN LIST.(1 < n)");
			gotoxy(7,18);cprintf(" CAN NOT POSIBLE TO SORT ONLY ONE NODE..IN C LANGUAEG..");
		}
		else
		{
			for(Temp=Front; Temp->Next!=NULL; Temp=Temp->Next)
			{
				for(NewNode=Front; NewNode->Next!=NULL; NewNode = NewNode->Next)
				{
					if(NewNode->no >= NewNode->Next->no)
					{
						tmp = NewNode->no;
						NewNode->no = NewNode->Next->no;
						NewNode->Next->no = tmp;
					}
				}
			}
			printf("\n DATA IS SUCSESSFULLY SORT... ");
		}
	}
}
//=========================================================================//
void SearchPosition()
{
	int p;
	if(Front == NULL)
		Error_NoData();
	else
	{
		printf("\n Which Node Do You Want To Search :-");
		scanf("%d",&se);
		for(Temp = Front,p=0; Temp!= NULL && se != Temp->no; Temp= Temp->Next,p++);
		if(Temp->no == se)
			printf("\n\n SEARCH ELEMENT IS FOUND \n\n\t DATA IS [ %d ], POSITION [ %d ]  ",Temp->no,p);
		else
			printf("\n SEARCH DATA IS NOT FOUND ...");
	}
}
void Display()
{
	int x=0,y=0,l=0,c=9;
	clrscr();
	if(Front == NULL)
		Error_NoData();
	else
	{
		textcolor(WHITE);
		for(Temp=Front; Temp!=NULL; Temp=Temp->Next,l++,c++)
		{
			if(l>=6)
			{
				x=0;
				l=0;
				y+=3;
				c=9;
			}
			textcolor(c);
			gotoxy(1+x,2+y);cprintf("________");
			gotoxy(1+x,4+y);cprintf("~~~~~~~~");
			gotoxy(1+x,3+y);cprintf("|");
			gotoxy(8+x,3+y);cprintf("|");

			textcolor(WHITE);
			gotoxy(2+x,3+y);cprintf("%d",Temp->no);
			textcolor(WHITE);
			gotoxy(9+x,3+y);cprintf("->");

			x+=11;
		}
		textcolor(RED);
		gotoxy(x-2,3+y);cprintf("NULL");
	}
}
void Error_NoData()
{
	clrscr();
	textcolor(3);
	for(i=1; i<10; i++)
	{
		gotoxy(20+i,6);cprintf("===============================");
		gotoxy(20,5+i);cprintf("|");
		gotoxy(20+i,14);cprintf("-------------------------------");
		gotoxy(60,5+i);cprintf("|");

	}
	textcolor(RED+BLINK);
	gotoxy(36,7);cprintf(" ERORR! ");
	textcolor(10);
	gotoxy(26,8);cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	textcolor(WHITE);
	gotoxy(28,9);cprintf("'YOU HAVEN'T MADE ANY NODE'");
	textcolor(10);
	gotoxy(30,10);cprintf("~~~~~~~~~~~~~~~~~~~~~~~");
	gotoxy(23,11);printf("When you create a NODE,");
	gotoxy(36,12);printf("it'll show up here.");
	textcolor(RED);
	gotoxy(54,13);cprintf("[ OK ]");
	gotoxy(56,13);
}
void DisplayG()
{
	int x=0,y=0,i,l=0;
	int gd=0,gm=0;
	char str[6];
	if(Front == NULL)
		Error_NoData();
	else
	{
		initgraph(&gd,&gm,"C:\\TC\\BGI");

		for(Temp=Front; Temp!=NULL; Temp=Temp->Next,l++)
		{
			if(l>=5)
			{
				l=0;
				y+=40;
				x=0;
			}
			setcolor(11);
			rectangle(1+x,5+y,90+x,30+y);

			line(15+x,5+y,15+x,30+y);
			line(75+x,5+y,75+x,30+y);

			setcolor(14);
			line(95+x,13+y,120+x,13+y);
			outtextxy(90+x,10+y,"<");

			setcolor(14);
			line(85+x,22+y,110+x,22+y);
			outtextxy(110+x,20+y,">");

			setcolor(WHITE);
			sprintf(str,"%d",Temp->no);
			outtextxy(20+x,14+y,str);

			x+=115;
		}
		x-=115;
		setcolor(4);

		line(75+x,5+y,90+x,30+y);// Next NULL Line
		line(5,5,15,30); // Prev NULL Line

		setcolor(0);
		line(95+x,13+y,120+x,13+y);
		outtextxy(90+x,10+y,"<");

		line(85+x,22+y,110+x,22+y);
		outtextxy(110+x,20+y,">");
	}
}
void DELETE_ALL_NODE_()
{
	if(Front == NULL)
		Error_NoData();
	else
	{
		for(Temp=End; Temp!=NULL; Temp=Temp->Perv)
		{
			DeleteLast();
		}
		printf("\n Sucsessfuly Delete all Node...");
	}

}
void DManu()
{
		 window(1,1,25,80);

		 textbackground(0);

		 clrscr();

		 textcolor(10);
		gotoxy(21,2);cprintf("<--<--<--<--LINKED LIST MENU-->-->-->-->");
		textcolor(GREEN);
		gotoxy(2,3);cprintf("===============================================================================");
		textcolor(YELLOW);
		gotoxy(20,3);cprintf("+============________________===========+");
		textcolor(11);
		gotoxy(10,5);cprintf("INSERT_NODE");
		gotoxy(36,5);cprintf("DELET_NODE");
		gotoxy(60,5);cprintf("OTHER OPRATION");
		gotoxy(6,6);cprintf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
		textcolor(WHITE);
		for(i=1; i<=9; i++)
		{
			gotoxy(4,3+i);cprintf("|");
			gotoxy(29,3+i);cprintf("|");
			gotoxy(54,3+i);cprintf("|");
			gotoxy(78,3+i);cprintf("|");
		}
		gotoxy(6,7);cprintf("1) CREATE()");
		gotoxy(6,8);cprintf("2) INSERT_LAST()");
		gotoxy(6,9);cprintf("3) INSERT_FIRST()");
		gotoxy(6,10);cprintf("4) INSERT_AFTER()");
		gotoxy(6,11);cprintf("5) INSERT_BEFORE()");
		gotoxy(31,7);cprintf("6) DELETE_FIRST()");
		gotoxy(31,8);cprintf("7) DELETE_LAST()");
		gotoxy(31,9);cprintf("8) DELETE_ANY()");
		gotoxy(31,10);cprintf("C) DELETE_ALL_NODE_()");
		textcolor(RED);
		gotoxy(57,7);cprintf("#) EXIT()");
		textcolor(WHITE);
		gotoxy(57,8); cprintf("0) DISPALY_IN_TEXT");
		gotoxy(57,9); cprintf("D) DISPALY_IN_GRAPHIC");
		gotoxy(57,10);cprintf("9) UPDATE()");
		gotoxy(57,11);cprintf("A) SORT_DATA()");
		gotoxy(57,12);cprintf("B) SEARCH_POSITION()");

		textcolor(12);
		gotoxy(1,13);cprintf("________________________________________________________________________________");
		gotoxy(1,14);cprintf("********************************************************************************");
		textcolor(13);
		gotoxy(33,14);cprintf("[ CHOICE :- ]");
		gotoxy(44,14);
}

//============================================================================//

void main()
{
	char ch;
	while(1)
	{
		DManu();

		ch=getch();
		gotoxy(1,16);
		switch(ch)
		{
			case '#': exit();
			case '0': DisplayG(); getch(); closegraph();break;
			case 'd':
			case 'D': Display(); getch(); break;

			case '1': textcolor(GREEN); gotoxy(6,7); cprintf("1) CREATE()");       textcolor(WHITE);gotoxy(44,14); Create(); 					break;
			case '2': textcolor(GREEN); gotoxy(6,8); cprintf("2) INSERT_LAST()");  textcolor(WHITE);gotoxy(44,14);InsertLast(); 				break;
			case '3': textcolor(GREEN); gotoxy(6,9); cprintf("3) INSERT_FIRST()"); textcolor(WHITE);gotoxy(44,14);InsertFirst();        	break;
			case '4': textcolor(GREEN); gotoxy(6,10);cprintf("4) INSERT_AFTER()"); textcolor(WHITE);gotoxy(44,14);InsertAfter();				break;
			case '5': textcolor(GREEN); gotoxy(6,11);cprintf("5) INSERT_BEFORE()");textcolor(WHITE);gotoxy(44,14);InsertBefore();			break;
			case '6': textcolor(GREEN); gotoxy(31,7);cprintf("6) DELETE_FIRST()"); textcolor(WHITE);gotoxy(44,14);DeleteFirst();	 getch();break;
			case '7': textcolor(GREEN); gotoxy(31,8);cprintf("7) DELETE_LAST()");  textcolor(WHITE);gotoxy(44,14);DeleteLast(); 	 getch();break;
			case '8': textcolor(GREEN); gotoxy(31,9);cprintf("8) DELETE_ANY()");	  textcolor(WHITE);gotoxy(44,14);DeletAny();					break;
			case '9': textcolor(GREEN); gotoxy(57,9);cprintf("9) UPDATE()");	     textcolor(WHITE);gotoxy(44,14);Update(); 					break;
			case 'a': case 'A':textcolor(GREEN); gotoxy(57,10);cprintf("A) ShortData()");textcolor(WHITE);gotoxy(44,14);ShortData();getch();	break;
			case 'b': case 'B':textcolor(GREEN); gotoxy(57,11);cprintf("B) Search_Position()");textcolor(WHITE);gotoxy(44,14); SearchPosition();getch();	break;
			case 'c': case 'C':textcolor(GREEN);gotoxy(31,10);cprintf("C) DELETE_ALL_NODE_()");textcolor(WHITE); DELETE_ALL_NODE_(); break;
		}
	}
}
/*
		 -->	THIS PROJECT CRETED BY SHAILESH MAKAVANA.
		 ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
		 -->  STARTING DATE IS 5/8/2023
		 -->  ENDING DATE IS 15/8/2023

	______CONTACT US________
	  search the web.
			-> https://github.com/shailesh-04
*/