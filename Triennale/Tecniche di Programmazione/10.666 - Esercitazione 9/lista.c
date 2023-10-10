#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

/********************************************************
*                    LIST BY SCL                        *
********************************************************/
list empty_list()
{
  list r = (list) malloc(sizeof(LIST_Element));
  r = NULL;
  return r;}

int is_empty(list l)
{
  return(l == NULL);
}

list cons(list_type x, list l)
{
  list nuovo = (list)malloc(sizeof(LIST_Element));
  nuovo->info = x;
  nuovo->next = l;
  return nuovo;
}

list_type car(list l)
{
  if(l == NULL)
  {
    printf("\n\tERRORE: lista vuota\n\n");
    exit(1);
  }
  return l->info;
}

list cdr(list l)
{
  if (l == NULL)
  {
    printf("\n\tERRORE: lista vuota\n\n");
    exit(1);
  }
  return l->next;
}

/*********************************************
*           AUSILIARY FUNCTIONS              *
*********************************************/

void printlist_aux(list l)
{
	if (is_empty(l)) return;
	printf("%d, ", car(l));
	printlist_aux(cdr(l));
}

void LIST_Print(list l)
{
	printlist_aux(l);
	printf("\n\n");
}

int LIST_Length(list l)
{
  if(is_empty(l)) return 0;
  else return 1 + LIST_Length(l->next);
}

list LIST_Add(list l, list_type x, int n)
{
  // Lists share last len-n elements
  if(n == 0)
  {
    list new_node = (list) malloc(sizeof(LIST_Element));
    new_node->info = x;
    new_node->next = l;
    return new_node;
  }
  else
  {
    list new_node = (list) malloc(sizeof(LIST_Element));
    new_node->info = l->info;
    new_node->next = LIST_Add(l->next, x, n-1);
    return new_node;
  }
}

// Questa implementazione con condivisione di memoria è folle se si deve eliminare un nodo.

// LIST_Delete non è utilizzabile dal client, farebbe un casino.
void LIST_Delete(list *l)
{
  if(*l != NULL)
  {
    list p = *l;
    LIST_Delete(&((*l)->next));
    free(p);
  }
}

void reverse(list to_reverse, list *reversed)
{
  if(to_reverse == NULL) {}
  else
  {
    LIST_Add(*reversed, to_reverse->info, 0);
    reverse(to_reverse->next, &((*reversed)->next));
  }
}

list LIST_Inverter(list l)  // Senza condivisione di memoria, farebbe un casino
{
  list inverted_list = NULL;
  reverse(l, &inverted_list);
  return inverted_list;
}

list copy(list l, list support)
{
  copy(l->next, support);
  return LIST_Add(support, l->info, 0);

}
list LIST_Copy(list l)
{
  if(is_empty(l)) return empty_list();
  else return copy(l, empty_list());
}

list LIST_Join(list a, list b)
{

  return a;
}

list lfa(list l, int *v, int n)
{
  if(n == 0) return l;
  else
  { 
    LIST_Add(l, /////////////////////////////////////)
    return lfa(l->next, v, n-1);
  }
}

list LIST_from_array(int *v, int n)
{
  list l;
  l = empty_list();
  lfa(l, v, n);
  return l;
}