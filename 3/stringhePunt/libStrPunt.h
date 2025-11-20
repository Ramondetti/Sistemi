#ifndef LIBSTRPUNT_H_INCLUDED
#define LIBSTRPUNT_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define STR_LEN 80+1

int lunghezza(char *s)
{
    int l;
    l=0;
    while(*s!='\0')
    {
        l++;
        s++;
    }
    return l;
}

int palindromo(char *s)
{
    char *s2;
    int pal;
    s2=s;
    while(*s2!='\0')
        s2++;
    s2--;
    while((*s==*s2)&&(s<s2))
    {
        s++;
        s2--;
    }
    if(s2<=s)
        pal=1;
    else
        pal=0;
    return pal;
}

void insStr(char *s, char *s2,int pos)
{
        int i;
        char strApp[STR_LEN],*sAp,*ps;
        if(pos>=lunghezza(s))
        {
            while(*s!='\0')
                s++;

            while(*s2!='\0')
            {
                *s=*s2;
                s++;
                s2++;
            }
            *s='\0';
        }
        else
        {
            ps=pos+lunghezza(s2)-1;
            sAp=strApp;
            while(*ps!='\0')
            {
                *sAp=*ps;
                ps++;
                sAp++;
            }
            *sAp='\0';
            ps=s+pos-1;
            strApp=ps+lunghezza(s2)-1;
            for(i=1;i<=lunghezza(s2);i++)
            {
                *sAp=*ps;
                ps++;
                sAp++;
            }
            *sAp='\0';
            ps=s+pos-1;
            sAp=s2;
             for(i=1;i<=lunghezza(s2);i++)
            {
                *sAp=*ps;
                ps++;
                sAp++;
            }
        }

}

int vocStr(char *s)
{
    int i,cont;
    cont=0;
    for(i=0;*s!='\0';i++)
        {
            if(*s=='a' || *s=='A' || *s=='e' || *s=='E' || *s=='i' || *s=='I' || *s=='o' || *s=='O' || *s=='u' || *s=='U' )
                cont++;
            s++;
        }

        return cont;
}

int diversiStr(char *s)
{
    while (*s != '\0') {
        char *s2 = s + 1;
        while (*s2 != '\0') {
            if (*s == *s2) {
                return 0;
            }
            s2++;
        }
        s++;
    }
    return 1;
}

void ripetiStr(char *s1, char*s2, int *num)
{
    int j;
    while (*s1 != '\0') {
        for (j = 1; j <= *num; j++) {
            *s2 = *s1;
            s2++;
        }
        num++;
        s1++;
    }
    *s2='\0';
}

#endif // LIBSTRPUNT_H_INCLUDED
