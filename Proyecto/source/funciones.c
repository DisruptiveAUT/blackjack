#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "definiciones.h"

void shuffle(struct Carta mazo[], int n) //ordena las cartas de la baraja de manera aleatoria
{
    int i;
    for (i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        struct Carta temp = mazo[i];
        mazo[i] = mazo[j];
        mazo[j] = temp;
    }
}

void construirBaraja(struct Carta baraja[]) //Construye la baraja de cartas
{
    int k = 0, i, j;
    for (i = 0; i < 4; i++)
    {                            // Palos
        for (j = 0; j < 13; j++) // Valores
        {
            baraja[k].id = k; // ID único de 0 a 51
            // Asignar valorNum
            if (j < 9)
            { // "2" a "10"
                baraja[k].valorNum = j + 2;
            }
            else if (j < 12)
            { // "J", "Q", "K"
                baraja[k].valorNum = 10;
            }
            else
            { // "A"
                baraja[k].valorNum = 11;
            }
            k++;
        }
    }
}
