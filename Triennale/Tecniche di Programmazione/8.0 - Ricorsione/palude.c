#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "matrix.h"
#include <unistd.h>
#include <stdbool.h>

void initPalude(int_matrix *palude, double p)
{
	srand(time(NULL));
	for(int r = 0; r < palude->row; r++)
		for(int c = 0; c < palude->col; c++)
			palude->element[r][c] = rand()/(double) RAND_MAX < p;
}

bool is_valid_spot(int_matrix *palude, int r, int c)
{
	return (r >= 0) && (r < palude->row) && (c >= 0) && (c < palude->col) && palude->element[r][c];
}

bool pathfinder(int_matrix *palude, int_matrix *path, int r, int c)
{
	if(!is_valid_spot(palude, r, c)) return false;
	else
	{
		//printf("\n\tFound sweet spot in (%d %d)", r, c); fflush(stdout); sleep(1);

		path->element[c][0] = r;
	 	path->element[c][1] = c;
	 	if(c == palude->col - 1)
	 		return true; 
		else
			return 	pathfinder(palude, path, r-1, c+1) 	||
					pathfinder(palude, path, r, c+1) 	||
					pathfinder(palude, path, r+1, c+1)	;
	}
}

void swamp_crossing(int_matrix *palude, int_matrix *path)
{
	bool found = false, multiple_paths = false;

	for(int r = 0; r < palude->row; r++)
		if(pathfinder(palude, path, r, 0))
		{
			if(found) multiple_paths = true;
			else
				{
					int_matrix_print(path, false);
					found = true;
				}
		}

	if(!found) printf("\n\tPath not found!\n\n");
	else if(multiple_paths) printf("\n\tMore than one single path was found!\n\n");
	// In realtà questo programma non riesce a spottare tutti i path multipli,
	// ma solo quelli con diverso punto di partenza.
}


int main(int argc, char const *argv[])
{
	int row, col;
	float p;
	int_matrix *palude, *path;

	if (argc != 4) {fprintf(stderr, "\n\n\tNB: ./main #rows #columns #land_probability\n\n"); exit(1);}
  	row = atoi(argv[1]);
  	col = atoi(argv[2]);
  	p = atof(argv[3]);
	if (row <= 0 || col <= 0 || p <= 0 || p > 1)
		{
			fprintf(stderr, "\n\n\tNB: #rows #columns must be positive integers and probability must make sense\n\n");
			exit(1);
		}

	palude = int_matrix_alloc(row, col, constcharstar_to_charstar("Palude"));
	initPalude(palude, p);
	int_matrix_print(palude, true);

	path = int_matrix_alloc(col, 2, constcharstar_to_charstar("Percorso"));
	
	swamp_crossing(palude, path);
	int_matrix_free(path);
	int_matrix_free(palude);
	return 0;
}