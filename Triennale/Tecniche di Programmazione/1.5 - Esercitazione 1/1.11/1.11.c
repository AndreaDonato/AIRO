#include <stdio.h>
#include <math.h>

int main() {

int N, M, mcm;

printf("\n\n\tInserire N1 ed N2: ");
scanf("%d%d", &N, &M);

mcm = N>M? M:N;

while(mcm%M != 0 || mcm%N != 0) mcm++;

printf("\n\tIl mcm tra %d e %d è %d\n\n", N, M, mcm);

return(0);
}
