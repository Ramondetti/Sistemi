#include <stdio.h>
#include <stdlib.h>
#define SIZE 100+1

int main()
{
    FILE *fp,*fp2,*fpP,*fpD;
    char str[SIZE];
    char numero[10];
    int i=1;
    fp = fopen("file2.txt","w");
    fp2 = fopen("testo1.txt","r");
    fpD = fopen("rDispari.txt","w");
    fpP = fopen("rPari.txt","w");
    if(fp!=NULL)
    {
        while(!feof(fp2)&&!feof(fp)){
            fgets(str,SIZE,fp2);
            fputs(itoa(i,numero,10),fp);
            fputs(". ",fp);
            fputs(str,fp);
            if(i%2==0)
            {
                fputs(itoa(i,numero,10),fpP);
                fputs(". ",fpP);
                fputs(str,fpP);
            }
            else
            {
                fputs(itoa(i,numero,10),fpD);
                fputs(". ",fpD);
                fputs(str,fpD);
            }

            i++;
        }
        fclose(fp);
        fclose(fp2);
        fclose(fpP);
        fclose(fpD);
        fp2 = fopen("testo1.txt","a");
        fp = fopen("file2.txt","r");
        fputs("\n",fp2);

                while(!feof(fp2)&&!feof(fp)){
            fgets(str,SIZE,fp);
            fputs(str,fp2);
        }
        }



    else{
        printf("Errore nell'apertura del file");
    }

    fclose(fp);
    fclose(fp2);
    return 0;
}
