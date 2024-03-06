#include <stdio.h>
#define limit 5
void cqinsert (int n);
int cqdelete (void);
int que[limit],f= -1,r= -1,data,ch;
main()
{

	clrscr();

	while(1)
	{
	printf("\n\nCIRCULAR QUEUE STUDY MENU");
	printf("\n1 : Insert data");
	printf("\n2 : Dlete data");
	printf("\n3 : Exit");

	printf("\n\nEnter choice : ");
	scanf("%d",&ch);


		switch (ch)
		{
		case 1 : printf("\nEnter data to insert in Queue: ");
			 scanf("%d",&data);
			 cqinsert(data);
			 break;

		case 2 : data =  cqdelete();
			 if (data != 0)
				printf("\nData = %d",data);
			 break;

		case 3 : exit(0);


		}
	}

}

void cqinsert (int n)
{
	if (r == limit-1)
	{
		r = 0;

	}

	else
		r++;

	if(f == r)
	{
		printf("Overflow...");
		r--;

		if (r == -1)
			r = limit-1;
		return;
	}


	que[r] = n;

	if (f == -1)
	{
		f = 0;
	}

}

int cqdelete (void)
{

	int a;

	if (f == -1)
	{
		printf("\nUnderflow...");
		return(0);
	}

	a = que[f];

	if(f == r)
	{
		f = r = -1;
		return(a);
	}
	if(f == limit - 1)
	{
		f = 0;
	}
	else
	{
		f++;
	}
	return(a);

}


