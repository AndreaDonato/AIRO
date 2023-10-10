#include <stdio.h>
#include <math.h>

int main() {

	int a, b, mcd;

	printf("\n\tInserire i due numeri interi positivi di cui si vuole conoscere il Massimo Comune Divisore: ");
	scanf("%d%d", &a, &b);

	if (a == b) mcd = a;
	else mcd = floor((a > b)? ((a/2.>b)? b : a/2.) : ((b/2.>a)? a : b/2.));		// Massimo valore possibile per l'MCD, ovvero il minimo tra il numero minore e la metà del numero maggiore.
																				// Forse si poteva fare più semplice ma volevo provare le espressioni condizionali.
	while (a%mcd || b%mcd) mcd--;

	printf("\n\tIl Massimo Comune Divisore tra %d e %d è %3\n", a, b, mcd);		// Scrivendo %3d imporrei di usare 3 spazi per scrivere il numero. Se devo scrivere 7 avrei "  7" (utile nelle tabelle).
	if (mcd == 1) printf("\t%d e %d sono pertanto detti coprimi.\n", a, b);
	else if (mcd == a) printf("\tTi faccio notare che hai inserito due volte lo stesso numero, potevi arrivarci da solo.\n");
	printf("\n");
}
