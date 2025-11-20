#ifndef LIBRUBRICA_H_INCLUDED
#define LIBRUBRICA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 30+1
#define NCONTATTI 100

typedef struct {
  int giorno;
  int mese;
  int anno;
 } data;
typedef struct {
  char nome[SIZE];
  char cognome[SIZE];
  data dataNascita;
  char telefono[SIZE];
 } persona;

int caricaRubrica(char fRubr[],persona rubr[],int *numCont)
 {
  FILE *fp;
  int ok;
  char str[3*SIZE],*campo;
  fp=fopen(fRubr,"r");
  if(fp==NULL)
   {
    ok=0;
   }
  else
   {
    ok=1;
    *numCont=0;
    while(!feof(fp))
     {
      fgets(str,3*SIZE,fp);
      if(!feof(fp))
       {
        campo=strtok(str,";");
        strcpy(rubr[*numCont].cognome,campo);
        campo=strtok(str,NULL);
        strcpy(rubr[*numCont].nome,campo);
        campo=strtok(str,NULL);
        rubr[*numCont].dataNascita.giorno=atoi(campo);
        campo=strtok(str,NULL);
        rubr[*numCont].dataNascita.mese=atoi(campo);
        campo=strtok(str,NULL);
        rubr[*numCont].dataNascita.anno=atoi(campo);
        campo=strtok(str,NULL);
        strcpy(rubr[*numCont].telefono,campo);
        rubr[*numCont].telefono[strlen(rubr[*numCont].telefono)-1]='\0';
        (*numCont)++;
       }
     }
    fclose(fp);
   }
  return ok;
 }

char scriviMenu()
 {
  char sc;
  system("cls");
  printf("RUBRICA TELEFONICA\n");
  printf("----\n");
  printf("a - Inserisci un nuovo contatto\n");
  printf("b - Visualizza un contatto\n");
  printf("c - Modifica un contatto\n");
  printf("d - Elimina un contatto\n");
  printf("e - Visualizza tutti i contatti\n");
  printf("g - Visualizza tutti i contatti maggiorenni\n");
  printf("--------\n");
  printf("q - Uscita\n\n");
  printf("Scelta: ");
  sc=getchar();
  fflush(stdin);
  return sc;
 }
int insContatto(persona rubr[], int *numcont)
  {
   int ok;
   ok=1;
   if(numcont!=NCONTATTI)
    {
     fflush(stdin);
     printf("-- Contatto n. %d --\n",*numcont+1);
     printf("Nome: ");
     gets(rubr[*numcont].nome);
     printf("Cognome: ");
     gets(rubr[*numcont].cognome);
     fflush(stdin);
     do
      {
       printf("Giorno di nascita: ");
       scanf("%d",&rubr[*numcont].dataNascita.giorno);
       printf("Mese di nascita: ");
       scanf("%d",&rubr[*numcont].dataNascita.mese);
       printf("Anno di nascita: ");
       scanf("%d",&rubr[*numcont].dataNascita.anno);
       fflush(stdin);
      }while(!controllaData(rubr[*numcont].dataNascita.giorno,
                            rubr[*numcont].dataNascita.mese,rubr[*numcont].dataNascita.anno));
     printf("Numero di telefono: ");
     gets(rubr[*numcont].telefono);
     (*numcont)++;
    }
   else
     ok=0;
   return ok;
 }

int visContatto(persona rubr[], char cogn[],int numCont)
 {
  int i, ok;
  i=0;
  ok=1;
  while((i<numCont)&&(strcmp(cogn,rubr[i].cognome)))
    i++;
  if(i<numCont)
    printf("%s \t%s \t %s \t%2d/%2d/%4d\n",rubr[i].cognome,rubr[i].nome,
            rubr[i].telefono,rubr[i].dataNascita.giorno,
            rubr[i].dataNascita.mese,rubr[i].dataNascita.anno);
  else
    ok=0;
  return ok;
 }

