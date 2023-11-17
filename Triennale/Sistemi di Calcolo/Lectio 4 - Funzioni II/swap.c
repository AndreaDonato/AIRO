#include <stdio.h>

void swap(char* x, char* y);

int main(int argc, char const *argv[])
{
	char a = 'A', b = 'B';
	swap(&a, &b);
	printf("\n\ta = %c, b = %c\n", a, b);
	return 0;
}