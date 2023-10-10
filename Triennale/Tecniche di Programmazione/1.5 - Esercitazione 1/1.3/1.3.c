#include <stdio.h>

int main() {

int N, i, j;
printf("\n\n\tInserire N intero per generare un quadrato di lato N: ");
scanf("%d", &N);
printf("\n\n");

for(i = 0; i < N; i++)
{
	printf("\t");
	for(j = 0; j < N; j++)
	{
		printf("* ");
	}
	printf("\n");
}

printf("\n\n");
return(0);
}