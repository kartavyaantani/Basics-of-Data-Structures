#include <stdio.h>
#define limit 4
void insert (int n);
int delete (void);
int que[limit],f= -1,r= -1,data,ch;
main()
{

	clrscr();

	while(1)
	{
	printf("\n\nQUEUE STUDY MENU");
	printf("\n1 : Insert data");
	printf("\n2 : Dlete data");
	printf("\n3 : Exit");

	printf("\n\nEnter choice : ");
	scanf("%d",&ch);


		switch (ch)
		{
		case 1 : printf("\nEnter data to insert in Queue: ");
			 scanf("%d",&data);
			 insert(data);
			 break;

		case 2 : data =  delete();
			 if (data != 0)
				printf("\nData = %d",data);
			 break;

		case 3 : exit(0);


		}
	}

}

void insert (int n)
{
	if (r >= limit)
	{
		printf("\nOverflow'-'  ");
	}
	else
	{
		r++;
		que[r] = n;
	}
	if (f == -1)
	{
		f = 0;
	}
	return;

}

int delete (void)
{
	
	int a;	

	if (f == -1)	
	{
		printf("\nUnderflow'-'  ");
		return 0;
	}
	else
	{
		a = que[f];
	}
	
	if (f == r)
	{
		f = r = -1;
	}
	else
	{
		f++;
	}			
		
	return(a);
}
		