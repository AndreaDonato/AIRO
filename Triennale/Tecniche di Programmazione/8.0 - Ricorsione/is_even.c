#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_lib.h"
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#define upper_lower_distance 32
#define upper_start 65
#define upper_end 90
#define lower_start 97
#define lower_end 122
#define N 256

char *get_string()
{
	char *s;
	s = (char*) malloc(N*sizeof(char));
	printf("\n\tScrivi pure: ");
	fgets(s, N, stdin);
	return s;
}


bool is_even(char *s)
{

}



int main(int argc, char const *argv[])
{
	char *s;
	s = get_string();
	printf("\n\tThis sentence is");
	if(is_even(s)) printf(" not");
	printf(" true\n\n");
	free(s);
}