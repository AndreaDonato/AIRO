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

char* capitalizer(const char s[]);
char** capitalizer_strings(const char* s[], int len);

int main(int argc, char const *argv[])
{
	const char p[] = "sALve a tUTtI";
	const char *s = NULL;
	s = capitalizer(p);
	printf("\n\tp = %s", p);
	printf("\n\ts = %s\n", s);

	// Bah è una merda inutile.



	return 0;
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

char** capitalizer_strings(const char* s[], int len)
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