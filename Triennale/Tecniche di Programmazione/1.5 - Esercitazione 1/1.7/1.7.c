#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {

int N, min = INT_MAX;
printf("\n\n\tVerrà restituito il minimo dei numeri scritti.\n\n");
do{
	printf("\tInserire numero: ");
	scanf("%d", &N);
	if(N < min) min = N;

} while(N != 0);

printf("\n\tIl più piccolo valore inserito è %d.\n\n", min);
return(0);
}