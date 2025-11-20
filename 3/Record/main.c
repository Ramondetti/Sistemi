#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 30+1
typedef struct {
 int giorno;
 int mese;
 int anno;
}data;
typedef struct{
 char nome[SIZE];
 char cognome[SIZE];
 data dataNascita;
 char telefono[SIZE];
} persona;
int main()
{
    persona pers[10];
    int n,i;
    printf("Numero di contatti (<=10): ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("-- Contatto n. %d --\n",i+1);
        printf("Nome: ");
        gets(pers[i].nome);
        printf("Cognome: ");
        gets(pers[i].cognome);
        printf("Giorno di nascita: ");
        scanf("%d",&pers[i].dataNascita.giorno);
        printf("Mese di nascita: ");
        scanf("%d",&pers[i].dataNascita.mese);
        printf("Anno di nascita: ");
        scanf("%d",&pers[i].dataNascita.anno);
        printf("Numero di telefono: ");
        gets(pers[i].telefono);

    }
    printf("==Rubrica telefonica");
   printf("%== %s %s %2d/%2d/%4d %s\n",pers.nome,pers.cognome,pers.dataNascita,pers.dataNascita.mese,pers.dataNascita.anno,pers.telefono);

    return 0;
}
