#include <stdio.h>
int evenOdd(int);

int main(void)
{
	int number;
	printf("This program will discern whether the given number is even or odd.\n");
	printf("Please write a number to check.\n");
	scanf("%d", &number);
	evenOdd(number);
	return 0;
}

int evenOdd(int num)
{
	if(num % 2 == 0)
	{
		printf("Even.\n");
	}
	else
	{
		printf("Odd.\n");
	}
	return num;
}