int modContatto(persona rubr[], char cogn[],int numCont)
 {
  int ok,i;
  char str[SIZE];
  i=0;
  while((i<numCont)&&(strcmp(cogn,rubr[i].cognome)!=0))
    i++;
  if(i<numCont)
   {
     ok=1;
     printf("== Modifica contatto ==\n");
     printf("Se non vuoi modificare il campo digita INVIO\n");
     printf("Nome (%s):",rubr[i].nome);
     gets(str);
     if (strlen(str))
       strcpy(rubr[i].nome,str);
     printf("Cognome (%s):",rubr[i].cognome);
     gets(str);
     if (strlen(str))
       strcpy(rubr[i].cognome,str);
     do
      {
       printf("Giorno di nascita (%d):",rubr[i].dataNascita.giorno);
       gets(str);
       if (strlen(str))
         rubr[i].dataNascita.giorno=atoi(str);
       printf("Mese di nascita (%d):",rubr[i].dataNascita.mese);
       gets(str);
       if (strlen(str))
         rubr[i].dataNascita.mese=atoi(str);
       printf("Anno di nascita (%d):",rubr[i].dataNascita.anno);
       gets(str);
       if (strlen(str))
         rubr[i].dataNascita.anno=atoi(str);
      }while(!controllaData(rubr[i].dataNascita.giorno,
                            rubr[i].dataNascita.mese,rubr[i].dataNascita.anno));
     printf("Numero di telefono (%s):",rubr[i].telefono);
     gets(str);
     if (strlen(str))
       strcpy(rubr[i].telefono,str);
    }
  else
    ok=0;
  return ok;
 }

int delContatto(persona rubr[], char cogn[],int *numCont)
 {
  int ok,i;
  char str[SIZE];
  i=0;
  while((i<*numCont)&&(strcmp(cogn,rubr[i].cognome)!=0))
    i++;
  if((*numCont)&&(i<*numCont))
   {
    ok=1;
    (*numCont)--;
    strcpy(rubr[i].cognome,rubr[*numCont].cognome);
    strcpy(rubr[i].nome,rubr[*numCont].nome);
    rubr[i].dataNascita.giorno=rubr[*numCont].dataNascita.giorno;
    rubr[i].dataNascita.mese=rubr[*numCont].dataNascita.mese;
    rubr[i].dataNascita.anno=rubr[*numCont].dataNascita.anno;
    strcpy(rubr[i].telefono,rubr[*numCont].telefono);
   }
  else
    ok=0;
  return ok;
 }

int visRubrica(persona rubr[],int numCont)
 {
  int i,ok;
  if(numCont==0)
    ok=0;
  else
   {
    ok=1;
    printf("== Elenco contatti ==\n\n");
    for(i=0;i<numCont;i++)
      printf("%s \t%s \t %s \t%2d/%2d/%4d\n",rubr[i].cognome,rubr[i].nome,
            rubr[i].telefono,rubr[i].dataNascita.giorno,
            rubr[i].dataNascita.mese,rubr[i].dataNascita.anno);
   }
  return ok;
 }

int visMaggiorenni(persona rubr[],int numCont,int g,int m,int a)
 {
  int i,numMagg;
  numMagg=0;
  a-=18;
  for(i=0;i<numCont;i++)
   {
    if((rubr[i].dataNascita.anno<=a)&&(rubr[i].dataNascita.mese<=m)&&(rubr[i].dataNascita.giorno<=g))
      printf("%s \t%s \t %s \t%2d/%2d/%4d\n",rubr[i].cognome,rubr[i].nome,
            rubr[i].telefono,rubr[i].dataNascita.giorno,
            rubr[i].dataNascita.mese,rubr[i].dataNascita.anno);
   }
 }

 int controllaData(int gg,int mm, int aa)
  {
   int giorni[]={31,28,31,30,31,30,31,31,30,31,30,31};
   int ok;
   if((mm<1)&&(mm>12))
     ok=0;
   else
    {
     if(((!(aa%4))&&(aa%100))||(!(aa%400))) // anno divisibile per 4 ma non per 400 è bisestile
       giorni[1]=29;           // febbraio
     if((gg<1)||(gg>giorni[mm-1]))
        ok=0;
     else
       ok=1;
    }
   return ok;
  }

  int salvaRubrica(char fRubr[],persona rubr,int numCont)
  {
      char str[SIZE],numStr[5];
      FILE *fp;
      int ok,i;
      fp=fopen(fRubr,"w");
      if(fp!=NULL)
      {
          ok=1;
          for(i=0;i<numCont;i++)
          {
              strcpy(str,"");
              strcat(str,rubr[i].nome);
              strcat(str,";");
              strcat(str,rubr[i].cognome);
              strcat(str,";");
              itoa(rubr[i].dataNascita.giorno,numStr,10);
              strcat(str,numStr);
              strcat(str,";");
              itoa(rubr[i].dataNascita.mese,numStr,10);
              strcat(str,numStr);
              strccat(str,";");
              itoa(rubr[i].dataNascita.anno,numStr,10);
              strcat(str,numStr);
              strcat(str,";");
              strcat(str,rubr[i].telefono);
              strcat(str,"\n");
              fputs(str,fp);

          }
          fclose(fp);
      }
      else
      {
          ok=0;
      }
      return ok;
  }

#endif // LIBRUBRICA_H_INCLUDED

