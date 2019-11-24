#include <stdio.h>
int matrixSize(char[]);
int matrixElem(int, int, int[*][*]);
int sorting(int, int, int[*], int[*][*]);
void output(char[], int, int, int[*]);

int main(void)
{
	int n, m;
	n = matrixSize("Enter number of rows:\n");
	m = matrixSize("Enter number of columns:\n");
	int M[n][m];
	matrixElem(n, m, M);
	int min[m];
	sorting(n, m, min, M);
	output("lowest value per row.", n, m, min);
	return 0;
}
int matrixSize(char text[])
{
	int n;
	printf("%s", text);
	scanf("%d", &n);
	while (n <= 2 || n >= 15)
	{
		printf("Error: please write a value between 3 and 14!\n");
		scanf("%d", &n);
	}
	return n;
}
int matrixElem(int n, int m, int M[n][m])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("Row #%d\n", i + 1);
		for (j = 0; j < m; j++)
		{
			printf("Column #%d\n", j + 1);
			scanf("%d", &M[i][j]);
		}
	}
	return M[n][m];
}
int sorting(int n, int m, int min[m], int M[n][m])
{
	int i, j;
	for (j = 0; j < m; j++)
	{
		min[j] = M[0][j];
		for (i = 1; i < n; i++)
		{
			if (min[j] > M[i][j])
			{
				min[j] = M[i][j];
			}
		}
	}
	return min[m];
}
void output(char text[], int n, int m, int min[n])
{
	int i;
	printf("Printing %s\n", text);
	for (i = 0; i < m; i++)
	{
		printf("%5d", min[i]);
	}
}
