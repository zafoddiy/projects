#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Write your constants here */
#define LIMIT_ROWS 20
#define LIMIT_COLS 20

/* Write your prototypes here. Some have been made for you. If necessary, modify the existing ones. */
int MenuBasic(void);
int MenuAdv(void);
int MenuMain(void);
int GetIntInRange(int min, int max);
void GenerateMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void DisplayMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void SwitchRows(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void SwitchCols(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void RemoveRow(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void RemoveCol(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void AddRow(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void AddCol(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void ReplaceRow(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void ReplaceCol(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void ReplaceElem(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void MirrorHorizontal(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void MirrorVertical(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);
void TransposeMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols);

int main(void)
{
    int data[LIMIT_ROWS][LIMIT_COLS] = {{0}}; // initialize the matrix to zeros
    int n, m;
    int menuSelectionMain, menuSelectionBasic, menuSelectionAdv;
    srand(time(NULL));
    puts("Enter matrix dimension to generate a matrix.");
    n = GetIntInRange(2, LIMIT_ROWS);
	m = GetIntInRange(2, LIMIT_COLS);
    GenerateMatrix(data, n, m);
    do
    {
		menuSelectionMain = MenuMain();
		switch (menuSelectionMain)
		{
			case 1:
				puts("Case 1: Enter new matrix dimensions and generate matrix");
				n = GetIntInRange(2, LIMIT_ROWS);
				m = GetIntInRange(2, LIMIT_COLS);
				GenerateMatrix(data, n, m);
				break;
			case 2:
				puts("Case 2: Printing matrix");
				DisplayMatrix(data, n, m);
				break;
			case 3:
				puts("Case 3: Basic operations");
				menuSelectionBasic = MenuBasic();
				switch (menuSelectionBasic)
				{
					case 1:
						puts("Case 1: Switching rows");
						SwitchRows(data, n, m);
						break;
					case 2:
						puts("Case 2: Switching columns");
						SwitchCols(data, n, m);
						break;
					case 3:
						puts("Case 3: Removing row");
						RemoveRow(data, n, m);
						n = n - 1;
						break;
					case 4:
						puts("Case 4: Removing column");
						RemoveCol(data, n, m);
						m = m - 1;
						break;
					case 5:
						puts("Case 5: Adding row");
						AddRow(data, n, m);
						n = n + 1;
						break;
					case 6:
						puts("Case 6: Adding column");
						AddCol(data, n, m);
						m = m + 1;
						break;
					case 0:
						puts("Case 0: Going Back");
						break;
					default:
						puts("Case unknown: We didn't understand Your request");
						break;
				}
				break;
			case 4:
				puts("Case 4: Advanced operations");
				menuSelectionAdv = MenuAdv();
				switch (menuSelectionAdv)
				{
					case 1:
						puts("Case 1: Replacing row");
						ReplaceRow(data, n, m);
						break;
					case 2:
						puts("Case 2: Replacing column");
						ReplaceCol(data, n, m);
						break;
					case 3:
						puts("Case 3: Replacing element");
						ReplaceElem(data, n, m);
						break;
					case 4:
						puts("Case 4: Mirroring horizontally");
						MirrorHorizontal(data, n, m);
						break;
					case 5:
						puts("Case 5: Mirroring vertically");
						MirrorVertical(data, n, m);
						break;
					case 6:
						puts("Case 6: Transposing matrix");
						TransposeMatrix(data, n, m);
						int temp;
						temp = n;
						n = m;
						m = temp;
						break;
					case 0:
						puts("Case 0: Going Back");
						break;
					default:
						puts("Case unknown: We didn't understand Your request");
						break;
				}
				break;
			case 0:
				puts("Case 0: Exit");
				break;
			default:
				puts("Case unknown: We didn't understand Your request");
				break;
		}
	}
	while (menuSelectionMain);
    return 0;
}

/**
 * Function:       Menu
 * Description:    Displays the possible menu options to the user,
 *                 allows to select an action to perform.
 *
 * Parameters:     None
 *
 * Return:         Integer, corrensponds to the menu selection from the list
 */
int MenuMain(void)
{
    int selection;
    putchar('\n');
    puts("Select Your action!");
    puts("1 - Generate new matrix");
    puts("2 - Display matrix");
    puts("3 - Basic operations");
    puts("4 - Advanced operations");
    puts("0 - Exit program");
    selection = GetIntInRange(0, 4);
    return selection;
}
int MenuBasic(void)
{
    int selection;
    putchar('\n');
    puts("Select Your action!");
    puts("	1 - Switch rows");
    puts("	2 - Switch columns");
    puts("	3 - Remove row");
    puts("	4 - Remove column");
    puts("	5 - Add row");
    puts("	6 - Add column");
    puts("	0 - Go back");
    selection = GetIntInRange(0, 6);
    return selection;
}
int MenuAdv(void)
{
    int selection;
    putchar('\n');
    puts("Select Your action!");
    puts("	1 - Replace row");
    puts("	2 - Replace column");
    puts("	3 - Replace element");
    puts("	4 - Mirror horizontally");
    puts("	5 - Mirror vertically");
    puts("	6 - Transpose matrix");
    puts("	0 - Go back");
    selection = GetIntInRange(0, 6);
    return selection;
}
/**
 * Function:       GetIntInRange
 *
 * Description:    Asks the user for an integer in between the given limits.
 *                 Repeats until requirements are met and then returns the number.
 *
 * Parameters:     min - integer, lower limit for the user input (inclusive)
 *                 max - integer, upper limit for the user input (inclusive)
 *
 * Return:         Integer, number within the specified limits
 */
int GetIntInRange(int min, int max)
{
    int num;
    do
    {
        printf("> ");
        scanf("%d", &num);
        if (num < min || num > max)
            printf("\nRetry! Input must be in between %d and %d\n", min, max);
    }
    while (num < min || num > max);
    return num;
}
/**
 * Function:       GenerateMatrix
 *
 * Description:    Generates a matrix with size that is inputted by the user.
 *
 * Parameters:     matrix[LIMIT_ROWS][LIMIT_COLS] - integer, matrix with max rows of LIMIT_ROWS and max columns of LIMIT_COLS
 *                 rows - integer, number of rows in the matrix
 * 				   cols - integer, number of columns in the matrix
 *
 * Return:         No return value
 */
void GenerateMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, j;
	i = 0;
	do
	{
		j = 0;
		do
		{
			matrix[i][j] = rand() % 100 + 1;
			j++;
		}
		while (j < cols);
		i++;
	}
	while (i < rows);
}
/**
 * Function:       DisplayMatrix
 *
 * Description:    Displays the last generated matrix.
 *
 * Parameters:     matrix[LIMIT_ROWS][LIMIT_COLS] - integer, matrix with max rows of LIMIT_ROWS and max columns of LIMIT_COLS
 *                 rows - integer, number of rows in the matrix
 * 				   cols - integer, number of columns in the matrix
 *
 * Return:         No return value
 */
void DisplayMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, j;
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j < cols)
		{
			printf("%3d ", matrix[i][j]);
			j++;
		}
		i++;
		putchar('\n');
	}
}
/**
 * Function:       SwitchRows
 *
 * Description:    Swaps 2 rows of the matrix, rows are specified by user.
 *
 * Parameters:     matrix[LIMIT_ROWS][LIMIT_COLS] - integer, matrix with max rows of LIMIT_ROWS and max columns of LIMIT_COLS
 *                 rows - integer, number of rows in the matrix
 * 				   cols - integer, number of columns in the matrix
 *
 * Return:         No return value
 */
void SwitchRows(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, temp, a, b;
	puts("Insert rows to swap!");
	a = GetIntInRange(1, rows) - 1;
	b = GetIntInRange(1, rows) - 1;
	for (i = 0; i < cols; i++)
	{
		temp = matrix[a][i];
		matrix[a][i] = matrix[b][i];
		matrix[b][i] = temp;
	}
}
/**
 * Function:       SwitchCols
 *
 * Description:    Swaps 2 columns of the matrix, columns are specified by user.
 *
 * Parameters:     matrix[LIMIT_ROWS][LIMIT_COLS] - integer, matrix with max rows of LIMIT_ROWS and max columns of LIMIT_COLS
 *                 rows - integer, number of rows in the matrix
 * 				   cols - integer, number of columns in the matrix
 *
 * Return:         No return value
 */
void SwitchCols(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, temp, a, b;
	puts("Insert columns to swap!");
	a = GetIntInRange(1, cols) - 1;
	b = GetIntInRange(1, cols) - 1;
	for (i = 0; i < rows; i++)
	{
		temp = matrix[i][a];
		matrix[i][a] = matrix[i][b];
		matrix[i][b] = temp;
	}
}
void RemoveRow(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, j, num;
	puts("Insert row to remove.");
	num = GetIntInRange(1, rows) - 1;
	for (i = num; i < rows - 1; i++)
	{
		for (j = 0; j < cols; j++)
		{
			matrix[i][j] = matrix[i + 1][j];
		}
	}
}
void RemoveCol(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, j, num;
	puts("Insert column to remove.");
	num = GetIntInRange(1, cols) - 1;
	for (j = num; j < cols - 1; j++)
	{
		for (i = 0; i < rows; i++)
		{
			matrix[i][j] = matrix[i][j + 1];
		}
	}
}
void AddRow(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, j, num;
	puts("Insert the position where you want your new row to be in.");
	num = GetIntInRange(1, rows) - 1;
	for (i = rows; i > num; i--)
	{
		for (j = 0; j < cols; j++)
		{
			matrix[i][j] = matrix[i - 1][j];
		}
	}
	i = 0;
	do
	{
		matrix[num][i] = rand() % 100 + 1;
		i++;
	}
	while (i < cols);
}
void AddCol(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, j, num;
	puts("Insert the position where you want your new column to be in.");
	num = GetIntInRange(1, cols) - 1;
	for (i = cols; i > num; i--)
	{
		for (j = 0; j < rows; j++)
		{
			matrix[j][i] = matrix[j][i - 1];
		}
	}
	i = 0;
	do
	{
		matrix[i][num] = rand() % 100 + 1;
		i++;
	}
	while (i < rows);
}
void ReplaceRow(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, num;
	puts("Insert the row you want to replace.");
	num = GetIntInRange(1, rows) - 1;
	for (i = 0; i < cols; i++)
	{
		matrix[num][i] = rand() % 100 + 1;
	}
}
void ReplaceCol(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, num;
	puts("Insert the column you want to replace.");
	num = GetIntInRange(1, cols) - 1;
	for (i = 0; i < rows; i++)
	{
		matrix[i][num] = rand() % 100 + 1;
	}
}
void ReplaceElem(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int a, b;
	puts("Insert the (1) row and (2) column of the element you want to replace.");
	a = GetIntInRange(1, rows) - 1;
	b = GetIntInRange(1, cols) - 1;
	matrix[a][b] = rand() % 100 + 1;
}
void MirrorHorizontal(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, j;
	int temp[rows / 2][cols];
	for (i = 0; i < rows / 2; i++)
	{
		for (j = 0; j < cols; j++)
		{
			temp[i][j] = matrix[i][j];
			matrix[i][j] = matrix[rows - 1 - i][j];
		}
	}
	for (i = 0; i < rows / 2; i++)
	{
		for (j = 0; j < cols; j++)
		{
			matrix[rows - 1 - i][j] = temp[i][j];
		}
	}
}
void MirrorVertical(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, j;
	int temp[rows][cols / 2];
	for (i = 0; i < cols / 2; i++)
	{
		for (j = 0; j < rows; j++)
		{
			temp[j][i] = matrix[j][i];
			matrix[j][i] = matrix[j][cols - 1 - i];
		}
	}
	for (i = 0; i < cols / 2; i++)
	{
		for (j = 0; j < rows; j++)
		{
			matrix[j][cols - 1 - i] = temp[j][i];
		}
	}
}
void TransposeMatrix(int matrix[LIMIT_ROWS][LIMIT_COLS], int rows, int cols)
{
	int i, j;
	int temp[cols][rows];
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			temp[j][i] = matrix[i][j];
		}
	}
	for (i = 0; i < cols; i++)
	{
		for (j = 0; j < rows; j++)
		{
			matrix[i][j] = temp[i][j];
		}
	}
}
