#include <stdlib.h>
#include <string.h>

char *constcharstar_to_charstar(const char *mystring)
{
	char *clone = (char*) malloc((strlen(mystring))*sizeof(char));
	strcpy(clone, mystring);
	return clone;
}