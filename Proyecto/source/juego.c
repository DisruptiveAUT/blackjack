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
	int cartasCrupier = 0;
	int cartasJugador = 0;
	int contadorBaraja = 0;
	int contadorCrupier = 0;
	int contadorJugador = 0;
	int seg = 0;
	int dinero = 100; 
	int apuesta = 0; 
	void vaciarVariables(){
		 cartasCrupier = 0;
		 cartasJugador = 0;
		 contadorBaraja = 0;
		 contadorCrupier = 0;
		 contadorJugador = 0;
		 seg = 0;	
		 apuesta = 0; 
	}
	typedef struct 
	{
		char palo[20];
		char valor[5];
		int valorNum;
	}Carta;
	
	srand(time(NULL));
	Carta baraja [52];
	construirBaraja(baraja);
	shuffle(baraja, sizeof(baraja)/sizeof(baraja[0]));
	touchPosition pos_pantalla;
	void robarCartaJugador(){
		manoJugador[contadorJugador] =  robarCarta( contadorBaraja, baraja);
			cartasJugador = cartasJugador + manoJugador[contadorJugador].valorNum; 
			contadorJugador++;
			
	}
	void robarCartaCrupier(){
		manoCrupier[contadorCrupier] = robarCarta (contadorBaraja, baraja);
			cartasCrupier = cartasCrupier + manoCrupier[contadorCrupier].valorNum; 
			contadorCrupier++;
	}
	
	mostrarInicio();
	while(1)
	{	
		iprintf("\x1b[11;5HDinero apostado=%d", apuesta);
		iprintf("\x1b[10;5HDinero restante=%d", dinero);
	if (ESTADO == INICIO){
	 
	
		if (TeclaPulsada() == START || (pos_pantalla.px == 0 && pos_pantalla.py == 0) ){ //PROVISIONAL, PONER RANGO DE LOS BOTONES 
	
		ESTADO = APOSTAR;
		mostrarApuesta();
		borrarInicio();
		}
	// FINAL CONDICIONAL DE ESTADO INICIO
	

	}  else if (ESTADO == APOSTAR){
		if ((pos_pantalla.px == 0 && pos_pantalla.py == 0) ){ // IF para cambiar de estado a JUGAR //PROVISIONAL, PONER RANGO DE LOS BOTONES 
			ESTADO = JUGAR;
			seg = 0; 
			borrarApostar();
			mostrarJugar();
			
			
			
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
		if (contadorBaraja < 4 ){

		
		for (int i = 0; i < 2; i++;){ //las dos cartas obligatorias del Jugador 
			manoJugador[i] = robarCarta( contadorBaraja, baraja);
			contadorBaraja++;	
			contadorJugador++;
			cartasJugador = cartasJugador + manoJugador[i].valorNum;

		}
		for (int i = 0; i < 2; i++; ){ //las dos cartas obligatorias del crupier
			manoCrupier[i] = robarCarta( contadorBaraja, baraja);
			contadorBaraja++;
			contadorCrupier++;
			cartasCrupier = cartasCrupier + manoCrupier[i].valorNum;
		}

		} 

		if(pos_pantalla.px == 0 && pos_pantalla.py == 0 || cartasJugador => 21) { //si se decide ya jugar pulsando el boton stay o el jugador ya ha superado 21
			while (cartasCrupier <= 17){ //el crupier deja de robar si tiene 17 o mas
					robarCartaCrupier();
				}
			if (calcularPartida(cartasJugador, cartasCrupier)){// si se pierde la partida cambiar estado 
				ESTADO = GANAR;
				dinero = dinero + (2*apuesta); 
				mostrarGanar();
				borrarJugar();
				
			}else if(!(calcularPartida(cartasJugador, cartasCrupier))){
				ESTADO = FIN;
				mostrarFin();
				borrarJugar();
				vaciarVariables();
			}
		}else if (pos_pantalla.px == 0 && pos_pantalla.py == 0){ //pulsa el boton de hit
			
			robarCartaJugador();
			
		}
			
	}else if (ESTADO == PAUSA){
		if (pos_pantalla.px == 0 && pos_pantalla.py == 0){// si se pulsa el boton de reanudar
			ESTADO = JUGAR;
		}else if (pos_pantalla.px == 0 && pos_pantalla.py == 0){// si se pulsa el boton de finalizar
			ESTADO = INICIO;
			construirBaraja(baraja); //barajar cartas y reiniciar
			shuffle(baraja, sizeof(baraja)/sizeof(baraja[0]));
			vaciarVariables();
			mostrarInicio();
		}
	}else if (ESTADO == FIN){
		if (dinero <= 0){
			mostrarPerdido();
			dinero = 100;
			vaciarVariables();
			borrarFin();
			mostrarInicio();
		}
		if (pos_pantalla.px == 0 && pos_pantalla.py == 0){// si se pulsa el boton de volver a jugar
			ESTADO = INICIO;
			vaciarVariables();
			borrarFin();
			mostrarInicio();
		}
	}else if (ESTADO == GANAR){
			mostrarVictoria();
			vaciarVariables();
			if (pos_pantalla.px == 0 && pos_pantalla.py == 0){
				ESTADO = APOSTAR;
				borrarGanar();
				mostrarApostar();
			}
			
	}
	
	//DeshabilitarInterrrupciones();
	// Inhibir las interrupciones al final
	} //FINAL WHILE PRINCIPAL 
}

/***********************2024-2025*******************************/


