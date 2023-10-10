#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matrix.h"
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{

	int row, col;
	matrix *m, *n, *s, *t, *p;

	if (argc != 3) {fprintf(stderr, "\n\n\tNB: ./main #rows #columns\n\n"); exit(1);}
  	row = atoi(argv[1]);
  	col = atoi(argv[2]);
	if (row <= 0 || col <= 0) {fprintf(stderr, "\n\n\tNB: #rows #columns must be positive integers\n\n"); exit(1);}

	m = matrix_alloc(row, col, constcharstar_to_charstar("NewMatrix"));
	matrix_random_fill(m);
	matrix_print(m);

	n = matrix_clone(m);
	matrix_rename(n, constcharstar_to_charstar("n"), true);
	matrix_print(n);
	
	printf("\n\tLa matrice %s ", m->name); if(!matrix_is_symmetric(m)) printf("non "); printf("è simmetrica\n\n");
	
	matrix_normalize_rows(n);
	matrix_print(n);
	
	s = matrix_sum(m, n);
	matrix_print(s);
	
	t = matrix_transpose(m);
	matrix_print(t);

	p = matrix_product(t, n);
	matrix_print(p);


	// ERROR HANDLING
	matrix *err, *s_err, *t_err, *p_err;
	printf("\n\tProducing non-valid matrix on purpose to test exception handling\n");
	err = matrix_produce_an_error();
	matrix_random_fill(err);
	matrix_print(err);
	printf("\n\tLa matrice %s ", err->name); if(!matrix_is_symmetric(err)) printf("non "); printf("è simmetrica");
	matrix_normalize_rows(err);
	matrix_rename(err, constcharstar_to_charstar("not_an_error_matrix_?"), false);
	s_err = matrix_sum(err, m);
	t_err = matrix_transpose(err);
	p_err = matrix_product(err, m);
	matrix_rename(err, constcharstar_to_charstar("definetely_an_error_matrix"), true);
	matrix_free(err);
	matrix_free(s_err);
	matrix_free(p_err);


	
	matrix_free(m);
	matrix_free(n);
	matrix_free(s);
	matrix_free(t);
	matrix_free(p);

	printf("\n\n\tAll tasks accomplished successfully!\n\n");
	return 0;
}