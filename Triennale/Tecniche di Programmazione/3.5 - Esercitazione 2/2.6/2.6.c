#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {
int k;
int i = 10;
int j = -1;
char *p, *q;
// Inserire codice qui (senza j = ...)
for(k = 0; k < sizeof(int); k++)  {				// Il puntatore a char legge 1byte alla volta, mentre l'int ne alloca 4. Con il ciclo eguaglio tutti i byte anziché solo il primo.
	p = (char*) &i + k;
	q = (char*) &j + k;
	*q = *p;	
}

printf("%d == %d\n", i, j);

return(0);
}