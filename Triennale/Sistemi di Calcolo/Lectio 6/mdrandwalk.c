//Questo programma simula n random walk D-dimensionali (con D = 1, 2, 3) e valuta statistiche del moto e probabilita' di ritorno nella posizione iniziale;
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct posizioni{int x; int y; int z;} pos;

void aggiorna_posizione (struct posizioni *pos, double p, int D);
void aggiorna_medie (struct posizioni *pos, double **medie, int k);
void stampa_statistiche (double **medie, int k, int nmax, int ts);

int main (int argc, char **argv)
{
  int t = 0, n, tmax, ts, nmax, i, j, k, kt, max, D, r = 0, rt;
  double **medie, p, pr = 0;
  unsigned long long int seed;
  FILE *f;

  if (argc != 5) {fprintf(stderr, "\n\nInserire <tmax> <nmax> <tempi di stampa (del tipo n**k, inserire n)> <numero di dimensioni (valori ammessi: {1, 2, 3})>\n\n"); exit(1);}
  tmax = atoi(argv[1]);
  nmax = atoi(argv[2]);
  n = atoi(argv[3]);
  //il numero di dimensioni D determina quante variabili verranno aggiornate nel corso del random walk; chiaramente è un numero positivo, ma in questo programma minore di 3;
  //aumentare a oltre 3 il numero di dimensioni non sarebbe troppo difficile, ma inutile ai fini del programma;
  D = atoi(argv[4]);
  if(tmax < 1) {fprintf(stderr, "\n\nAttenzione! Il tempo deve essere positivo!\n\n"); exit(1);}
  if(nmax < 1) {fprintf(stderr, "\n\nAttenzione! Il numero di iterazioni deve essere positivo!\n\n"); exit(1);}
  if(D < 1) {fprintf(stderr, "\n\nAttenzione! Un numero negativo di dimensioni e' quantomeno singolare!\n\n"); exit(1);}
  if(D > 3) {fprintf(stderr, "\n\nAttenzione! Le simulazioni per un numero di dimensioni superiore a 3 va oltre gli scopi di questo programma.\n\n"); exit(1);}
  ts = n;
  if(ts < 1) {fprintf(stderr, "\n\nAttenzione! Inserire un n > 0, e preferibilmente > 1\n\n"); exit(1);}

  //Definizione di un intero per l'allocazione dinamica. E' definito come parte intera del logaritmo in base n di tmax, ovvero il numero di tempi di stampa;
  max = (int) ((log2(tmax))/(log2(n)));

  //matrice dinamica per le statistiche relative a x, y, z. Tale matrice ha come righe (9 in totale) <x>, <x^2>, <x^4>, ecc.. e come colonne i tempi di stampa in cui calcolarle;
  medie = (double**) calloc (9, sizeof(double*));

  //allocazione dinamica elementi;
  for(i = 0; i < 9; i++)
    {
      medie[i] = (double*) calloc (max, sizeof(double));
    }

  //inizializzazione elementi;
  for(i = 0; i < 9; i++)
    {
      for(j = 0; j < max; j++)
  	{
  	  medie[i][j] = 0;
  	}
    }    
  
  //lettura seed e inizializzazione srand48;
  f = fopen("/dev/urandom", "r");
  fread(&seed, sizeof(unsigned long long), 1, f);
  fclose(f);
  srand48(seed);
  
  //scarto dei primi 1000 numeri random;
  for(i = 0; i < 1000; i++){p = drand48();}
     
  //ciclo sul numero di simulazioni;
  for(i = 0; i < nmax; i++)
    {
      //inizializzazione della simulazione;
      pos.x = 0;
      pos.y = 0;
      pos.z = 0;
      ts = n; k = 0; kt = k; rt = 0;
      
      //ciclo sulla singola simulazione;
      for(t = 0; t < tmax; t++)
	{
	  p = drand48();
	  aggiorna_posizione(&pos, p, D);
	  //se il random walk torna ad avere coordinate nulle, si incrementa una variabile;
	  if(pos.x == 0 && pos.y == 0 && pos.z == 0){rt++;}
	  //ricalcolo di ts dopo ogni stampa; k tiene conto del numero progressivo di stampa, e fa aggiornare ts solo se si aggiorna k;
	  if (k != kt){ts *= n;}
	  kt = k;
	  if(t + 1 == ts) 
	    {
	      //funzione che aggiorna le medie;
	      aggiorna_medie(&pos, medie, k);
	      k++;
	    }
	}
      //se la variabile flag rt è diversa da zero, si tiene conto della simulazione;
      if(rt != 0){r++;}
    }
  
  fprintf(stdout, "\n\n");
  ts = n; 

  //stampa di medie e deviazioni standard;
  fprintf(stdout, "#t\t<x>\t\tsd[<x>]\t\t<x^2>\t\tsd[<x^2>]\t<y>\t\tsd[<y>]\t\t<y^2>\t\tsd[<y^2>]\t<z>\t\tsd[<z>]\t\t<z^2>\t\tsd[<z^2>]\n\n");
  for (i = 0; i < k; i++)
    {
      stampa_statistiche(medie, i, nmax, ts);  
      ts *= n;
    }
  
  fprintf(stdout, "\n\n");

  //si normalizza la probabilità rendendola double solo alla fine per evitare imprefezioni di approssimazione;
  pr = ((double)r)/nmax;

  fprintf(stdout, "#La probabilità di ritorno al punto di partenza entro un tempo t = %d calcolata su %d simulazioni in %d dimensioni è %.7f\n\n", tmax, nmax, D, pr);

  
  //liberazione della memoria;
  for(i = 0; i < max; i++)
    {
      free(medie[i]);
    }
  free(medie);
  
  return(0);
}


