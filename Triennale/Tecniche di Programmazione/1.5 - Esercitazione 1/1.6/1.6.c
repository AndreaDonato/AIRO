#include <stdio.h>
#include <math.h>

int main() {

int M, N, i, j, l, switch_riga = 0, switch_colonna = 0;
printf("\n\n\tVerrà realizzata una scacchiera di dimensioni N*M x N*M con blocchi di asterischi M*M.");
do{
	printf("\n\n\tInserire M intero ed N multiplo di M: ");
	scanf("%d%d", &M, &N);
} while(N%M != 0);

for(i = 1; i <= M*N; i++) {
	
	for(j = 1; j <= M*N; j++) {
		
		if(switch_riga^switch_colonna) printf("  ");
		else printf("* ");		

		if(j%M == 0) switch_colonna = ~switch_colonna;
	}

	printf("\n");
	if(i%M == 0) switch_riga = ~switch_riga;
}
return(0);
}