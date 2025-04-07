// Curso 2024-2025

/*---------------------------------------------------------------------------------
Este código se ha desarrollado basándose en el código de dovoto "Simple sprite demo" 
y en otro ejemplo de Jaeden Ameronen
---------------------------------------------------------------------------------*/


#include <nds.h> 		// Librería de la nds
#include <stdio.h>		// Librería de entrada/salida estándar de C
#include <stdlib.h>		// Librería estándar de C para reserva de memoria y conversiones numéricas
#include <unistd.h>		// Librería para asegurar la compatibilidad entre sistemas operativos

// Librerías desarrolladas por nosotros para el proyecto
	
#include "definiciones.h"
#include "perifericos.h"
#include "rutinasAtencion.h"
#include "fondos.h"

int tiempo;

void juego()
{	
	// Definiciones de variables
	int i=4;
	int tecla=0;

	ESTADO=ESPERA;
	
	// Escribe en la fila 22 columna 5 de la pantalla	
	iprintf("\x1b[22;5HPrueba de escritura");

/* Si se quiere visualizar el valor de una variable escribir %d dentro de las comillas y el nombre de la variable fuera de las comillas */
	iprintf("\x1b[23;5HPrueba de escritura con variable. Valor=%d", i);

	//******************************* EN LA 2.ACTIVIDAD ********************************//
        // LLAMADAS A REALIZAR (ORDEN RECOMENDADO):
	// Configurar el teclado.
	// Configurar el temporizador.
	// Establecer las rutinas de atención a interrupciones.
	// Habilitar las interrupciones del teclado.
	// Habilitar las interrupciones del temporizador.
	// Habilitar interrupciones.
	//******************************************************************************//
	int Conf_Tec = 0x4001; //a insertar en TECLAS_CNT activa A 
	int Conf_Tempo = 0x062; //a insertar en TIMER0_CNT 
	int latch = 26218 ; //latch pasar a timer0_DAT
	ConfigurarTeclado(Conf_Tec);
	ConfigurarTemporizador( latch , Conf_Tempo);
	EstablecerVectorInt();
	HabilitarIntTeclado();
	HabilitarIntTempo();
	PonerEnMarchaTempo();
	EstablecerVectorInt();
	
	


	while(1)
	{	
		
      /*******************************EN LA 1.ACTIVIDAD *****************************************/
		/* Si el estado es ESPERA: codificar aquí la encuesta del teclado, sacar por pantalla la tecla que se ha pulsado, y si se pulsa la tecla START cambiar de estado */
	//HabilitarInterrrupciones();

	if (ESTADO == ESPERA){
	
	if (TeclaPulsada() == START){
	
	ESTADO = CERRADA;
	visualizarPuerta();
	

	}else{
		iprintf("\x1b[17;5HSe ha pulsado la tecla: %d", TeclaPulsada());
	}
	

	}
	
	//DeshabilitarInterrrupciones();
	// Inhibir las interrupciones al final
}
}

/***********************2024-2025*******************************/


