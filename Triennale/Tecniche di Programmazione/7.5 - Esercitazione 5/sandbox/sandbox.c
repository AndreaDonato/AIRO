#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef MATRIX_H
#define MATRIX_H
typedef struct
	{
		int row;
		int col;
		float **element;
		char *name;

	} matrix;

#endif



char *constcharstar_to_charstar(const char *mystring)
{
	char *clone = (char*) malloc((strlen(mystring))*sizeof(char));
	strcpy(clone, mystring);
	return clone;
}



matrix *matrix_alloc(int row, int col, char *name)
{
	if(row <= 0 || col <= 0)
	{
		printf("\n\tMatrix require positive row/column numbers.\n\n");
		exit(1);
	}

	matrix *m = (matrix*) malloc(sizeof(matrix));
	m->row = row;
	m->col = col;
	//m->name = (char*) malloc(strlen(name)*sizeof(char));
	//printf("\n\tmalloc function on *char m->name executed successfully..."); fflush(stdout); sleep(1);
	//free(m->name);
	//printf("\n\tfree function on *char m->name executed successfully..."); fflush(stdout); sleep(1);
	m->name = name;
	// Alloco l'array di array (leggi: la colonna di puntatori alle righe)
	m->element = (float**) calloc(row, sizeof(float*));
	// Alloco le singole righe
	for(int i = 0; i < row; i++)
	{
		m->element[i] = (float*) calloc(col, sizeof(float));
	}
	return m;
}



void matrix_print(matrix *m)
{
	printf("\n\tPrint of %dx%d matrix named '%s':\n", m->row, m->col, m->name); fflush(stdout);
	
	for(int i = 0; i < m->row; i++)
	{
		printf("\n\t");
		for(int j = 0; j < m->col; j++) printf("%.3f\t", m->element[i][j]);
	}
	printf("\n\n");	
}


void matrix_free(matrix *m)
{
	for(int i = 0; i < m->row; i++) free(m->element[i]);
	free(m->element);
	printf("\n\t*char %s->name has address %p", m->name, m->name); fflush(stdout); sleep(1);
	printf("\n\t%s matrix has address %p", m->name, m); fflush(stdout); sleep(1);
	free(m->name);
	free(m);
	printf("\n\t*char %s->name has address %p", m->name, m->name); fflush(stdout); sleep(1);
	printf("\n\t%s matrix has address %p", m->name, m); fflush(stdout); sleep(1);
}

int main(int argc, char const *argv[])
{

	int row, col;
	matrix *m, *n, *s;

	if (argc != 3) {fprintf(stderr, "\n\n\tNB: ./main #rows #columns\n\n"); exit(1);}
  	row = atoi(argv[1]);
  	col = atoi(argv[2]);

	m = matrix_alloc(row, col, constcharstar_to_charstar("NewMatrix"));
	matrix_print(m);
	printf("\n\tAddress of\tm\tn\ts\n\t          \t%p\t%p\t%p\n", m, n, s); fflush(stdout); sleep(1);
	printf("\n\t*char %s->name has address %p", m->name, m->name); fflush(stdout); sleep(1);
	printf("\n\t%s matrix has address %p", m->name, m); fflush(stdout); sleep(1);
	//free(m->name);
	matrix_free(m);
	printf("\n\n");
	return 0;
}