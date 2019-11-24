#include <stdio.h>

int main(void)
{
	int *p;
	int n = 5;
	int b = 3;
	p = &n;
	p = &b;
	printf("%p\n", &n);
	printf("%p\n", p);
	printf("%d\n", *p);
    return 0;
}

