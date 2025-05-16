#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"
#include <stdbool.h>

struct Carta robarCarta(int cont, struct Carta x[])
{
    cont++;
    return x[cont];
}

/*bool calcularPartida(int valorJugador, int valorCrupier){

    if(valorJugador > 21){
        if (valorCrupier > 21){
            return true;
        }
        else{
            return false;
        }
    }
    else if(valorJugador == 21){
        return true;
    }
    else if(valorJugador < 21)
        if (valorCrupier < 21){
            if (valorCrupier > valorJugador){
                return false;
            }
        }
        else if(valorCrupier == 21){
            return false;
        }
        else if(valorCrupier > 21){
            return true;
        }

}*/

bool calcularPartida(int valorJugador, int valorCrupier)
{
    if (valorJugador > 21)
    {
        return valorCrupier > 21 ? true : false;
    }

    if (valorJugador == 21)
    {
        return true;
    }

    // valorJugador < 21
    if (valorCrupier == 21 || (valorCrupier < 21 && valorCrupier > valorJugador))
    {
        return false;
    }

    return true; // jugador gana si crupier se pasa o tiene menos valor
}
