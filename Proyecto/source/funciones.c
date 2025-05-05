#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    char palo[20];
    char valor[5];
    int valorNum;
} Carta;

void shuffle(Carta mazo[], int n) {
    for (int i = n - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Carta temp = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = temp;
    }
}

void construirBaraja(Carta baraja[]) {
    // Array de valores
    const char *valores[] = { // Array de valores
        "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"
    };

    const char *palos[] = { //Array de palos
        "Corazones", "Diamantes", "Treboles", "Picas"
    };

    int k = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            strcpy(baraja[k].valor, valores[j]); //Asignar valores
            strcpy(baraja[k].palo, palos[i]); //Asignar palo
            
            //Asignar valor numerico
            if (j < 9) { // "2" a "10"
                baraja[k].valorNum = j + 2;
            } else if (j < 12) { // "J", "Q", "K"
                baraja[k].valorNum = 10;
            } else { // "A"
                baraja[k].valorNum = 11;
            }
            k++;
        }
    }
}
