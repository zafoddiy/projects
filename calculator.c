#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int error_check_operator(char**);
int error_check_values(char**);
double calculation(int, char**);
void output(int, int, double);

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		puts(">>>Invalid amount of arguments!");
		puts("You must write two numbers between an operator!");
        puts("Valid operators: '+', '-', '*', '/'");
        puts("Multiplication must be written between double quotation marks!");
        puts("Only write numbers!");
		return 0;
	}
	output(error_check_values(argv), error_check_operator(argv), calculation(argc, argv));
	return 0;
}

int error_check_values(char **num)
{
	int n = 1;
	int i;
	for (i = 0; i < strlen(num[1]); i++)
	{
		if ((num[1][i] < 48 || num[1][i] > 57) && (num[1][i] != '.' || strchr(num[1], 46) != strrchr(num[1], 46)))
		{
			n = 2;
			return n;
		}
	}
	for (i = 0; i < strlen(num[3]); i++)
	{
		if ((num[3][i] < 48 || num[3][i] > 57) && (num[3][i] != '.' || strchr(num[3], 46) != strrchr(num[3], 46)))
		{
			n = 2;
			return n;
		}
	}
	return n;
}

int error_check_operator(char **num)
{
	int n = 1;
	if (!(strcmp(num[2], "+") == 0 || strcmp(num[2], "-") == 0 || strcmp(num[2], "*") == 0 || strcmp(num[2], "/") == 0))
	{
		n = -2;
		return n;
	}
	return n;
}

double calculation(int count, char **num)
{
	double a, b;
	double n;
	a = atof(num[1]);
	b = atof(num[3]);
	if (num[2][0] == '+')
	{
		n = a + b;
	}
	else if (num[2][0] == '-')
	{
		n = a - b;
	}
	else if (num[2][0] == '*')
	{
		n = a * b;
	}
	else if (num[2][0] == '/')
	{
		n = a / b;
	}
	return n;
}

void output(int operandCheck, int operatorCheck, double answer)
{
	
	if (operatorCheck == -2)
	{
		puts(">>>Invalid operator!");
		puts("You must write two numbers between an operator!");
        puts("Valid operators: '+', '-', '*', '/'");
        puts("Multiplication must be written between double quotation marks!");
        puts("Only write numbers!");
	}
	else if (operandCheck == 2)
	{
		puts(">>>Invalid characters for operands!");
		puts("You must write two numbers between an operator!");
        puts("Valid operators: '+', '-', '*', '/'");
        puts("Multiplication must be written between double quotation marks!");
        puts("Only write numbers!");
	}
	else if (answer == INFINITY)
	{
		puts(">>>Division by zero!");
	}
	else
	{
		printf("> %.2lf\n", answer);
	}
}
