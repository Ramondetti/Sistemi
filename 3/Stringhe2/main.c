#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIMSTR 10+1

int catStr(char s1[],char s2[]); //firma, dichiarato prima del richiamo
int main()
{
    char str[DIMSTR],str2[DIMSTR];
    int p;
    printf("Stringa");
    gets(str);
    printf("Stringa2");
    gets(str2);
    if(catStr(str,str2)==1)
        printf("Stringa concatenata \212 %s\n",str); // \212 e accentata
    else
        printf("Non \212 possibile concatenare %s a %s\n",str,str2);

    p = intStr(str,str2);
    if(p == -1)
        printf("La stringa %s non \212 contenuta nella stringa %s\n",str2,str);
    else
        printf("La stringa %s \212 contenuta nella stringa %s\n",str2,str);
    return 0;
}

int catStr(char s1[],char s2[])
{
    int i,lun,ret,j;
    for(i=0; s1[i]!='\0'; i++);
    for(j=0; s1[j]!='\0'; j++);
    lun = i+j; //dimensione stringa concatenata
    if(lun<DIMSTR)
    {
        for(j=0;s2[j]!='\0';j++)
        {
         i++;
         s1[i] = s2[j];
        }
        s1[i]='\0';
        ret=1;
    }

    else
        ret=-1;
    return ret;

}

int intStr(char s1[],char s2[])
{
    int i,j,pos,n;
    for(i=0;s1[i]!='\0';i++,j++){
        if(s1[i] == s2[j])
        {
            pos = i;
            n=i+1;
            for(j=1;s1[n] != s2[j] && s2[j] != '\0' && s1[n] !='\0';j++,n++);
            if(s1[n] != s2[j])
                j=0;
        }
}
if(s2[j]!= '\0')
    pos = -1;
return pos;
}
