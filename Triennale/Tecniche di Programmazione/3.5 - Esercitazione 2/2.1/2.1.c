#include <stdio.h>
#include <math.h>

int main() {
	char c;
	short s;	// Si intende short int
	int i;
	long l;		// Si intende long int
	float f;
	double d;

	printf("\n\n\tDimensioni in byte per tipo di variabile.\n\n\tchar:\t%lu;\n\tshort:\t%lu;\n\tint:\t%lu;\n\tlong:\t%lu;\n\tfloat:\t%lu;\n\tdouble:\t%lu.\n\n", sizeof(c), sizeof(s), sizeof(i), sizeof(l), sizeof(f), sizeof(d));

return(0);
}