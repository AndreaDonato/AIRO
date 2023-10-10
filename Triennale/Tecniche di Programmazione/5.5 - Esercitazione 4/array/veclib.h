#include <stdarg.h>

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