#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"

typedef struct 
{
    char palo[20];
    char valor[5];
    int valorNum;
}Carta;


Carta robarCarta(int cont, Carta x[]){
    cont ++;
    return x[cont];
}

bool calcularPartida(int valorJugador, int valorCrupier){
    
    if(valorJugador > 21){
        if (valorCrupier > 21){
            return TRUE;
        }
        else{
            return FALSE;
        }
    }
    else if(valorJugador == 21){
        return TRUE;
    }
    else if(valorJugador < 21) 
        if (valorCrupier < 21){
            if (valorCrupier > valorJugador){
                return FALSE;
            }
        }
        else if(valorCrupier == 21){
            return FALSE;
        }
        else if(valorCrupier > 21){
            return TRUE;
        }
        
}
