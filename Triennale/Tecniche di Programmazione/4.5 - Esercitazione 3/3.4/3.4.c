#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
const float OFFSET_CELSIUS = 273.15f;
const int OFFSET_FAHRENHEIT = 32;
const float SLOPE_FAHRENHEIT = 1.8f;

int main() {

float *t;

t = (float*) malloc(4*sizeof(float)+sizeof(char)); // Allocazione t-C-K-F-s(char)
printf("\n\n\tHo allocato t avente indirizzi:\n\n\tt (float): %p\n\tC (float): %p\n\tK (float): %p\n\tF (float): %p\n\ts (char) : %p\n", t, t+1, t+2, t+3, (char*)(t+4));
// sizeof(char) = 1
// sizeof(float) = 4
// Se casto char* la locazione del char è *(t+16) ++ NO ++ Il cast avviene dopo lo spostamento, quindi è t+4.


printf("\n\n\tInserire temperatura: ");
scanf(" %f", t);

do {
	printf("\n\n\tInserire unità di misura (C, K, F): ");
	scanf(" %c", (char*) (t+4));
	printf("\n\n\tHo appena letto il valore %c e l'ho salvato nella locazione %p", *(char*)(t+4), t+4);
} while(*(char*)(t+4) != 'C' && *(char*)(t+4) != 'K' && *(char*)(t+4) != 'F');

if(*(char*)(t+4) == 'C') {
	*(t+1) = *t;
	*(t+2) = *t + OFFSET_CELSIUS;
	*(t+3) = *t*SLOPE_FAHRENHEIT + OFFSET_FAHRENHEIT;
}
else if(*(char*)(t+4) == 'K') {
	*(t+1) = *t - OFFSET_CELSIUS;
	*(t+2) = *t;
	*(t+3) = (*t - OFFSET_CELSIUS)*SLOPE_FAHRENHEIT + OFFSET_FAHRENHEIT;
}
else {
	*(t+1) = (*t-OFFSET_FAHRENHEIT)/SLOPE_FAHRENHEIT;
	*(t+2) = *(t+1) + OFFSET_CELSIUS;
	*(t+3) = *t;

}

if(*(t+2) < 0) {
	printf("\n\n\tLa temperatura inserita non è fisicamente accettabile in quanto corrisponderebbe ad un valore di entropia negativo.\n\n");
	return 1;
}
printf("\n\n\tTemperatura in Celsius:\t\t%f", *(t+1));
printf("\n\n\tTemperatura in Kelvin:\t\t%f", *(t+2));
printf("\n\n\tTemperatura in Fahrenheit:\t%f\n\n", *(t+3));

free(t);

// Morale della favola: l'operazione di cast non modifica il tipo di puntatore.
// Probabilmente il tipo di variabile in generale.
return 0;
}