#include <stdio.h>
#include <stdlib.h>

int absol(int* p);
int main(int argc, char const *argv[])
{
	int n;
	if (argc != 2) {fprintf(stderr, "\n\n\tNB: ./main n\n\n");}
  	n  = atoi(argv[1]);

  	printf("\n\tIl valore assoluto di %d è %d\n\n", n, absol(&n));
	return 0;
}