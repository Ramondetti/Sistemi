#ifndef LIBSTR_H_INCLUDED
#define LIBSTR_H_INCLUDED

// Menu
char scriviMenu()
 {
  char sc;
  system("cls");
  printf("MENU\n");
  printf("----\n");
  printf("a - Calcola lunghezza della stringa\n");
  printf("b - Conta le occorrenze di un carattere nella stringa\n");
  printf("c - Trasforma maiuscolo/minuscolo e viceversa\n");
  printf("d - Copia di una stringa\n");
  printf("e - Verifica se una stringa e' palindroma\n");
  printf("f - Concatenare due stringhe\n");
  printf("g - restituire la posizione del primo carattere di una sottostringa in una stringa o -1 se la sottostringa\nnon e' contenuta nella stringa\n");
  printf("h - inserire sottostringa in una stringa\n");
  printf("i - contare parole in una stringa\n");
  printf("j - eliminare gli eventuali spazi iniziali/finali di una stringa \n");
  printf("k - contare parole in una stringa\n");
  printf("--------\n");
  printf("q - Uscita\n\n");
  printf("Scelta: ");
  sc=getchar();
  fflush(stdin);

  return sc;
 }

// Restituisce la lunghezza della stringa passata come parametro
int lenStr(char s[])
 { int l;
   l=0;
   while(s[l]!='\0')
     l++;
   return l;
 }

// conta quante volte un carattere è contenuto in una stringa,
// indipendentemente dal fatto che sia maiuscolo o minuscolo
int contaCar(char c, char s[])
 {
  char c2;
  int nc,i;
  if((c>='A')&&(c<='Z'))
     c2='a'+(c-'A');
   else
     if((c>='a')&&(c<='z'))
       c2='A'+(c-'a');
   nc=0;
   i=0;
   while(s[i]!='\0') // scorro la stringa fino al tappo
    {
     if((s[i]==c)||(s[i]==c2))
       nc++;
     i++;
    }
  return nc;
 }

// Trasforma i caratteri maiuscoli in minuscoli e viceversa
void invCase(char s[])
 {
   int i;
   for(i=0;s[i]!='\0';i++)
    {
     if((s[i]>='A')&&(s[i]<='Z'))
      {
        s[i]='a'+(s[i]-'A');  // s[i]+=0x20;
      }
     else
      {
       if((s[i]>='a')&&(s[i]<='z'))
        {
         s[i]='A'+(s[i]-'a');
        }
      }
    }
 }

 // Copia la prima stringa nella seconda
 void copyStr(char s[],char s2[])
  {
   int i;
   for(i=0;s[i]!='\0';i++)
      s2[i]=s[i];
    s2[i]='\0';
  }

// Restituisce 1 se la stringa passata come parametro è palindroma, 0 altrimenti
int palindroma(char s[])
 {
  int i1,i2,pal;
  i1=0;
  i2=lenStr(s)-1;
  while((i1<i2)&&(s[i1]==s[i2]))
   {
    i1++;
    i2--;
   }
   if(i1>=i2)
     pal=1;
   else
     pal=0;
   return pal;
 }
 //concatenzione di due stringhe
int catStr(char s1[],char s2[],int dim)
{
    int i,j,lun,ret;
    for(i=0; s1[i]!='\0'; i++);
    for(j=0; s2[j]!='\0'; j++);
    lun = i+j; //dimensione stringa concatenata
    if(lun<dim)
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
//restituire la posizione del primo carattere di una sottostringa in una stringa o -1 se la sottostringa\nnon e' contenuta nella stringa
 int inStr(char str[],char str2[])
 {
     int i,j;
     for(i=0;str[i]!='\0';i++)
     {  int istrue=1;
         for(j=0;str2[j]!='\0'&&istrue;j++)
         {
            if(str[i+j]!=str2[j])
            {
               istrue=0;
            }

         }
     if(istrue&&str2[j]=='\0')
     {
         return i;
     }
    }
        return -1;

 }
//inserire sottostringa in una stringa
    void insertStr(char s1[],char s2[])
    {
        int i,k,pos,len1,len2;
        len1=lenStr(s1);
        len2=lenStr(s2);
        if(len2>len1)
        {
            for(i=0;s2[i]!='\0';i++)
            {
                s1[len1++] = s2[i];
            }

            s1[len1] = '\0';
        }
        else
        {
          printf("inserire posizione ");
          scanf("%d",&pos);
            for(k=0;s2[k]!='\0';k++)
            {
                s1[pos++] = s2[k];
            }
            len1 = lenStr(s1);
            s1[len1] = '\0';
        }
        printf("stringa:%s\n",s1);
    }
        //contare le parole contenute in una stringa
        int contaParole(char s[])
        {
            int i,lunghezza,conteggio,in_parola;
            conteggio = 0;
            in_parola = 0;
            lunghezza = lenStr(s);
            for(i=0;i<lunghezza;i++)
            {
                if(s[i]==' ')
                {
                     if(in_parola)
                     {
                         conteggio++;
                         in_parola = 0;
                     }
                }
                    else
                    {
                        in_parola = 1;
                    }

            }
              if(in_parola)
                    {
                        conteggio++;
                    }
            return conteggio;
        }

        void strNormal(char s[])
        {
            int i,j,in_spazio=1;
            while(s[j]==' ')
            {
                j++;
            }
            for(i=j;i!='\0';i++)
            {
                if(s[i]==' ')
                {
                    if(!in_spazio)
                    {
                        s[j++] = ' ';
                        in_spazio = 1;
                    }
                }

                else
                {
                   s[j++] = s[i];
                   in_spazio = 0;
                }

            }

            if(in_spazio==0&&j>0)
            {
                j--;
            }

            s[j] = '\0';
        }



int isAlphanumeric(char c) {
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
}

void strNormalPunt(char s[]) {
    int i,j = 0;
    int primaLettera = 1;

    for (i = 0; s[i]!= '\0'; i++) {
        if (isAlphanumeric(s[i])) {
            if (primaLettera)
                {
                           if (s[i + 1] != ' ') {
                s[j++] = ' ';
            }
                if (j > 0 && s[j - 1] != ' ') {
                    s[j++] = ' ';
                }
                if (s[i] >= 'a' && s[i] <= 'z') {
                    s[j++] ='A' + (s[i] - 'a');
                } else {
                    s[j++] = s[i];
                }
                primaLettera = 0;
            } else {

                if (s[i] >= 'A' && s[i] <= 'Z')
                {
                    s[j] = s[i] - 'A' + 'a';
                    }
            else {
                    s[j] = s[i];
                 }

            j++;
            }
        } else if (s[i] == ',' || s[i] == ';' || s[i] == ':') {
            s[j++] = s[i];
            if (s[i + 1] != ' ') {
                s[j++] = ' ';
            }
        } else if (s[i] == '.' || s[i] == '!' || s[i] == '?') {
            s[j++] = s[i];
            if (s[i + 1] != ' ') {
                s[j++] = ' ';
            }
        }
    }
    s[j] = '\0';
}





#endif // LIBSTR_H_INCLUDED
