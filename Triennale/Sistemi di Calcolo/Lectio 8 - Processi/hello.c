#include <stdio.h>
#include <stdlib.h>
#include <time.h>

	int x;							// 4byte nella sezione data, inizializzati a 0 perché dichiarati fuori dal main;
	int main() 						// il main (e in generale tutto il codice) sta in TEXT;
	{
		int* p = malloc(100); 		// in HEAP vengono allocati 100byte contigui, p può stare in stack o in un registro a seconda di come è scritto il programma Assembly;
		char* q = "hello"; 			// in DATA vengono scritti i caratteri contigui 'h' 'e' 'l' 'l' 'o' '\0', q segue la stessa logica di p;
		
		do
			scanf("%d", &x); 			// fermo il programma per analizzare cosa fa il SO
		while(x != 1);

		return 0;
	}
