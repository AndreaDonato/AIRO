#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "charSCL.h"
#include <unistd.h>
#include <stdbool.h>
#define N 256


int main(int argc, char const *argv[])
{
	/*char *s;
	s = (char*) malloc(N*sizeof(char));
	printf("\n\tInserire stringa: ");
	fgets(s, N, stdin);*/
	
	SCL_Pointer My_SCL_String = NULL;
	SCL_Pointer My_Second_SCL_String = NULL;

	// 7.8
	SCL_String_Create("Stringa di prova", &My_SCL_String);

	// 7.7 (ordinamento furbo a sto giro)
	SCL_String_Print(My_SCL_String);

	// 7.9
	printf("\n\tDentro al codice %sc'è scritto 'Buona giornata'\n", SCL_String_is_equal(My_SCL_String, "Buona giornata")?"":"non ");
	printf("\n\tDentro al codice %sc'è scritto 'Stringa di prova'\n", SCL_String_is_equal(My_SCL_String, "Stringa di prova")?"":"non ");

	// 7.10
	SCL_String_Remove(&My_SCL_String, 'c');
	printf("\n\tProvo a rimuovere la lettera 'c', che %sè presente in 'Stringa di prova', ottenendo quindi\n", !SCL_String_is_equal(My_SCL_String, "String di prov")?"":"non ");
	SCL_String_Print(My_SCL_String);
	SCL_String_Remove(&My_SCL_String, 'a');
	printf("\n\tProvo a rimuovere la lettera 'a', che %sè presente in 'Stringa di prova', ottenendo quindi\n", SCL_String_is_equal(My_SCL_String, "String di prov")?"":"non ");
	SCL_String_Print(My_SCL_String);
	
	//free(s);
	return 0;
}