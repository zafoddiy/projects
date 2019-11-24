#include <stdio.h>
#define LEN 4

int main(void)
{
	int n = LEN, m = LEN;
	int i, j;
	int array[n][m];
	for (i = 0; i < n; i++)
	{
		printf("Row #%d\n", i + 1);
		for (j = 0; j < m; j++)
		{
			printf("Column #%d\n", j + 1);
			scanf("%d", &array[i][j]);
		}
	}
	int sum = 0;
	for (i = 0; i < m; i++)
	{
		if (array[n][i] < 0)
		{
			sum = array[n - 1][i] + sum;
		}
	}
	printf("%d", sum);
	return 0;
}
