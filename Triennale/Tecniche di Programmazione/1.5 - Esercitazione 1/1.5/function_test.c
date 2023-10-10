#include <stdio.h>
#include <math.h>

int isbroken(unsigned long long int a, unsigned long long int b, unsigned long long int c, int d);

int main() {

unsigned long long int a, b, c;
int cut;
printf("\n\n\tInserire a b c interi: ");
scanf("%llu%llu%llu", &a, &b, &c);
printf("\n\n\tInserire il valore di taglio (minore della lunghezza di a, b, c): ");
scanf("%d", &cut);

if(isbroken(a, b, c, cut)) {printf("\n\n\tHo trovato l'errore!\n\n"); return(1);}

return(0);
}



int isbroken(unsigned long long int prec, unsigned long long int supp, unsigned long long int succ, int cut) {
	
	// L'idea è "rompere a metà" i numeri che si sommano in modo da avere un confronto tra due sottonumeri risultato.
	unsigned long long int  prec_sx, prec_dx, supp_sx, supp_dx, succ_sx, succ_dx, risultato_dx = 0, risultato_sx = 0;
	int flag = 0, riporto = 0;
	//printf("\n\n\tFunzione per la verifica di una somma. Dati due numeri e la loro presunta somma, verifica che non vi siano stati errori.\n");
	// Sinistra e destra sono i due pezzi di numero: a = 12345678 con cut = 3 viene spezzato in a_dx = 678 e a_sx = 12345.
	prec_sx = prec/(int)pow(10, cut);
	prec_dx = prec%(int)pow(10, cut);
	supp_sx = supp/(int)pow(10, cut);
	supp_dx = supp%(int)pow(10, cut);
	succ_sx = succ/(int)pow(10, cut);
	succ_dx = succ%(int)pow(10, cut);	
	//printf("\n\t%llu spezzato in %llu e %llu;\n\t%llu spezzato in %llu e %llu;\n\t%llu spezzato in %llu e %llu.\n\n ", prec, prec_sx, prec_dx, supp, supp_sx, supp_dx, succ, succ_sx, succ_dx);

	/*	Il controllo da fare su [precedente + supporto = successivo] è [successivo - precedente = supporto].
		Oppure analogo rifaccio la somma sui numeri spezzati. Magari meglio eh?
	*/

	risultato_dx = prec_dx + supp_dx;
	riporto = risultato_dx/(int)pow(10, cut);
	if(riporto) {
		risultato_sx += riporto;
		risultato_dx %= (int)pow(10, cut);
	}
	risultato_sx += prec_sx + supp_sx;

	//printf("\n\n\tris_dx = %llu, riporto = %d, ris_sx = %llu: numero costruito %llu%llu.", risultato_dx, riporto, risultato_sx, risultato_sx, risultato_dx); DEBUGGING
	if(risultato_dx != succ_dx || risultato_sx != succ_sx) flag = 1;

	if(flag == 1) printf("\n\n\tLa somma dei numeri %llu e %llu è entrata in contrasto con la precisione numerica del calcolatore.\n\n", prec, supp);
	//else printf("\n\n\tLa somma dei numeri %llu e %llu è stata eseguita correttamente.\n\n", prec, supp);
	return(flag);
}

