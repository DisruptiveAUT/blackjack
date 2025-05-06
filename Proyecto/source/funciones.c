#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "definiciones.h"

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
    const char *valores[] = {
        "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"
    };

    const char *palos[] = {
        "Corazones", "Diamantes", "Treboles", "Picas"
    };

    int k = 0;
    for (int i = 0; i < 4; i++) {         // Palos
        for (int j = 0; j < 13; j++) {    // Valores
            baraja[k].id = k; // ID único de 0 a 51

            strcpy(baraja[k].valor, valores[j]);
            strcpy(baraja[k].palo, palos[i]);

            // Asignar valorNum
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
