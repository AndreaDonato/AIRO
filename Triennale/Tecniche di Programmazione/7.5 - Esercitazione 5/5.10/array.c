#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#define M 256



char *constcharstar_to_charstar(const char *mystring)
{
	char *clone = (char*) malloc((strlen(mystring))*sizeof(char));
	strcpy(clone, mystring);
	return clone;
}

//5.10 - Funzione che ordina per lunghezza un array di stringhe
void sort_strings(char **s)
{
	char *temp;
	int i = 0, j;

	while(s[i] != NULL)
	{
		//printf("\n\tNo problem in while condition i = %d...", i); fflush(stdout); sleep(1);
		j = 0;
		while(s[j+i+1] != NULL)
		{
			//printf("\n\tNo problem in while condition j = %d...", j); fflush(stdout); sleep(1);
        	if(strlen(s[j]) < strlen(s[j+1]))
        	{
        		temp = s[j];
          		s[j] = s[j+1];
          		s[j+1] = temp;
         	}
         	j++;
		}
		i++;
	}
}

char **get_N_strings(int N)
{
	printf("\n");
	char **s;
	s = (char**) malloc((M+1)*sizeof(char*));
	for (int i = 0; i < N; ++i)
	{
		s[i] = (char*) malloc(M*sizeof(char));
		printf("\n\tScrivi la stringa #%d:\t", i);
		fgets(s[i], M, stdin);
	}
	s[N] = NULL;
	printf("\n");
	return s;
}

void print_strings(char **s)
{
	printf("\n");
	int i = 0;
	while (s[i] != NULL)
	{
		//printf("\n\tNo problem in while condition..."); fflush(stdout); sleep(1);
		printf("\n\t%s", s[i]);
		//printf("\n\tNo problem in s[i] print..."); fflush(stdout); sleep(1);
		i++;
	}
	printf("\n");	
}


int main(int argc, char const *argv[])
{
	if (argc != 2) {fprintf(stderr, "\n\n\tNB: ./array n_strings\n\n"); exit(1);}
  	int n;
	n = atoi(argv[1]);
	char **strings;
	strings = get_N_strings(n);
	//printf("\n\tGot N strings..."); fflush(stdout); sleep(1);
	//printf("\n\tHere's an example: s[0] = %s", strings[0]);
	printf("\n\tInput:");
	print_strings(strings);
	sort_strings(strings);
	printf("\n\tOutput:");
	print_strings(strings);
	return 0;
}