/**
 * File:        HW1_192933_Elias_Sepp.c
 * Author:      Elias Sepp
 * Created:     26.02.2020
 * Last edit:   07.03.2019
 *
 * Description: Reads products from an input file and saves them 
 * 				into a structure. Compares price points and stock 
 * 				with the user inputted amount of money.
 */

#include <stdio.h>
#include <stdlib.h>
#include "HW1_Elias_Sepp_192933MVEB.h" // header file which contains define macros,
					  // structs and function prototypes

int main(void)
{
	FILE *fOutput = fopen(OUTPUT_FILE, "w");
	if (fOutput == NULL)
	{
		puts("Error opening output file, exiting.");
		fputs("Error opening output file, exiting.\n", fOutput);
		exit(-2);
	}
	product prod[DATA_SIZE];
	// return the read amount of products from input file
	int readSize = Read_File(DATA_SIZE, STRING_LEN, prod, fOutput);
	if (readSize == 0)
	{
		puts("No data was read, exiting!");
		fputs("No data was read, exiting!\n", fOutput);
		exit(0);
	}
	Print_Products(readSize, prod, fOutput);
	float userMoney = Read_Money(fOutput);
	Find_Products(readSize, userMoney, prod, fOutput);
	fclose(fOutput);
	return 0;
}

/**
 * Function:       Read_File
 *
 * Description:    Reads each line and saves the data into a structure array.
 *
 * Parameters:     limit - Integer, the maximum amount of data that can be read
 * 					as defined in the header file.
 * 				   prod - Structure defined as 'product', contains the read
 * 					data from the input file.
 * 				   fo - FILE, pointer to the output file.
 *
 * Return:         Integer, the read amount of products.
 */
int Read_File(int dataLimit, int strLimit, product *prod, FILE *fo)
{
	FILE *fi = fopen(INPUT_FILE, "r"); // open file with mode "read"
	if (fi == NULL)		// check whether the file was opened or not
	{
		puts("Error opening the input file, exiting.");
		fputs("Error opening the input file, exiting.\n", fo);
		exit(-1);
	}
	char tempString[strLimit];
	int i = 0;
	int check;
	while (fgets(tempString, strLimit, fi) != NULL)
	{
		// convert the line saved into tempString into 
		// 4 seperate elements in prod structure
		check = Convert_String(i, tempString, prod);
		if (check != FIELD_SIZE)
		{
			printf("Line %d does not have enough elements or "
				"has invalid element type(s),"
				"forcing reading to stop!\n", i + 1);
			fprintf(fo, "Line %d does not have enough elements or "
				"has invalid element type(s),"
				"forcing reading to stop!\n", i + 1);
			break;
		}
		Negative_Check(i, prod);
		Normalize_String(i, prod);
		++i;
		if (i >= dataLimit)	// stop reading data if the amount 
			break;		// exceeds the predefined structure array size
	}
	fclose(fi);		// close the input file at the end
	return i;
}

/**
 * Function:       Convert_String
 *
 * Description:    Converts a line read into a temporary string array by fgets
 * 					into 4 different elements and saves them into structure.
 *
 * Parameters:     i - Integer, the current increment of structure array.
 * 				   tempString - String, contains the current read line from
 * 					input file by fgets function.
 * 				   prod - Structure defined as 'product', contains the read
 * 					data from the input file.
 *
 * Return:         None
 */
int Convert_String(int i, char tempString[STRING_LEN], product *prod)
{
	return sscanf(tempString, "%ld %s %f %d", 
		&(prod + i)->code, (prod + i)->name, 
		&(prod + i)->price, &(prod + i)->stock);
}

/**
 * Function:       Read_Money
 *
 * Description:    Reads user input for money within given limits.
 *
 * Parameters:     fo - FILE, pointer to the output file.
 *
 * Return:         Float, money to be compared with the data.
 */
float Read_Money(FILE *fo)
{
	float query;
	puts("Enter the amount of money you have.");
	fputs("Enter the amount of money you have.\n", fo);
	do
	{
		scanf("%f", &query);
		// reading user input of money amount, cannot be negative
		if (query < MIN)
		{
			printf("ERROR: Enter a value greater than %d!\n", MIN);
			fprintf(fo, "ERROR: Enter a value greater than %d!\n", MIN);
		}
	}
	while (query < MIN);
	printf(">>>  %.2f$ inputted.\n", query);
	fprintf(fo, ">>>  %.2f$ inputted\n", query);
	return query;
}

/**
 * Function:       Print_Products
 *
 * Description:    Prints out the read data with the correct formatting.
 *
 * Parameters:     dataSize - Integer, the read amount of data
 * 					from the input file.
 * 				   prod - Structure defined as 'product', contains the read
 * 					data from the input file.
 * 				   fo - FILE, pointer to the output file.
 *
 * Return:         None
 */
