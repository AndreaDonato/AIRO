#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
int main() {

int *min, *n;
n = (int*) malloc(sizeof(int));
min = (int*) malloc(sizeof(int));
*min = INT_MAX;

printf("\n");

do {
	do {
		printf("\tInserire intero positivo (0 per terminare): ");
		scanf("%d", n);
		if(*n < 0) printf("\n\tValore non valido.\n");
	} while(*n < 0);

	if(*n != 0 && *min > *n) *min = *n;

} while(*n != 0);

printf("\n\n\tIl minimo valore inserito è %d.\n\n", *min);

free(min);
free(n);

return 0;
}