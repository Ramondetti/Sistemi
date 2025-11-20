#include <stdio.h>
#include <stdlib.h>
#define DIMSTR 30+1     // dimensione massima 30 caratteri + tappo '\0'
int main()
{
    char str[DIMSTR],ch,ch2;
    int i=0,len=0;
    printf("Stringa: ");
    do
    {
        str[i] = getchar();
        i++;
    } while((str[i-1] != '\n') && (i<DIMSTR));
    str[i-1] = '\0';
    printf("Stringa digitata %s\n",str);

    //calcolo della lunghezza della stringa
    while(str[len] != '\0')
        len++;
    printf("La lunghezza di %s e' %d\n",str,len);

    // visualizzazione stringa al contrario utilizzando la lunghezza
    printf("Stringa al contrario: ");
    for(i=len-1;i>=0;i--)
        printf("%c",str[i]);
    printf("\n");

    //contare le occorenze di un carattere indipendentemente
    // che sia maiuscolo o minuscolo in una stringa
    printf("Carattere: ");
    ch = getchar();
    if((ch>='A') && (ch<='Z'))
        ch2 = 'a' + (ch-'A');
    else
    if((ch>='a') && (ch<='z'))
        ch2 = 'A' + (ch - 'a');
    int nCar = 0;
    i = 0;
    while(str[i] != '\0') //scorro la stringa fino al tappo
    {
        if((str[i] == ch) || (str[i] == ch2))
            nCar++;
        i++;
    }
    printf("Il carattere %c e' contenuto per %d volte in %s\n",ch,nCar,str);

    //Trasformazione dei caratteri maiuscoli e minuscoli e viceversa
    for(i=0;str[i] != '\0';i++)
    {
        if((str[i] >= 'A') && (str[i] <= 'Z'))
        {
            str[i]  = 'a' + (str[i] - 'A'); // str[i]+=0x20;
        }

        else
        {
            if((str[i] >= 'a') && (str[i] <='z'))
            {
                str[i] = 'A' + (str[i] - 'a');
            }
        }
    }
    printf("La stringa trasformata e' %s\n",str);

    //Copia di una stringa in un'altra
    char str2[DIMSTR];
    for(i=0;str[i] |= '\0';i++)
        str2[i] = str[i];
    str2[i] = '\0';
        printf("La stringa copiata e' %s\n",str2);
    // Invertire una stringa su se stessa
    int m = 0;
    for(i=0;i<len/2;i++)
    {
       str[i] = str[len-1];
    }
    str[len] = '\0';
    printf("la stringa al contrario: %s",str);
    return 0;
}
