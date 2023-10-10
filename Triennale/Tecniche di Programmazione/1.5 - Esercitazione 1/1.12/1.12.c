#include <stdio.h>
#include <math.h>

int main() {

double x, sqrt_x;
int N, i;

printf("\n\n\tInserire x per conoscerne la radice approssimata: ");
scanf("%lf", &x);
printf("\n\n\tInserire il numero di iterazioni: ");
scanf("%d", &N);
sqrt_x = x;

for(i = 0; i < N; i++) sqrt_x = 0.5*(sqrt_x + x/sqrt_x);

printf("\n\tCon %d iterazioni la radice quadrata approssimata di %lf vale %lf.\n\n", N, x, sqrt_x);

return(0);
}
