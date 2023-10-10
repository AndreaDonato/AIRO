#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BUFF_SIZE 20


int length(const char *s);
int char_position(const char *s, char ch);
int char_last_position(const char *s, char ch);
bool is_lowercase(const char *s);
bool is_any_lowercase(const char *s);
void to_uppercase(char *s);
void copy(char *dest, const char *src);
void concat(char *dest, const char *src);


int main(int argc, char **argv) {
		
	//inizializza parametri stringhe
	char s[] = "ASsfQg";
	char s_variante[] = "mMapOlaTT";
	printf("Data la stringa \"%s\"\n", s);

	//calcolo lunghezza
	int value = length(s);
	printf("La sua lunghezza e': %d\n\n", value);

	//check carattere
	char ch = 'z';
	int index = char_position(s, ch);
	printf("%c in %s? %d\n", ch, s, index);
	ch = 'f';
	index = char_position(s,ch);
	printf("%c in %s? %d\n\n", ch, s, index);

	//check ultimo carattere
	ch = 'a';
	index = char_last_position(s_variante, ch);
	printf("%c in %s? %d\n", ch, s_variante, index);
	ch = 'Z';
	index = char_last_position(s_variante, ch);
	printf("%c in %s? %d\n\n", ch, s_variante, index);

	//check minuscole
	char s1[] = "questeinvecesi";
	printf("In \"%s\"%ssono tutte minuscole\n", s, is_lowercase(s)? " ": " non ");
	printf("In \"%s\"%ssono tutte minuscole\n\n", s1, is_lowercase(s1)? " ": " non ");

	//converti maiuscole-minuscole
	printf("%s in maiuscolo: ", s);
	to_uppercase(s);
	printf("%s\n\n", s);

	//check almeno una minuscola
	printf("In \"%s\"%sc'è una minuscola\n", s, is_any_lowercase(s)? " ": " non ");
	printf("In \"%s\"%sc'è una minuscola\n", s_variante, is_any_lowercase(s_variante)? " ": " non ");
	printf("In \"%s\"%sc'è una minuscola\n\n", s1, is_any_lowercase(s1)? " ": " non ");


	const char s2[BUFF_SIZE] = "1234";
	char *s3 = (char *)malloc(BUFF_SIZE * sizeof(char));

	copy(s3, s2);
	printf("Copio la stringa \"%s\": %s\n", s2, s3);

	printf("Concateno le due stringhe\n");
	concat(s3, s2);
	printf("Stringa concatenata: %s\n\n", s3);
}


int length(const char *s)
{

	if (*s == '\0')
	{
		return 0;
	}
	else
	{
		return 1 + length(s + 1);
	}
}


int char_position_aux(const char *s, char ch, int i)
{

	if (*s == '\0')
	{
		return -1;
	}
	else if (*s == ch)
	{
		return i;
	}
	else
	{
		return char_position_aux(s + 1, ch, i + 1);
	}
}

int char_last_position_aux(const char *s, char ch, int i)
{
	if (i == -1) {
		return -1;
	}
	else if (s[i] == ch){
		return i;
	}
	else {
		return char_last_position_aux(s, ch, i-1);
	}
}


int char_position(const char *s, char ch)
{
	int i = 0;
	return char_position_aux(s, ch, i);
}

int char_last_position(const char *s, char ch)
{
	int dim = length(s);
	return char_last_position_aux(s, ch, dim);
}


bool is_lowercase(const char *s)
{

	if (*s == '\0')
	{
		return true;
	}
	else if (*s >= 'a' && *s <= 'z')
	{
		return is_lowercase(s + 1);
	}
	else
	{
		return false;
	}
}

bool is_any_lowercase(const char *s)
{
	if (*s == '\0')
	{
		return false;
	}
	else if (*s >= 'a' && *s <= 'z')
	{
		return true;
	}
	else
	{
		return is_any_lowercase(s + 1);
	}
}


void to_uppercase(char *s)
{

	if (*s == '\0')
	{
		return;
	}
	if (*s >= 'a' && *s <= 'z')
	{
		*s = *s + 'A' - 'a';
	}
	return to_uppercase(s + 1);
}


void copy(char *dest, const char *src)
{

	if (*src == '\0')
	{
		*dest = '\0';
		return;
	}
	else
	{
		*dest = *src;
		return copy(dest + 1, src + 1);
	}
}


void concat(char *dest, const char *src)
{

	if (*dest == '\0')
	{
		copy(dest, src);
	}
	else
	{
		return concat(dest + 1, src);
	}
}
