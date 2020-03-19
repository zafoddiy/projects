/**
 * File:        generator_base.c
 * Author:      Risto Heinsar
 * Created:     12.03.2015
 * Modified     21.10.2019
 *
 * Description: Base code to get you started on the generator task
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "generator_base.h" /* this is where you get your names from*/

int main(void)
{
	srand(time(NULL));
    int firstNamePoolSize, lastNamePoolSize, curriculumCodePoolSize;
    char *firstNames[] = FIRST_NAME_POOL;
    char *lastNames[] = LAST_NAME_POOL;
    char *curriculumCodes[] = CURRICULUM_CODES;


    // Find the counts for the pool sizes, these numbers may differ!
    // Size of the pointer array divided by the size of a single pointer.
    firstNamePoolSize = sizeof(firstNames) / sizeof(char*);
    lastNamePoolSize = sizeof(lastNames) / sizeof(char*);
    curriculumCodePoolSize = sizeof(curriculumCodes) / sizeof(char*);

    printf("The database contains:\n"
           "\t%4d first names\n"
           "\t%4d last names\n"
           "\t%4d curriculum codes\n",
           firstNamePoolSize, lastNamePoolSize, curriculumCodePoolSize);


    // ask the user for how many elements are needed and assign memory to them
	int userInput = GetElem();
	data *admissions = (data*)malloc(sizeof(data) * userInput);
	if (admissions == NULL)
	{
		puts("Error allocating memory to admissions structure, exiting!");
		exit(2);
	}
    // start your generation code here
    int i;
	for (i = 0; i < userInput; ++i)
	{
		Assignment(admissions, i, firstNamePoolSize, lastNamePoolSize, 
			curriculumCodePoolSize, firstNames, lastNames, curriculumCodes);
	}
    // and then output it to the destination file
	FILE *fo = fopen("malloc_dest.txt", "w");
	if (fo == NULL)
	{
		puts("Error opening output file, exiting!");
		exit(-1);
	}
	for (i = 0; i < userInput; ++i)
	{
		printf("%d %s %s %s %.1f\n", (admissions + i)->index, 
			(admissions + i)->fName, (admissions + i)->lName, 
			(admissions + i)->code, (admissions + i)->admPoints);
		fprintf(fo, "%d %s %s %s %.1f\n", (admissions + i)->index, 
			(admissions + i)->fName, (admissions + i)->lName, 
			(admissions + i)->code, (admissions + i)->admPoints);
	}
    // When done, free everything you allocated memory for!
	fclose(fo);
	for (i = 0; i < userInput; ++i)
	{
		free((admissions + i)->fName);
		free((admissions + i)->lName);
		free((admissions + i)->code);
	}
	free(admissions);
    return EXIT_SUCCESS;
}

/**
 * Description:    Generates a random number in range provided, ends inclusive
 *
 * Parameters:     numMin, integer, minimum value
 *                 numMax, integer, maximum vale
 *
 * Return:         integer, generated random number
 */
int GetRand(int numMin, int numMax)
{
    return (rand() % (numMax - numMin + 1)) + numMin;
}

int GetElem(void)
{
	int num;
	do
	{
		scanf("%d", &num);
		if (num <= 0 || num >= LIMIT)
			puts("Enter a valid amount of elements!");
	}
	while (num <= 0 || num >= LIMIT);
	return num;
}

float GetFloatRand(int numMin, int numMax)
{
	float num;
	do
	{
		const int multiplier = GetRand(10, 30);
		num = (float)rand()/(float)RAND_MAX * multiplier;
	}
	while (num < numMin || num > numMax);
	return num;
}

void Assignment(data *admissions, int i, int firstNamePoolSize, 
int lastNamePoolSize, int curriculumCodePoolSize, 
char *firstNames[], char *lastNames[], char *curriculumCodes[])
{
	int randIncrement;
	(admissions + i)->index = i + 1;
	randIncrement = GetRand(0, firstNamePoolSize - 1);
	// allocate memory for string
	(admissions + i)->fName = (char*)malloc(sizeof(char) * 
		(strlen(*(firstNames + randIncrement)) + 1));
	if ((admissions + i)->fName == NULL)
	{
		printf("Error allocating memory for first name with index %d, exiting!",
			i + 1);
		exit(3);
	}
	strcpy((admissions + i)->fName, *(firstNames + randIncrement));
	randIncrement = GetRand(0, lastNamePoolSize - 1);
	// allocate memory for string
	(admissions + i)->lName = (char*)malloc(sizeof(char) * 
		(strlen(*(lastNames + randIncrement)) + 1));
	if ((admissions + i)->lName == NULL)
	{
		printf("Error allocating memory for last name with index %d, exiting!", 
			i + 1);
		exit(3);
	}
	strcpy((admissions + i)->lName, *(lastNames + randIncrement));
	randIncrement = GetRand(0, curriculumCodePoolSize - 1);
	// allocate memory for string
	(admissions + i)->code = (char*)malloc(sizeof(char) * 
		(strlen(*(curriculumCodes + randIncrement)) + 1));
	if ((admissions + i)->code == NULL)
	{
		printf("Error allocating memory for first name with index %d, exiting!",
			i + 1);
		exit(3);
	}
	strcpy((admissions + i)->code, *(curriculumCodes + randIncrement));
	(admissions + i)->admPoints = GetFloatRand(10, 30);
}

int Generate_eID(
