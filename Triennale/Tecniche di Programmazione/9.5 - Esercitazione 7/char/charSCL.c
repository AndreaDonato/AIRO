#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "charSCL.h"
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#define MIN -10
#define MAX 10
#define epsilon 0.001

/********************************************************
*               AUSILIARY FUNCTIONS                     *
********************************************************/
char *constcharstar_to_charstar(const char *mystring)
{
	char *clone = (char*) malloc((strlen(mystring))*sizeof(char));
	strcpy(clone, mystring);
	return clone;
}

bool SCL_is_empty(SCL_Pointer scl_p)
{
	return scl_p == NULL;
}

void SCL_Copy(SCL_Pointer scl_p, SCL_Pointer *ris)
{
	if(SCL_is_empty(scl_p)) *ris = NULL;
	else
	{
		*ris = (SCL_Node*) malloc(sizeof(SCL_Node));
		(*ris)->info = scl_p->info;
		SCL_Copy(scl_p->next, &((*ris)->next));
	}
}

void SCL_Delete(SCL_Pointer *scl_p)
{
	if(*scl_p != NULL)
	{
		SCL_Pointer p = *scl_p;
		SCL_Delete(&((*scl_p)->next));
		free(p);
	}
}

void SCL_Add_Node(SCL_Pointer *scl_p, SCL_Type x, int n)
{
	if(n < 0) {fprintf(stderr, "\n\n\tImpossible to find node in negative position\n\n"); exit(1);}

	if(n == 0)
	{
		SCL_Pointer temp = *scl_p;
		*scl_p = (SCL_Node*) malloc(sizeof(SCL_Node));
		(*scl_p)->info = x;
		(*scl_p)->next = temp;
	}
	else SCL_Add_Node(&((*scl_p)->next), x, n-1);
}

void SCL_Delete_Node(SCL_Pointer *scl_p, int n)
{
	if(n < 0) {fprintf(stderr, "\n\n\tImpossible to find node in negative position\n\n"); exit(1);}
	if(*scl_p == NULL){}
	else if (n == 0)
	{
		SCL_Pointer temp = *scl_p;
		(*scl_p) = (*scl_p)->next;
		free(temp);
	}
	else SCL_Delete_Node(&((*scl_p)->next), n-1);
}

bool SCL_Same_Size(SCL_Pointer scl1_p, SCL_Pointer scl2_p)
{
	return SCL_Length(scl1_p) == SCL_Length(scl2_p);
}

void reverse(SCL_Pointer to_reverse, SCL_Pointer *reversed)
{
	if(to_reverse == NULL) {}
	else
	{
		SCL_Add_Node(reversed, to_reverse->info, 0);
		reverse(to_reverse->next, &((*reversed)->next));
	}
}

void SCL_Inverter(SCL_Pointer scl_p)
{
	SCL_Pointer scl_p_inverted = NULL;

	reverse(scl_p, &scl_p_inverted);

	SCL_Pointer temp;
	temp = scl_p;
	scl_p = scl_p_inverted;

	SCL_Delete(&scl_p_inverted);
	SCL_Delete(&temp);
}

int SCL_Length(SCL_Pointer scl_p)
{
	if(scl_p == NULL) return 0;
	else return 1 + SCL_Length(scl_p->next); 

}
/********************************************************
*               REQUESTED FUNCTIONS                     *
********************************************************/

// 7.7
void printing(SCL_Pointer s)
{
	if(s == NULL) {}
	else
	{
		printf("%c", s->info);
		printing(s->next);
	}
}
void SCL_String_Print(SCL_Pointer s)
{
	printf("\n\t");
	printing(s);
	printf("\n\n");
}

// 7.8
void SCL_String_Create(const char *s, SCL_Pointer *ris)
{
	if(*s == '\0'){}
	else
	{
		SCL_String_Create(s+1, ris);
		SCL_Add_Node(ris, *s, 0);
	}
}

// 7.9
bool SCL_String_is_equal(SCL_Pointer scl_p, const char *s)
{
	if(scl_p == NULL) return true;
	else if(scl_p->info == *s)
	{
		SCL_String_is_equal(scl_p->next, s+1);
		return true;
	}
	else return false;
}

// 7.10
void SCL_String_Remove(SCL_Pointer *scl_p, char val)
{
	if(*scl_p == NULL) {}
	else if((*scl_p)->info == val)
	{
		SCL_String_Remove(&((*scl_p)->next), val);
		SCL_Delete_Node(scl_p, 0);
	}
	else SCL_String_Remove(&((*scl_p)->next), val);
}