#include <stdio.h>

int main(void)
{
	int number;
	char query;
	printf("This program will discern whether the given number is even or odd.\n");
	do
	{
		printf("Please write a number to check.\n");
		scanf("%d", &number);
		if(number % 2 == 0)
		{
			printf("Even.\n");
		}
		else
		{
			printf("Odd.\n");
		}		
		scanf("%c", &query);
		getchar();
		if(query == 'n')
		{
			break;
		}
		else if(query != 'y')
		{
			do
			{
				
				printf("Please write y or n!\n");
				scanf("%c", &query);
				getchar();
			}
			while(query != 'y' && query != 'n');
		}
	}
	while(query == 'y');
	return 0;
}
