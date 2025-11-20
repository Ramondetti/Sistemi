#include "libRubrica.h"
int main()
{
    persona contatti[NCONTATTI];
    int nCont=0,ok;
    char scelta,sc,cogn[SIZE];
    do
    {
        scelta = scriviMenu();
        switch(scelta)
        {
        case 'a':
        case 'A':
            do
            {
                ok = insContatto(contatti,&nCont);
                if(ok)
                {
                    printf("Contatto inserito correttamente");
                    printf("Continui inserimento? (s/n): ");
                    sc = getchar();
                }
                else
                {
                    printf("Rubrica piena, cancella almeno un contatto\n");
                    sc = 'n';
                }
            } while((sc!='n')&&(sc!='N'));
            break;
        case 'b':
        case 'B':
            printf("Cognome del contatto da visualizzare: ");
            gets(cogn);
            ok=visContatto(contatti,cogn,nCont);
            if(!ok) //if(ok==0)
                printf("Il contatto non e' presente in rubrica\n");
            break;
        case 'c':
        case 'C':
            printf("Cognome del contatto da modificare: ");
            gets(cogn);
            ok=modContatto(contatti,cogn,nCont);
            if(!ok) //if(ok==0)
                printf("Il contatto non e' presente in rubrica\n");
            break;
        case 'd':
        case 'D':
            printf("Cognome del contatto da cancellare: ");
            gets(cogn);
            ok=delContatto(contatti,cogn,&nCont);
            if(!ok)
                printf("Il contatto non e' presente in rubrica\n");
            else
                printf("Il contatto e' stato cancellato dalla rubrica\n");
            break;
        case 'e':
        case 'E':
            ok=visRubrica(contatti,nCont);
            if(!ok)
                printf("Non sono presenti contatti in rubrica\n");
            break;
        case 'f':
        case 'F':
            ok=ordnRubrica(contatti,nCont);
            if(!ok)
                printf("Nessun contatto in rubrica\n");
            else
                printf("Rubrica ordinata\n");
            break;
        case 'G':
        case 'g':
            printf("Inserire data del giorno corrente\n");
            data giornoC;
            printf("Giorno corrente ");
            scanf("%d",&giornoC.giorno);
            getchar();
            printf("Mese corrente ");
            scanf("%d",&giornoC.mese);
            getchar();
            printf("Anno corrente ");
            scanf("%d",&giornoC.anno);
            getchar();
            if(controlloData(giornoC))
            {
                printf("Data corretta\n");
                printf("I contatti maggiorenni sono %d\n",dataList(contatti,nCont,giornoC));
            }

            else
                printf("Data non corretta");

            break;
        }
     printf("\nPremi invio per continuare");
     getchar();
     fflush(stdin);
    }while(scelta!='q' && scelta!='Q');

    return 0;
}
