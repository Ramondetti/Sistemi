#include <stdio.h>
#include <stdlib.h>
#define SIZE 100+1
int main()
{
    /*MODALITA' DI APERTURA DEL FILE
    "r" --> lettura
    "w" --> scrittura (se il file esiste lo sovrascrive se il file non esiste lo crea)
    "a" -->append (aggiunge al file,se il file non esiste lo crea)
    iToa  da int a ascii
    strcat per concatenare 2 stringhe
    */

    FILE *fp,*fp2; //dichiarare una variabile di tipo puntatore di tipo FILE
    char str[SIZE];
    fp = fopen("testo.txt","r"); //si mette il puntatore a inizio file
    fp2 =fopen("testo2.txt","w");
    printf("Prima riga: ");
    gets(str);
    str[strlen(str)] = '\n';
    //strcpy(str,"FILE DI COPIA\n");
    fputs(str,fp2);
    if((fp!=NULL)&&(fp2!=NULL))
    {
        while(!feof(fp)) //feof(fp) == 0
        {
            fgets(str,SIZE,fp);  // legge il contenuto e lo mette in str
            printf("%s",str);
            fputs(str,fp2);  //scrive il contenuto di str in un secondo file

        }
    }
    else
        printf("ERRORE NELL'APERTURA DEI FILE\n ");
    fclose(fp);
    fclose(fp2);
}

