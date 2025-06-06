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
#include "funciones.h"
#include "funciones2.h"
#include "juego.h"

int ESTADO;	 // Para controlar el estado del autómata en que esté
int seg = 0; //

void RutAtencionTeclado()
{

	if (ESTADO == APOSTAR && TeclaPulsada() == START)
	{
		ESTADO = JUGAR;
		diseno();
	}
	if (TeclaPulsada() == SELECT && ESTADO == JUGAR)
	{
		ESTADO = PAUSA;
		menuPausa();
	}
}

void RutAtencionTempo()
{
	static int tick = 0;
	// static int seg =0;

	if (ESTADO != INICIO)
	{
		tick++;
		swiWaitForVBlank();
		oamUpdate(&oamMain);
		if (tick % 30 == 0)
		{
			seg++;

			tocadoPantalla = false;
			iprintf("\x1b[12;HSegundos que han pasado=%d", seg);
			// tick=0;
		}
		if (ESTADO == JUGAR)
		{

			if (seg == 120)
			{
				if (llamadaCalcularPartida())
				{
					ESTADO = GANAR;
					victoria();
				}
				else
				{
					ESTADO = FIN;
					partidaPerdida();
				}
				seg = 0;
			}
		}
		
	}
}
int devolverSeg()
{
	return seg;
}

void EstablecerVectorInt()
{

	irqSet(IRQ_TIMER0, RutAtencionTempo);
	irqSet(IRQ_KEYS, RutAtencionTeclado);
}

/***********************2024-2025*******************************/
