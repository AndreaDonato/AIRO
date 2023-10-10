#include <math.h>
#include <stdio.h>
void calcola (double (*f)(double), double primo, double ultimo, double inc);

int main (void) {

double ini, fin ,inc ;
printf("\n\n\tImmetti valori (iniziale, incremento, finale): ");
scanf("%lf%lf%lf", &ini, &inc, &fin);
printf("\n\n\t   x\t     cos(x)" "\n\t   -------   -------\n");
calcola(cos, ini, fin, inc);
printf("\n\n\t   x\t     sin(x)" "\n\t   -------   -------\n");
calcola(sin, ini, fin, inc);
return 0;
}

void calcola(double (*f)(double), double primo, double ultimo, double inc) {

	double x;
	int i, num_intervalli;
	num_intervalli = ceil((ultimo-primo)/inc);

	for(i = 0; i <= num_intervalli; i ++) {
		x = primo + i*inc;
		printf ("\t%10.5f%10.5f\n", x, (*f)(x));
		}
}


