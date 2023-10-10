#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int main() {

int N, *interi;

printf("\n\n\tInserire il numero di interi da allocare: ");
scanf("%d", &N);
interi = (int*) malloc(N*sizeof(int));
*(interi+1) = 42; // Giusto per capire se funziona o spara zeri a caso
printf("\n\n\tIndirizzo\tValore in memoria\n");
for(int i = 0; i < N; i++) {
	printf("\n\t%p\t%d", interi+i, *(interi+i));
}
printf("\n\n");
free(interi);
}