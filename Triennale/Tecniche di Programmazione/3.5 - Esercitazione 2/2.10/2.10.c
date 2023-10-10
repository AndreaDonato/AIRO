#include <stdio.h>
#include <math.h>

int main() {
	
int i, j, p = 0, flag = 1;

printf("\n\n\tInserire i e j interi: ");
scanf("%d%d", &i, &j);

double k = (double)i/(double)j;
printf("\n\n\tk vale %lf, e alle sue cifre decimali associo", k);

k -= (int)k;					//Rendo k del tipo 0.decimali

while(p < 10 && flag){
	k *= 10;
	printf(" %c", (int)k + p);
	p++;
	if((int)k == k) flag = 0;	// Se k int è identico a k double ho finito i decimali non nulli
}
printf("\n\n");

return 0;
}