#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int i = 2, *p;
	p = &i;

	printf("\n\tIndirizzo della variabile puntatore p:\t\t%p", &p); sleep(1);
	printf("\n\tIndirizzo puntato dalla variabile puntatore p: \t%p", p); sleep(1);
	printf("\n\tChe dovrebbe essere uguale all'indirizzo di i: \t%p", &i); sleep(1);
	printf("\n\tValore puntato dalla variabile puntatore i:\t%d\n\n", *p); sleep(1);
	
	return 0;
}