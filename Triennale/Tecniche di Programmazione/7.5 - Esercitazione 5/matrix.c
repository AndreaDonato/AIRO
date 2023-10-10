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

void matrix_rename(matrix *m, char *new_name, bool verbose)
{
	//printf("\n\tfree() and new malloc() on %s->name...", m->name); fflush(stdout); sleep(1);
	if(verbose) printf("\n\t'%s' renamed '%s'", m->name, new_name);	
	free(m->name);
	m->name = (char*) malloc(strlen(new_name)*sizeof(char));
	m->name  = new_name;
	//printf("\n\tsuccessful execution. new matrix name: %s", m->name); fflush(stdout); sleep(1);	
}


void matrix_random_fill(matrix *m)
{
	srand(time(NULL));
	if(m->valid)
	{
		for(int i = 0; i < m->row; i++)
			{
				for(int j = 0; j < m->col; j++) m->element[i][j] = ((float)(rand()%2)) * 1.0f;
			}
	}
	else printf("\n\tCannot fill non-valid matrix.");
}

matrix *matrix_transpose(matrix *m)
{
	if(m->valid)
	{
		matrix *t;
		char *newname = (char *)malloc((strlen(m->name)+11)*sizeof(char));
		sprintf(newname, "%s%s", m->name, "_transposed");
		t = matrix_alloc(m->col, m->row, newname);
		for(int i = 0; i < m->row; i++)	for(int j = 0; j < m->col; j++)	t->element[j][i] = m->element[i][j];
		return t;
	}
	else
	{
		printf("\n\tCannot transpose non-valid matrix. Returning input pointer.");
		return m;
	}
}

matrix *matrix_produce_an_error()
{
	matrix *err;
	err = matrix_alloc(0, 0, constcharstar_to_charstar("error_matrix"));
	return err;
}


/********************************************************
*               REQUESTED FUNCTIONS                     *
********************************************************/
// 5.1
matrix *matrix_alloc(int row, int col, char *name)
{
	//printf("\n\tExecuting matrix malloc function..."); fflush(stdout); sleep(1);
	matrix *m = (matrix*) malloc(sizeof(matrix));
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
	m->element = (float**) calloc(row, sizeof(float*));
	for(int i = 0; i < row; i++) m->element[i] = (float*) calloc(col, sizeof(float));
	m->valid = true;
	return m;
}


// 5.2
void matrix_free(matrix *m)
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
void matrix_print(matrix *m)
{
	//printf("\n\tEntered print, m->valid = %d...", m->valid); fflush(stdout); sleep(1);

	if(m->valid)
	{
		printf("\n\tPrint of %dx%d matrix named '%s':\n", m->row, m->col, m->name); fflush(stdout);
		for(int i = 0; i < m->row; i++)
		{
			printf("\n\t");
			for(int j = 0; j < m->col; j++) printf("%.3f\t", m->element[i][j]);
		}
		printf("\n\n");	
	}
	else printf("\n\tCannot print non-valid matrix.");
}

// 5.4
matrix *matrix_clone(matrix *m)
{
	matrix *new_matrix;

	if(m->valid)
	{
		char *newname = (char *)malloc((strlen(m->name)+7)*sizeof(char));
		sprintf(newname, "%s%s", m->name, "_clone");
		new_matrix = matrix_alloc(m->row, m->col, newname);

		for(int i = 0; i < m->row; i++)	
		{
			for(int j = 0; j < m->col; j++)
			{
				//printf("\n\tExecuting assignment of m_ij = %f", m->element[i][j]); fflush(stdout); sleep(1);
			 	new_matrix->element[i][j] = m->element[i][j];
			}
		}
				
		return new_matrix;
	}
	else
	{
		printf("\n\tCannot clone non-valid matrix. Returning input pointer.");
		return new_matrix;
	}
}

// 5.5
bool matrix_is_symmetric(matrix *m)
{
	if(m->valid)
	{
		if(m->row != m->col) return false;
		else for(int i = 0; i < m->row; i++)	for(int j = 0+i; j < m->col; j++)	if(m->element[i][j] != m->element[j][i]) return false;
		return true;
	}
	else return false;
}

// 5.6
void matrix_normalize_rows(matrix *m)
{
	if(m->valid)
	{
		float sum;
		for(int i = 0; i < m->row; i++)	
		{
			sum = 0;
			for(int j = 0; j < m->col; j++) sum += pow(m->element[i][j], 2);
			if(sum > 0)	for(int j = 0; j < m->col; j++) m->element[i][j] /= sqrt(sum);
		}
		char *newname = (char *)malloc((strlen(m->name)+11)*sizeof(char));
		sprintf(newname, "%s%s", m->name, "_normalized");
		matrix_rename(m, newname, true);
	}
	else printf("\n\tCannot normalize non-valid matrix");
}

// 5.7
matrix *matrix_sum(matrix *m1, matrix *m2)
{
	matrix *m;

	if(m1->valid && m2->valid)
	{
		if(m1->row != m2->row || m1->col != m2->col)
		{
			printf("\n\tImpossible to sum matrices having different dimensions"); fflush(stdout);
			m = matrix_alloc(0, 0, constcharstar_to_charstar("matrix_sum undefined"));
			return m;
		}

		char *newname = (char *)malloc((strlen(m1->name)+strlen(m2->name)+19)*sizeof(char));
		sprintf(newname, "%s%s%s%s%s", "Sum Of '", m1->name, "' and '", m2->name, "'");
		m = matrix_alloc(m1->row, m1->col, newname);

		for(int i = 0; i < m1->row; i++)
		{
			for(int j = 0; j < m1->col; j++)
			{
				m->element[i][j] = m1->element[i][j] + m2->element[i][j];
				//printf("\n\tExecuting sum\ti=%d\tj=%d", i, j); fflush(stdout); sleep(1);
			}
		}
	}
	else
	{
		printf("\n\tCannot sum non-valid matrix");
		m = matrix_alloc(0, 0, constcharstar_to_charstar("matrix_sum undefined"));
	}

	return m;
}

