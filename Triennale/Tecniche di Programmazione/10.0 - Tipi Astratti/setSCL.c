#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "setSCL.h"
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#define MIN -10
#define MAX 10
#define epsilon 0.001

/********************************************************
*               PRIMITIVE FUNCTIONS                     *
********************************************************/

set empty_set()
{
	set r = (set) malloc(sizeof(SET_Element));
	r = NULL;
	return r;
}

bool SET_is_empty(set s)
{
	return s == NULL;
}

bool is_in_SET(set s, set_type x)
{
	if(SET_is_empty(s)) return false;
	else if(s->info == x) return true;
	else return is_in_SET(s->next, x);
}	

void SET_Add(set *s, set_type x)
{
	if(!is_in_SET(*s, x))
	{
		set new_set;
		new_set = (SET_Element*) malloc(sizeof(SET_Element));
		new_set->info = x;
		new_set->next = *s;
		*s = new_set;
	}
}

set F_SET_Add(set s, set_type x)		// Variante funzionale + condivisione memoria
{
	if(!is_in_SET(s, x))
	{
		set new_set;
		new_set = (SET_Element*) malloc(sizeof(SET_Element));
		new_set->info = x;
		new_set->next = s;
		return new_set;
	}
	else return s;
}


// Funzione di supporto a SET_Delete
void delete_value(set *s, set_type x)
{
	if((*s)->info != x) delete_value(&((*s)->next), x);
	else
	{
		set temp = *s;
		*s = (*s)->next;
		free(temp);
	}
}

void SET_Delete(set *s, set_type x)
{
	if(is_in_SET(*s, x))
	{
		delete_value(s, x);
	}
}

set F_delete_value(set s, set_type x)
{
	if(s->info == x) return s->next;	// s e new_set condividono la memoria dal valore successivo a quello eliminato in poi
	else
	{
		set new_set = (set) malloc(sizeof(SET_Element));
		new_set->info = s->info;
		new_set->next = F_delete_value(s->next, x);
		return new_set;
	}
}

set F_SET_Delete(set s, set_type x)		// Variante funzionale + condivisione memoria
{
	if(is_in_SET(s, x))
	{
		return F_delete_value(s, x);
	}
	else return s;
}

/*********************************************
*            SCL_SET ITERATOR                *
*********************************************/

iterator* IT_create(set s)
{
	iterator* r = (iterator*) malloc(sizeof(iterator));
	*(r->pointer) = s;
	return r;
}

bool IT_has_next(iterator *it)
{
	return it->pointer != NULL;
}

set_type IT_next(iterator *it)
{
	set_type r = ERROR_VALUE;
	
	if(IT_has_next(it))
	{
		set new_set = *(it->pointer);		// A quanto pare a g++ non piace *(it->pointer)->info
		r = new_set->info;					// Chiaramente ho scritto la stessa cosa con un supporto e gli è andato bene...
		*(it->pointer) = new_set->next;
	}
	else printf("ERRORE Iteratore non valido.\n");
	
	return r;
}

/*********************************************
*          HIGH LEVEL FUNCTIONS              *
*********************************************/

void SET_Print(set s)
{
	iterator *it = IT_create(s);
	
	while(IT_has_next(it))
	{
		printf("%d", IT_next(it));
	}
	
	printf("\n");
}