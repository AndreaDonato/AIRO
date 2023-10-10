#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>

int *allocaInt();
void printInt(int *i1, int *i2);
void soluzioneEquazione(int a, int b, int c);

int main() {
int *p, *q;
p = allocaInt();
printf("\n\tHo allocato memoria per un intero all'indirizzo %p.\n", p);
q = allocaInt();
printInt(p, q);
soluzioneEquazione(4, -5, 2);

return 0;
}


int *allocaInt() {
	int *p = (int*) malloc(sizeof(int));
	return p;
}

void printInt(int *i1, int *i2) {
	printf("\n\tValore in %p: %d;\n\tValore in %p: %d.\n", i1, *i1, i2, *i2);
}

void soluzioneEquazione(int a, int b, int c) {
	float real, img, delta;
	delta = pow(b, 2) - 4*a*c;
	real = -(float)b/(2*a);
	if(delta < 0) {
 		img = sqrt(-delta)/(2*a);
 		printf("\n\tSoluzioni complesse %f +/- i %f\n", real, img);
 	}
 	else {
 		img = sqrt(delta)/(2*a);
 		printf("\n\tSoluzioni reali x1 = %f e x2 = %f\n", real-img, real+img);
	}

}
