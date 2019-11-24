#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 6
#define RAND_COUNT 10

int main(void)
{
	srand(time(NULL));
	int i, num[NUM_COUNT];
	printf("Enter 6 numbers between 1 and 30.\n");
	for (i = 0; i < NUM_COUNT; i++)
	{
		printf("#%d\n", i + 1);
		scanf("%d", &num[i]);
		while (num[i] < 1 || num[i] > 30)
		{
			printf("Error: please write a number between 1 and 30!\n");
			scanf("%d", &num[i]);
		}
	}
	int randNum[RAND_COUNT];
	printf("The random numbers are: \n");
	for (i = 0; i < RAND_COUNT; i++)
	{
		randNum[i] = rand() % 30 + 1;
		printf("%d ", randNum[i]);
	}
	putchar('\n');
	int j;
	int k = 0;
	for (i = 0; i < NUM_COUNT; i++)
	{
		for (j = 0; j < RAND_COUNT; j++)
		{
			if (num[i] == randNum[j])
			{
				printf("The %d. and %d. numbers with value %d matched.\n", i + 1, j + 1, num[i]);
				k++;
				break;
			}
		}
	}
	printf("%d numbers matched.\n", k);
	if (k == 0)
	{
		printf("Unfortunately none of your numbers matched, our condolences.\n");
	}
	else if (k == 6)
	{
		printf("Congratulations! All of your numbers matched!\n");
	}
	return 0;
}
