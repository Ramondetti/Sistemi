#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30+1
#define MAX_TEAMS 16

typedef struct {
    int pos;
    char nSquadra[SIZE];
    int punti;
    int pGiocate;
    int vit;
    int pa;
    int pers;
    int gf;
    int gs;
} squadre;

void ordinamento(squadre squadra[], int n) {
    int i, j;
    squadre temp;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (squadra[j].pos > squadra[j + 1].pos) {
                temp = squadra[j];
                squadra[j] = squadra[j + 1];
                squadra[j + 1] = temp;
            }
        }
    }
}

int main() {
    FILE *fp;
    int i = 0,minVit,index,j,maxPartitePerse,maxGoal,minGoal;
    char fileClassifica[SIZE], str[SIZE],*campo;
    squadre squadra[MAX_TEAMS];
    printf("File della classifica: ");
    gets(fileClassifica);
    fp = fopen(fileClassifica, "r");
    if (fp == NULL) {
        printf("Errore nell'apertura del file");
        getchar();
    }

    while (fgets(str, SIZE, fp)) {
        campo = strtok(str, ";");
        squadra[i].pos = atoi(campo);

        campo = strtok(NULL, ";");
        strcpy(squadra[i].nSquadra, campo);

        campo = strtok(NULL, ";");
        squadra[i].punti = atoi(campo);

        campo = strtok(NULL, ";");
        squadra[i].pGiocate = atoi(campo);

        campo = strtok(NULL, ";");
        squadra[i].vit = atoi(campo);

        campo = strtok(NULL, ";");
        squadra[i].pa = atoi(campo);

        campo = strtok(NULL, ";");
        squadra[i].pers = atoi(campo);

        campo = strtok(NULL, ";");
        squadra[i].gf = atoi(campo);

        campo = strtok(NULL, ";");
        squadra[i].gs = atoi(campo);

        i++;
    }

    fclose(fp);
    ordinamento(squadra, i);

    printf("Classifica finale:\n");
    printf("pos squadra                pt vi pa pe gf gs\n");
    printf("---------------------------------------------\n");
    for (int j = 0; j < i; j++) {
        printf("%2d %-25s %2d %2d %2d %2d %2d %2d\n", squadra[j].pos, squadra[j].nSquadra,
               squadra[j].punti, squadra[j].vit, squadra[j].pa, squadra[j].pers,
               squadra[j].gf, squadra[j].gs);
    }

    printf("\nLa squadra che ha vinto lo scudetto è: %s\n", squadra[0].nSquadra);
    printf("Le squadre retrocesse in serie B sono: %s, %s, %s\n", squadra[i-3].nSquadra,
           squadra[i-2].nSquadra, squadra[i-1].nSquadra);

    printf("La squadra con meno vittorie: ");
    minVit=squadra[0].vit;
    for(j=1;j<i;j++)
    {
        if(squadra[j].vit<minVit)
        {
            minVit=squadra[j].vit;
            index=j;
        }
    }
    printf("(%d) %s ",minVit,squadra[index].nSquadra);
        for(j=0;j<i;j++)
        {
            if(squadra[j].vit==minVit)
            {
                printf("%s ",squadra[j].nSquadra);
            }
        }
    printf("\nSquadre che hanno pareggiato un numero di partite compreso tra 6 e 10: ");
    for(j=0;j<i;j++)
    {
        if(squadra[j].pa>=6 && squadra[j].pa<=10)
            printf("%s ",squadra[j].nSquadra);
    }
    printf("Le squadre che hanno perso piu partite: ");
    maxPartitePerse=squadra[0].pers;
        for(j=1;j<i;j++)
    {
        if(squadra[j].pers>maxPartitePerse)
            maxPartitePerse=squadra[j].pers;
    }
            for(j=0;j<i;j++)
    {
        if(squadra[j].pers==maxPartitePerse)
        {
            printf("(%d) %s ",squadra[j].pers,squadra[j].nSquadra);
        }
    }
    maxGoal=squadra[0].gf;
    printf("\nLa squadra che ha segnato piu goal \212: ");
        for(j=1;j<i;j++)
    {
        if(squadra[j].gf>maxGoal)
        {
            maxGoal=squadra[j].gf;
            index=j;
        }

    }
    printf("(%d) %s ",maxGoal,squadra[index].nSquadra);
    minGoal=squadra[0].gs;
    printf("\nLa squadra che ha subito meno goal \212: ");
    for(j=1;j<i;j++)
        {
        if(squadra[j].gs<minGoal)
        {
            minGoal=squadra[j].gs;
            index=j;
        }

    }
    printf("(%d) %s ",minGoal,squadra[index].nSquadra);
    return 0;
}

