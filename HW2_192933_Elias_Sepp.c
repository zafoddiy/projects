/**
 * File:        HW2_192933_Elias_Sepp.c
 * Author:      Elias Sepp
 * Created:     15.11.2019
 * Last Edit:   18.11.2019
 *
 * Description: Reads matrix size and elements, then
 * 				displays the result in a formatted form,
 * 				where column headers are sets and row
 * 				headers are competitors. Also calculates
 * 				the sum for each competitor and searches
 * 				for the best one.
 */
#include <stdio.h>

#define MAX_SIZE 15

int ReadingSize(void);
void ReadingMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void SumCalc(int sum[MAX_SIZE], int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void DisplayMatrix(int sum[MAX_SIZE], int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void BestPerf(int sum[MAX_SIZE], int rows);

int main(void)
{
	
	int sharpShoot[MAX_SIZE][MAX_SIZE] = {{0}};	// initialising matrix with a max size, elements are all initialised to zero
	int sumPoints[MAX_SIZE] = {0};				// initialising array for each competitor's total, elements are all initialised to zero
	int comp, sets;								// initialising matrix number of rows and columns
	puts(">>> Please enter the number of competitors and number of sets.");
	comp = ReadingSize();						// returning ReadingSize return value to comp and sets respectively
	sets = ReadingSize();
	ReadingMatrix(sharpShoot, comp, sets);
	SumCalc(sumPoints, sharpShoot, comp, sets);			// calling functions with given variables within main function
	DisplayMatrix(sumPoints, sharpShoot, comp, sets);
	putchar('\n');
	BestPerf(sumPoints, comp);
	return 0;
}

/**
 * Function:       ReadingSize
 * Description:    Reads the size of the main matrix, does this for
 * 				   rows and columns.
 *
 * Parameters:     None
 *
 * Return:         Integer, the value is returned to row or column size.
 */
int ReadingSize(void)
{
	int num;
	do
	{
		scanf("%d", &num);
		if (num < 2 || num > MAX_SIZE)			// reading one of the sizes of matrix
		{										// prints an error and repeats the loop
			puts(">>> Error! Invalid size!");		// if the value is not between the limits
		}
	}
	while (num < 2 || num > MAX_SIZE);
	return num;									// returning the read value num
}

/**
 * Function:       ReadingMatrix
 * Description:    Reads matrix elements.
 *
 * Parameters:     matrix[MAX_SIZE][MAX_SIZE] - integer, two-dimensional array with max size of MAX_SIZE
 * 						for both rows and columns
 *				   rows - number of rows in the matrix
 * 				   cols - number of columns in the matrix
 * Return:         None
 */
void ReadingMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
	puts(">>> Enter the amount of points each competitor got for each set.");
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)		// initialising a nested loop
		{
			scanf("%d", &matrix[i][j]);	// reads into element on row i and column j
		}
	}
}

/**
 * Function:       SumCalc
 * Description:    Calculates the sum of all elements in one row of matrix.
 * 				   Saves the value into a position within one-dimensional array.
 *
 * Parameters:     sum[MAX_SIZE] - integer, one-dimensional array that houses the sum of each row within main matrix
 * 				   matrix[MAX_SIZE][MAX_SIZE] - integer, primary two-dimensional array with max size of MAX_SIZE
 * 						for both rows and columns
 *				   rows - number of rows in the matrix
 * 				   cols - number of columns in the matrix
 * Return:         None
 */
void SumCalc(int sum[MAX_SIZE], int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)	// initialising nested loop to sum each column in a row
		{
			sum[i] += matrix[i][j]; // summing each element in a row to one position in array sum
		}
	}
}

/**
 * Function:       DisplayMatrix
 * Description:    Displays all the matrix elements. Formats the column and row headers.
 * 				   Also displays the sum of each row at the end of them.
 *
 * Parameters:     sum[MAX_SIZE] - integer, one-dimensional array that houses the sum of each row within main matrix
 * 				   matrix[MAX_SIZE][MAX_SIZE] - integer, two-dimensional array with max size of MAX_SIZE
 * 						for both rows and columns
 *				   rows - number of rows in the matrix
 * 				   cols - number of columns in the matrix
 * Return:         None
 */
void DisplayMatrix(int sum[MAX_SIZE], int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols)
{
	int i, j;
	printf("Scoreboard\n");
	printf("%11s", " ");					// adding 11 empty spaces at the start for better formatting
	for (i = 0; i < cols; i++)
	{
		printf("S%02d  ", i + 1);			// printing out the column headers, empty spaces between character and number are replaced with 0
	}
	printf("%2sSUM\n", " ");
	for (i = 0; i < rows; i++)
	{
		printf("SHOOTER%02d  ", i + 1);		// printing out row headers, empty spaces between the word and number are replaced with 0
		for (j = 0; j < cols; j++)
		{
			printf("%3d  ", matrix[i][j]);	// printing out matrix elements, giving 3 spaces for each
		}
		printf("  %3d\n", sum[i]);			// printing out the sum of each row at the end of each row
	}
}

/**
 * Function:       BestPerf
 * Description:    Finds and displays the overall best performer.
 *
 * Parameters:     sum[MAX_SIZE] - integer, one-dimensional array that houses the sum of each row within main matrix
 *				   rows - number of rows in the matrix
 * Return:         None
 */
void BestPerf(int sum[MAX_SIZE], int rows)
{
	int i = 1;
	int k = 1;				// initialising k to be the index of the best performer, 
							// making assumption that the 1st is the best before the search
	int best = sum[0];		// initialising best to be the 1st element in array sum
	while (i < rows)
	{
		if (best < sum[i])	// finding values that are higher than the previous best
		{
			best = sum[i];
			k = i + 1;		// if the condition holds true, k increments by one
		}
		i++;
	}
	printf("Most accurate: SHOOTER%02d", k);	// printing out the found competitor
}
