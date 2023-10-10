#include <stdio.h>
#include <math.h>

int main() {

char c;
int first_sum = 0, n = 0, esp, sum = 0;

printf("\n");

do {
	printf("\n\tInserisci la prossima lettera del tuo nome (* per terminare): ");
	scanf(" %c", &c);
	first_sum += (int)c;
} while(c != '*');

sum = first_sum;
do {
	first_sum = sum;
	sum = 0;
	for(esp = (int)log10(first_sum); esp >= 0; esp--) {
		printf("\n\n\tProgresso operazioni interne: Cifre da sommare = %d\tEsponente di taglio = %d", first_sum, esp);
		n = first_sum/(int)pow(10, esp);
		sum += n;
		first_sum -= n*pow(10, esp);
		printf("\tCifra ottenuta = %d\tSomma parziale = %d.", n, sum);
	}
} while(sum > 9 && sum != 11 && sum != 22);

printf("\n\nIl tuo numero magico è %d!\n\n", sum);

return(0);

}
