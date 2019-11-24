#include <stdio.h>

int main(void)
{
	int i, number, sum;
	sum = 0;
	printf("Please insert a number\n");
	for(i = 0; i < 5; i++)
	{
		scanf("%d", &number);
		sum = sum + number;
		printf("Subtotal: %d\n", sum);
	}
	return 0;
}