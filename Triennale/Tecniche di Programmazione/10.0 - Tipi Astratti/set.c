#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "setSCL.h"
#include <unistd.h>
#include <stdbool.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	set s;
	s = empty_set();
	SET_Add(&s, 3);
	SET_Add(&s, 2);
	SET_Add(&s, 1);
	sleep(5);
	SET_Print(s);
	free(s);
	return 0;
}