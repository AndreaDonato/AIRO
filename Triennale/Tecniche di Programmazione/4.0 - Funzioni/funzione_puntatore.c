#include <stdio.h>
#include <stdlib.h>

double *puntatore (double a) {
	double *r = (double*) malloc(sizeof(double));
	*r = a;
	return r ;
	}

int main () {

double *pd = puntatore(5.4);
printf("\n\n\tpd = %p", pd);
printf("\n\t*pd = %f\n\n", *pd);
return 0;
}