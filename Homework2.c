#include <stdio.h>

#define MAX_SIZE 15

int ReadingSize(void);
void ReadingMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void SumCalc(int sum[MAX_SIZE], int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void DisplayMatrix(int sum[MAX_SIZE], int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void BestPerf(int sum[MAX_SIZE], int rows);

int main(void)
{
	
	int sharpShoot[MAX_SIZE][MAX_SIZE] = {{0}};
	int comp, sets;
	puts("Please enter the number of competitors and number of sets.");
	comp = ReadingSize();
	sets = ReadingSize();
	ReadingMatrix(sharpShoot, comp, sets);
	int sumPoints[MAX_SIZE] = {0};
	SumCalc(sumPoints, sharpShoot, comp, sets);
	DisplayMatrix(sumPoints, sharpShoot, comp, sets);
	putchar('\n');
	BestPerf(sumPoints, comp);
	return 0;
}

int ReadingSize(void)
{
	int num;
	do
	{
		scanf("%d", &num);
		if (num < 2 || num > MAX_SIZE)
		{
			puts("Error! Invalid size!");
		}
	}
	while (num < 2 || num > MAX_SIZE);
	return num;
}

void ReadingMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
	puts("Enter the amount of points each competitor got for each set.");
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}
}

void SumCalc(int sum[MAX_SIZE], int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		sum[i] = 0;
		for (j = 0; j < cols; j++)
		{
			sum[i] += matrix[i][j];
		}
	}
}

void DisplayMatrix(int sum[MAX_SIZE], int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
	int i;
	printf("Scoreboard\n");
	printf("%11s", " ");
	for (i = 0; i < cols; i++)
	{
		printf("S%02d  ", i + 1);
	}
	printf("%2sSUM\n", " ");
	int j;
	for (i = 0; i < rows; i++)
	{
		printf("SHOOTER%02d  ", i + 1);
		for (j = 0; j < cols; j++)
		{
			printf("%3d  ", matrix[i][j]);
		}
		printf("  %3d\n", sum[i]);
	}
}

void BestPerf(int sum[MAX_SIZE], int rows)
{
	int i = 1;
	int k = 1;
	int best = sum[0];
	while (i < rows - 1)
	{
		if (best < sum[i])
		{
			best = sum[i];
			k = i + 1;
		}
		i++;
	}
	printf("Most accurate: SHOOTER%02d", k);
}
