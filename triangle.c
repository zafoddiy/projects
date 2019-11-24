#include <stdio.h>
#include <math.h>

#define MAX_ROWS 3
#define MAX_COLS 2

void input(int, int, float[MAX_ROWS][MAX_COLS]);
void output(int, int, float[MAX_ROWS][MAX_COLS], double[MAX_ROWS]);
void distance(int, float[MAX_ROWS][MAX_COLS], double[MAX_ROWS]);
int error_check(double[MAX_ROWS]);
double area(double*);

int main(void)
{
	float coord[MAX_ROWS][MAX_COLS];
	input(MAX_ROWS, MAX_COLS, coord);
	double length[MAX_ROWS];
	distance(MAX_ROWS, coord, length);
	output(MAX_ROWS, MAX_COLS, coord, length);
	return 0;
}

void input(int n, int m, float arr[MAX_ROWS][MAX_COLS])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			scanf("%f", &arr[i][j]);
		}
	}
}

void output(int n, int m, float arr[MAX_ROWS][MAX_COLS], double len[MAX_ROWS])
{
	int i, j;
	printf("%2c %2c\n", 'X', 'Y');
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			printf("%.2f ", arr[i][j]);
		}
		putchar('\n');
	}
	if (error_check(len) == -1)
	{
		puts("You cannot make a triangle with these coordinate values!");
	}
	else
	{
		puts("Your triangle's sides' lengths:");
		for (i = 0; i < n; i++)
		{
			printf("%.2lf ", len[i]);
		}
		putchar('\n');
		printf("The area of your triangle is %.2lf\n", area(len));
	}
}

void distance(int n, float arr[MAX_ROWS][MAX_COLS], double vector[MAX_ROWS])
{
	int i;
	int xCoord, yCoord;
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			xCoord = arr[0][0] - arr[2][0];
			yCoord = arr[0][1] - arr[2][1];
			vector[i] = sqrt(pow(xCoord, 2) + pow(yCoord, 2));
		}
		else
		{
			xCoord = arr[i][0] - arr[i - 1][0];
			yCoord = arr[i][1] - arr[i - 1][1];
			vector[i] = sqrt(pow(xCoord, 2) + pow(yCoord, 2));
		}
	}
}

int error_check(double *vector)
{
	int n = 1;
	double answer;
	for (int i = 0; i < MAX_ROWS; i++)
	{
		if (vector[i] <= 0)
		{
			n = -1;
			return n;
		}
	}
	answer = acos((pow(vector[2], 2) + pow(vector[0], 2) - pow(vector[1], 2)) / (2 * vector[2] * vector[0]));
	if (answer <= 0 || answer >= M_PI)
	{
		n = -1;
		return n;
	}
	answer = acos((pow(vector[0], 2) + pow(vector[1], 2) - pow(vector[2], 2)) / (2 * vector[0] * vector[1]));
	if (answer <= 0 || answer >= M_PI)
	{
		n = -1;
		return n;
	}
	answer = acos((pow(vector[1], 2) + pow(vector[2], 2) - pow(vector[0], 2)) / (2 * vector[1] * vector[2]));
	if (answer <= 0 || answer >= M_PI)
	{
		n = -1;
		return n;
	}
	return n;
}

double area(double vector[MAX_ROWS])
{
	double answer;
	double partPerimeter;
	partPerimeter = (vector[0] + vector[1] + vector[2]) / 2;
	answer = sqrt(partPerimeter * (partPerimeter - vector[0]) * (partPerimeter - vector[1]) * (partPerimeter - vector[2]));
	return answer;
}
