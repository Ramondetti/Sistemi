#include "libPunt.h"
int main()
{
    int vet[10],*pv,i,n,min=0,max=0,uguali=0,j;
    srand(time(NULL));

    caricaVet(vet);
    visualizzaVet(vet);

    printf("\nValore da confrontare: ");
    scanf("%d",&n);
    pv=vet;

    for(i=0;i<10;i++)
    {
        if(*pv>n)
            max++;
        else
        {
            if(*pv<n)
                min++;
            else
            {
                if(*pv==n)
                uguali++;
            }
        }
         pv++;
    }
    printf("\nElementi minori di %d: %d\n",n,min);
    pv=vet;
    visualizzaElemMIn(vet,n);
    if(uguali!=0)
      {
         printf("\nElementi uguali di %d: %d\n",n,uguali);
      }
    else
        printf("Non ci sono elementi del vettore uguali a %d",n);
    printf("\n");
    printf("\nElementi maggiori di %d: %d\n",n,max);
    visualizzaElemMax(vet,n);

    printf("\n");
    visualizzaIstogramma(vet);
    printf("\n");

    return 0;
}
