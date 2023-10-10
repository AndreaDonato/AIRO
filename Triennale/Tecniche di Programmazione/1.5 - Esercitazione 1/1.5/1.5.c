#include <stdio.h>
#include <math.h>
#define CUT 8

int isbroken(unsigned long long int a, unsigned long long int b, unsigned long long int c, int d);

int main() {

int N, i;
unsigned long long int fib_precedente = 1, fib_successivo = 1, supporto;

printf("\n\n\tInserire N intero (convenientemente > 2) per generare i primi N numeri della sequenza di Fibonacci: ");
scanf("%d", &N);
if(N < 3) {printf("\n\n\tLa sequenza di Fibonacci inizia con 1 1. Si consiglia di inserire un valore di N più rilevante.\n\n"); return(1);}
printf("\n\n\t1 1 ");

for(i = 3; i <= N; i++)
{
	supporto = fib_successivo;
	fib_successivo += fib_precedente;

	//A questo punto del codice ho tre numeri consecutivi della sequenza nell'ordine fib_precedente, supporto, fib_successivo. Posso controllare se il successivo è davvero la somma degli altri due.
	/* if(fib_successivo-supporto != fib_precedente) {printf("\n\n\tLavorando con gli unsigned long long int, per N = %d si rompe la precisione del calcolatore.\n\n", i); return(1);}
	Molto interessante: Questa dovrebbe essere una condizione per individuare il punto in cui il calcolatore mette numeri "a caso". Non funziona. Segue una mia teoria da verificare.
	Non funziona perché non sono a caso. Se faccio c = a+b e c è oltre la precisione del long long int uscirà un numero che MATEMATICAMENTE non è a+b, ma dal punto di vista del calcolatore sì!
	Quindi se faccio un controllo del tipo if(c-a == b), pur essendo matematicamente falso, per il calcolatore risulterà vero!
	Edit: ho scritto una funzione.
	*/
	if(isbroken(fib_precedente, supporto, fib_successivo, CUT)) {
		printf("\n\tPer questa architettura è possibile calcolare al massimo %d numeri della sequenza di Fibonacci.\n\n", i-1);
		exit(1);
	}

	printf("%llu ", fib_successivo);
	fib_precedente = supporto;
	if(i != 0 && i%7 == 0) printf("\n\t");
}

printf("\n\n");

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

	if(flag == 1) printf("\n\n\tLa somma dei numeri %llu e %llu è entrata in contrasto con la precisione numerica del calcolatore.\n", prec, supp);
	//else printf("\n\n\tLa somma dei numeri %llu e %llu è stata eseguita correttamente.\n\n", prec, supp);
	return(flag);
}
