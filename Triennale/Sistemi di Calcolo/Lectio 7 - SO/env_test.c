#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char const *argv[])
{
	int result = setenv("PIPPO", "100", 1);
	if(result == -1)
	{
		perror("\n\tErrore in setenv!");

		//switch errno
		
		 
		
	}
	return 0;
}