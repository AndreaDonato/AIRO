#include <stdio.h>

int main() {

double a, b;

printf("\n\tInserire i valori di a e b: ");
scanf("%lf%lf", &a, &b);

if(a == 0) {printf("\n\tNessun valore di x può soddisfare questa equazione.\n\n"); return(1);}
else {printf("\n\tPer coefficienti a = %lf e b = %lf x vale %lf.\n\n", a, b, -b/a);}

return(0);
}