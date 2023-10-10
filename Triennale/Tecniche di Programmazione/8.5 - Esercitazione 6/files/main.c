#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include "files.h"
#define N 256


int main(int argc, char const *argv[])
{
	FILE *fp = fopen("lowercase_message", "w");
	char *s;
	s = (char*) malloc(N*sizeof(char));
	printf("\n\tStringa: ");
	// sDTelGFimBERFbraDFFDdleLLyisDhomunFDGSRculSDFEuSs
	fgets(s, N, stdin);
	//printf("\n\tHai inserito: %s", s);

	// 6.9
	filter_write(s, fp);
	fclose(fp);

	// 6.10
	printf("\n\tNome file da confrontare con quello appena creato: ");
	fgets(s, N, stdin);
    s[strlen(s) - 1] = '\0';
   	fp = fopen("lowercase_message", "r");
   	FILE *fp2 = fopen(s, "r");
	if(fp2 == NULL) {fprintf(stderr, "\n\tError opening file '%s', probably no such file was found\n\n", s); fflush(stdout); exit(1);}

	printf("\n\tIl file '%s'", s); fflush(stdout); sleep(1);
	if(!same_content(fp, fp2)) printf(" non");
	printf(" ha lo stesso contenuto del file 'lowercase_message'\n\n");

	free(s);
	fclose(fp);
	fclose(fp2);
	return 0;
}

