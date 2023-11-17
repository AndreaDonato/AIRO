#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>


int main(int argc, char const *argv[])
{
	int x = 0;
	char* s = (char*) malloc(2*sizeof(char));
	int  parentDelay = 0, parentWait = 1;

	do
	{
		printf("\nDesideri che l'esecuzione del figlio finisca prima dell'esecuzione del genitore? (y/n) ");
		fgets(s, 2, stdin);
	}
	while (*s != 'y' && *s != 'Y' && *s != 'n' && *s != 'N');
	
	if(*s == 'y' || *s == 'Y') parentDelay = 1;
	getchar();
	do
	{
		printf("Desideri che il padre 'aspetti' il figlio? (y/n) ");
		fgets(s, 2, stdin);
	}
	while (*s != 'y' && *s != 'Y' && *s != 'n' && *s != 'N');

	if(*s == 'n' || *s == 'N') parentWait = 0;

	pid_t PID = fork();

	if(PID == -1)
	{
		perror("Errore nella fork\n");
		exit(1);
	}

	if (PID == 0)
	{
		printf("\nCiao, sono il processo figlio\tPID = %d\tPPID = %d\n", getpid(), getppid()); fflush(stdout);
		printf("Diamo un'occhiata ai processi\n\n"); fflush(stdout);
		system("ps"); fflush(stdout);
		sleep(2);
		if(!parentWait && !parentDelay)
			{
				printf("\n\nSe siamo qui è perché hai risposto no a entrambe le richieste.\nQuindi il padre è terminato ma il figlio no.\n"
						"Essendo morto il genitore, il flusso è passato alla shell (che era il genitore del genitore), ma il figlio deve ancora fare la sua syscall ad _exit.\nDiamo un'occhiata ai processi.\n\n"); fflush(stdout);
				system("ps");
				printf("\nCiao, sono sempre il processo figlio, ho ancora PID = %d ma stavolta ho PPID = %d, che sarà il mio traghettatore verso la morte!\n", getpid(), getppid()); fflush(stdout);
				printf("\nMagari dopo il termine dell'esecuzione verifica se è tutto morto per davvero con il comando 'ps'.\n"); fflush(stdout);
			}

		printf("\nQui il figlio! Sto uscendo!\n"); fflush(stdout);
		if(!parentWait && !parentDelay) getchar();
		_exit(0);
	}

	else
	{
		sleep(1);
		printf("\nCiao, sono il processo padre\tPID = %d\tPPID = %d\n", getpid(), getppid()); fflush(stdout);
		
		if(parentDelay)
		{
			sleep(2);
			printf("\nIl resto del codice genitore viene eseguito dopo la terminazione del processo figlio. Se guardiamo i processi il figlio risulta Zombie (defunto).\n\n"); fflush(stdout);
		}

		else printf("Il processo figlio non è ancora terminato. I processi sono ancora entrambi attivi.\n\n"); fflush(stdout);
		system("ps"); fflush(stdout);
		
		if(parentWait)
		{
			printf("\nOra 'aspetterò' il processo figlio con una wait\n"); fflush(stdout);
			int status;
			pid_t c = wait(&status);
			printf("\nHo raccolto l'exit status (%d) del processo figlio con PID %d, pertanto è stato terminato da me. Vediamo i processi aggiornati.\n\n", status, c); fflush(stdout);
			system("ps");

		}
		else if(parentDelay) printf("\nSe io genitore non uso una wait e muoio, il SO assegnerà al mio defunto processo figlio un nuovo genitore, il quale a un certo punto lo ucciderà.\n\n"); fflush(stdout);
	}

	if(parentDelay && !parentWait)
		{
			printf("Verifichiamolo! Creiamo un nuovo processo figlio per lasciar morire il genitore e osservare il PPID del primo figlio che cambia!\n\n"); fflush(stdout);

			pid_t PID2 = fork();
			
			if(PID2 == -1)
			{
				perror("Errore nella fork\n");
				exit(1);
			}

			if(PID2 == 0)
			{
				sleep(1);
				printf("\n\nQuando il controllo passa alla shell significa che è morto il genitore. Ho messo uno sleep(1) per migliorare la leggibilità, ma anche senza non si vede più il processo defunto."); fflush(stdout);
				printf("\n\nCiao, sono il secondo processo figlio\tPID = %d\tPPID = %d\n", getpid(), getppid()); fflush(stdout);
				printf("Diamo un'occhiata ai processi\n\n"); fflush(stdout);
				system("ps"); fflush(stdout);
				printf("\nSembra che il meccanismo di kill automatico per processi Zombie sia rapidissimo...\n"
						"Si vede comunque che il PPID di questo processo è diverso da quello del vero genitore (perché è morto).\n"
						"In modo analogo, anche il PPID è diventato %d dopo la morte del vero genitore, ed è proprio %d che si occupa di uccidere entrambi i figli.\n\n", getppid(), getppid()); fflush(stdout);
				_exit(0);
			}

		}
	return 0;
}