// Curso 2024-2025

/*-------------------------------------
perifericos.c
-------------------------------------*/

#include <nds.h>
#include <stdio.h>
#include "definiciones.h"

int tecla; // Variable para guardar la tecla pulsada; valorar si es necesaria

int TeclaDetectada()
{
	// Devuelve TRUE si detecta que se ha pulsado alguna tecla.
	if ((~TECLAS_DAT & 0x03ff) != 0)
		return 1;
	else
		return 0;
}

int TeclaPulsada()
{

	// Devuelve el código de la tecla pulsada utilizando para ello las constantes definidas en
	// definiciones.h:  A=0;B=1;SELECT=2;START=3;DERECHA=4;IZQUIERDA=5;
	// ARRIBA=6;ABAJO=7;R=8;L=9;
	if ((TECLAS_DAT & 0x0001) == 0)
	{
		return 0;
	}
	else if ((TECLAS_DAT & 0x0002) == 0)
	{
		return 1;
	}
	else if ((TECLAS_DAT & 0x0004) == 0)
	{
		return 2;
	}
	else if ((TECLAS_DAT & 0x0008) == 0)
	{
		return 3;
	}
	else if ((TECLAS_DAT & 0x0010) == 0)
	{
		return 4;
	}
	else if ((TECLAS_DAT & 0x0020) == 0)
	{
		return 5;
	}
	else if ((TECLAS_DAT & 0x0040) == 0)
	{
		return 6;
	}
	else if ((TECLAS_DAT & 0x0080) == 0)
	{
		return 7;
	}
	else if ((TECLAS_DAT & 0x0100) == 0)
	{
		return 8;
	}
	else if ((TECLAS_DAT & 0x0200) == 0)
	{
		return 9;
	}
}

void ConfigurarTeclado(int Conf_Tec)
{
	// Configuración del teclado. Modificar su registro de control en base a los bits
	// activados en el parametro Conf_Tec
	TECLAS_CNT = TECLAS_CNT | Conf_Tec;
}

void ConfigurarTemporizador(int Latch, int Conf_Tempo)
{
	// Configuración del temporizador. El latch es el valor del registro de datos del temporizador
	// Activar los bits del registro de control necesarios en base a los bits activados en el parámetro Conf_Tempo
	TIMER0_CNT = TIMER0_CNT | Conf_Tempo;
	TIMER0_DAT = Latch;
}

void HabilitarIntTeclado()
{
	// Habilitar las interrupciones del teclado
	// Para realizar esa operación, primero deshabilitar todas las interrupciones de forma general, realizar la operación,
	// y después volver a habilitar las interrupciones de forma general
	IME = 0;
	// ESCRIBID AQUÍ VUESTRO CÓDIGO
	IE = IE | 0x00001000;

	IME = 1;
}

void InhibirIntTeclado()
{

	// Deshabilitar las interrupciones del teclado
	// Para realizar esa operación, primero deshabilitar todas las interrupciones de forma general, realizar la operación,
	// y después volver a habilitar las interrupciones de forma general

	IME = 0;
	// ESCRIBID AQUÍ VUESTRO CÓDIGO
	IE = IE & 0xFFFFEFFF;
	IME = 1;
}

void HabilitarIntTempo()
{

	// Habilitar las interrupciones del temporizador (timer0)
	// Para realizar esa operación, primero deshabilitar todas las interrupciones de forma general, realizar la operación,
	// y después volver a habilitar las interrupciones de forma general
	IME = 0;
	// ESCRIBID AQUÍ VUESTRO CÓDIGO
	IE = IE | 0x00000008;
	IME = 1;
}

void InhibirIntTempo()
{

	// Deshabilitar las interrupciones del temporizador (timer0)
	// Para realizar esa operación, primero deshabilitar todas las interrupciones de forma general, realizar la operación,
	// y después volver a habilitar las interrupciones de forma general
	IME = 0;
	// ESCRIBID AQUÍ VUESTRO CÓDIGO
	IE = IE & 0xFFFFFFF7;
	IME = 1;
}

void PonerEnMarchaTempo()
{
	// ESCRIBID AQUÍ VUESTRO CÓDIGO
	TIMER0_CNT = TIMER0_CNT | 0x80;
}

void PararTempo()
{
	// ESCRIBID AQUÍ VUESTRO CÓDIGO
	TIMER0_CNT = TIMER0_CNT & 0x7F;
}

/***********************2024-2025*******************************/
