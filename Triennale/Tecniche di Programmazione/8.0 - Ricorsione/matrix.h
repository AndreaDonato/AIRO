// 5.0 - Definizione di tipo matrice
#ifndef INT_MATRIX_H
#define INT_MATRIX_H
typedef struct
	{
		int row;
		int col;
		int **element;
		char *name;
		bool valid;

	} int_matrix;

#endif


/********************************************************
*               AUSILIARY FUNCTIONS                     *
********************************************************/
// Casts const char* string ("Example") to char* string	
char *constcharstar_to_charstar(const char *mystring);
// Changes matrix (as defined MATRIX_H) name
void int_matrix_rename(int_matrix *m, char *new_name, bool verbose);
// Starting set for Hanoi Towers
void int_matrix_hanoi_fill(int_matrix *m);

/********************************************************
*               REQUESTED FUNCTIONS                     *
********************************************************/
// 5.1 - Funzione per allocare il tipo matrice
int_matrix *int_matrix_alloc(int row, int col, char *name);
// 5.2 - Funzione per deallocare una matrice
void int_matrix_free(int_matrix *m);
//5.3 - Funzione per stampare una matrice
void int_matrix_print(int_matrix *m, bool is_palude);
