#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 80+1

int main() {
    char str[DIM], cifrato[DIM], *pv, *pc, decifrato[DIM];
    int chiave, chiave2;

    // Lettura del messaggio
    printf("Inserisci messaggio: ");
    gets(str);

    // Lettura della chiave
    do {
        printf("Inserisci la chiave: ");
        scanf("%d", &chiave);
    } while ((chiave < 1) || (chiave > 25));

    // Cifratura del messaggio
    pv = str;
    pc = cifrato;
    while (*pv != '\0') {
        if (*pv >= 'A' && *pv <= 'Z') {
            *pc = *pv + chiave;
            if (*pc > 'Z') {
                *pc = 'A' + (*pc - 'Z') - 1;
            }
        } else if (*pv >= 'a' && *pv <= 'z') {
            *pc = *pv + chiave;
            if (*pc > 'z') {
                *pc = 'a' + (*pc - 'z') - 1;
            }
        } else {
            *pc = *pv;
        }
        pc++;
        pv++;
    }
    *pc = '\0';
    printf("Il messaggio cifrato è: %s\n", cifrato);

    // Tentativo di decifratura con tutte le chiavi possibili
    for (chiave2 = 1; chiave2 <= 25; chiave2++) {
        pc = cifrato;
        pv = decifrato;

        while (*pc != '\0') {
            if (*pc >= 'A' && *pc <= 'Z') {
                *pv = *pc - chiave2;
                if (*pv < 'A') {
                    *pv = 'Z' - ('A' - *pv - 1);
                }
            } else if (*pc >= 'a' && *pc <= 'z') {
                *pv = *pc - chiave2;
                if (*pv < 'a') {
                    *pv = 'z' - ('a' - *pv - 1);
                }
            } else {
                *pv = *pc;
            }
            pc++;
            pv++;
        }
        *pv = '\0';
        printf("Con chiave %d, il messaggio decifrato è: %s\n", chiave2, decifrato);
    }

    return 0;
}
