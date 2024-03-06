#include <stdio.h>
#define limit 4

void push(int n);
int pop(void);
void peep(int n);

int stack[5],data,tos = -1,loc,n;

main()
{

	clrscr();
	while(1)
	{
	printf("\n\nSTACK STUDY MENU");
	printf("\n1 : Push data");
	printf("\n2 : Pop  data");
	printf("\n3 : Peep data");
	printf("\n4 : Exit");

	printf("\n\nEnter choice : ");
	scanf("%d",&n);


		switch (n)
		{
		case 1 : printf("\nEnter data to push in stack.: ");
			 scanf("%d",&data);
			 push(data);
			 break;

		case 2 : data =  pop();
			 if (data != 0)
				printf("\nData = %d",data);
			 break;

		case 3 : printf("\nEnter location : ");
			 scanf("%d",&loc);
			 peep(loc) ;
			 break;

		case 4 : exit(0);


		}
	}

}

void push (int n)
{
	if(tos == limit)
	{
		printf("\nOverflow....");

	}
	else
	{
		tos++;
		stack[tos] = n;
	}

	return;

}

int pop ()
{
	int a;
	if (tos == -1)
	{
		printf("\nUnderflow....");
		return(0);
	}
	else
	{
		a = stack[tos];
		tos-- ;
		return(a);
	}
}

void peep (int n)
{
	if (loc < 0 || loc > tos)
	{
		printf("\nNot Available :");
	}
	else
	{
		printf("\nLocation data = %d on location %d",stack[loc],loc);
	}
	return;
}
