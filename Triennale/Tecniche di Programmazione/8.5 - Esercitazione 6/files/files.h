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

void filter_write(char *s, FILE *filename)
{
	if((int)s[0] >= lower_start && (int)s[0] <= lower_end)
	{
		fputc(s[0], filename);
		filter_write(s+1, filename);
	}
	else if (s[0] == '\0');
	else filter_write(s+1, filename);
}

void compare_letter(FILE *f1, FILE *f2)
{

}
bool same_content(FILE *f1, FILE *f2)
{
	//printf("\n\tEntering same_content..."); fflush(stdout); sleep(1);
	char c1, c2;
	c1 = fgetc(f1);
	//printf("\n\tNo problem with fgetc(f1) function"); fflush(stdout); sleep(1);

	c2 = fgetc(f2);
	//printf("\n\tNo problem with fgetc(f2) function"); fflush(stdout); sleep(1);

	if(c1 == EOF && c2 == EOF) 
	{
		//printf("\n\tComparing c1 == EOF raised no error..."); fflush(stdout); sleep(1);
		return true;
	}

	else if(c1 != c2) 
	{
		//printf("\n\tHey, I noticed that %c is different from %c...", c1, c2); fflush(stdout); sleep(1);
		return false;
	}

	else 
	{
		//printf("\n\tHey, I noticed that %c and %c are the same char...", c1, c2); fflush(stdout); sleep(1);
		if(same_content(f1, f2)) return true;
		else return false;
	}
}