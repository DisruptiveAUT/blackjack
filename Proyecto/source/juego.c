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
	int Conf_Tec = 0x400C; //a insertar en TECLAS_CNT activa START Y SELECT 0100 0000 0000 1100 
	int Conf_Tempo = 0xC1; //a insertar en TIMER0_CNT 1100 0001
	int latch = 48060 ; //latch pasar a timer0_DAT
	ConfigurarTeclado(Conf_Tec);
	ConfigurarTemporizador( latch , Conf_Tempo);
	EstablecerVectorInt();
	HabilitarIntTeclado();
	HabilitarIntTempo();
	PonerEnMarchaTempo();
	EstablecerVectorInt();
	
	int seg = 0;
	int dinero = 0; 
	int apuesta = 0; 
	typedef struct carta
	{
		int *palo;
		int *numero;
	};
	
	carta baraja [52] =	construirBaraja(baraja);
	touchPosition pos_pantalla;
	
	mostrarInicio();
	while(1)
	{	
		
	if (ESTADO == INICIO){
	 
	
		if (TeclaPulsada() == START || (pos_pantalla.px == 0 && pos_pantalla.py == 0) ){ //PROVISIONAL, PONER RANGO DE LOS BOTONES 
	
		ESTADO = APOSTAR;
		mostrarApuesta();
		botonesApuesta(); 
		}
	// FINAL CONDICIONAL DE ESTADO INICIO
	

	}  else if (ESTADO == APOSTAR){
		if ((pos_pantalla.px == 0 && pos_pantalla.py == 0) ){ // IF para cambiar de estado a PARTIDA //PROVISIONAL, PONER RANGO DE LOS BOTONES 
			ESTADO = PARTIDA;
			seg = 0; 
			mostarPartida();
			cartasCrupier ();
			
		} else {
			if(pos_pantalla.px == 0 && pos_pantalla.py == 0){//boton de anadir 1 ficha
				apuesta = apuesta + 1;
				dinero = dinero - 1;
			} else if(pos_pantalla.px == 0 && pos_pantalla.py == 0){//boton de anadir 10 fichas
				apuesta = apuesta + 10;
				dinero = dinero - 10;
			} else if(pos_pantalla.px == 0 && pos_pantalla.py == 0){//boton de anadir 20 fichas
				apuesta = apuesta + 20;
				dinero = dinero - 20;
			} else if(pos_pantalla.px == 0 && pos_pantalla.py == 0){//boton de anadir 50 fichas
				apuesta = apuesta + 50;
				dinero = dinero - 50;
			} else if(pos_pantalla.px == 0 && pos_pantalla.py == 0){//boton de all in
				apuesta = apuesta + dinero;
				dinero = 0;
			} 
		}
		//FINAL CONDICIONAL DE ESTADO APOSTAR
	} else if (ESTADO == JUGAR){
			if (calcularPartida()){// si se pierde la partida cambiar estado 

			}else if(!(calcularPartida())){
				
			}
	}
	
	//DeshabilitarInterrrupciones();
	// Inhibir las interrupciones al final
	} //FINAL WHILE PRINCIPAL 
}

/***********************2024-2025*******************************/


