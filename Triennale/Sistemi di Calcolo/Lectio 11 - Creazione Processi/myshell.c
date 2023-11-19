#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1024
#define MAX_TOKENS 50


int main(int argc, char const *argv[])
{

	/* +++   SE LA SHELL VIENE CHIAMATA CON ARGOMENTI   +++ */
	if(argc > 1)
	{	
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
			wait(NULL);
	}




	/* +++   NUOVO COMANDO   +++ */

    char input[MAX_INPUT_LENGTH];
    char *tokens[MAX_TOKENS];
    char *token;

	printf("$ ");
    if (fgets(input, sizeof(input), stdin) == NULL) {
        perror("Errore durante la lettura dell'input");
        exit(EXIT_FAILURE);
    }
    // Rimuovi il carattere di nuova linea se presente
    char *newline = strchr(input, '\n');
    if (newline != NULL) {
        *newline = '\0';
    }
    // Inizializza il vettore di puntatori a stringa
    for (int i = 0; i < MAX_TOKENS; ++i) {
        tokens[i] = NULL;
    }
    // Usa strtok per estrarre i token
    token = strtok(input, " ");
    if(token == NULL)
	{
	   	char* my_argv[] = {"./myshell", NULL};
		int res = execvp("./myshell", my_argv);
    }
    if(strcmp(token, "quit") == 0) exit(0);


    int i = 0;
    while (token != NULL && i < MAX_TOKENS - 1) {
        tokens[i] = token;
        token = strtok(NULL, " ");
        i++;
    }


    /*//Stampa i token
    for (int j = 0; j < MAX_TOKENS && tokens[j] != NULL; ++j) {
        printf("Token %d: %s\n", j + 1, tokens[j]);
    }*/




    /*   +++   ESECUZIONE COMANDO   +++ */
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("Fork error");
		exit(1);
	}
	else if(pid == 0)
	{
		int res = execvp(tokens[0], tokens);
		perror("Errore nella execvps"); fflush(stdout);
		printf("Questa riga viene eseguita solo se non è stato possibile lanciare il programma\n"); fflush(stdout);
	}
	else
	{
		wait(NULL);
		char* my_argv[] = {"./myshell", NULL};
		int res = execvp("./myshell", my_argv);
		perror("Errore nella execvps"); fflush(stdout);
		printf("Questa riga viene eseguita solo se non è stato possibile lanciare il programma\n"); fflush(stdout);
	}


	return 0;
}