#include "matrix.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>


/********************************************************
*               AUSILIARY FUNCTIONS                     *
********************************************************/
char *constcharstar_to_charstar(const char *mystring)
{
	char *clone = (char*) malloc((strlen(mystring))*sizeof(char));
	strcpy(clone, mystring);
	return clone;
}

void int_matrix_rename(int_matrix *m, char *new_name, bool verbose)
{
	//printf("\n\tfree() and new malloc() on %s->name...", m->name); fflush(stdout); sleep(1);
	if(verbose) printf("\n\t'%s' renamed '%s'", m->name, new_name);	
	free(m->name);
	m->name = (char*) malloc(strlen(new_name)*sizeof(char));
	m->name  = new_name;
	//printf("\n\tsuccessful execution. new matrix name: %s", m->name); fflush(stdout); sleep(1);	
}

void int_matrix_hanoi_fill(int_matrix *m)
{
	for(int i = 0; i < m->row; i++)
	{
		for(int j = 0; j < m->col; j++)
		{
			if(i == 0) m->element[i][j] = m->col-j;
			else m->element[i][j] = 0;
		}
	}
}

/********************************************************
*               REQUESTED FUNCTIONS                     *
********************************************************/
// 5.1
int_matrix *int_matrix_alloc(int row, int col, char *name)
{
	//printf("\n\tExecuting matrix malloc function..."); fflush(stdout); sleep(1);
	int_matrix *m = (int_matrix*) malloc(sizeof(int_matrix));
	m->name = (char*) malloc(strlen(name)*sizeof(char));
	m->name = name;

	if(row <= 0 || col <= 0)
	{
		printf("\n\tWarning: non-valid matrix allocated"); fflush(stdout);
		m->valid = false;
		return m;
	}

	m->row = row;
	m->col = col;
	m->element = (int**) calloc(row, sizeof(int*));
	for(int i = 0; i < row; i++) m->element[i] = (int*) calloc(col, sizeof(int));
	m->valid = true;
	return m;
}


// 5.2
void int_matrix_free(int_matrix *m)
{
	if(m->valid)
	{
		for(int i = 0; i < m->row; i++) free(m->element[i]);
		free(m->element);
		//printf("\n\t*char %s->name has address %p", m->name, m->name); fflush(stdout); sleep(1);
		//printf("\n\t%s matrix has address %p", m->name, m); fflush(stdout); sleep(1);
		//printf("\n\t%s matrix no problem with free(name)", m->name); fflush(stdout); sleep(1);	
	}
	free(m->name);
	free(m);
}


// 5.3
void int_matrix_print(int_matrix *m, bool is_palude)
{
	//printf("\n\tEntered print, m->valid = %d...", m->valid); fflush(stdout); sleep(1);

	if(m->valid)
	{
		printf("\n\tPrint of %dx%d matrix named '%s':\n", m->row, m->col, m->name); fflush(stdout);
		for(int i = 0; i < m->row; i++)
		{
			printf("\n\t");
			for(int j = 0; j < m->col; j++)
				is_palude? printf(m->element[i][j]? " * " : " o ") : printf("%d\t", m->element[i][j]);
		}
		printf("\n\n");	
	}
	else printf("\n\tCannot print non-valid matrix.");
}