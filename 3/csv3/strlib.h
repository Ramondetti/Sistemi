#ifndef STRLIB_H_INCLUDED
#define STRLIB_H_INCLUDED
#define DIMSTR 30+1
#define NSTUD 100
#define NMATERIE 6

typedef struct {
    char cognome[DIMSTR];
    char nome[DIMSTR];
    int Ita;
    int Sto;
    int Mat;
    int Inf;
    int Sis;
    int TPSI;
} studente;

char scriviMenu()
 {
  char sc;
  system("cls");
  printf("PAGELLA\n");
  printf("-------\n");;
  printf("a - Visualizza pagella\n");
  printf("b - Inserisci un nuovo studente\n");
  printf("c - Modifica voti di uno studente\n");
  printf("d - Ellimina uno studente\n");
  printf("e - Visualizza elenco studenti promossi, con debiti e non promossi\n");
  printf("f - Visualizza numero di insufficenti di una materia\n");
  printf("--------\n");
  printf("q - Uscita\n\n");
  printf("Scelta: ");
  sc=getchar();
  fflush(stdin);

  return sc;
 }

 void visualizzaPagella(studente studenti[],int nstudenti)
 {
    int i;
    float somma;
    char str[DIMSTR];
        printf("%-20s %-20s %-3s %-3s %-3s %-3s %-3s %-3s %-3s\n", "Cognome", "Nome", "Ita", "Sto", "Mat", "Inf", "Sis", "TPSI","Media");
        printf("------------------------------------------------------------------------\n");

        for(i=0;i<nstudenti;i++)
        {
            somma=0;
            printf("%-20s ", studenti[i].cognome);

            printf("%-21s ", studenti[i].nome);

            printf("%-3d ", studenti[i].Ita );
            somma+=studenti[i].Ita;

            printf("%-3d ", studenti[i].Sto);
            somma+=studenti[i].Sto;

            printf("%-3d ", studenti[i].Mat);
            somma+=studenti[i].Mat;

            printf("%-3d ", studenti[i].Inf);
            somma+=studenti[i].Inf;

            printf("%-3d ", studenti[i].Sis);
            somma+=studenti[i].Sis;

            printf("%-4d ", studenti[i].TPSI);
            somma+=studenti[i].TPSI;

            printf("%-1.1f\n",somma/NMATERIE);
        }

        getchar();


 }

 int insStudente(studente studenti[],int *nStudenti)
 {
     int ok;
     if(*nStudenti==NSTUD)
        ok=0;
     else
     {
         fflush(stdin);
         printf("Cognome:");
         gets(studenti[*nStudenti].cognome);
         printf("Nome:");
         gets(studenti[*nStudenti].nome);
         printf("Italiano:");
         scanf("%d",&studenti[*nStudenti].Ita);
         printf("Storia:");
         scanf("%d",&studenti[*nStudenti].Sto);
         printf("Matematica:");
         scanf("%d",&studenti[*nStudenti].Mat);
         printf("Informatica:");
         scanf("%d",&studenti[*nStudenti].Inf);
         printf("Sistemi:");
         scanf("%d",&studenti[*nStudenti].Sis);
         printf("TPSI:");
         scanf("%d",&studenti[*nStudenti].TPSI);
         (*nStudenti)++;
         ok=1;
     }
     return ok;
 }

 int modContatto(studente studenti[], int nStudenti)
 {
    int i = 0, ok = 0;
    char str[DIMSTR], str2[DIMSTR];
    printf("Cognome dello studente:");
    gets(str);

    // Cerca lo studente con il cognome corrispondente
    while (i < nStudenti && !ok)
    {
        if (strcmp(studenti[i].cognome, str) == 0)
        {
            ok = 1; // Studente trovato
        }
        else
        {
            i++;
        }
    }

    if (ok)
    {
        printf("== Modifica voti ==\n");
        printf("Se non vuoi modificare il voto premi INVIO\n");
        printf("Italiano(%d): ", studenti[i].Ita);
        gets(str2);
        if (strlen(str2) != 0)
        {
            studenti[i].Ita = atoi(str2);
        }
        printf("Storia(%d): ", studenti[i].Sto);
        gets(str2);
        if (strlen(str2) != 0)
        {
            studenti[i].Sto = atoi(str2);
        }
        printf("Matematica(%d): ", studenti[i].Mat);
        gets(str2);
        if (strlen(str2) != 0)
        {
            studenti[i].Mat = atoi(str2);
        }
        printf("Informatica(%d): ", studenti[i].Inf);
        gets(str2);
        if (strlen(str2) != 0)
        {
            studenti[i].Inf = atoi(str2);
        }
        printf("Sistemi(%d): ", studenti[i].Sis);
        gets(str2);
        if (strlen(str2) != 0)
        {
            studenti[i].Sis = atoi(str2);
        }
        printf("TPSI(%d): ", studenti[i].TPSI);
        gets(str2);
        if (strlen(str2) != 0)
        {
            studenti[i].TPSI = atoi(str2);
        }
    }
    else
    {
        printf("Studente non trovato.\n");
    }

    return ok;

 }

 int delContatto(studente studenti[],int *nStudenti)
 {
     char str[DIMSTR];
     int i=0,ok=0;
     printf("Cognome dello studente da elliminare:");
     gets(str);
     while(i<nStudenti && !ok)
     {
         if(!strcmp(studenti[i].cognome,str))
            ok=1;
         else
            i++;
     }

     if(ok)
     {
        for (int j = i; j < *nStudenti - 1; j++)
        {
            strcpy(studenti[j].cognome, studenti[j + 1].cognome);
            strcpy(studenti[j].nome, studenti[j + 1].nome);
            studenti[j].Ita = studenti[j + 1].Ita;
            studenti[j].Sto = studenti[j + 1].Sto;
            studenti[j].Mat = studenti[j + 1].Mat;
            studenti[j].Inf = studenti[j + 1].Inf;
            studenti[j].Sis = studenti[j + 1].Sis;
            studenti[j].TPSI = studenti[j + 1].TPSI;
        }


        strcpy(studenti[*nStudenti - 1].cognome, "");
        strcpy(studenti[*nStudenti - 1].nome, "");
        studenti[*nStudenti - 1].Ita = 0;
        studenti[*nStudenti - 1].Sto = 0;
        studenti[*nStudenti - 1].Mat = 0;
        studenti[*nStudenti - 1].Inf = 0;
        studenti[*nStudenti - 1].Sis = 0;
        studenti[*nStudenti - 1].TPSI = 0;


        (*nStudenti)--;

     }
     return ok;
 }

 void visStudentiPrBoccRim(studente studenti[],int nStudenti)
 {
     int i,ok=0;
     printf("Studenti promossi:\n");
     for(i=0;i<nStudenti;i++)
     {
         if(studenti[i].Ita>=6 && studenti[i].Sto>=6 && studenti[i].Mat>=6 && studenti[i].Inf>=6 && studenti[i].Sis>=6 && studenti[i].TPSI>=6)
            printf("%s ",studenti[i].cognome);
     }
     printf("\nStudenti bocciati:\n");
        for(i=0;i<nStudenti;i++)
     {
         if(studenti[i].Ita<6 && studenti[i].Sto<6 && studenti[i].Mat<6 && studenti[i].Inf<6 && studenti[i].Sis<6 && studenti[i].TPSI<6)
            printf("%s ",studenti[i].cognome);
     }
     printf("\nStudenti rimandati:\n");
    for(i=0;i<nStudenti;i++)
     {
         if((studenti[i].Ita<6 && studenti[i].Sto<6 && studenti[i].Mat<6 && studenti[i].Inf<6 && studenti[i].Sis<6 && studenti[i].TPSI<6) ||
             (studenti[i].Ita>=6 && studenti[i].Sto>=6 && studenti[i].Mat>=6 && studenti[i].Inf>=6 && studenti[i].Sis>=6 && studenti[i].TPSI>=6))
            ok=1;
         else
            printf("%s ",studenti[i].cognome);
     }
 }

 void visNMaterieInsuff(studente studenti[], int nStudenti)
 {
     int i,cont=0;
     char materia[DIMSTR];
     printf("Materia:");
     gets(materia);
     for(i=0;i<nStudenti;i++)
     {
         if(!strcmp(materia,"Italiano") && studenti[i].Ita<6)
         cont++;
         else if(!strcmp(materia,"Storia") && studenti[i].Sto<6)
            cont++;
         else if(!strcmp(materia,"Matematica") && studenti[i].Mat<6)
            cont++;
         else if(!strcmp(materia,"Informatica") && studenti[i].Inf<6)
            cont++;
          else if(!strcmp(materia,"Sistemi") && studenti[i].Sis<6)
            cont++;
          else if(!strcmp(materia,"TPSI") && studenti[i].TPSI<6)
            cont++;

     }
     printf("Gli insufficente di %s sono: %d",materia,cont);
     cont=0;
 }






#endif // STRLIB_H_INCLUDED
