#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int error_check_operator(char**);
int error_check_values(int, char**);
double calculation(int, char**);
void output_general(char**, int, int, double);

int main(int argc, char **argv)
{
	if (argc == 3 || argc == 4)
	{
		output_general(argv, error_check_values(argc, argv), error_check_operator(argv), calculation(argc, argv));
	}
	else if (argc == 2 && strcmp(argv[1], "--help") == 0)
	{
		puts("You must write two numbers between an operator!");
		puts("Valid operators: '+', '-', '*', '/', 'sqrt/SQRT', '^'");
		puts("Multiplication and exponentiation must be written between double quotation marks!");
		puts("Only write numbers!");
	}
	else
	{
		puts(">>> Invalid amount of arguments! <<<");
		puts("You must write two numbers between an operator!");
        puts("Valid operators: '+', '-', '*', '/', 'sqrt/SQRT', '^'");
        puts("Multiplication and exponentiation must be written between double quotation marks!");
        puts("Only write numbers!");
	}
	return 0;
}

int error_check_values(int count, char **num)
{
	int n = 1;
	int i;
	if (count == 4)
	{
		for (i = 0; i < strlen(num[1]); i++)
		{
			if (((num[1][i] < '0' || num[1][i] > '9') && (num[1][i] !=
			 '.' || strchr(num[1], '-') != strrchr(num[1], '-'))) &&
			  num[1][0] != '-')
			{
				n = 2;
				return n;
			}
		}
		for (i = 0; i < strlen(num[3]); i++)
		{
			if (((num[3][i] < '0' || num[3][i] > '9') && (num[3][i] !=
			 '.' || strchr(num[3], '-') != strrchr(num[3], '-'))) &&
			  num[1][0] != '-')
			{
				n = 2;
				return n;
			}
		}
	}
	else
	{
		for (i = 0; i < strlen(num[2]); i++)
		{
			if (((num[2][i] < '0' || num[2][i] > '9') && (num[2][i] !=
			 '.' || strchr(num[2], '-') != strrchr(num[2], '-')))
			  && num[2][0] != '-')
			{
				n = 2;
				return n;
			}
		}
	}
	return n;
}

int error_check_operator(char **num)
{
	int n = 1;
	if (!((strcmp(num[2], "+") == 0 || strcmp(num[2], "-") == 0 ||
	 strcmp(num[2], "*") == 0 || strcmp(num[2], "/") == 0 ||
	  strcmp(num[2], "^") == 0) || (strcmp(num[1], "sqrt") == 0 ||
	   strcmp(num[1], "SQRT") == 0)))
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
	if (count == 4)
	{
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
		else if (num[2][0] == '^')
		{
			n = pow(a, b);
		}
		return n;
	}
	else
	{
		a = atof(num[2]);
		n = sqrt(a);
		return n;
	}
}

void output_general(char **num, int operandCheck, int operatorCheck, double answer)
{
	
	if (operatorCheck == -2)
	{
		puts(">>> Invalid operator! <<<");
		puts("You must write two numbers between an operator, or sqrt/SQRT 'number'!");
        puts("Valid operators: '+', '-', '*', '/', 'sqrt/SQRT', '^'");
        puts("Multiplication and exponentiation must be written between double quotation marks!");
        puts("Only write numbers!");
	}
	else if (operandCheck == 2)
	{
		puts(">>> Invalid characters for operands! <<<");
		puts("You must write two numbers between an operator!");
        puts("Valid operators: '+', '-', '*', '/', 'sqrt/SQRT', '^'");
        puts("Multiplication and exponentiation must be written between double quotation marks!");
        puts("Only write numbers!");
	}
	else if (answer == INFINITY || answer == -INFINITY)
	{
		puts(">>> Division by zero! <<<");
	}
	else if (atof(num[2]) < 0)
	{
		puts(">>> Complex number! <<<");
	}
	else
	{
		printf("> %lf\n", answer);
	}
}
