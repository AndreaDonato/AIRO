#include <stdio.h>
#include <math.h>
#define MIN 124578
#define MAX 166666

int main() {

// Il più piccolo numero candidato straordinario è 124578.

int S = MIN, non_trovato = 1, S_mul, supporto;

while(non_trovato && S <= MAX) {

	int i = 1, candidato = 1;
	
	while(i < 7 && candidato) {
		
		S_mul = S*i;
		//printf("\n\tConsidero %d, ovvero %d*%d.", S_mul, S, i);
		int exp = 1;
		int s1 = 0, s2 = 0, s4 = 0, s5 = 0, s7 = 0, s8 = 0;

		do { 
			supporto = S_mul%(int)pow(10, exp);
			supporto /= (int) pow(10, exp-1);

			switch (supporto) {
				case 1: s1++; break;
				case 2: s2++; break;
				case 4: s4++; break;
				case 5: s5++; break;
				case 7: s7++; break;
				case 8: s8++; break;
				default: candidato = 0;
			}
		//printf("\n\tConsidero %d avente le seguenti cifre con le rispettive frequenze: 1: %d, 2: %d, 4: %d, 5: %d, 7: %d, 8: %d", S_mul, s1, s2, s4, s5, s7, s8);
		//printf("\n\n\ts1 vale %d, ", s1);
		//if (s1 == 2) printf("quindi se vale 2 entro in questo if.\n\n");
		if (s1 == 2 || s2 == 2 || s4 == 2 || s5 == 2 || s7 == 2 || s8 == 2) candidato = 0;
		//if (candidato == 0) printf("\n\tHo messo a zero la variabile candidato.\n\n");
		exp++;
		//printf("\n\texp vale %d\n\n", exp);
		} while(candidato && exp < 7);

		if(exp > 6 && candidato == 1) printf("\n\n\tSono uscito dal ciclo interno perché tutte le cifre compaiono una e una sola volta. %d è una permutazione di 124578.\n", S_mul); 
		//else printf("\n\n\tSono uscito dal ciclo interno perché ho trovato una cifra (%d) che non doveva esserci o che si ripete.\n", supporto);
		i++;
	}

	if(candidato) non_trovato = 0;
	else S++;
}
printf("\n\n\tIl più piccolo numero straordinario è %d.\n\n", S);
}