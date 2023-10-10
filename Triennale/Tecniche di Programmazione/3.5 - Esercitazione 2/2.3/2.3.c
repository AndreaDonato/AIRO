#include <stdio.h>
#include <math.h>

int main() {
	
int i;
printf("\n\n\tCarattere;\tCodice Carattere.\n");

for(i = 0; i < 256; i++) {
	printf("\n\t%c;\t%d.", i, i);
}

printf("\n\n");


return(0);
}