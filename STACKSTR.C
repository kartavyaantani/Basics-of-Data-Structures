/*read 1 string from keyboard and reverse it using string*/
#include <stdio.h>
#define limit 25
void push(int n);
int pop(void);
int stack[limit],data,tos = -1;
main()
{
	char s[limit];
	int length,i;

	clrscr();

	printf("\nEnter 1 string : ");
	gets(s);

	length = strlen(s);

	for (i = 0 ; i < length ; i++)
	{
		push(s[i]);
	}
	for(i = 0 ; i < length ; i++)
	{
		printf("%c",pop());
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
