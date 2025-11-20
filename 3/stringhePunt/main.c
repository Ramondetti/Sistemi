#include "libStrPunt.h"
int main()
{
    char str[STR_LEN],str2[STR_LEN],*pv,str3[4*(STR_LEN-1)+1];
    int pos,i,vet[STR_LEN];
    srand(time(NULL));

    printf("Stringa: ");
    gets(str);
    fflush(stdin);

    printf("La lunghezza di %s e' %d\n",str,lunghezza(str));

    //generazione vettore
    pv=vet;
    for(i=1;i<=lunghezza(str);i++)
    {
        *pv=rand()%5;
         pv++;
    }

    if(palindromo(str))
        printf("la stringa %s e' palindroma\n",str);
    else
       printf("la stringa %s non e' palindroma\n",str);

    printf("Stringa da inserire:");
    gets(str2);
    printf("Posizione in cui inserire %s ",str2);
    scanf("%d" ,&pos);
    insStr(str,str2,pos);
    printf("Stringa modificata: %s",str);

    printf("\nIl numero di vocali contenute nella stringa %s e' %d",str,vocStr(str));

    if(diversiStr(str))
        printf("\nCaratteri di %s tutti diversi: SI",str);
    else
        printf("\nCaratteri di %s tutti diversi: NO",str);

        printf("\nNumero di ripetizioni di: ");

        pv=vet;
        for(i=1;i<=lunghezza(str);i++)
        {
             printf("%d - ",*pv);
             pv++;
        }
        pv=vet;
        ripetiStr(str,str3,vet);
        printf("\nStringa: %s",str3);
    return 0;
}
