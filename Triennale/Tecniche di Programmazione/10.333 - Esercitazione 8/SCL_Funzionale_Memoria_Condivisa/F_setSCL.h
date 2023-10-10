/********************************************************
*                     SET BY SCL                        *
********************************************************/

#ifndef SETSCL_H
#define SETSCL_H

typedef int set_type;
//#define type_print;

struct SCL_Node
{
	set_type info;
	struct SCL_Node *next;
};

typedef struct SCL_Node SET_Element;
typedef SET_Element* set;


set empty_set(); 						// Le costanti possono essere definite come funzioni senza argomenti
bool SET_is_empty(set s);				// true se l'insieme in input è vuoto
bool is_in_SET(set s, set_type x);		// true se x appartiene all'insieme s
set F_SET_Add(set s, set_type x);		// Variante funzionale + condivisione memoria
set F_SET_Delete(set s, set_type x);	// Variante funzionale + condivisione memoria


/*********************************************
*            SCL_SET ITERATOR                *
*********************************************/
#define ERROR_VALUE 666

typedef set* SET_Iterator;

SET_Iterator IT_create(set s);				// Crea un iteratore per il set s
bool IT_has_next(SET_Iterator it);			// true se l'elemento puntato non è NULL
set_type IT_next(SET_Iterator it);			// Restituisce il valore puntato

#endif

/*********************************************
*           AUSILIARY FUNCTIONS              *
*********************************************/

void random_array(int v[], int dim, int max_value);

void print_int_vector(int v[], int dim, const char* title);

/*********************************************
*           REQUESTED FUNCTIONS              *
*********************************************/

// 8.1
set SET_from_array(int *v, int n);

// 8.2
void SET_Print(set s);

// 8.3 - Assumo si intenda senza condivisione di memoria (sarebbe davvero banale altrimenti)
set SET_Copy(set s);

// 8.4
int SET_Size(set s);

// 8.5
bool is_subset(set a, set b);

// 8.6
bool SET_are_equal(set a, set b);

// 8.7
set SET_Intersection(set a, set b);

// 8.8
set SET_Union(set a, set b);