void aggiorna_posizione (struct posizioni *pos, double p, int D)
{
  if(D == 1)
    {
      if(p < 0.5) {pos->x ++;}
      else {pos->x --;}
    }
  
  if(D == 2)
    {
      if(p < 0.25) {pos->x --;}
      else if(p < 0.5){pos->x ++;}
      else if(p < 0.75){pos->y --;}
      else {pos->y ++;}
    }
  
  if(D == 3)
    {
      if(p < 1./6.) {pos->x --;}
      else if(p < 1./3.){pos->x ++;}
      else if(p < 0.5){pos->y --;}
      else if(p < 2./3.){pos->y ++;}
      else if(p < 5./6.){pos->z --;}
      else {pos->z ++;}
    }
}


void aggiorna_medie (struct posizioni *pos, double **medie, int k)
{
  int i;
  double var;
  //sia in questa funzione che nella successiva si sfrutta il fatto di avere tre grandezze caratteristiche identiche per ogni coordinata, potendo così trattarle in modo identico;
  for(i = 0; i < 9; i += 3)
    {      
      if(i < 3) {var = (double) pos->x;}
      else if (i < 6) {var = (double) pos->y;}
      else {var = (double) pos->z;}
 
      medie[i][k] += var;
      medie[i + 1][k] += var*var;
      medie[i + 2][k] += var*var*var*var;
    }
}


void stampa_statistiche (double **medie, int k, int nmax, int ts)
{
  int i;
  double sd, sd2;

  //normalizzazione per ottenere le medie effettive;
  for(i = 0; i < 9; i += 3)
    {      
      medie[i][k] /= nmax;
      medie[i + 1][k] /= nmax;
      medie[i + 2][k] /= nmax;
    }
  
  fprintf(stdout, "%d", ts);
  
  //calcolo deviazioni standard e stampa;
  for(i = 0; i < 9; i += 3)
    {
      sd = sqrt((medie[i + 1][k] - medie[i][k]*medie[i][k])/(nmax - 1));
      sd2 = sqrt((medie[i + 2][k] - medie[i + 1][k]*medie[i + 1][k])/(nmax - 1));
      
      fprintf(stdout, "\t%.7f\t%.7f\t%.7f\t%.7f", medie[i][k], sd, medie[i + 1][k], sd2);
    }
  fprintf(stdout, "\n");
}


