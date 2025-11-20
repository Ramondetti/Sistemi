#include <stdio.h>
#include <stdlib.h>
#include "strlib.h"

int main() {
    char scelta, str[DIMSTR], str2[DIMSTR], fPag[DIMSTR], *campo,car;
    studente studenti[NSTUD];
    int i = 0,nStudenti=0,ok;
    float somma;
    FILE *fp;

    printf("file della pagella: ");
    gets(fPag);
    fp = fopen(fPag, "r");

    if (fp == NULL) {
        printf("Errore nell'apertura del file");
        getchar();
    } else {
        printf("%-20s %-20s %-3s %-3s %-3s %-3s %-3s %-3s %-3s\n", "Cognome", "Nome", "Ita", "Sto", "Mat", "Inf", "Sis", "TPSI","Media");
        printf("------------------------------------------------------------------------\n");

        while (fgets(str, DIMSTR, fp) != NULL) {
                somma=0;
            campo = strtok(str, ";\n");
            strcpy(studenti[i].cognome, campo);
            printf("%-20s ", studenti[i].cognome);

            campo = strtok(NULL, ";\n");
            strcpy(studenti[i].nome, campo);
            printf("%-21s ", studenti[i].nome);

            campo = strtok(NULL, ";\n");
            studenti[i].Ita = atoi(campo);
            printf("%-3d ", studenti[i].Ita );
            somma+=studenti[i].Ita;

            campo = strtok(NULL, ";\n");
            studenti[i].Sto = atoi(campo);
            printf("%-3d ", studenti[i].Sto);
            somma+=studenti[i].Sto;

            campo = strtok(NULL, ";\n");
            studenti[i].Mat = atoi(campo);
            printf("%-3d ", studenti[i].Mat);
            somma+=studenti[i].Mat;

            campo = strtok(NULL, ";\n");
            studenti[i].Inf = atoi(campo);
            printf("%-3d ", studenti[i].Inf);
            somma+=studenti[i].Inf;

            campo = strtok(NULL, ";\n");
            studenti[i].Sis = atoi(campo);
            printf("%-3d ", studenti[i].Sis);
            somma+=studenti[i].Sis;

            campo = strtok(NULL, ";\n");
            studenti[i].TPSI = atoi(campo);
            printf("%-4d ", studenti[i].TPSI);
            somma+=studenti[i].TPSI;

            printf("%-1.1f\n",somma/NMATERIE);

            i++;
        }
        nStudenti=i;
        getchar();

        do {
            scelta = scriviMenu();
            switch (scelta) {
                case 'a':
                        visualizzaPagella(studenti,nStudenti);
                    break;
                case 'b':
                    do{
                    ok=insStudente(studenti,&nStudenti);
                    if(ok)
                        printf("contatto inserito correttamente\n");
                    else
                    printf("contatto non inserito\n");

                    printf("Vuoi inserire un altro contatto(s/n)?");
                        scanf(" %c", &car);
                        getchar();
                    }while(car=='s' || car=='S');

                    break;
                case 'c':
                    modContatto(studenti,nStudenti);
                    break;
                case 'd':
                    ok=delContatto(studenti,&nStudenti);
                    if(ok)
                        printf("Contatto elliminato");
                    else
                        printf("Contatto non trovato");

                    break;
                case 'e':
                    visStudentiPrBoccRim(studenti,nStudenti);
                    break;
                case 'f':
                    visNMaterieInsuff(studenti,nStudenti);
                    break;
            }
            fflush(stdin);
            getchar();
        } while (scelta != 'q');

    }

    return 0;
}
