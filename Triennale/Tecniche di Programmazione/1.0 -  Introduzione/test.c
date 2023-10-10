/* esempio richiamato a lezione, lezione 6 */
#include <stdio.h>

int main () {
double f1=3.14, f2=0.00000313; 
  
  printf ("bla bla ... %f\n", f1);
  printf ("bla bla ... %e\n", f1);
  printf ("bla bla ... %f\n", f2);
  printf ("bla bla ... %e\n", f2);
  printf ("bla bla ... %g\n", f2);
  printf ("bla bla ... %g\n", f1);

f2=0.000313;
  printf ("\nbla bla ... %f\n", f2);
  printf ("bla bla ... %e\n", f2);
  printf ("bla bla ... %g\n", f2);

printf ("\nFINE programma\n");
getchar();
getchar();
return 0;
}