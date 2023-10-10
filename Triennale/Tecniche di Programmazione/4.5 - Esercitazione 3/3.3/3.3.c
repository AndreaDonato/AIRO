#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <limits.h>
const float OFFSET_CELSIUS = 273.15f;
const int OFFSET_FAHRENHEIT = 32;
const float SLOPE_FAHRENHEIT = 1.8f;

int main() {

float *t;
char *s;
int *i;

t = (float*) malloc(4*sizeof(float)); // Allocazione t-C-K-F
s = (char*) malloc(sizeof(char));
i = (int*) malloc(sizeof(int));
*i = 1;

printf("\n\n\tInserire temperatura: ");
scanf(" %f", t);

do {
	printf("\n\n\tInserire unità di misura (C, K, F): ");
	scanf(" %c", s);
} while(*s != 'C' && *s != 'K' && *s != 'F');

if(*s == 'C') {
	*(t+1) = *t;
	*(t+2) = *t + OFFSET_CELSIUS;
	*(t+3) = *t*SLOPE_FAHRENHEIT + OFFSET_FAHRENHEIT;
}
else if(*s == 'K') {
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
free(s);
free(i);

return 0;
}