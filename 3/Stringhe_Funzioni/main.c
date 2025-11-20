#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libStr.h"
#define DIMSTR 30+1  // dimensione max 30 caratteri + tappo '\0'

int main()
 {
  char str[DIMSTR],str2[DIMSTR],ch,ch2,scelta,s1[DIMSTR],s2[DIMSTR],s3[DIMSTR],s[DIMSTR],str3[DIMSTR];
  int i,len,len2,ncar,z,o,cont;
  do
   {
    scelta=scriviMenu();
    switch (scelta)
     {
      case 'a':
        printf("Stringa: ");
        gets(str);
        len=lenStr(str);
        printf("La stringa %s e' lunga %d caratteri\n",str,len);
        break;
      case 'b':
        printf("Stringa: ");
        gets(str);
        printf("Carattere da cercare: ");
        ch=getchar();
        ncar=contaCar(ch,str);
        printf("Il carattere %c e' contenuto %d volte nella stringa %s\n",ch,ncar,str);
        break;
      case 'c':
        printf("Stringa: ");
        gets(str);
        invCase(str);
        printf("Stringa risultato: %s\n",str);
        break;
      case 'd':
        printf("Stringa: ");
        gets(str);
        copyStr(str,str2);
        printf("La stringa copiata e': %s\n",str2);
        break;
      case 'e':
        printf("Stringa: ");
        gets(str);
        i=palindroma(str);
        if(i)  // if (i!=0)
          printf("La stringa %s e' palindroma\n",str);
        else
          printf("La stringa %s non e' palindroma\n",str);
          break;
      case 'f':
        printf("Stringa 1: ");
        gets(str);
        printf("Stringa 2: ");
        gets(str2);
        if(catStr(str,str2,DIMSTR)==1)
        printf("Stringa concatenata \212 %s\n",str); // \212 e accentata
        else
        printf("Non \212 possibile concatenare %s a %s\n",str,str2);
        break;
      case 'g':
        printf("Stringa 1: ");
        gets(str);
        printf("Stringa 2: ");
        gets(str2);
        int c = inStr(str,str2);
        printf("valore:%d \n",c);
        break;
      case 'h':
        printf("Stringa 1: ");
        gets(str);
        printf("Stringa 2: ");
        gets(str2);
        insertStr(str,str2);
        break;
      case 'i':
        printf("Stringa : ");
        gets(s);
        printf("la stringa contiene %d parole\n",contaParole(s));
        break;
      case 'j':
        printf("Stringa :");
        gets(s);
        strNormal(s);
        printf("Stringa normalizzata: %s\n",s);
        break;
    case 'k':
        printf("Stringa :");
        gets(str3);
        strNormalPunt(str3);
        printf("Stringa normalizzata %s\n",str3);
        break;
     }
     fflush(stdin);
     getchar();
   }while(scelta!='q');
  return 0;
 }