// 5.8
matrix *matrix_product(matrix *m1, matrix *m2)
{
	//printf("\n\tExecuting matrix_product function... m1->col = %d, m2->row = %d", m1->col, m2->row); fflush(stdout); sleep(1);
	matrix *mul;
	if(m1->valid && m2->valid)
	{
		if(m1->col != m2->row)
		{
			printf("\n\tImpossible to perform row-column product");fflush(stdout); //sleep(1);
			mul = matrix_alloc(0, 0, constcharstar_to_charstar("matrix_product undefined"));
			return mul;
		}

		char *newname = (char *)malloc((strlen(m1->name)+strlen(m2->name)+23)*sizeof(char));
		sprintf(newname, "%s%s%s%s%s", "Product Of '", m1->name, "' and '", m2->name, "'");
		mul = matrix_alloc(m1->row, m2->col, newname);

		for(int i = 0; i < m1->row; i++)
		{
			for(int j = 0; j < m2->col; j++)
			{
				for(int k = 0; k < m1->col; k++) mul->element[i][j] += m1->element[i][k]*m2->element[k][j];
			}
		}
	}
	else
	{
		printf("\n\tCannot multiply non-valid matrix");
		mul = matrix_alloc(0, 0, constcharstar_to_charstar("matrix_product undefined"));
	}	
	return mul;
}



// 5.9
matrix *timestep(matrix *p, matrix *d)
{
	int count;

	for(int i = 0; i < p->row; i++)
	{
		for(int j = 0; j < p->col; j++)
		{
			count = 0;
			
			if(i-1 >= 0 && p->element[i-1][j] > 0.5f) count++;
			if(i+1 < p->row && p->element[i+1][j] > 0.5f) count++;
			if(j-1 >= 0 && p->element[i][j-1] > 0.5f) count++;
			if(j+1 < p->col && p->element[i][j+1] > 0.5f) count++;
			//printf("\n\tmatrix point %d %d has %d live cells nearby", i, j, count); fflush(stdout); sleep(1);
			if(p->element[i][j] > 0.5f && (count == 2 || count == 3)) d->element[i][j] = 1;
			else if(p->element[i][j] < 0.5f && count == 3) d->element[i][j] = 1;
			else d->element[i][j] = 0;
		}
	}
	return d;
}

// 5.11
matrix *matrix_read(const char *filename)
{
  	FILE *fp = fopen(filename, "r");
  	int row = 0, col = 0, i = 0, j = 0;
  	bool error = false;
	matrix *m;

	if(fp == NULL) 
	{
		fprintf(stderr, "\n\tError opening file %s, returning non-valid matrix", filename); fflush(stdout);
		m = matrix_alloc(0, 0, constcharstar_to_charstar("error_in_file_opening"));
	}
	else if(fscanf(fp, "%d", &row) != 1 || fscanf(fp, "%d", &col) != 1 || row <= 0 || col <= 0)
	{
		fprintf(stderr, "\n\tError reading matrix dimensions from file %s, returning non-valid matrix", filename);
		m = matrix_alloc(0, 0, constcharstar_to_charstar("error_in_matrix_format"));
		fclose(fp);
	}
	else
	{
		char *newname = (char *) malloc((strlen(filename)+10)*sizeof(char));
		sprintf(newname, "%s%s", "read_from_", filename);
		m = matrix_alloc(row, col, newname);
		
		while(i < row && !error)
		{
			j = 0;
			while(j < col && !error)
			{
				if(fscanf(fp, "%f", &m->element[i][j]) != 1)
				{
					fprintf(stderr, "\n\tError reading matrix elements from file %s (missing element?), returning non-valid matrix", filename);
					error = true;
				}
				//printf("\n\tm->element[%d][%d] = %f", i, j, v); fflush(stdout); sleep(1);
				j++;
			}
			char c;
			do c = fgetc(fp); while(c == ' ' || c == '\t');
			//printf("\n\tExecuting fgetc() function at i = %d j = %d: %c", i, j, c); fflush(stdout); sleep(1);
			if(c != '\n' && c != EOF)
			{
				fprintf(stderr, "\n\tDimensions-format incoherence in file %s, returning non-valid matrix", filename);
				error = true;
			}
			i++;
		}
		if(error) m->valid = false;
		fclose(fp);
	}
	return m;
}

// 5.12
void matrix_write(const char *filename, matrix *m)
{
	if(m->valid)
	{
		FILE *fp = fopen(filename, "w");
		fprintf(fp, "%d %d", m->row, m->col);
		for(int i = 0; i < m->row; i++)
		{
			fprintf(fp, "\n");
			for(int j = 0; j < m->col; j++)
			{
				fprintf(fp, "%.3f ", m->element[i][j]);
			}
		}
		fclose(fp);
	}
	else {printf("\n\tCannot write non-valid matrix"); fflush(stdout);}
}