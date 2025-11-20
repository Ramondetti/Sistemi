#include <stdio.h>
#include <stdlib.h>

int main()
{
    float f,*pf; // * in dichiarazione indica una variabile puntatore
    int n,n1,n2,*pn;
    char ch,*pch;

    f=3.14;
    n=110;
    ch='a';
    n1=200;
    n2=57;

    pf=&f; //la & indica l'indirizzo della variabile
    pn=&n;
    pch=&ch;

    printf("Un intero occupa %d by e\n",sizeof(int));
    printf("Un float occupa %d by e\n",sizeof(float));
    printf("Un double occupa %d by e\n",sizeof(double));
    printf("Un char occupa %d by e\n",sizeof(char));

    printf("Indirizzo di f: %p\n",&f); //%p indirizzo variabile
    printf("Indirizzo di *pf: %p\n",&pf);
    printf("Indirizzo di n: %p\n",&n);
    printf("Indirizzo di n1: %p\n",&n1);
    printf("Indirizzo di pn: %p\n",&pn);
    printf("Indirizzo di ch: %p\n",&ch);
    printf("Indirizzo di *pch: %p\n",&pch);

    pn=&n2;
    printf("Indirizzo area puntata da pn: %p contenuto dell'area puntata da pn e' %d\n",pn,*pn);
    pn=pn+1;
    printf("Indirizzo area puntata da pn: %p contenuto dell'area puntata da pn e' %d\n",pn,*pn);
    pn=pn+1;
    printf("Indirizzo area puntata da pn: %p contenuto dell'area puntata da pn e' %d\n",pn,*pn);
    return 0;
}
