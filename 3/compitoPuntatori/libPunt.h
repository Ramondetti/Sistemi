#ifndef LIBPUNT_H_INCLUDED
#define LIBPUNT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void caricaVet(int *pv)
{
    int i;
    for(i=0;i<10;i++)
    {
        *pv=rand()%10+1;
         pv++;
    }
}

void visualizzaVet(int *pv)
{
    int i;
    printf("Elementi del vettore: ");
    for(i=0;i<10;i++)
    {
        printf("%d - ",*pv);
         pv++;
    }
}

void visualizzaElemMIn(int *pv,int n)
{
    int i;

    for(i=0;i<10;i++)
    {
        if(*pv<n)
            printf("%d - ",*pv);
        pv++;
    }
    printf("\n");
}

void visualizzaElemMax(int *pv ,int n)
{
    int i;
    for(i=0;i<10;i++)
    {
        if(*pv>n)
            printf("%d - ",*pv);
        pv++;
    }
}
void visualizzaIstogramma(int *pv)
{
    int i,j;
    for(i=1;i<=10;i++)
    {
        printf("\nElemento %2d (%d): %8c",i,*pv,' ');
        for(j=0;j<*pv;j++)
        {
            printf("*");
        }
        pv++;
    }
}

#endif // LIBPUNT_H_INCLUDED
