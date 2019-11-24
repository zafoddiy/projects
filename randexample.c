#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_COUNT 5

int main(void)
{
	srand(time(NULL));
	int randNum, i;
	printf("The range of random numbers is: 0 ... %d\n", RAND_MAX);
	
	for (i = 0; i < NUM_COUNT; i++)
	{
		randNum = rand();
		printf("%d\n", randNum);
	}
	return 0;
}
