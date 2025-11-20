#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
    int vet[10],*pv,cont,somma,max;
    srand(time(NULL));

    //caricamento random di vet
    pv=vet;// == pv=%vet[0]  il nome del vettore mi dà l'indirizzo
    for(cont=1;cont<=10;cont++)
    {
        *pv=rand()%1000+1;
         pv++;
    }

    //stampa di vet
    pv=&vet[0];
    for(cont=1;cont<=10;cont++)
    {
        printf("%d: indirizzo:%p contenuto:%d\n",cont,pv,*pv);
        pv++;
    }

    //somma elementi di un vettore
    somma=0;
    pv=vet;
    for(cont=1;cont<=10;cont++)
    {
        somma+=(*pv);
        pv++;
    }
    printf("somma: %d\n",somma);

    //ricerca del massimo
    pv=vet;
    max=*pv;
    for(cont=2;cont<=10;cont++)
    {
        pv++;
        if(*pv>max)
            max=*pv;
    }
    printf("max: %d\n",max);
    return 0;
}
