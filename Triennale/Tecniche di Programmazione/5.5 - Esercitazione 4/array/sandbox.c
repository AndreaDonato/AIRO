#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "veclib.h"
#include <unistd.h>

void random_array(int v[], int dim, int max_value);
void print_vector(double v[], int dim);
int* numeri_unici(const int array[], int dim, int* output_dim);

int main(int argc, char const *argv[])
{
	//4.1
	int len = 10, *int_vector, max = 50;
	int_vector = (int*) malloc(len*sizeof(int));
	random_array(int_vector, len, max);

	//4.4
	int *unici, *unici_dim;
	unici_dim = (int*) calloc(1, sizeof(int));
	printf("\n\n\tHO DEFINITO UN PUNTATORE A INT CHIAMATO UNICI_DIM E GLI HO ASSEGNATO ESPLICITAMENTE UN INT IN MEMORIA HEAP CON UNA CALLOC, VADO A DORMIRE..."); fflush(stdout);
	sleep(1);
	unici = numeri_unici(int_vector, len, unici_dim);
	printf("\n\n\tHO ESEGUITO SENZA ERRORI NUMERI_UNICI ASSEGNANDONE IL RISULTATO AL PUNTATORE UNICI. UNICI_DIM VALE %d, VADO A DORMIRE...", *unici_dim); fflush(stdout);
	sleep(1);
	print_vector(vector_cast_int_to_double(unici, *unici_dim), *unici_dim);
	free(int_vector);
	free(unici);
	return 0;
}

void random_array(int v[], int dim, int max_value)
{
	printf("\n\n");
	srand(time(NULL)); 					// Questa cosa randomizza bene solo se faccio meno di una esecuzione al secondo!
	
	for(int i = 0; i < dim; i++)
	{
		v[i] = rand()%(max_value+1);
		printf("\tv[%d] = %d", i, v[i]);
	}
	printf("\n\n");
}

void print_vector(double v[], int dim)
{
	printf("\n\n");
	for(int i = 0; i < dim; i++)
	{
		printf("\tv[%d] = %.1lf", i, v[i]);
	}
	printf("\n\n");
}


int* numeri_unici(const int array[], int dim, int* output_dim)
{
	int *p;
	p = (int*) calloc(dim, sizeof(int));
	//printf("\n\n\tHO ALLOCATO UN ARRAY PER P IN MEMORIA HEAP, VADO A DORMIRE..."); fflush(stdout);
	//sleep(1);
	//p[0] = 1;
	//printf("\n\n\tHO ASSEGNATO P[0]=ARRAY[0], VADO A DORMIRE..."); fflush(stdout);
	//sleep(1);
	//*output_dim++;

	for(int i = 0; i < dim; i++)
	{
		//printf("\n\n\tSONO ENTRATO NEL CICLO FOR, output_dim VALE %d, VADO A DORMIRE...", *output_dim); fflush(stdout);
		//sleep(1);

		if(!int_vector_check_number(p, *output_dim, array[i]))
		{
			printf("\n\n\tSONO ENTRATO NELL'IF: output_dim vale %d", *output_dim); fflush(stdout);
			p[*output_dim] = array[i];
			(*output_dim)++;	
			printf("\n\n\tSONO USCITO DALL'IF: output_dim vale %d", *output_dim); fflush(stdout);
			sleep(1);
		}
	}
	printf("\n\n\tHO FINITO IL CICLO FOR, VADO A DORMIRE..."); fflush(stdout);
	sleep(1);
	p = (int*) realloc(p, *output_dim*sizeof(int));
	printf("\n\n\tHO USATO REALLOC SU P, VADO A DORMIRE..."); fflush(stdout);
	sleep(1);

	return p;
}