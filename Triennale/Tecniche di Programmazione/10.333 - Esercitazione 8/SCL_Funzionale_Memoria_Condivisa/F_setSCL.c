#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "F_setSCL.h"
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
	//printf("\n\tEntering is_in_SET, all good"); fflush(stdout); sleep(1);

	if(SET_is_empty(s)) return false;
	else if(s->info == x) return true;
	else return is_in_SET(s->next, x);
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

SET_Iterator IT_create(set s)
{
	SET_Iterator r = (SET_Iterator) malloc(sizeof(set));
	*r = s;
	return r;
}

bool IT_has_next(SET_Iterator it)
{
	//printf("\n\tIt_has_next function executed, result is next is %sNULL", *it==NULL?"":"not "); fflush(stdout); sleep(1);
	return *it != NULL;
}

set_type IT_next(SET_Iterator it)
{
	set_type r = ERROR_VALUE;
	
	if(IT_has_next(it))
	{
		set new_set = *it;
		r = new_set->info;
		*it = new_set->next;
	}
	else printf("ERRORE Iteratore non valido.\n");
	
	return r;
}

/*********************************************
*           AUSILIARY FUNCTIONS              *
*********************************************/

void random_array(int v[], int dim, int max_value)
{
	srand(time(NULL)); 	// Questa cosa randomizza bene solo se faccio meno di una esecuzione al secondo!
	for(int i = 0; i < dim; i++) v[i] = rand()%(max_value+1);
}

void print_int_vector(int v[], int dim, const char* title)
{
	printf("\n\n\t%s\n", title);
	for(int i = 0; i < dim; i++)
	{
		if(i%11 == 0) printf("\n");
		printf("\tv[%d] = %d", i, v[i]);
	}
	printf("\n\n");
}

/*********************************************
*           REQUESTED FUNCTIONS              *
*********************************************/

// 8.1
set SET_from_array(int *v, int n)
{
	set s;
	s = empty_set();
	for(int i = 0; i < n; i++)
	{
		s = F_SET_Add(s, v[i]);
	}
	return s;
}

// 8.2
void SET_Print(set s)
{
	SET_Iterator it = IT_create(s);
	//printf("\n\tSET_Iterator creation, all good"); fflush(stdout); sleep(1);
	printf("\n\tPrint of set elements:"); fflush(stdout);
	while(IT_has_next(it))
	{
		//printf("\n\tIT_has_next function executed, iteration %d, all good. Next is SET_Element of address %p", ++i, *it); fflush(stdout); sleep(1);
		printf(" %d", IT_next(it));
	}
	
	printf("\n\n");
}

// 8.3
set SET_Copy(set s)
{
	set new_set;
	new_set = empty_set();

	SET_Iterator it = IT_create(s);

	while(IT_has_next(it))
	{
		new_set = F_SET_Add(new_set, IT_next(it));
	}
	return new_set;
}

// 8.4
int SET_Size(set s)
{
	int i = 0;
	SET_Iterator it = IT_create(s);
	while(IT_has_next(it)) 
	{
		i++;
		IT_next(it);
	}
	return i;
}

// 8.5
bool is_subset(set a, set b)
{
	if(SET_Size(a) >= SET_Size(b)) return false;

	SET_Iterator it = IT_create(a);
	
	while(IT_has_next(it))
	{
		if(!is_in_SET(b, IT_next(it))) return false;
	}
	
	return true;
}


// 8.6
bool SET_are_equal(set a, set b)
{
	if(SET_Size(a) != SET_Size(b)) return false;

	SET_Iterator it = IT_create(a);
	
	while(IT_has_next(it))
	{
		if(!is_in_SET(b, IT_next(it))) return false;
	}
	
	return true;
}

// 8.7
set SET_Intersection(set a, set b)
{
	set c;
	set_type current_value;
	c = empty_set();

	SET_Iterator it = IT_create(a);
	
	while(IT_has_next(it))
	{
		current_value = IT_next(it);
		if(is_in_SET(b, current_value)) c = F_SET_Add(c, current_value);
	}
	return c;
}

// 8.8
set SET_Union(set a, set b)
{
	set c;
	c = empty_set();
	SET_Iterator it_a = IT_create(a);
	SET_Iterator it_b = IT_create(b);
	while(IT_has_next(it_a)) c = F_SET_Add(c, IT_next(it_a));
	while(IT_has_next(it_b)) c = F_SET_Add(c, IT_next(it_b));
	return c;
}