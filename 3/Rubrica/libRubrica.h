#ifndef LIBRUBRICA_H_INCLUDED
#define LIBRUBRICA_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

#define SIZE 30+1
#define NCONTATTI 100

typedef struct{
    int giorno;
    int mese;
    int anno;
} data;

typedef struct {
    char nome[SIZE];
    char cognome[SIZE];
    data dataNascita;
    char telefono[SIZE];
}persona;

char scriviMenu()
{
    char sc;
    system("cls");
    printf("RUBRICA TELEFONICA\n");
    printf("--------\n");
    printf("a - Inserisci un nuovo contatto\n");
    printf("b - Visualizza contatto\n");
    printf("c - Modifica contatto\n");
    printf("d - Cancellazione contatto\n");
    printf("e - Visualizzazione di tutti i contatti\n");
    printf("f - Ordinamento dei contatti\n");
    printf("g - Visualizzazione contatti maggiorenni\n");
    printf("--------\n");
    printf("q - Uscita\n");
    printf("Scelta: \n");
    sc = getchar();
    fflush(stdin);
    return sc;

}
//inserimento contatto
int insContatto(persona rubr[], int *numCont)
{
    int ok;
    ok = 1 ;
    if(numCont!=NCONTATTI)
    {
        fflush(stdin);
        printf("- Contatto n. %d -\n",(*numCont)+1);
        printf("Nome: ");
        gets(rubr[*numCont].nome);
        printf("Cognome: ");
        gets(rubr[*numCont].cognome);
        printf("Giorno di nascita:");
        scanf("%d",&rubr[*numCont].dataNascita.giorno);
        printf("Mese di nascita:");
        scanf("%d",&rubr[*numCont].dataNascita.mese);
        printf("Anno di nascita:");
        scanf("%d",&rubr[*numCont].dataNascita.anno);
        printf("Telefono:");
        fflush(stdin);
        gets(rubr[*numCont].telefono);
        (*numCont)++;
    }
    else
        ok = 0;
    return ok;
}

// Visualizzazione di un contatto
int visContatto(persona rubr[], char cogn[], int numCont)
{
    int i,ok=0;
    i=0;
    while(i<numCont)
    {
            if(!strcmp(cogn, rubr[i].cognome))
            {
                printf("%s - %s Tel: %s %2d/%2d/%4d\n",rubr[i].nome,rubr[i].cognome,
                rubr[i].telefono,rubr[i].cognome,rubr[i].dataNascita.giorno,
                rubr[i].dataNascita.mese,rubr[i].dataNascita.anno);
                ok=1;
            }
            i++;
    }



    return ok;
}

//modifica di un contatto

int modContatto(persona rubr[], char cogn[], int numCont)
{
    int i=0,ok;
    char str[SIZE];
    while(i<numCont) //strcmp restituisce 0 se sono uguali
    {
    if(!strcmp(cogn,rubr[i].cognome))
    {
        printf("- Modifica contatto -\n");
        printf("Se non vuoi modificare il campo digita INVIO\n");
        printf("Nome (%s):",rubr[i].nome);
        gets(str);
        if(strlen(str)!=0)
            strcpy(rubr[i].nome,str);
        printf("Cognome (%s):",rubr[i].cognome);
        gets(str);
        if(strlen(str)!=0)
            strcpy(rubr[i].cognome,str);
        printf("Giorno di nascita (%d) :",rubr[i].dataNascita.giorno);
        gets(str);
        if(strlen(str)!=0)
            rubr[i].dataNascita.giorno=atoi(str);
                printf("Mese di nascita (%d) :",rubr[i].dataNascita.mese);
        gets(str);
        if(strlen(str)!=0)
            rubr[i].dataNascita.mese=atoi(str);
                printf("Anno di nascita (%d) :",rubr[i].dataNascita.anno);
        gets(str);
        if(strlen(str)!=0)
            rubr[i].dataNascita.anno=atoi(str);
                printf("Numero di telefono (%s):",rubr[i].telefono);
        gets(str);
        if(strlen(str)!=0)
            strcpy(rubr[i].telefono,str);
        ok=1;
    }
            else
          ok=0;
        i++;
    }


    return ok;
}

