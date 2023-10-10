#include <stdio.h>
void stampa_variabili(int, int, int*, int*, long int);

int main() {

int a = 0, *pa, b = 0, *pb;
long dist = 0;
pa = &a;
pb = &b;
stampa_variabili(a, b, pa, pb, dist);
dist = &b - &a;
*(pb - dist) = 13;
stampa_variabili(a, b, pa, pb, dist);
printf("\n\n");
return(0);
}



void stampa_variabili (int a, int b, int *pa, int *pb, long int dist) {

	//printf("\n\n\tIndirizzo di memoria di:\n\ta: %p\n\tb: %p\n\n\tDistanza (in unità sizeof(int)) tra le due locazioni di memoria: %ld\n\n", &a, &b, dist);
	printf("\n\n\tVariabile\tValore\t\tIndirizzo\t\tIndirizzo a cui punta\t&var - puntatore a var\n\n");
	printf("\ta\t\t%d\t\t%p\n", a, &a);
	printf("\t*pa\t\t%d\t\t%p\t\t%p\t\t%d\n", *pa, &pa, pa, (int)((long long int)pa-(long long int)&a));		// &var - puntatore a var non può mai fare zero, sei dentro una funzione...
	printf("\tb\t\t%d\t\t%p\n", b, &b);
	printf("\t*pb\t\t%d\t\t%p\t\t%p\t\t%d\n", *pb, &pb, pb, (int)(&b-pb));
	printf("\tdist\t\t%ld\t\t%p\n", dist, &dist);
}
