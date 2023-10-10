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
void SET_Add(set *s, set_type x);		// Inserisce x nell'insieme s
set F_SET_Add(set s, set_type x);		// Variante funzionale + condivisione memoria
void SET_Delete(set *s, set_type x);	// Rimuove x dall'insieme s
set F_SET_Delete(set s, set_type x);	// Variante funzionale + condivisione memoria


/*********************************************
*            SCL_SET ITERATOR                *
*********************************************/
#define ERROR_VALUE 666

typedef struct
{
	set* pointer;
} iterator;

iterator* IT_create(set s);				// Crea un iteratore per il set s
bool IT_has_next(iterator *it);			// true se l'elemento puntato non è NULL
set_type IT_next(iterator *it);			// Restituisce il valore puntato

#endif

void SET_Print(set s);					// Stampa l'insieme s
