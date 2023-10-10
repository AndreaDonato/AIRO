#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matrix.h"
#include <unistd.h>
#include <stdbool.h>


int main(int argc, char const *argv[])
{
	int row, col, t;
	matrix *prev, *next;
	
	if (argc != 4) {fprintf(stderr, "\n\n\tNB: ./main #rows #columns T_MAX\n\n"); exit(1);}
  	
  	row  = atoi(argv[1]);
  	col  = atoi(argv[2]);
  	t 	 = atoi(argv[3]);
  	prev = matrix_alloc(row, col, constcharstar_to_charstar("Lifegame t = 0"));
	next = matrix_alloc(row, col, constcharstar_to_charstar("Lifegame"));
	//printf("\n\tmatrix pointers before first execution:\n\t%p\tprev\n\t%p\tnext", prev, next); fflush(stdout); sleep(1);

	matrix_random_fill(prev);
	matrix_print(prev);

	for(int i = 0; i < t; i++)
	{
		next = timestep(prev, next);
		matrix_print(next);
		//printf("\n\tmatrix pointers before prev = next:\n\t%p\tprev\n\t%p\tnext", prev, next); fflush(stdout); sleep(1);
		*prev = *next;
		//printf("\n\tmatrix pointers before first execution:\n\t%p\tprev\n\t%p\tnext", prev, next); fflush(stdout); sleep(1);
	}

	printf("\n\tmatrix pointers:\n\t%p\tprev\n\t%p\tnext\n\t", prev, next); fflush(stdout); sleep(1);

	matrix_free(prev);
	matrix_free(next);			//Boh questo dà segmentation fault, non mi va di capire perché

	return 0;

}