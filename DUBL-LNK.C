#include <stdio.h>
void insert(int data);
void display_forwd();
void display_backwd();
void before_insert (int data , int tmpdata);
void after_insert (int data , int tmpdata);
void delete (int data);

	struct node
	{
		struct node *prev;
		int info;
		struct node *next;
	};
	struct node *head = NULL , *prev1 = NULL ;
	struct node *tail = NULL , *tmp = NULL , *tmp1 = NULL , *tmp2 = NULL;

	int ch, data , tmpdata;

main()
{

	clrscr();

	while(1)
	{
		printf("\nDouble Link list study>>>>>>>>>>>>>>>");
		printf("\n1:Insert Data at the end ");
		printf("\n2:Insert Data Before");
		printf("\n3:Insert Data After");
		printf("\n4:Delete Data ");
		printf("\n5:Display Data Foreward ");
		printf("\n6:Display Data Backward ");
		printf("\n7:Exit");
		printf("\n\nEnter choice:  ");
		scanf("%d",&ch);

		switch (ch)
		{
			case 1 : printf("\nEnter data : ");
				 scanf("%d",&data);
				 insert(data);
				 break;

			case 2 : display_forwd();
				 printf("\nEnter data  : ");
				 scanf("%d",&data);
				 printf("\nBefore which data :  ");
				 scanf("%d",&tmpdata);
				 before_insert(data , tmpdata);
				 break;

			case 3 : display_forwd();
				 printf("\nEnter data  : ");
				 scanf("%d",&data);
				 printf("\nAfter which data :  ");
				 scanf("%d",&tmpdata);
				 after_insert(data , tmpdata);
				 break;

			case 4 : printf("Enter data to delete : ");
				 scanf("%d",&data);
				 delete(data);
				 break;

			case 5 : display_forwd();
				 break;

			case 6 : display_backwd();
				 break;

			case 7 : free(head);
				 free(tmp);
				 free(tmp1);
				 free(prev1);
				 exit (0);
				 break;

			default: printf("\nInvalid Choice...");
				 break;

		}

	}
}

void insert(int data)
{
	if(head == NULL && tail == NULL)
	{
		head  = tail = (struct node *) malloc(sizeof(struct node));
		head->info = data;
		head->next = NULL;
		head->prev = NULL;
	}
	else
	{
		tmp = head;
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = (struct node *) malloc(sizeof(struct node));
		tmp1 = tmp;
		tmp = tmp->next;
		tmp->info = data;
		tmp->prev = tmp1;
		tmp->next = NULL;
		tail = tmp;
	}
	printf("\nData Inserted");

	return;
}

void display_forwd()
{
	if(head == NULL)
	{
		printf("\n\nEmpty list.....");
	}
	else
	{
		tmp = head;
		while(tmp != NULL)
		{
			printf("\nData = %d",tmp->info);
			tmp = tmp->next;
		}
	}
	return;
}

void display_backwd()
{
	if(head == NULL)
	{
		printf("\n\nEmpty list.....");
	}
	else
	{
		tmp = tail;
		while(tmp != NULL)
		{
			printf("\nData = %d",tmp->info);
			tmp = tmp->prev;
		}
	}
	return;
}

void before_insert (int data , int tmpdata)
{
	if(head == NULL )
	{
		printf("List is empty...");
		return;
	}
	if(head->info == tmpdata && head->next == NULL)
	{
		tmp = (struct node *)  malloc(sizeof(struct node));
		tmp->next = head;
		head->prev = tmp;
		tmp->prev = NULL;
		head  = tmp;
		head->info = data;
		tail = tmp;
		return;
	}
	tmp = head->next;
	prev1 = head;
	while(1)
	{
		if(tmp->info != tmpdata)
		{
			prev1 = tmp;
			tmp = tmp->next;
			if (tmp == NULL )
			{
				printf("Not valid...");
				return;
			}

			continue ;
		}


		{
			tmp1 = (struct node *) malloc(sizeof(struct node));
			tmp1->info = data;
			prev1->next = tmp1;
			tmp1->next = tmp;
			tmp->prev = tmp1;
			tmp1->prev = prev1;
			return;
		}

	}
}

void after_insert(int data , int tmpdata)
{
	if(head == NULL)
	{
		printf("List is empty...");
		return;
	}
	if(head->info == tmpdata && head->next == NULL)
	{
		tmp = (struct node *)  malloc(sizeof(struct node));
		tmp1 = head->next;
		head->next = tmp;
		tmp->info = data;
		tmp->next = tmp1;
		tmp->prev = head;
		tail = tmp;
		return;
	}

	tmp = head->next;
	while(1)
	{
		if(tmp->info != tmpdata)
			{
			tmp = tmp->next;
			if (tmp == NULL )
			{
				printf("Not valid...");
				return;
			}

			continue ;
		}


		{
			tmp1 = (struct node *) malloc(sizeof(struct node));
			tmp1->info = data;
			if(tmp->next == NULL) //last node
			{
				tmp1->next = NULL;
				tmp1->prev = tmp;
				tmp->next = tmp1;
				tail = tmp1;
			}
			else   //not last, middle
			{
				tmp1->next = tmp->next;
				tmp->next = tmp1;
				tmp1->prev = tmp;
				(tmp1->next)->prev = tmp1;
			}

			return;
		}

	}

}


void delete (int data)
{
	if(head == NULL)
	{
		printf("\nEmpty list. ");
		return;
	}
	if (head->info == data && head->next == NULL)
	{
		head = tail = NULL;
		printf("Deletion successful...");
		return;
	}
	if(head->info == data && head->next==tail)
	{
		head=head->next;
		tail->prev = NULL;
		return;
	}

	tmp = head->next;
	prev1 = head;
	while(tmp != NULL)
	{
		if (tmp->info != data)
		{
			prev1 = tmp;
			tmp = tmp->next;
			continue;
		}

		if(tmp->next == NULL)
		{
		     tail = tmp->prev;
		     tail->next = NULL;

		}
		else
		{
			prev1->next = tmp->next;
			tmp2 = tmp->next;
			tmp2->prev = tmp->prev;

		}
		return;
	}
	printf("Invalid data....");
	return;
}