void Print_Products(int dataSize, product *prod, FILE *fo)
{
	int i;
	for (i = 0; i < dataSize; ++i)
	{
		printf(">>>  %ld - %s, price: %.2f$, stock: %d units\n", 
			(prod + i)->code, (prod + i)->name, // print out data saved
			(prod + i)->price, (prod + i)->stock); // into struct, formatted
		fprintf(fo, ">>>  %ld - %s, price: %.2f$, stock: %d units\n", 
			(prod + i)->code, (prod + i)->name, // same but print in output file
			(prod + i)->price, (prod + i)->stock);
	}
}

/**
 * Function:       Find_Products
 *
 * Description:    Compares each products prices with the inserted user money.
 * 					Also takes into account the stock available.
 *
 * Parameters:     dataSize - Integer, the read amount of data
 * 					from the input file.
 * 				   insertMoney - Float, user inputted amount of money.
 * 				   prod - Structure defined as 'product', contains the read
 * 					data from the input file.
 * 				   fo - FILE, pointer to the output file.
 *
 * Return:         None
 */
void Find_Products(int dataSize, float insertMoney, product *prod, FILE *fo)
{
	int i, j;
	for (i = 0; i < dataSize; ++i)
	{
		// do the following condition if the product of
		// stock and price is less than or equal to the inputted money amount
		if ((prod + i)->price * (prod + i)->stock <= insertMoney)
		{
			printf("<<<  Product %ld - %s is fully purchasable.\n", 
				(prod + i)->code, (prod + i)->name);
			fprintf(fo, "<<<  Product %ld - %s is fully purchasable.\n", 
				(prod + i)->code, (prod + i)->name);
		}
		// if the price of 1 unit is less
		// than or equal to inputted money
		else if ((prod + i)->price <= insertMoney)
		{
			// call a seperate function to count amount
			// of stock purchasable with given amount of money
			j = Partial_Purchase(i, insertMoney, prod);
			// prints out that product is partially purchasable
			// and also how much of it
			printf("<<<  Product %ld - %s is partially purchasable." 
				" %d units can be purchased.\n", 
				(prod + i)->code, (prod + i)->name, j);
			fprintf(fo, "<<<  Product %ld - %s is partially purchasable." 
				" %d units can be purchased.\n", 
				(prod + i)->code, (prod + i)->name, j);
		}
		else
		{
			printf("<<<  Product %ld - %s is not affordable.\n", 
				(prod + i)->code, (prod + i)->name);
			fprintf(fo, "<<<  Product %ld - %s is not affordable.\n", 
				(prod + i)->code, (prod + i)->name);
		}
	}
}

/**
 * Function:       Partial_Purchase
 *
 * Description:    Finds how many units of a product can be purchased if
 * 					there isn't enough money to buy all.
 *
 * Parameters:     i - Integer, the current increment of structure array.
 * 				   insertMoney - Float, user inputted amount of money.
 * 				   prod - Structure defined as 'product', contains the read
 * 					data from the input file.
 *
 * Return:         None
 */
int Partial_Purchase(int i, float insertMoney, product *prod)
{
	// initialise sum that is to be compared with user input and the price tag
	float sum = (prod + i)->price;
	// amount of stock that will be purchasable
	int j = 0;
	// loop while sum is less than or equal to user input
	while (sum <= insertMoney)
	{
		// will keep adding price tag and
		// incrementing stock until condition is met
		sum += (prod + i)->price;
		++j;
	}
	return j;
}

/**
 * Function:       Negative_Check
 *
 * Description:    Checks whether numeric values were negative. If so,
 * 					turns them positive.
 *
 * Parameters:     i - Integer, the current increment of the array.
 * 				   prod - Structure defined as 'product', contains the read
 * 					data from the input file.
 *
 * Return:         None
 */
void Negative_Check(int i, product *prod)
{
	if ((prod + i)->code < 0)
		(prod + i)->code *= -1;
	if ((prod + i)->price < 0)
		(prod + i)->price *= -1;
	if ((prod + i)->stock < 0)
		(prod + i)->stock *= -1;
}

/**
 * Function:       Normalize_String
 *
 * Description:    Checks each letter to make sure it is in the proper case.
 * 					If it isn't, changes it to the correct one.
 *
 * Parameters:     i - Integer, the current increment of the array.
 * 				   prod - Structure defined as 'product', contains the read
 * 					data from the input file.
 *
 * Return:         None
 */
void Normalize_String(int i, product *prod)
{
	// checks if first element of string is lower case, changes to upper if so
	if (*(prod + i)->name >= LOWER_MIN && *(prod + i)->name <= LOWER_MAX)
	{
		*(prod + i)->name -= CASE_DIFF;
	}
	// checks the letters afterwards if they're upper case, 
	// if so, swaps to lower case
	for (int j = 1; j < sizeof((prod + i)->name) - 1; ++j)
	{
		if (prod[i].name[j] >= UPPER_MIN && prod[i].name[j] <= UPPER_MAX)
			prod[i].name[j] += CASE_DIFF;
	}
}
