//Campo d'azione di una variabile

# include <stdio.h>
# include <math.h>
int main () {
double a = 2.3;															// a double
int i = 1;																// i int
printf ( " liv . 0 a= % f \n " , a );									// 2.3
printf ( " liv . 0 i= % d \n " , i ) ;									// 1
	
{
	printf(" liv . 1 a = % f \n " , a ) ;								// 2.3
	printf( " liv . 1 i = % d \n " , i ) ;								// 1

	double i = 0.1;														// Ridefinisco i double

	{
		double r = 5.5;													// Definisco r
		i = i + 1;
		printf ( " liv . 2.1 r = % f \n " , r ) ;						// 5.5
		printf ( " liv . 2.1 i = % f \n " , i ) ;						// 1.1
	}

	// printf (" liv . 1 r = % f \ n " , r );							// r non è definita al di fuori del blocco più interno: questa istruzione darebbe errore!
	printf ( " liv . 1 i = % f \n " ,i ) ;

}}