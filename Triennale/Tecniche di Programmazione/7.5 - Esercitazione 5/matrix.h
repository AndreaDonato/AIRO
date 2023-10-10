// 5.0 - Definizione di tipo matrice
#ifndef MATRIX_H
#define MATRIX_H
typedef struct
	{
		int row;
		int col;
		float **element;
		char *name;
		bool valid;

	} matrix;

#endif


/********************************************************
*               AUSILIARY FUNCTIONS                     *
********************************************************/
// Casts const char* string ("Example") to char* string	
char *constcharstar_to_charstar(const char *mystring);
// Changes matrix (as defined MATRIX_H) name
void matrix_rename(matrix *m, char *new_name, bool verbose);
// Fills matrix (as defined MATRIX_H) with random floats
void matrix_random_fill(matrix *m);
// Returns transposed input matrix (as defined MATRIX_H)
matrix *matrix_transpose(matrix *m);
// Returns a non-valid matrix
matrix *matrix_produce_an_error();


/********************************************************
*               REQUESTED FUNCTIONS                     *
********************************************************/
// 5.1 - Funzione per allocare il tipo matrice
matrix *matrix_alloc(int row, int col, char *name);
// 5.2 - Funzione per deallocare una matrice
void matrix_free(matrix *m);
//5.3 - Funzione per stampare una matrice
void matrix_print(matrix *m);
// 5.4 - Funzione per copiare una matrice 
matrix *matrix_clone(matrix *m);
// 5.5 - Funzione per verificare che una matrice sia simmetrica
bool matrix_is_symmetric(matrix *m);
// 5.6 - Funzione per normalizzare le righe di una matrice
void matrix_normalize_rows(matrix *m);
// 5.7 - Funzione per calcolare la somma di matrici
matrix *matrix_sum(matrix *m1, matrix *m2);
// 5.8 - Funzione per calcolare il prodotto rigaxcolonna
matrix *matrix_product(matrix *m1, matrix *m2);

// 5.9 - Funzione per calcolare il passo successivo del Game Of Life
matrix *timestep(matrix *p, matrix *d);

// 5.11 - Funzione per leggere una matrice da file
matrix *matrix_read(const char *filename);
// 5.12 - Funzione per scrivere una matrice su file
void matrix_write(const char *filename, matrix *m);


/********************************************************
*                 OTHER FUNCTIONS                       *
********************************************************/
//matrix *matrix esercizio su kernel sommatore