int delContatto(persona rubr[], char cogn, int *numCont)
{
    int i,ok;
    i=0;

    while (i < *numCont)
        {
        if (!strcmp(cogn,rubr[i].cognome))
        {
            (*numCont)--;
            strcpy(rubr[i].nome, rubr[*numCont].nome);
            strcpy(rubr[i].cognome, rubr[*numCont].cognome);
            rubr[i].dataNascita.giorno = rubr[*numCont].dataNascita.giorno;
            rubr[i].dataNascita.mese = rubr[*numCont].dataNascita.mese;
            rubr[i].dataNascita.anno = rubr[*numCont].dataNascita.anno;
            strcpy(rubr[i].telefono, rubr[*numCont].telefono);

            strcpy(rubr[*numCont ].nome, "");
            strcpy(rubr[*numCont].cognome, "");
            rubr[*numCont].dataNascita.giorno = 0;
            rubr[*numCont].dataNascita.mese = 0;
            rubr[*numCont].dataNascita.anno = 0;
            strcpy(rubr[*numCont].telefono, "");


        ok = 1;
    }
        else
            ok = -1;
        i++;
    }


    return ok;

}

int visRubrica(persona rubr[], int numCont)
{
    int i,ok;
    if(!numCont)
        ok=0;
    else
    {
        ok=1;
        printf("== CONTATTI RUBRICA == \n");
        for(i=0;i<numCont;i++)
        {
                printf("%s - %s Tel: %s  %2d/%2d/%4d\n",rubr[i].nome,rubr[i].cognome,
                rubr[i].telefono,rubr[i].dataNascita.giorno,
                rubr[i].dataNascita.mese,rubr[i].dataNascita.anno);
        }
    }

    return ok;
}

int ordnRubrica(persona rubr[], int numCont)
{
    int i,ok,posmin,j;
    persona aus;
    if(!numCont)
        ok=0;
    else
    {
        ok=1;
            for(i=0;i<numCont-1;i++)
    {
        posmin = i;
        for(j=i+1;j<numCont;j++)
        {
            if(strcmp(rubr[posmin].cognome,rubr[j].cognome)>0)
                posmin = j;
        }
        if(posmin!=i)
        {
            //scambio cognome
            strcpy(aus.cognome,rubr[i].cognome);
            strcpy(rubr[i].cognome,rubr[posmin].cognome);
            strcpy(rubr[posmin].cognome,aus.cognome);
            //scambio nome
            strcpy(aus.nome,rubr[i].nome);
            strcpy(rubr[i].nome,rubr[posmin].nome);
            strcpy(rubr[posmin].nome,aus.nome);
            //scambio giorno data nascita
            aus.dataNascita.giorno = rubr[posmin].dataNascita.giorno;
            rubr[i].dataNascita.giorno = rubr[posmin].dataNascita.giorno;
            rubr[posmin].dataNascita.giorno = aus.dataNascita.giorno;
            //scambio mese data nascita
            aus.dataNascita.mese = rubr[posmin].dataNascita.mese;
            rubr[i].dataNascita.mese = rubr[posmin].dataNascita.mese;
            rubr[posmin].dataNascita.mese = aus.dataNascita.mese;
            //scambio anno data nascita
            aus.dataNascita.anno = rubr[posmin].dataNascita.anno;
            rubr[i].dataNascita.anno = rubr[posmin].dataNascita.anno;
            rubr[posmin].dataNascita.anno = aus.dataNascita.anno;
            //scambio telefono
            strcpy(aus.telefono,rubr[i].telefono);
            strcpy(rubr[i].telefono,rubr[posmin].telefono);
            strcpy(rubr[posmin].telefono,aus.telefono);
        }
    }
    }

    return ok;
}

int dataList(persona rubr[], int numCont,data giornoC)
{
    int i,nContMag;
    nContMag = 0;
    for(i=0;i<numCont;i++)
    {
        if((((giornoC.anno - rubr[i].dataNascita.anno) > 18 || giornoC.anno - rubr[i].dataNascita.anno) == 18 && giornoC.mese>rubr[i].dataNascita.mese
            || giornoC.anno - rubr[i].dataNascita.anno) == 18 && giornoC.mese==rubr[i].dataNascita.mese && giornoC.giorno>rubr[i].dataNascita.giorno)
            nContMag++;
    }
    return nContMag;
}

int controlloData(data giornoC)
{
    int i,ok,giorniMesi[] = {31, 28 , 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

   if(giornoC.mese<=0 || giornoC.mese >12 )
   ok=0;
   else
   {
       if((!(giornoC.anno%4) &&(giornoC.anno%100)) || (!(giornoC.anno%400)))
       giorniMesi[1]++;
       if(giornoC.giorno<=0 || giornoC.giorno > giorniMesi[giornoC.mese-1])
        ok=0;
       else
       {
           ok=1;
       }
   }



    return ok;
}


#endif // LIBRUBRICA_H_INCLUDED
