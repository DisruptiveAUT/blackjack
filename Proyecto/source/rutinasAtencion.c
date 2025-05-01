// Curso 2024-2025

/*-------------------------------------
rutinasAtencion.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"
#include "perifericos.h"
#include "fondos.h"
#include "sprites.h"

int ESTADO; // Para controlar el estado del autómata en que esté
int seg3;   // Para ver si pasan tres segundos

void RutAtencionTeclado ()
{
	if (ESTADO == INICIO)
	{	
		if (TeclaPulsada()==START)
		{
			ESTADO=APOSTAR;
			Verde();

		}
	}
	if (ESTADO == PARTIDA)
	{	
		if (TeclaPulsada()==SELECT)
		{
			ESTADO=PAUSA;
			Verde();
			MostrarRomboGrande(1, 80, 45);
			MostrarRomboGrande(2, 80, 115);
		}
	}
}

void RutAtencionTempo()
{
	static int tick=0;
	static int seg=0;
	

if (ESTADO!=INICIO)
{
	tick++; 
	if (tick%30 == 0){
		seg++;
		iprintf("\x1b[12;5HSegundos que han pasado=%d", seg);
		//tick=0;		
	}
	if (ESTADO == JUGAR){
		
		if (seg ==120){
			if(calcularPartida(cartasJugador, cartasCrupier)){
				
				ESTADO = GANAR;
				mostrarGanar();
				borrarJugar();
			}else{
				ESTADO = FIN;
				mostrarFin();
				borrarJugar();
			}
			seg = 0;
			
		}
	}else if (ESTADO == GANAR){
		if(seg = 10){
			ESTADO = APOSTAR;
			borrarGanar();
			mostrarApostar();
			seg = 0;
		} 

	}
}
	
}

void EstablecerVectorInt()
{
// A COMPLETAR
	 irqSet(IRQ_TIMER0, RutAtencionTempo);
	 irqSet(IRQ_KEYS, RutAtencionTeclado);
	
}

/***********************2024-2025*******************************/

