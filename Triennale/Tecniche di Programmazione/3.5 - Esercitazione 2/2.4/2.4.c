#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
	
int i, flag = 1;
long l;
long long test;

printf("\n\n\tRisultato con libreria <limiths.h>:\n\tint:\t%d;\n\tlong:\t%ld.", INT_MAX, LONG_MAX);

i = (int) pow(2, CHAR_BIT*sizeof(int));
l = (long) pow(2, CHAR_BIT*sizeof(long int));

printf("\n\n\tRisultato con calcolo esplicito:\n\tint:\t%d;\n\tlong:\t%ld.\n\n", i-1, l-1);

return(0);
}

