#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define N 256
#define upper_lower_distance 32
#define upper_start 65
#define upper_end 90
#define lower_start 97
#define lower_end 122

void print_chars(const char s[], const int idxs[], int dim);
char* select_chars(const char s[], const int idxs[], int dim);
char* capitalizer(const char s[]);
char* invert_string(const char s[]);
char* mocking_spongebob(const char s[], int step);
char* capitalizer(const char s[]);
char** capitalizer_strings(char* s[], int len);			// const char* s[] è una merda inutile.

int main(int argc, char const *argv[])
{
	char *s;
	s = (char*) malloc(N*sizeof(char));
	printf("\n\tScRIvi puRE: ");
	// gtrsdfgadfgLVfe a tUtiti
	fgets(s, N, stdin);
	printf("\n\tHai inserito: %s", s);
	//4.5
	int indici[] = {3, 7, 11, 266, 12, 14, 15, 16, 17, 388, 18, 19, 20, 22, 23};
	print_chars(s, indici, sizeof(indici)/sizeof(int));
	
	//4.6
	char *p;
	p = select_chars(s, indici, sizeof(indici)/sizeof(int));
	printf("\n\tNuova stringa p: %s\n", p);

	//4.7
	char *reverse;
	reverse = invert_string(p);
	printf("\n\tStringa p invertita: %s\n", reverse);

	//4.8
	char *mock;
	mock = mocking_spongebob(p, 2);
	printf("\n\tStringa p Spongebob: %s\n", mock);

	//4.9
	char *caps;
	caps = capitalizer(p);
	printf("\n\tStringa p pettinata: %s\n", caps);

	// 4.10
	char **inception, **inception_pettinata;
	//char* prova = (char*) malloc(20*sizeof(char));
	//strcpy(prova, "sTriNGa dI pROva !");									// Stringa in heap da codice sorgente (oppure char *prova = strdup("sTriNGa dI pROva !");)
	inception = (char**) calloc(4, sizeof(char*));
	for(int i = 0; i<4; i++) inception[i] = (char*) calloc(N, sizeof(char));
	strcpy(inception[0], "sTriNGa pROva");		// Non posso assegnarla perché è una conversione implicita da const char (stringa) a char*.
	inception[1] = p;
	inception[2] = reverse;
	inception[3] = mock;
	inception_pettinata = capitalizer_strings(inception, 4);
	printf("\n\n\tIndice\tPrima\t\tDopo\n");
	for(int i = 0; i < 4; i++)
	{
		printf("\n\t%d\t'%s'\t'%s'", i, inception[i], inception_pettinata[i]); fflush(stdout);
	}
	printf("\n\n");
	free(s);
	//free(p); free(reverse); free(mock); BISOGNA SCEGLIERE TRA QUESTI FREE E QUELLI DEL CICLO SOTTO INCEPTION[i], FANNO RIFERIMENTO ALLA STESSA AREA DI MEMORIA!
	free(caps);
	for(int i = 0; i < 4; i++)
	{
		free(inception[i]);
		free(inception_pettinata[i]);
	}
	free(inception);
	free(inception_pettinata);

	return 0;
}



void print_chars(const char s[], const int idxs[], int dim)
{
	printf("\n\t"); fflush(stdout);
	//sleep(1);
	for(int i = 0; i < dim; i++)
	{
		if(idxs[i] < strlen(s)) printf("%c", s[idxs[i]]);
	}
	printf("\n");
}

char *select_chars(const char s[], const int idxs[], int dim)
{
	char *new_string;
	new_string = (char*) malloc(dim*sizeof(char));
	int i = 0, j = 0;

	while(i<dim)
	{
		if(idxs[i] < N)
		{
			if(s[idxs[i]] != '\n') new_string[j] = s[idxs[i]];
			j++;
		}
		i++;
	}
	return new_string;
}

char* invert_string(const char s[])
{
	char *inverted;
	int dim;
	dim = strlen(s);
	//while(s[dim] != '\0') dim++;
	//if(strlen(s) == dim) printf("DDUBVJDBVEBDLOVBVDBLBVDD"); fflush(stdout);
	//printf("\n\tdim=%d", dim); fflush(stdout);
	inverted = (char*) calloc(dim, sizeof(char));
	for(int i = 0; i < dim; i++)
	{
		inverted[i] = s[dim-2-i]; //-2 per skippare \n
		//printf("\n\tHo copiato s[%d]=%c in inverted[%d] = %c", dim-1-i, s[dim-1-i], i, inverted[i]); fflush(stdout);
		//sleep(1);
	}
	return inverted;
}

char* mocking_spongebob(const char s[], int step)
{
	char *mock;
	int i = 0, dim = 0, is_step, is_caps, is_letter;
	
	while(s[dim] != '\0') dim++;	//ovvero strlen(s)
	mock = (char*) calloc(dim, sizeof(char));
	
	while(s[i] != '\0')
	{
		mock[i] = s[i];
		// Controllo se: l'indice corrisponde a uno step, ho preso una lettera maiuscola, ho preso una lettera;
		is_step = (i%step==0);
		is_caps = ((int)s[i] >= upper_start && (int)s[i] <= upper_end);
		is_letter = (is_caps || ((int)s[i] >= lower_start && (int)s[i] <= lower_end));
		//printf("\n\ts[%d] = %c, quindi is step = %d, is_caps = %d, is_letter = %d", i, s[i], is_step, is_caps, is_letter);

		if(is_letter)
		{
			if(is_step && !is_caps) mock[i] -= upper_lower_distance;
			else if(!is_step && is_caps) mock[i] += upper_lower_distance;
		}
		i++;
	}
	return mock;
}

char* capitalizer(const char s[])
{
	char *proper;
	int i = 0, dim = 0, is_first, is_caps, is_letter = 0;
	
	while(s[dim] != '\0') dim++;
	proper = (char*) calloc(dim, sizeof(char));
	
	while(s[i] != '\0')
	{
		proper[i] = s[i];
		// Controllo se: l'indice corrisponde a una iniziale, ho preso una lettera maiuscola, ho preso una lettera;
		is_first = (!is_letter);
		is_caps = ((int)s[i] >= upper_start && (int)s[i] <= upper_end);
		is_letter = (is_caps || ((int)s[i] >= lower_start && (int)s[i] <= lower_end));
		//printf("\n\ts[%d] = %c, quindi is_first = %d, is_caps = %d, is_letter = %d", i, s[i], is_first, is_caps, is_letter);

		if(is_letter)
		{
			if(is_first && !is_caps) proper[i] -= upper_lower_distance;
			else if(!is_first && is_caps) proper[i] += upper_lower_distance;
		}
		i++;
	}
	return proper;
}

char** capitalizer_strings(char* s[], int len)
{
	char **pettinate, *singola;

	pettinate = (char**) calloc(len, sizeof(char*));

	for(int i = 0; i < len; i++)
	{
		pettinate[i] = (char*) calloc(strlen(s[i]), sizeof(char));
		pettinate[i] = capitalizer(s[i]);
	}
	return pettinate;
}