#include <stdarg.h>
#define MAX_RAND 10

// 6.0 - Facciamo i coatti
#ifndef FLOAT_VECTOR_H
#define FLOAT_VECTOR_H
typedef struct
	{
		int dim;
		float *element;
		char *name;
		bool valid;
	} float_vector;
#endif

float_vector *float_vector_alloc(int dim, char *name)
{
	//printf("\n\tExecuting float_vector malloc function..."); fflush(stdout); sleep(1);
	float_vector *v = (float_vector*) malloc(sizeof(float_vector));
	v->name = (char*) malloc(strlen(name)*sizeof(char));
	v->name = name;

	if(dim <= 0)
	{
		printf("\n\tWarning: non-valid float_vector allocated"); fflush(stdout);
		v->valid = false;
		return v;
	}

	v->dim = dim;
	v->element = (float*) calloc(dim, sizeof(float));
	v->valid = true;
	return v;
}

void float_vector_manual_fill(float_vector *v)
{
	for(int i = 0; i < v->dim; i++)
	{
		printf("\tInsert element #%d: ", i);
		scanf("%f", &v->element[i]);
	}
}

void float_vector_random_fill(float_vector *v)
{
	srand(time(NULL));
	if(v->valid) for(int j = 0; j < v->dim; j++) v->element[j] = ((float)rand()/(float)(RAND_MAX)) * MAX_RAND;
	else printf("\n\tCannot fill non-valid float_vector.");
}

void float_vector_print(float_vector *v)
{
	printf("\n\tPrint of %d-dimensional float_vector named '%s'\n\t", v->dim, v-> name);
	for(int i = 0; i < v->dim; i++) printf("%.3f\t", v->element[i]);
	printf("\n");
}


void float_vector_free(float_vector *v)
{
	if(v->valid) free(v->element);
	free(v->name);
	free(v);
}



double* vector_cast_int_to_double(int v[], int dim)
{
	double *p;
	p = (double*) malloc(dim*sizeof(double));

	for(int i = 0; i < dim; i++)
	{
		p[i] = (double) v[i];
	}
	return p;
}

// Controlla se un intero n è presente nell'array
int int_vector_check_number(int v[], int dim, int n)
{
	int found = 0;
	for(int i = 0; i < dim && !found; i++)
	{
		if(v[i] == n) found = 1;
	}
	return found;
}


void print_double_vector(double v[], int dim, const char* title)
{
	printf("\n\n\t%s\n", title);
	for(int i = 0; i < dim; i++)
	{
		if(i%11 == 0) printf("\n");
		printf("\tv[%d] = %.1lf", i, v[i]);
	}
	printf("\n\n");
}

void print_int_vector(int v[], int dim, const char* title)
{
	printf("\n\n\t%s\n", title);
	for(int i = 0; i < dim; i++)
	{
		if(i%11 == 0) printf("\n");
		printf("\tv[%d] = %d", i, v[i]);
	}
	printf("\n\n");
}