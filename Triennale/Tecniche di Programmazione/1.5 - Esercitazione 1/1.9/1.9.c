#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {

int dec = 0, N, exp = 0;

printf("\n\n\tInserire un numero in binario dal bit meno significativo. 9 per terminare.\n\n");

do{
	printf("\tCoefficiente di 2^%d: ", exp);
	scanf("%d", &N);
	if(N && N != 9) dec += pow(2, exp);
	exp++;

} while(N != 9);

printf("\n\tConversione in decimale: %d.\n\n", dec);
return(0);
}