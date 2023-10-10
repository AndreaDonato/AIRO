#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "veclib.h"

void random_array(int v[], int dim, int max_value);
double* vec_clone(const double v[], int dim);
void vec_scale(double v[], int dim, double scale);
int* numeri_unici(const int array[], int dim, int *output_dim);

int main(int argc, char const *argv[])
{
	//4.1
	int len = 20, *int_vector, max = 50;
	int_vector = (int*) malloc(len*sizeof(int));
	random_array(int_vector, len, max);
	print_int_vector(int_vector, len, "Vettore di interi estratti randomicamente tra 0 e 50.");
	
	//4.2
	double *double_vector;
	double_vector = vec_clone(vector_cast_int_to_double(int_vector, len), len);
	print_double_vector(double_vector, len, "Vettore di prima, ma double");

	//4.3
	double scale_factor = 2.2;
	vec_scale(double_vector, len, scale_factor);
	print_double_vector(double_vector, len, "Vettore double, riscalato di 2.2");

	//4.4
	int *newlen, *unici;
	newlen = (int*) calloc(1, sizeof(int));
	unici = numeri_unici(int_vector, len, newlen);
	print_int_vector(unici, *newlen, "Vettore di interi senza ripetizioni");

	free(int_vector);
	free(double_vector);
	free(unici);
	free(newlen);
	return 0;
}

void random_array(int v[], int dim, int max_value)
{
	srand(time(NULL)); 	// Questa cosa randomizza bene solo se faccio meno di una esecuzione al secondo!
	for(int i = 0; i < dim; i++) v[i] = rand()%(max_value+1);
}

double* vec_clone(const double v[], int dim)
{
	double *p;
	p = (double*) malloc(dim*sizeof(double));
	
	for(int i = 0; i < dim; i++)
	{
		p[i] = v[i];
	}
	return p;
}


void vec_scale(double v[], int dim, double scale)
{
	for(int i = 0; i < dim; i++)
	{
		v[i] *= scale;
	}
}

int* numeri_unici(const int array[], int dim, int *output_dim)
{
	int *p;
	p = (int*) malloc(dim*sizeof(int));

	for(int i = 0; i < dim; i++)
	{
		if(!int_vector_check_number(p, *output_dim, array[i]))
		{
			p[*output_dim] = array[i];
			(*output_dim)++;
		}
	}
	p = (int*) realloc(p, *output_dim*sizeof(int));
	return p;
}