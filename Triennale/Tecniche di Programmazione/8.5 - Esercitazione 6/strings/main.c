#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "string_lib.h"
#include <unistd.h>
#include <stdbool.h>
#define N 256


int main(int argc, char const *argv[])
{
	char *s, *c, *new_string;
	s = (char*) malloc(N*sizeof(char));
	c = (char*) malloc(2*sizeof(char));
	new_string = (char*) malloc(N*sizeof(char));

	printf("\n\tStringa: ");
	fgets(s, N, stdin);
	printf("\n\tHai inserito: %s", s);

	printf("\n\tCarattere: ");
	fgets(c, 2, stdin); getchar();		// ... ma perché dovete scrivere le funzioni basilari MALE?
	// 6.3
	printf("\n\tLa stringa inserita è lunga [%ld (secondo strlen)], [%d (secondo length)]", strlen(s), length(s));

	//6.4
	printf("\n\tIl carattere %c ", *c);
	if(char_position(s, *c) == -1) printf("non ");
	printf("compare nella stringa inserita");
	if(char_position(s, *c) >= 0) printf(" in posizione %d", char_position(s, *c));
	
	//6.5
	printf("\n\tLa stringa inserita");
	if(!is_lowercase(s)) printf(" non");
	printf(" contiene solo lettere minuscole");

	// 6.6
	to_uppercase(s);
	printf("\n\tLa stringa inserita, ma CAPS LOCK: %s", s);

	// 6.7
	printf("\n\tNuova stringa, verrà copiata nell'indirizzo della vecchia: ");
	fgets(s, N, stdin);
	copy(s, new_string);
	printf("\n\tEcco cosa si trova all'indirizzo del primo puntatore: %s", s);
	// 6.8
	printf("\n\tLa nuova stringa, ma è una foto: ");
	concat(s, ".jpg");
	printf("%s\n", s);

	printf("\n\n");
	free(s);
	free(c);
	free(new_string);
	return 0;
}


const char *charstar_to_constcharstar(const char *mystring)
{
	const char *clone = (const char*) malloc((strlen(mystring))*sizeof(const char));
	strcpy(clone, mystring);
	return clone;
}