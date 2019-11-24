#include <stdio.h>

int main(void)
{
	int i, j, sum, k, empty=10;
	sum = 0;
	printf("Pyramid      row  total\n");
	for(i = 0; i < 10; i++)
	{
		for(k = 0; k < empty; k++)
		{
			printf(" ");
		}
		for(j = 0; j <= i; j++)
		{
			printf("#");
		}
		sum = sum + j;
		printf("%4d %6d", j, sum);
		empty--;
		printf("\n");
	}
	return 0;
}