#include <stdio.h>

int addition (int, int);
int multiplication (int, int);
int division (int, int);
int input (char[]);
void output (char[], int);

int main(void)
{
	int X, fcontrol, a, b;
	char desc[][10] = {"Addition", "Multiply", "Division"};
	fcontrol = input("Choose operation\n");
	a = input("A:\n"); b = input("B:\n");
	if (fcontrol == 1)
	{
		X = addition(a, b);
	}
	else if (fcontrol == 2)
	{
		X = multiplication(a, b);
	}
	else if (fcontrol == 3)
	{
		X = division(a, b);
	}
	output(desc[fcontrol - 1], X);
	return 0;
}
int input(char text[])
{
	int n;
	printf("%s", text);
	scanf("%d", &n);
	return n;
}
int addition(int a, int b)
{
	int y;
	y = a + b;
	return y;
}
int multiplication(int a, int b)
{
	int y;
	y = a * b;
	return y;
}
int division(int a, int b)
{
	int y;
	y = a / b;
	return y;
}
void output(char description[], int val)
{
	printf("%s result: %d\n", description, val);
}
