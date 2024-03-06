#include<stdio.h>
void main()
{
	int sz;
	int l;
	int el;
	printf("Enter the size \n"); 
		scanf("%d", &sz);
	int arr[sz];
	printf("Enter the elements \n");
	for (l = 0; l < sz; l++)
		scanf("%d", &arr[l]);
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