/**
 * File:        HW1_192933_Elias_Sepp.c
 * Author:      Elias Sepp
 * Created:     22.09.2019
 * Last edit:   06.10.2019
 *
 * Description: Prints out X and Y values for given function,
 *              using user inputs for certain values as basis.
 */
 
#include <stdio.h>
#include <math.h>	// including the standard math library to perform mathematical calculations
#define MAX_ELEM 15	// defining MAX_ELEM to be 15 for the number of array elements

int main()
{
	int stepNum, i;													// initialising variables and setting the number of elements in arrays
    float startVal, stepVal, xArray[MAX_ELEM], yArray[MAX_ELEM];	// setting N and i as integers as otherwise it would allow float values for N and i, which goes against the task
    printf("Enter the starting value.\n");
    scanf("%f", &startVal);
    printf("Enter the step value. (greater than 0)\n");
	scanf("%f", &stepVal);
    while (stepVal <= 0)
    {
        printf("Error: please enter a value greater than 0.\n");	// checks if the inserted step value is less than or equal to 0
        scanf("%f", &stepVal);										// if so, keeps printing an error message and asking to insert
    }																// a value that is greater than 0
	printf("Enter the number of steps you want to have.\n");
	scanf("%d", &stepNum);
	while (stepNum < 1 || stepNum > 15)
	{
		printf("Error: please enter a value between 1 and 15.\n");	// similar to the step value - checks whether step number is less than 1
        scanf("%d", &stepNum);										// or greater than 15 - will break out of loop if it's between 1 and 15
	}
	printf("The results are:\n");
	printf("%10s %10s\n", "X", "f(X)");
    for (i = 0; i < stepNum; i++)									// initialises a loop that begins from 0 and increments by one
    {																// breaks the loop once the condition i < stepNum is not met
        xArray[i] = startVal + i * stepVal;
		printf("%10.2f ", xArray[i]);								// saving calculated X value into array and printing it out under the X column, formatting a table for f(X) values
		if (xArray[i] == 0)
		{
			printf("%10s\n", "missing");							// by observing the function, we can eliminate unnecessary computation
		}															// by doing a check whether the x values inside the function are possible
		else if (xArray[i] < 0)										// if the values yield an impossibility(division by zero) or a complex number
		{															// then we print 'missing' or 'complex' under the f(X) column
			printf("%10s\n", "complex");
		}
		else
		{
			yArray[i] = pow(xArray[i], 2) + xArray[i] / 2 - 
			sqrt(1 / (2 * xArray[i]));								// if calculations are possible or output real numbers, then we can let
			printf("%10.2f\n", yArray[i]);							// the program calculate the function value and print it out under the f(X) column
		}
    }
    return 0;
}