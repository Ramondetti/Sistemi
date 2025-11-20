#include <stdio.h>
#include <stdlib.h>
#define DIMSTR 30+1


int main()
{
    char str[DIMSTR];
    int frCar[26];
    int i,k,z;
    printf("Stringa: ");
    gets(str);
    for(k=0;k<26;k++)
        frCar[k] = 0;

    for(i=0;str[i]!='\0';i++)
    {
        if(str[i]>='a'&&str[i]<='z')
        frCar[str[i]-'a']++;
        else if(str[i]>='A'&&str[i]<='Z')
            frCar[str[i]-'A']++;
    }
    printf("\nFrequenze dei caratteri alfabetici nella stringa %s",str);
    printf("\n------------------------------------------------\n\n");
    for(z=0;z<26;z++)
        printf("%c:  %d  *  ",'A'+z,frCar[z]);

    frMax(frCar);
    frMaxVoc(frCar);
    frMaxCons(frCar);

    return 0;
}

void frMax(int frCar[])
{
    char cMax[26];
    int max=0,j,k=0,x,cont=0;
    char car;
    for(j=0;j<26;j++)
    {
        if(frCar[j]> max)
        {
            max = frCar[j];
            cMax[0] = max;
            k=1;
            cont=1;
        }
        if(frCar[j]==max)
        {
            cMax[k++] = 'A'+j;
            cont++;
        }
    }
    printf("\n\nIl numero di frequenze massimo \212 %d\n",max);
    printf("I caratteri che ricorrono piu' frequentemente sono:");
    for(x=0;x<cont;x++)
        printf(" %c",cMax[x]);
}

void frMaxVoc(int frCar[])
{
    char cMax[5],vocali[] = {'A','E','I','O','U'};
    int maxV=0,j,k=0,z;
    for(j=0;j<5;j++)
    {
        if(frCar[vocali[j]-'A']>maxV)
            {
                maxV = frCar[vocali[j]-'A'];
                cMax[0] = maxV;
                k=1;
            }
        if(frCar[vocali[j]-'A']==maxV)
        {
            cMax[k++] = vocali[j];
        }
    }
    printf("\n\nIl numero di frequenze massimo delle vocali \212 %d\n",maxV);
    printf("le vocali che ricorrono piu' frequentemente sono:");
    for(z=0;z<5;z++)
    {
        printf(" %c",cMax[z]);
    }
}

void frMaxCons(int frCar[])
{
    char CMax[21];
    int max=0,j,k=0,z,x,isVocal=0,cont=0;
    for(j=0;j<21;j++)
    {
        if('A'+j=='A'||'A'+j=='I'||'A'+j=='E'||'A'+j=='O'||'A'+j=='U')
            isVocal=0;
        else
            isVocal=1;

        if(frCar[j]> max&&isVocal)
        {
            max = frCar[j];
            CMax[0] = max;
            k=1;
            cont=1;
        }
        if(frCar[j]==max)
        {
            CMax[k++] = 'A'+j;
            cont++;
        }
    }
    printf("\n\nIl numero di frequenze massimo delle consonanti \212 %d\n",max);
    printf("Le consonanti che che ricorrono piu' frequentemente sono:");
    for(x=0;x<cont;x++)
        printf(" %c",CMax[x]);
    printf("\n");
    }

