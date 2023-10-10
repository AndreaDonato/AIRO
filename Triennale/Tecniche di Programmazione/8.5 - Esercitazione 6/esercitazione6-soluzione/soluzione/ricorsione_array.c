#include <stdio.h>
#include <stdlib.h>


float product(float vec[], int n);
void vec_integral(float v[], int n);

void vec_print(float *v, int dim);


int main(void) {


	float vec[] = {3.1, -2.3, 5.8, 1.4, -0.3, 4.1, 0.1};
	int n1 = sizeof(vec) / sizeof(vec[0]);
	printf("Dato il  vettore:\n");
	vec_print(vec, n1);

	float prodotto_res = product(vec, n1);
	printf("\nIl prodotto delle componenti del vettore  è: %f\n", prodotto_res);

	vec_integral(vec, n1);
	printf("\nIl risultato di integral e':\n");
	vec_print(vec, n1);
	printf("\n\n");

}


float product(float vec[], int n)
{

	if (n == 0)
	{
		return 1;
	}
	else
	{
		return vec[0] * product(vec + 1, n - 1);
	}
}

void vec_integral_aux(float *v, int n, int i, float sum_till_now)
{
	if (i == n)
		return;
	*v += sum_till_now;
	i++;
	vec_integral_aux(v + 1, n, i, *v);
}


void vec_integral(float v[], int n)
{
	if (n == 0)
		return;

	int i = 0;
	vec_integral_aux(v, n, i, 0);
}


void vec_print(float v[], int dim)
{
	if (dim <= 0) return;
	printf("%f ", *v);
	vec_print(v + 1, dim - 1);
}
