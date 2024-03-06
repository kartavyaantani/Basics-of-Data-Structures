#include <stdio.h>
int move;
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
		move++;
		return;
	}
	towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
	printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
	move++;
	towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
	int n;
	printf("Enter no. of rods: ");
	scanf("%d",&n);
	towerOfHanoi(n, 'A', 'C', 'B');
	printf("\n");
	printf("\nNo. of Moves: %d\n",move);
	return 0;
}

