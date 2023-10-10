#include <stdio.h>

int main() {

int N, i, j;
printf("\n\n\tInserire N intero per generare un perimetro quadrato di lato N: ");
scanf("%d", &N);
printf("\n\n");

for(i = 1; i <= N; i++)
{
	printf("\t");
	for(j = 1; j <= N; j++)
	{
		if(i == 1 || j == 1 || i == N || j == N) printf("* ");
		else printf("  ");
	}
	printf("\n");
}

printf("\n\n");
return(0);
}