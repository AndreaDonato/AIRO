// Questo programma alloca iterativamente (senza liberarla) memoria heap.
// Dopo un certo numero di iterazioni il pc inizierà ad andare a scatti.
// Perché non mi avvisa di aver finito la memoria??

#include <stdio.h>
#include <stdlib.h>
int main (void) {

long int s = 0;
long *p;
while (1) {
	p = (long*) malloc(1000000); // 1 MiB
	*p = 10l;
	s++;
	printf ( "\n\tAllocati %ld MiB\n", s) ;
	}
}