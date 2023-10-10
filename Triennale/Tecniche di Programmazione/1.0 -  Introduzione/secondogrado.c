# include <stdio.h>
# include <math.h>

int main () {
double a, b ,c ;
printf("Inserisci coefficienti a, b, c:\t") ;
scanf ( "%lf %lf %lf", &a, &b, &c);
double delta = b*b - 4.0*a*c;

if (delta> 0.0) {
	double root = sqrt(delta);
	double root1 = 0.5*(root-b)/a;
	double root2 = -0.5*(root+b)/a;
	printf("Radici reali: %lf e %lf\n", root1, root2);
	}
else if (delta<0.0) {
	double root = sqrt(-delta);
	double real_part = -0.5*b/a;
	double imag_part = 0.5*root/a;
	printf ( "Radici complesse: %lf + i*%lf e %lf - i*%lf \n", real_part, imag_part, real_part, imag_part) ;
	}
else {
	double root1 = -0.5* b / a ;
	printf ( "Radici coincidenti: %lf\n", root1);
	}

return 0;
}