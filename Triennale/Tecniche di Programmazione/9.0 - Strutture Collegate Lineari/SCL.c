#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

typedef int TipoInfoSCL;
struct ElemSCL
{
	TipoInfoSCL info;
	struct ElemSCL *next;
};
typedef struct ElemSCL TipoNodoSCL;
typedef TipoNodoSCL* TipoSCL;
										
void addSCL(TipoSCL *scl, TipoInfoSCL e) 					
{
	printf("\n\tIndirizzo della variabile puntatore scl:\t\t%p", &scl); sleep(1);
	printf("\n\tIndirizzo puntato dalla variabile puntatore scl: \t%p\n", scl); sleep(1);

	TipoSCL temp = *scl;
	*scl = (TipoNodoSCL*) malloc(sizeof(TipoNodoSCL));
	(*scl)->info = e;
	(*scl)->next = temp;
}

int main(int argc, char const *argv[])
{
	TipoSCL scl = (TipoNodoSCL*) malloc(sizeof(TipoNodoSCL));	// Ricordiamo che TipoNodoSCL* == TipoSCL.
	scl->info = 1;												// Assegno il valore di a al campo info.
	scl->next = NULL;											// Al momento non c'è un modo successivo.
	
	printf("\n\tIndirizzo della variabile puntatore scl:\t\t%p", &scl); sleep(1);
	printf("\n\tIndirizzo puntato dalla variabile puntatore scl: \t%p\n", scl); sleep(1);

	addSCL(&scl, 2);

	printf("\n\tIndirizzo della variabile puntatore scl:\t\t%p", &scl); sleep(1);
	printf("\n\tIndirizzo puntato dalla variabile puntatore scl: \t%p\n", scl); sleep(1);

	return 0;
}