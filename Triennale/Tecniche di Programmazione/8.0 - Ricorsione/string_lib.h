#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#define upper_lower_distance 32
#define upper_start 65
#define upper_end 90
#define lower_start 97
#define lower_end 122


char *constcharstar_to_charstar(const char *mystring)
{
	char *clone = (char*) malloc((strlen(mystring))*sizeof(char));
	strcpy(clone, mystring);
	return clone;
}

// 6.3
int length(char *s)
{
	if(s[0] == '\n' || s[0] == '\0') return 1;
	else return 1+length(s+1);
}

// 6.4 (NB: è impossibile senza una funzione di supporto)
int support(char *s, char ch)
{
	if(s[0] == ch) return 0;
	else 
	{
		if(s[0] == '\n' || s[0] == '\0') return 1;
		else return 1+support(s+1, ch);
	}
}

int char_position(char* s, char ch)
{
	int position;
	position = support(s, ch);
	if(position >= length(s)) return -1;
	else return position;
}
// 6.4 variante è simile, parte da fine stringa e decrementa
// Serve anche un controllo su quando finisci la stringa
// Insomma, non mi va di farlo
// Carino come lo fa nella soluzione ufficiale


// 6.5
bool is_lowercase(char *s)
{
	//printf("\n\tis_lowercase execution on letter %c having ASCII serial %d", s[0], s[0]); fflush(stdout); sleep(1);

	if(s[0] == '\0' || s[0] == '\n') return true;
	
	else if((int)s[0] >= upper_start && (int)s[0] <= upper_end)
		{
			//printf("\n\tis_lowercase execution on letter %c having ASCII serial %d, evalueted as NOT LOWERCASE", s[0], s[0]); fflush(stdout); sleep(1);
			return false;
		}

	else 
	{
		if(is_lowercase(s+1)) return true;
		else return false;
	}
}


// 6.6
void to_uppercase(char *s)
{
	if((int)s[0] >= lower_start && (int)s[0] <= lower_end)
	{
		s[0] -= upper_lower_distance;
		to_uppercase(s+1);
	}
	else if (s[0] == '\n');
	else to_uppercase(s+1);
}


// 6.7
void copy_support(char *dest, char *src)
{
	if(src[0] != '\0')
	{
		dest[0] = src[0];
		copy_support(dest+1, src+1);
	}
	else
	{
		dest = src;
	}
}
void copy(char *dest, char *src)
{
	if(realloc(dest, length(src)*sizeof(char)) != NULL) copy_support(dest, src);
}


// 6.8
void concat(char *dest, const char *src)
{
	if(src[0] != '\0')
	{
		if(realloc(dest, (length(dest)+1)*sizeof(char)) != NULL)
			{
				dest[length(dest)-1] = src[0];		//NB: Questa scrittura taglia il \n dovuto al presunto inserimento da tastiera di dest, in generale taglia l'ultimo carattere prima di \0
				concat(dest, src+1);
			}
	}
}

