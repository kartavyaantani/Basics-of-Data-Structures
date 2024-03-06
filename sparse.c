//Check whether the given matrix is sparse matrix or not using functions.
#include<stdio.h>
void main()
{
	int sz;
	int l,j;
	int el;
	printf("Enter the row \n"); 
		scanf("%d", &l);
	printf("Enter the column \n"); 
		scanf("%d", &j);
	int arr[l,j];
	printf("Enter the elements \n");
	for (l = 0; l < sz; l++)
		for(j = 0; j <sz)
		scanf("%d", &arr[l,j]);
	printf("Enter the element to search \n"); 
		scanf("%d", &el);
int i;
for (i=0;i<sz;i++)
{	
	if (arr[i] == el)
		{printf("Element found at location %d\n",i);
		break;}
	else
		printf("Element not found\n");
}

}