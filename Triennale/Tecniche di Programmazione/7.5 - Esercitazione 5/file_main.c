#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matrix.h"
#include <unistd.h>
#include <stdbool.h>

int main(int argc, char const *argv[])
{
	matrix *m, *n;
	m = matrix_read("mat.txt");
	matrix_print(m);
	matrix_write("new_mat.txt", m);
	n = matrix_read("new_mat.txt");
	matrix_print(n);
	matrix_free(m);
	matrix_free(n);
	printf("\n\n");
	return 0;
}