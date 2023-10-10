#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SCL.h"
#include <unistd.h>
#include <stdbool.h>
#define N 256


int main(int argc, char const *argv[])
{
	list l = NULL;
	int n;

	if (argc != 2) {fprintf(stderr, "\n\n\tNB: ./main #LIST_Elements\n\n"); exit(1);}
  	n = atoi(argv[1]);
	if (n <= 0) {fprintf(stderr, "\n\n\tNB: #LIST_Elements must be positive integer\n\n"); exit(1);}
	
	


	return 0;
}