#include "libRubrica.h"

int main()
 {
  persona contatti[NCONTATTI];
  int nCont,i,ok,g,m,a;
  char fileRubrica[SIZE],cogn[SIZE],scelta,sc;

  nCont=0;
  printf("File della rubrica: ");
  gets(fileRubrica);
  ok=caricaRubrica(fileRubrica,contatti,&nCont);
  if(!ok)
   {
    printf("Non ci sono contatti memorizzati\n");
    printf("Premi INVIO per continuare\n");
    getchar();
   }
  do
   {
    scelta=scriviMenu();
    switch (scelta)
     {
      case 'a':
      case 'A':
        do
         {
          ok=insContatto(contatti,&nCont);
          if(ok)
           {
            printf("Contatto inserito correttamente\n");
            printf("Continui l'inserimento(s/n)? : ");
            sc=getchar();
           }
          else
           {
            printf("Rubrica piena, cancella almeno un contatto\n");
            sc='n';
           }
          }while((sc!='n')&&(sc!='N'));
        break;
      case 'b':
      case 'B':
        printf("Cognome del contatto da visualizzare: ");
        gets(cogn);
        ok=visContatto(contatti,cogn,nCont);
        if(!ok)
          printf("Il contatto non e' presente in rubrica\n");
        break;
      case 'c':
      case 'C':
        printf("Cognome del contatto da modificare: ");
        gets(cogn);
        ok=modContatto(contatti,cogn,nCont);
        if(ok)
          printf("Il contatto è stato modificato correttamente\n");
        else
          printf("Il contatto non e' presente in rubrica\n");
        break;
      case 'd':
      case 'D':
        printf("Cognome del contatto da eliminare: ");
        gets(cogn);
        ok=delContatto(contatti,cogn,&nCont);
        if(ok)
          printf("Il contatto e' stato eliminato correttamente\n");
        else
          printf("Il contatto non e' presente in rubrica\n");
        break;
      case 'e':
      case 'E':
        ok=visRubrica(contatti,nCont);
        if(!ok)
          printf("Non ci sono contatti in rubrica\n");
        break;
      case 'g':
      case 'G':
        do
         {
          printf("Data odierna - Giorno: ");
          scanf("%d",&g);
          printf("Data odierna - Mese: ");
          scanf("%d",&m);
          printf("Data odierna - Anno: ");
          scanf("%d",&a);
         }while(!(controllaData(g,m,a))); // controllaData(g,m,a)==0
        ok=visMaggiorenni(contatti,nCont,g,m,a);
        if(!ok)
          printf("Non ci sono contatti in rubrica\n");
        else
          if(ok==-1)
            printf("Non ci sono contatti maggiorenni\n");
        break;
      }
    printf("\nPremi un tasto per continuare");
    getchar();
   }while((scelta!='q')&&(scelta!='Q'));
   ok=salvaRubrica(fileRubrica,contatti,nCont);
   if(ok)
     printf("Rubrica salvata correttamente\n");
   else
     printf("Errore nel salvataggio della rubrica\n");
   getchar();
   return 0;
 }
