#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matrix.h"
#include <unistd.h>
#include <stdbool.h>

// Tre pile: sorgente, destinazione, ausiliario (A, B, C)
// Si trova iterando che l'algoritmo può essere diviso in tre fasi:
//	1	Sposto N-1 dischi da A a C;
//	2	Sposto il disco di base da A a B;
//	3	Sposto N-1 dischi da C a B.
// Tre cose da notare:
// 		Il passo 3 per N dischi è identico all'intero algoritmo per N-1 dischi;
//		Il passo 1 per N dischi è identico al passo 1 per N-1 dischi se si invertono B e C;
//		Il passo 2 si trova sempre invariato in mezzo ai passi 1 e 3.

int first_zero_index(int_matrix *t, int *row)
{
	//printf("\n\tEntering first_zero_index, all good"); fflush(stdout); sleep(1);
	for(int i = 0; i < t->col; i++) if(row[i] == 0) return i;
}

void step(int_matrix *t, int from, int to)
{
	//printf("\n\tEntering step, all good"); fflush(stdout); sleep(1);
	t->element[to][first_zero_index(t, t->element[to])] = t->element[from][first_zero_index(t, t->element[from])-1];
	t->element[from][first_zero_index(t, t->element[from])-1] = 0;
	int_matrix_print(t);
}

void hanoi_towers(int_matrix *t, int N, int A, int B, int C, int *count)
{
	//printf("\n\tEntering hanoi_towers, all good"); fflush(stdout); sleep(1);

	if(N == 1) 
	{
		//printf("\n\tEntering if, all good"); fflush(stdout); sleep(1);
		step(t, A, B);
		(*count)++;
	}

	else
	{	
		//printf("\n\tEntering else, all good. count = %d", *count); fflush(stdout); sleep(1);
		hanoi_towers(t, N-1, A, C, B, count);
		step(t, A, B);
		(*count)++;
		hanoi_towers(t, N-1, C, B, A, count);
	}
}


int main(int argc, char const *argv[])
{
	int N, *count;
	int_matrix *hanoi;

	printf("\n\tInserisci il numero di dischi: ");
	scanf("%d", &N);

	count = (int*) calloc(1, sizeof(int));

	// Rappresentazione grafica delle torri (situazione iniziale)
	hanoi = int_matrix_alloc(3, N, constcharstar_to_charstar("Hanoi"));
	int_matrix_hanoi_fill(hanoi);
	int_matrix_print(hanoi);

	// Soluzione del problema
	hanoi_towers(hanoi, N, 0, 1, 2, count);

	printf("\n\tIl problema delle torri di Hanoi con %d dischi si risolve in %d mosse\n\n", N, *count);
			//Il problema delle torri di Hanoi con N dischi si risolve in 2^N - 1 mosse
	free(count);
	int_matrix_free(hanoi);
	return 0;
}

