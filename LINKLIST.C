#include <stdio.h>
void insert(int data);
void display();
void before_insert (int data , int tmpdata);
void after_insert (int data , int tmpdata);
void delete (int data);

	struct node
	{
		int info;
		struct node *next;
	};
	struct node *head = NULL,*tmp = NULL,*tmp1 = NULL , *prev = NULL;

	int ch, data , tmpdata;

main()
{

	clrscr();

	while(1)
	{
		printf("\n\n\nSimple Link list study>>>>>>>>>>>>>>>");
		printf("\n1:Insert Data at the end ");
		printf("\n2:Insert Data Before");
		printf("\n3:Insert Data After");
		printf("\n4:Delete Data ");
		printf("\n5:Display Data ");
		printf("\n6:Exit");
		printf("\n\nEnter choice:  ");
		scanf("%d",&ch);

		switch (ch)
		{
			case 1 : printf("\nEnter data : ");
				 scanf("%d",&data);
				 insert(data);
				 break;

			case 2 : display();
				 printf("\nEnter data  : ");
				 scanf("%d",&data);
				 printf("\nBefore which data :  ");
				 scanf("%d",&tmpdata);
				 before_insert(data , tmpdata);
				 break;

			case 3 : display();
				 printf("\nEnter data :  ");
				 scanf("%d",&data);
				 printf("\nAfter which data :  ");
				 scanf("%d",&tmpdata);
				 after_insert(data,tmpdata);
				 break;

			case 4 : printf("Enter data to delete : ");
				 scanf("%d",&data);
				 delete(data);
				 break;

			case 5 : display();
				 break;

			case 6 : free(head);
				 free(tmp);
				 free(tmp1);
				 free(prev);
				 exit (0);
				 break;

			default: printf("\nInvalid Choice...");
				 break;

		}

	}
}

void insert(int data)
{
	if(head == NULL)
	{
		head  = (struct node *) malloc(sizeof(struct node));
		head->info = data;
		head->next = NULL;
	}
	else
	{
		tmp = head;
		while(tmp->next != NULL)
		{
			tmp = tmp->next;
		}
		tmp->next = (struct node *) malloc(sizeof(struct node));
		tmp = tmp->next;
		tmp->info = data;
		tmp->next = NULL;
	}
	printf("\nData Inserted");


	return;
}
void display()
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

void before_insert (int data , int tmpdata)
{
	if(head == NULL)
	{
		printf("List is empty...");
		return;
	}
	if(head->info == tmpdata)
	{
		tmp = (struct node *)  malloc(sizeof(struct node));
		tmp->next = head;
		head  = tmp;
		head->info = data;
		return;
	}
	tmp = head->next;
	prev = head;
	while(1)
	{
		if(tmp->info != tmpdata)
		{
			prev = tmp;
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
			prev->next = tmp1;
			tmp1->next = tmp;
			return;
		}

	}
}

void delete (int data)
{
	if (head->info == data)
	{
		head = head->next;
		display();
		printf("Deletion successful...");
		return;
	}

	tmp = head->next;
	prev = head;
	while(tmp != NULL)
	{
		if (tmp->info != data)
		{
			prev = tmp;
			tmp = tmp->next;
			continue;
		}

		prev->next = tmp->next;
		printf("Deletion successful...");
		display();
		return;
	}
	printf("Invalid data....");
	return;
}

void after_insert(data,tmpdata)
{
	if(head == NULL)
	{
		printf("List is empty...");
		return;
	}
	if(head->info == tmpdata)
	{
		tmp = (struct node *)  malloc(sizeof(struct node));
		tmp->info = data;
		tmp->next = head->next;
		head->next = tmp;
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
				printf("\nNode does not exist.");
				return;
			}

			continue ;
		}


		{
			tmp1 = (struct node *) malloc(sizeof(struct node));
			tmp1->info = data;
			tmp1->next = tmp->next;
			tmp->next = tmp1;
			return;
		}

	}
}