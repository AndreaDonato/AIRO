#include <stdio.h>
int f();

int main(int argc, char const *argv[])
{
	int x = f();
	printf("\n\t%d\n", x);
	return 0;
}