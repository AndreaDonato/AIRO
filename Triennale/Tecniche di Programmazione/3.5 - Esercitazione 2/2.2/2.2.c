#include <stdio.h>
#include <math.h>

int main() {
	
short s;	// Si intende short int
int i;
long l;		// Si intende long int
float f;
double d;


printf("\n\n\tInserire, nell'ordine, {short, int, long, float, double}: ");
scanf("%hd%d%ld%f%lf", &s, &i, &l, &f, &d);
printf("\n");

printf("\n\t s+10*l\t\tvale\t%ld", s+10*l);
printf("\n\t (s+i)*l\tvale\t%ld", (s+i)*l);
printf("\n\t (s+i)*l+f\tvale\t%f", (s+i)*l+f);
printf("\n\t s/f + sin(f)\tvale\t%f", s/f + sin(f));
printf("\n\t l+1.5*f\tvale\t%f", l+1.5*f);
printf("\n\t i<10\t\tvale\t%d", i<10);
printf("\n\t d*3.14159\tvale\t%lf\n\n", d*3.14159);



return(0);
}