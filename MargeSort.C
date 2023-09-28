#include<conio.h>
#include<stdio.h>
void Marge(int arr[],int l,int m,int r)
{
	int i,j,k;
	int n1 = m-l+1,
		n2 = r-m;
	int *L = (int*)malloc(n1 * sizeof(int)),
		*R  = (int*)malloc(n2 * sizeof(int));

	for(i=0; i<n1; i++)
		L[i]=arr[l+i];
	for(j=0; j<n2; j++)
		R[j]=arr[m+1+j];

	for(i=0,j=0,k=l; i<n1 && j<n2; k++)
	{
		if(L[i] <= R[j])
		{
			arr[k] = L[i];
			i++;
		}
		else
		{
			arr[k]= R[j];
			j++;
		}
	}
	while(i<n1)
	{
		arr[k]=L[i];
		i++;
		k++;
	}
	while(j<n2)
	{
		arr[k]=R[j];
		j++;
		k++;
	}

}
void Divide(int arr[],int l,int r)
{
	if(l<r)
	{
		int m = l+(r-l)/2;
		Divide(arr,l,m);
		Divide(arr,m+1,r);
		Marge(arr,l,m,r);
	}

}
void Get_Element(int *arr,int n)
{
	char ch;
	int i;
	printf("\n You Want To Insert Automatic Random Element Press(Y / N)");
	ch = getch();
	printf("[ %c ]\n",ch);
	if(ch == 'y'||ch== 'Y')
	{
		for(i =0; i<n; i++)
		{
			arr[i] = rand() % 100;
			printf("Enter Element Of Arry[%d] :-%d\n",i,arr[i]);
		}
	}
	else
	{
		for(i =0; i<n; i++)
		{
			printf("Enter Element Of Arry[%d] :-",i);
			scanf("%d",&arr[i]);
		}
	}
}
void main()
{
	int *arr;
	int n=0,i;
	clrscr();
	printf("\n How Many Data You Want Inser :-");
	scanf("%d",&n);
	arr = (int*)malloc(n * sizeof(int));// Its's Use To Allocate Dinamacly Memory

	Get_Element(arr,n);

	Divide(arr,0,n-1);

	printf("\n After Marge Sorting\n___________________________\n");
	for(i=0; i<n; i++)
		printf("%d,",arr[i]);
	getch();
}