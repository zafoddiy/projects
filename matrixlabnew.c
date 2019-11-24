#include <stdio.h>
#define LEN 7

int main()
{
	int i, j;
	int n = LEN, m = LEN;
	int matrix[LEN][LEN];
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < m; j++)
		{
			printf("Enter matrix element [%d][%d]\n", i + 1, j + 1);
			scanf("%d", &matrix[i][j]);
		}
	}
	printf("Entered matrix:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%4d", matrix[i][j]);
		}
		printf("\n\n");
	}
	int negSum = 0;
	i = 0;
	j = 0;
	printf("Here is the sum of the negative numbers on the main diagonal:\n");
	while(i < n)
	{
		if(matrix[i][j] < 0)
		{
			negSum += matrix[i][j];
		}
		i++;
		j++;
	}
	printf("%d\n", negSum);
	int posProd = 1;
	printf("Here is the product of all positive numbers above the main diagonal:\n");
	for(j = 1; j < m; j++)
	{
		for(i = 0; i < j; i++)
		{
			if(matrix[i][j] > 0)
			{
				posProd *= matrix[i][j];
			}
		}
	}
	printf("%d\n", posProd);
	int oddSum = 0;
	printf("Here is the sum of all odd number below the main diagonal:\n");
	for(i = 1; i < n; i++)
	{
		for(j = 0; j < i; j++)
		{
			if(matrix[i][j] % 2 != 0)
			{
				oddSum += matrix[i][j];
			}
		}
	}
	printf("%d\n", oddSum);
	printf("Here is the greatest number on each line:\n");
	int greatNum[n];
	int temp;
	for(i = 0; i < n; i++)
	{
		temp = matrix[i][0];
		for(j = 0; j < m; j++)
		{
			if(matrix[i][j] > temp)
			{
				temp = matrix[i][j];
			}
		}
		greatNum[i] = temp;
		printf("Line %d: %d\n", i + 1, greatNum[i]);
	}
	printf("Here is the sum for each diagonal above the main one:\n");
	int k;
	int length = LEN;
	int diagSum[LEN - 1] = {0, 0, 0, 0, 0, 0};
	for (k = 0; k < 6; k++)
	{
		i = 0;
		j = k + 1;
		while(i < length - k - 1)
		{
			diagSum[k] += matrix[i][j];
			i++;
			j++;
		}
		printf("Diagonal %d: %d\n", k + 1, diagSum[k]);
	}
	return 0;
}
