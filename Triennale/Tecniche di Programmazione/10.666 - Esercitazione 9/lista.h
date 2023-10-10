#pragma once


/********************************************************
*                    LIST BY SCL                        *
********************************************************/

typedef int list_type;
struct SCL_Node
{
    list_type info;
    struct SCL_Node *next;
};
typedef struct SCL_Node LIST_Element;
typedef LIST_Element *list;

// Operazioni
list empty_lista();                 // crea lista vuota
int is_empty(list l);               // controllo se vuota
list cons(list_type x, list l);     // creo lista aggiungendo per primo
list_type car(list l);              // leggo valore del primo
list cdr(list l);                   // ritorno coda della lista


/*********************************************
*           AUSILIARY FUNCTIONS              *
*********************************************/
void printlist(list l);


/*********************************************
*           REQUESTED FUNCTIONS              *
*********************************************/