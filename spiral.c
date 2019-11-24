#include <stdio.h>
#include <string.h>

#define	UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define MAX_SIZE 13

int get_size(char*);
void selection(char*);
void generate_spiral_num(int, int(*)[]);
void generate_spiral_char(int, char(*)[]);
void output_num(int, int(*)[]);
void output_char(int, char(*)[]);

int main(void)
{
	int size;
	char select[8];
	selection(select);
	if (strcmp(select, "numbers") == 0)
	{
		size = get_size(select);
		int matrix[MAX_SIZE][MAX_SIZE] = {{0}};
		generate_spiral_num(size, matrix);
		output_num(size, matrix);
	}
	else
	{
		size = get_size(select);
		char matrix[MAX_SIZE][MAX_SIZE] = 
   {{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'},
	{'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'}};
		generate_spiral_char(size, matrix);
		output_char(size, matrix);
	}
	return 0;
}

int get_size(char choice[8])
{
	int n;
	puts("Enter a dimension of matrix to generate a square matrix.");
	do
	{
		scanf("%d", &n);
		if (n < 2 || n > MAX_SIZE)
		{
			puts("Error! Enter a valid size for matrix (between 2 and " 
			"13)!");
		}
		else if (n > 5 && strcmp(choice, "numbers") == 0)
		{
			puts("Error! Max size of numbers is 5!");
		}
	}
	while ((n < 2 || n > MAX_SIZE) || (n > 5 && strcmp(choice,
	 "numbers") == 0));
	return n;
}

void selection(char choice[7])
{
	puts("Enter 'letters' or 'numbers'");
	do
	{
		scanf("%s", choice);
		if (strcmp(choice, "letters") != 0 &&
		 strcmp(choice, "numbers") != 0)
		{
			puts("Error! Enter a valid option!");
		}
	}
	while (strcmp(choice, "letters") != 0 &&
		 strcmp(choice, "numbers") != 0);
}

void generate_spiral_num(int n, int (*mat)[MAX_SIZE])
{
	printf("\n\n");
	int direction = UP;
	int i, j;
	int x = 1;
	int row_right  = 0, column_down = n-1, row_left = n-1,
	 column_up = 0;
	while (x != (n + n))
	{
		if (direction == UP)
		{
			i = row_right++;
			for (j = 0; j < n; j++)
			{
				if (mat[i][j] == 0)
				{
					mat[i][j] = x;
				}
			}
			x++;
			direction = RIGHT;
		}
		else if (direction == RIGHT)
		{
			j = column_down--;
			for (i = 0; i < n; i++)
			{
				if (mat[i][j] == 0)
				{
					mat[i][j] = x;
				}
			}
			x++;
			direction = DOWN;
		}
		else if (direction == DOWN)
		{
			i = row_left--;
			for (j = n - 1; j >= 0; j--)
			{
				if (mat[i][j] == 0)
				{
					mat[i][j] = x;
				}
			}
			x++;
			direction = LEFT;
		}
		else
		{
			j = column_up++;
			for (i = n - 1; i >= 0; i--)
			{
				if (mat[i][j] == 0)
				{
					mat[i][j] = x;
				}
			}
			x++;
			direction = UP;
		}
	}
}

void generate_spiral_char(int n, char (*mat)[MAX_SIZE])
{
	printf("\n\n");
	int direction = UP;
	int i, j;
	char y = 'A';
	int row_right  = 0, column_down = n-1, row_left = n-1,
	 column_up = 0;
	while (y < 'Z')
	{
		if (direction == UP)
		{
			i = row_right++;
			for (j = 0; j < n; j++)
			{
				if (mat[i][j] == '0')
				{
					mat[i][j] = y;
				}
			}
			y++;
			direction = RIGHT;
		}
		else if (direction == RIGHT)
		{
			j = column_down--;
			for (i = 0; i < n; i++)
			{
				if (mat[i][j] == '0')
				{
					mat[i][j] = y;
				}
			}
			y++;
			direction = DOWN;
		}
		else if (direction == DOWN)
		{
			i = row_left--;
			for (j = n - 1; j >= 0; j--)
			{
				if (mat[i][j] == '0')
				{
					mat[i][j] = y;
				}
			}
			y++;
			direction = LEFT;
		}
		else
		{
			j = column_up++;
			for (i = n - 1; i >= 0; i--)
			{
				if (mat[i][j] == '0')
				{
					mat[i][j] = y;
				}
			}
			y++;
			direction = UP;
		}
	}
}

void output_num(int n, int (*mat)[MAX_SIZE])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%2d ", mat[i][j]);
		}
		putchar('\n');
	}
}

void output_char(int n, char (*mat)[MAX_SIZE])
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%2c ", mat[i][j]);
		}
		putchar('\n');
	}
}
