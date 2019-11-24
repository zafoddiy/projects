#include <stdio.h>

int main(void)
{
	int endTime, startTime, dayTime, dayNum, hourWage, dayWage, monthWage;
	char query;
	printf("Hello, this will calculate your daily and monthly income.\n");
	do
	{
		printf("Please insert your work start time.\n");
		scanf("%d", &startTime);
		printf("Now please insert your work end time.\n");
		scanf("%d", &endTime);
		dayTime = endTime - startTime;
		printf("Please specify the number of days you work in a month.\n");
		scanf("%d", &dayNum);
		printf("Lastly, specify your hourly wage.\n");
		scanf("%d", &hourWage);
		if(startTime < 0 || startTime > 24 || endTime < 0 || endTime > 24 || dayNum < 0 || dayNum > 31 || hourWage < 0 || dayTime < 0)
		{
			printf("One or more values are not realistic!\n");
		}
		else
		{
			dayWage = dayTime * hourWage;
			monthWage = dayWage * dayNum;
			printf("Daily wage is %d, monthly wage is %d.\n", dayWage, monthWage);
		}
		printf("Do you want to try again?(y/n)\n");
		scanf("%s", &query);
		while(query != 'y' && query != 'n')
		{
			printf("Please write y or n!\n");
			scanf("%s", &query);
		}
	}
	while(query == 'y');
	return 0;
}