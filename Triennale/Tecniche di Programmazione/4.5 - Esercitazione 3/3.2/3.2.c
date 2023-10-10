#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
int main() {

int *min;
min = (int*) malloc(2*sizeof(int));
*(min+1) = INT_MAX;

printf("\n");

do {
	do {
		printf("\tInserire intero positivo (0 per terminare): ");
		scanf("%d", min);
		if(*min < 0) printf("\n\tValore non valido.\n");
	} while(*min < 0);

	if(*min != 0 && *(min+1) > *min) *(min+1) = *min;

} while(*min != 0);

printf("\n\n\tIl minimo valore inserito è %d.\n\n", *(min+1));

free(min);

return 0;
}