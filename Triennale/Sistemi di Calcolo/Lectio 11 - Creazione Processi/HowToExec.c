#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{

	if(argc < 2)
	{
		printf("Usage: %s executable param1 param2 ...\n", argv[0]); fflush(stdout);
		exit(1);
	}
	
	char* my_argv[argc-1];
	int i = 1;

	while(i < argc)
	{
		my_argv[i-1] = (char*) argv[i];
		i++;
	}
	my_argv[i-1] = NULL;

	pid_t pid = fork();

	if(pid == -1)
	{
		perror("Fork error");
		exit(1);
	}
	else if(pid == 0)
	{
		int res = execvp(argv[1], my_argv);
		perror("Errore nella execvps"); fflush(stdout);
		printf("Questa riga viene eseguita solo se non è stato possibile lanciare il programma\n"); fflush(stdout);
	}
	else
	{
		wait(NULL);
	}

	return 0;
}