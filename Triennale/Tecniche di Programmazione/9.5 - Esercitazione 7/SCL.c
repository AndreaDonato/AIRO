#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SCL.h"
#include <unistd.h>
#include <stdbool.h>
#include <math.h>
#define MIN -10
#define MAX 10
#define epsilon 0.001

/********************************************************
*               AUSILIARY FUNCTIONS                     *
********************************************************/

void SCL_Add_First_Node(SCL_Pointer *scl_p, SCL_Type x) 					
{
	SCL_Pointer temp = *scl_p;
	*scl_p = (SCL_Node*) malloc(sizeof(SCL_Node));
	(*scl_p)->info = x;
	(*scl_p)->next = temp;
}

void SCL_Delete_First_Node(SCL_Pointer *scl_p)
{
	SCL_Pointer temp = *scl_p;
	*scl_p = (*scl_p)->next;
	free(temp);
}

bool SCL_is_empty(SCL_Pointer scl_p)
{
	return scl_p == NULL;
}

void SCL_Find_Element(SCL_Pointer scl_p, SCL_Type x, SCL_Pointer *ris)
{
	if(SCL_is_empty(scl_p)) *ris = NULL;
	else if(abs(scl_p->info-x) < epsilon) *ris = scl_p;
	else SCL_Find_Element(scl_p->next, x, ris);
}

void SCL_Uniform_Fill(SCL_Pointer *scl_p, int n, SCL_Type x)
{
	if(n < 0) {fprintf(stderr, "\n\n\tWarning: negative-size request\n\n"); exit(1);}

	if(n == 0) *scl_p = NULL;
	else
	{
		*scl_p = (SCL_Node*) malloc(sizeof(SCL_Node));
		(*scl_p)->info = x;
		SCL_Uniform_Fill(&((*scl_p)->next), n-1, x);
	}
}

// Funzione di supporto a Recursive_Random_Fill, genera un float tra a e b;
float Random_Float()
{
    float random = ((float) rand()) / (float) RAND_MAX;
    float diff = MAX - MIN;
    float r = random * diff;
    return MIN + r;
}

// Funzione di supporto a SCL_Random_Fill per inizializzare una sola volta srand
void Recursive_Random_Fill(SCL_Pointer *scl_p, int n)
{
	if(n == 0) *scl_p = NULL;
	else
	{
		//printf("\n\tExecuting else in Recursive_Random_Fill function as scl_p points address %p", *scl_p); fflush(stdout); sleep(1);
		SCL_Uniform_Fill(scl_p, 1, Random_Float());
		//printf("\n\tSingle SCL_Uniform_Fill executed, info %f added in node address %p", (*scl_p)->info, *scl_p); fflush(stdout); sleep(1);
		Recursive_Random_Fill(&((*scl_p)->next), n-1);
	}
}

void SCL_Random_Fill(SCL_Pointer *scl_p, int n)
{
	if(n < 0) {fprintf(stderr, "\n\n\tWarning: negative-size request\n\n"); exit(1);}

	srand(time(NULL));
	Recursive_Random_Fill(scl_p, n);
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

// Funzione di supporto a SCL_Print
void fileprint(SCL_Pointer scl_p, FILE *fp)
{
	if(scl_p == NULL) {} 
	else
	{
		//printf("\n\tExecuting else in SCL_Fileprint function as scl_p points address %p and has value %f. Next address is %p", scl_p, scl_p->info, scl_p->next); fflush(stdout); sleep(1);
		fprintf(fp, "%.3f  ", scl_p->info);
		fileprint(scl_p->next, fp);
	}
}

void SCL_Print(SCL_Pointer scl_p, const char *filename)
{
	FILE *fp;
	bool flag = false;

	if(!strcmp(filename, "stdout"))		// strcmp ritorna 0 se le stringhe sono uguali
	{
		fp = stdout;
		printf("\n\t");
	}
	else 
	{
		fp = fopen(filename, "w");
		flag = true;
	}

	fprintf(fp, "SCL elements are: ");
	fileprint(scl_p, fp);
	
	if(flag) fclose(fp);
	else printf("\n\n");
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

/********************************************************
*               REQUESTED FUNCTIONS                     *
********************************************************/

// 7.1
int SCL_Length(SCL_Pointer scl_p)
{
	if(scl_p == NULL) return 0;
	else return 1 + SCL_Length(scl_p->next); 

}


// 7.2
float SCL_Sum(SCL_Pointer scl_p)
{
	if(scl_p == NULL) return 0;
	else return scl_p->info + SCL_Sum(scl_p->next); 
}

// 7.3
float SCL_Mean(SCL_Pointer scl_p)
{
	// Esercizio sterile?
	return 0;
}

// 7.4
float SCL_Dot(SCL_Pointer scl1_p, SCL_Pointer scl2_p)
{
	if(!SCL_Same_Size(scl1_p, scl2_p)) {fprintf(stderr, "\n\n\tImpossible to perform dot product between different-sized lists\n\n"); exit(1);}

	if(scl1_p == NULL) return 0;
	else return scl1_p->info*scl2_p->info + SCL_Dot(scl1_p->next, scl2_p->next); 
}

// 7.5
void SCL_Duplicate_Node(SCL_Pointer scl_p, int pos)
{
	if(pos < 0) {fprintf(stderr, "\n\n\tImpossible to find node in negative position\n\n"); exit(1);}
	if(pos == 0) SCL_Add_Node(&scl_p, scl_p->info, 1);
	else SCL_Duplicate_Node(scl_p->next, pos-1);
}

// 7.6
void SCL_Positives(SCL_Pointer scl_p, SCL_Pointer *ris)
{
	if(scl_p == NULL) {}
	else if(scl_p->info >= 0)
		{
			SCL_Positives(scl_p->next, ris);
			SCL_Add_Node(ris, scl_p->info, 0);
		}
	else SCL_Positives(scl_p->next, ris);
}

// Non mi va di fare la variante funzionale;