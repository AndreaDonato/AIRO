#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "veclib.h"
#include "array.h"
#include <unistd.h>
#include <stdbool.h>

char *constcharstar_to_charstar(const char *mystring)
{
	char *clone = (char*) malloc((strlen(mystring))*sizeof(char));
	strcpy(clone, mystring);
	return clone;
}

int main(int argc, char const *argv[])
{

	int dim;
	char choose;
	float_vector *v;

	if (argc != 2) {fprintf(stderr, "\n\n\tNB: ./main array_dimension\n\n"); exit(1);}
	dim = atoi(argv[1]);
	v = float_vector_alloc(dim, constcharstar_to_charstar("MyVector"));

	do
	{
		printf("\n\tInsert array values manually? (y/n) ");
		scanf("%c", &choose);
	}
	while(choose != 'y' && choose != 'n');
	if(choose == 'y') float_vector_manual_fill(v);
	else float_vector_random_fill(v);

	float_vector_print(v);

	// 6.1
	printf("\n\n\tProduct of array '%s' elements is %.3f\n\n", v->name, product(v->element, dim));

	// 6.2
	printf("\n\n\tExecuting sum of first k elements of array '%s' and storing value in element k+1:\n", v->name);
	vec_integral(v->element, v->dim);
	float_vector_print(v);

	float_vector_free(v);
	return 0;
}