#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 100+1
#define NGIOC 100
#define NUM_TURNS 4

typedef struct {
  char nome[SIZE];
  int punteggio;
  int vTurno[NUM_TURNS];
} Giocatore;

int main() {

  FILE* fp;
  int i,cont;
  char str[SIZE], *campo,fileGara[SIZE];
  Giocatore giocatori[NGIOC];

 printf("file gara: ");
 gets(fileGara);
 fp = fopen(fileGara, "r");

  cont=0;

  if(fp == NULL) {
    printf("Errore nell'apertura del file\n");
    getchar();
  }

  printf("Nome Turno Punti\n");
  printf("---- ---- ----\n");

     while (fgets(str, SIZE, fp)) {
            campo = strtok(str, ";");
            printf("%s   ", campo);
            campo = strtok(NULL, ";");
            printf("%s    ", campo);
            campo = strtok(NULL, ";");
            printf("%s\n", campo);
        }

        fclose(fp);
        fp = fopen(fileGara, "r");
  // Inizializza struct
  for(i=0; i<NGIOC; i++) {
    giocatori[i].punteggio = 0;
    for(int j=0; j<NUM_TURNS; j++) {
      giocatori[i].vTurno[j] = 0;
    }
  }

  // Legge il file e aggiorna i punteggi
  int giocatoreIndex;
  while(fgets(str, SIZE, fp)) {

    campo = strtok(str, ";");
    giocatoreIndex = -1;

    // Trova l'indice del giocatore
    for(i=0; i<NGIOC; i++) {
      if(strcmp(giocatori[i].nome, campo) == 0) {
        giocatoreIndex = i;
        break;
      }
    }

    // Giocatore non ancora incontrato
    if(giocatoreIndex == -1) {
      strcpy(giocatori[cont].nome, campo);
      giocatoreIndex = cont;
      cont++;
    }

    campo = strtok(NULL, ";");
    int turno = atoi(campo);

    campo = strtok(NULL, ";");
    int punti = atoi(campo);

    giocatori[giocatoreIndex].vTurno[turno-1] = punti;
    giocatori[giocatoreIndex].punteggio += punti;

  }


int maxScore = 0;
for(i=0; i<cont; i++) {
  if(giocatori[i].punteggio > maxScore) {
    maxScore = giocatori[i].punteggio;
  }
}



  fclose(fp);

  printf("\nPunteggi totali:\n");
  // Stampa punteggi totali
  for(i=0; i<cont; i++) {
    printf("%s: %d\n", giocatori[i].nome, giocatori[i].punteggio);
  }
  // Stampa vincitore/i
printf("\nVincitore/i:\n");
for(i=0; i<cont; i++) {
  if(giocatori[i].punteggio == maxScore) {
    printf("%s\n", giocatori[i].nome);
  }
}


int maxTurno[NUM_TURNS];

for(int t=0; t < NUM_TURNS; t++) {

  // Trova punteggio massimo per turno
  maxTurno[t] = 0;
  for(i=0; i<cont; i++) {
    if(giocatori[i].vTurno[t] > maxTurno[t]) {
      maxTurno[t] = giocatori[i].vTurno[t];
    }
  }

  // Stampa vincitore/i per turno
  printf("\nTurno %d:\n", t+1);
  for(i=0; i<cont; i++) {
    if(giocatori[i].vTurno[t] == maxTurno[t]) {
      printf("%s\n", giocatori[i].nome);
    }
  }

}


  return 0;
}

