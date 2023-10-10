#include <stdio.h>
#include <math.h>

int main() {

int N, i, j = 1, n = 1;

printf("\n\n\tInserire N intero: ");
scanf("%d", &N);


do {
	printf("\n\t");
	for(i = 0; i < j; i++) {
		printf("%d ", n);
		n++;
	}
	j++;
} while(j <= N);

printf("\n\n");

return(0);
}
