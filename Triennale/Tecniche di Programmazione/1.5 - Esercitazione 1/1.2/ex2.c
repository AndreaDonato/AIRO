#include <stdio.h>

int main()
{

float media = 0, valore;
int counter = 0;

do {
	printf("\n\tInserire un valore da includere nella media aritmetica (0 per terminare): ");
	scanf("%f", &valore);
	counter++;
	media += valore;		//Notare che eventuali caratteri ASCII al posto di numeri verranno interpretati con la loro posizione ASCII.
	}
	while(valore != 0);

counter = (float)counter;
printf("\n\tLa media aritmetica dei numeri inseriti in input è pari a %f.\n\n", media/counter);
return(0);

}