#include <stdio.h>
#include <math.h>
#include <limits.h>

int main() {

int N, i;

printf("\n\n\tQuanti asterischi vuoi vedere stavolta? \n\n\t");
scanf("%d", &N);

while(N != 0) {
	printf("\n\t");
	for(i = 0; i < N; i++) printf("*");
	printf("\n\n\tQuanti asterischi vuoi vedere stavolta? \n\n\t");
	scanf("%d", &N);
}

return(0);
}