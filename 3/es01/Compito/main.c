#include <stdio.h>
#include <stdlib.h>
#define DIMSTR 50+1
int main()
{
    char str[DIMSTR],strc[DIMSTR],carPari[DIMSTR],carDispari[DIMSTR],sottostringa[DIMSTR],copiaS[DIMSTR];
    int i=0,len=0,M=0,m=0,q,c,u;
    printf("Stringa: ");
    do
    {
        str[i] = getchar();
        copiaS[i] = str[i];
        i++;

    } while((str[i-1] != '\n') && (i<DIMSTR));
    str[i-1] = '\0';
    printf("Stringa digitata %s\n",str);
    while(str[len] != '\0')
        len++;
    printf("la lunghezza della sringa %s\n  e' %d\n",str,len);
    int j = 0;
    for(i=len-1;i>=0;i--)
    {
        strc[j++] = str[i];
    }
    strc[len] = '\0';
    printf("Stringa al contrario %s\n",strc);

    int n = 0,x=0;
    for(i=0;str[i] != '\0';i++)
    {
       if((str[i]>='A') &&(str[i]<='Z'))
        M++;
       else
        if((str[i]>='a') && (str[i]<='z'))
        m++;
        else
            if((str[i]>='0')&&(str[i]<='9'))
                n++;
            else
                x++;
    }
    printf("\nla stringa %s ha %d caratteri maiuscoli, ha %d caratteri minuscoli, ha %d caratteri numerici e ha %d caratteri non riconosciuti",str,M,m,n,x);
    int t = 0;
    int b = 0;
    for(i=0;i<len;i++)
{
    if(i%2==0)
        carPari[t++] = str[i];
    else
        if(i%2!=0)
        carDispari[b++] = str[i];
}
    printf("\nNella stringa %s i caratteri con indice pari sono %s e i caratteri con indice dispari sono %s",str,carPari,carDispari);
    //invertire stringa su se stessa

    int e = len-1;
    char s;
    for(i=0;i<len/2;i++)
    {
        s = str[i];
        str[i] = str[e];
        str[e--] = s;
    }
    str[len] = '\0';
    printf("\nla stringa al contrario e' %s ",str);

    //estrazione sottostringa da una stringa
    printf("\nLunghezza sottostringa:");
    scanf("%d",&q);
    printf("\nposizione carattere:");
    scanf("%d",&c);

    if((copiaS[c-1] == "")|| len-c<q)
        sottostringa[0] = "";
    else
        for(i=0;i<q;i++)
    {
        sottostringa[i] = copiaS[c+i-1];
    }
    sottostringa[q] = '\0';
    printf("\nLa sottostringa e' %s",sottostringa);

    return 0;
}

