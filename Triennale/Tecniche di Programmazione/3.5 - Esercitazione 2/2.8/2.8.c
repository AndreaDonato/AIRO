#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {

int *p, address;

if((unsigned long long)p > pow(2, sizeof(unsigned long))) unsigned long long address = (unsigned long long)p;
else if ((unsigned long long)p > pow(2, sizeof(unsigned int))) unsigned long address = (unsigned long)p;
else unsigned int address = (unsigned int)p;

printf("\n\n\tLa minima allocazione è %dbyte.\n\n", sizeof(address));

return(0);
}




// QUESTO PROGRAMMA NON HA SENSO, IL COMPILATORE MI SPOILERA IL RISULTATO DANDOMI ERRORE.