#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SCL.h"
#include <unistd.h>
#include <stdbool.h>
#define N 256


int main(int argc, char const *argv[])
{
	SCL_Pointer My_SCL = NULL;
	SCL_Pointer My_Second_SCL = NULL;
	SCL_Pointer My_Positive_SCL = NULL;

	int n;

	if (argc != 2) {fprintf(stderr, "\n\n\tNB: ./main #SCL_Elements\n\n"); exit(1);}
  	n = atoi(argv[1]);
	if (n <= 0) {fprintf(stderr, "\n\n\tNB: #SCL_Elements must be positive integer\n\n"); exit(1);}
	
	// Just testing ausiliary functions
	SCL_Random_Fill(&My_SCL, n);
	SCL_Print(My_SCL, "stdout");
	SCL_Delete_Node(&My_SCL, 3);
	SCL_Print(My_SCL, "stdout");
	SCL_Add_Node(&My_SCL, 3.14, 4);
	SCL_Print(My_SCL, "stdout");
	

	// 7.1
	printf("\n\tLa SCL creata è composta da %d elementi\n", SCL_Length(My_SCL));
	// 7.2
	printf("\n\tLa somma dei valori della SCL creata è %f\n", SCL_Sum(My_SCL));		
	// 7.3

	// 7.4
	SCL_Copy(My_SCL, &My_Second_SCL);
	printf("\n\tIl modulo quadro della SCL creata è %f\n", SCL_Dot(My_SCL, My_Second_SCL));

	// 7.5
	SCL_Duplicate_Node(My_SCL, 3);
	printf("\n\tDuplico il nodo in posizione 3:");
	SCL_Print(My_SCL, "stdout");

	// 7.6
	SCL_Positives(My_SCL, &My_Positive_SCL);
	printf("\n\tFiltro i soli positivi:");	
	SCL_Print(My_Positive_SCL, "stdout");

	SCL_Delete(&My_SCL);
	SCL_Delete(&My_Second_SCL);
	SCL_Delete(&My_Positive_SCL);

	return 0;
}