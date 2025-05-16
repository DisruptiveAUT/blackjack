// Curso 2024-2025




#include <nds.h> 		// Libreria de la nds
#include <stdio.h>		// Libreria de entrada/salida estándar de C
#include <stdlib.h>		// Libreria estándar de C para reserva de memoria y conversiones numéricas
#include <unistd.h>		// Libreria para asegurar la compatibilidad entre sistemas operativos

// Librerias desarrolladas por nosotros para el proyecto
	
#include "definiciones.h"
#include "perifericos.h"
#include "rutinasAtencion.h"
#include "fondos.h"
#include "sprites.h"
#include "funciones.h"
#include "funciones2.h"



//int tiempo;

// juego.c (antes de la función juego())

int cartasCrupier = 0;
int cartasJugador = 0;
int contadorBaraja = 0;
int contadorCrupier = 0;
int contadorJugador = 0;
//int seg = 0;
int dinero = 100;
int apuesta = 0;
bool crupierMostradas = false;
int segActual = -1;
bool llamadaCalcularPartida(){
	return calcularPartida(cartasJugador,cartasCrupier);
}
bool tocadoPantalla = false;

struct Carta manoJugador[5];
struct Carta manoCrupier[5];
struct Carta manoJugadorLimpio[5];
struct Carta manoCrupierLimpio[5];
struct Carta baraja[52];

	void vaciarVariables(){
		int i;
		 cartasCrupier = 0;
		 cartasJugador = 0;
		 contadorBaraja = 0;
		 contadorCrupier = 0;
		 contadorJugador = 0;
		 seg = 0;	
		 apuesta = 0; 
		 crupierMostradas = false;
		 for ( i = 0; i < 5; i++) {
    		manoJugador[i] = manoJugadorLimpio[i];
   			manoCrupier[i] = manoCrupierLimpio[i];
			}
		
		 construirBaraja(baraja);
		 shuffle(baraja, sizeof(baraja)/sizeof(baraja[0]));
	}

	
	void robarCartaJugador(){
		manoJugador[contadorJugador] =  robarCarta( contadorBaraja, baraja);
			cartasJugador = cartasJugador + manoJugador[contadorJugador].valorNum; 
			if (cartasJugador > 21 && manoJugador[contadorJugador].valorNum == 11){
				cartasJugador = cartasJugador - 10; 
			}
			contadorJugador++;
			
			
	}
	void robarCartaCrupier(){
		manoCrupier[contadorCrupier] = robarCarta (contadorBaraja, baraja);
			cartasCrupier = cartasCrupier + manoCrupier[contadorCrupier].valorNum; 
			if (cartasCrupier > 21 && manoCrupier[contadorCrupier].valorNum == 11){
				cartasCrupier = cartasCrupier - 10; 
			}
			contadorCrupier++;
	}



void juego()
{	
	int i;
	touchPosition pos_pantalla;
	int Conf_Tec = 0x400C; //a insertar en TECLAS_CNT activa START Y SELECT 0100 0000 0000 1100 
	int Conf_Tempo = 0xC1; //a insertar en TIMER0_CNT 1100 0001
	int latch = 48060 ; //latch pasar a timer0_DAT
	ConfigurarTeclado(Conf_Tec);
	ConfigurarTemporizador( latch , Conf_Tempo);
	EstablecerVectorInt();
	HabilitarIntTeclado();
	HabilitarIntTempo();
	PonerEnMarchaTempo();
	//EstablecerVectorInt();
	//int cartasCrupier = 0; //valor numerico de la mano en total
	/*int cartasJugador = 0; //valor numerico de la mano en total
	int contadorBaraja = 0; //cantidad de cartas robadas
	int contadorCrupier = 0; //cantidad de cartas robadas (apunta siempre al siguiente)
	int contadorJugador = 0; //cantidad de cartas robadas (apunta siempre al siguiente)
	int seg = 0;
	int dinero = 100; 
	int apuesta = 0;
	bool crupierMostradas = false;  
	Carta manoJugador[5]; 
	Carta manoCrupier[5];
	Carta manoJugadorLimpio[5]; 
	Carta manoCrupierLimpio[5];*/
	srand(time(NULL));
//	Carta baraja [52];
	construirBaraja(baraja);
	shuffle(baraja, sizeof(baraja)/sizeof(baraja[0]));
	
	
	

	while(1)
	{	
		touchRead(&pos_pantalla);
		
		iprintf("\x1b[2;5Hcontador de jugador =%d           ", contadorJugador);
		iprintf("\x1b[4;5Hcontador de crupier =%d           ", contadorCrupier);		
		iprintf("\x1b[11;5HDinero apostado=%d           ", apuesta);
		iprintf("\x1b[10;5HDinero restante=%d           ", dinero);
		iprintf("\x1b[7;3HEstas tocando los pixeles x: %d e y: %d", pos_pantalla.px, pos_pantalla.py);
		iprintf("\x1b[9;5HSeg pero de juego =%d           ", seg);
		iprintf("\x1b[5;5HSegActual =%d           ", segActual);
		iprintf("\x1b[13;5HSuma de jugador=%d           ", cartasJugador);
		iprintf("\x1b[14;5HSuma de crupier=%d           ", cartasCrupier);

	if (ESTADO == INICIO){
		portada();
	
		if ((pos_pantalla.px >= 1 && pos_pantalla.px <= 256 &&
			pos_pantalla.py >= 1 && pos_pantalla.py <= 192) || TeclaPulsada() == START){ //si se pulsa START o se le da al boton central
	
		ESTADO = APOSTAR;
		}
	// FINAL CONDICIONAL DE ESTADO INICIO
	

	}  else if (ESTADO == APOSTAR){
		
		seleccionarApuesta();
		if (pos_pantalla.px != 0 && tocadoPantalla == false){
				if((pos_pantalla.px >= 15 && pos_pantalla.px <= 47 &&
				pos_pantalla.py >= 100 && pos_pantalla.py <= 132) && dinero >= 1){//boton de anadir 1 ficha
				apuesta = apuesta + 1;
				dinero = dinero - 1;
				tocadoPantalla = true;
			} else if((pos_pantalla.px >= 62 && pos_pantalla.px <= 94 &&
				pos_pantalla.py >= 100 && pos_pantalla.py <= 132) && dinero >= 10){//boton de anadir 10 fichas
				apuesta = apuesta + 10;
				dinero = dinero - 10;
				tocadoPantalla = true;
			} else if((pos_pantalla.px >= 109 && pos_pantalla.px <= 141 &&
				pos_pantalla.py >= 100 && pos_pantalla.py <= 132) && dinero >= 20){//boton de anadir 20 fichas
				apuesta = apuesta + 20;
				dinero = dinero - 20;
				tocadoPantalla = true;
			} else if((pos_pantalla.px >= 156 && pos_pantalla.px <= 188 &&
				pos_pantalla.py >= 100 && pos_pantalla.py <= 132) && dinero >= 50){//boton de anadir 50 fichas
				apuesta = apuesta + 50;
				dinero = dinero - 50;
				tocadoPantalla = true;
			} else if((pos_pantalla.px >= 203 && pos_pantalla.px <= 235 &&
				pos_pantalla.py >= 100 && pos_pantalla.py <= 132) && dinero != 0){//boton de all in
				apuesta = apuesta + dinero;
				dinero = 0;
				tocadoPantalla = true;
			} 
		}

		//FINAL CONDICIONAL DE ESTADO APOSTAR
	} else if (ESTADO == JUGAR){
		diseno();
		if (contadorBaraja < 4 ){

		
		for (i = 0; i < 2; i++){ //las dos cartas obligatorias del Jugador 
			manoJugador[i] = robarCarta( contadorBaraja, baraja);
			contadorBaraja++;	
			contadorJugador++;
			if (manoJugador[i].valorNum == 11){// si es un as
				if (cartasJugador + manoJugador[i].valorNum > 21 ){ //el as cuenta como 11 o 1 segun convenga
					cartasJugador = cartasJugador + 1;
				}else {
					cartasJugador = cartasJugador + 11;
				}
			}else {
				cartasJugador = cartasJugador + manoJugador[i].valorNum;
			}
			mostrarCartaJugador(manoJugador[i], i); // poner las primeras dos cartas robadas del jugador en sus espacios

		}
		for (i = 0; i < 2; i++ ){ //las dos cartas obligatorias del crupier
			manoCrupier[i] = robarCarta( contadorBaraja, baraja);
			contadorBaraja++;
			contadorCrupier++;
			if (manoCrupier[i].valorNum == 11){
				if (cartasCrupier + manoCrupier[i].valorNum > 21 ){ //el as cuenta como 11 o 1 segun convenga
					cartasCrupier = cartasCrupier + 1;
				}else {
					cartasCrupier = cartasCrupier + 11;
				}
			}else {
				cartasCrupier = cartasCrupier + manoCrupier[i].valorNum;
			}
		}

		} 

		if( (pos_pantalla.px >= 198 && pos_pantalla.px <= 246 &&
			pos_pantalla.py >= 96 && pos_pantalla.py <= 128 ) && tocadoPantalla == false || (cartasJugador >= 21 && crupierMostradas == false) || contadorJugador >= 6 ) { //si se decide ya jugar pulsando el boton stay o el jugador ya ha superado 21
				crupierMostradas = true;
				tocadoPantalla = true; 
				while (cartasCrupier < 17){ //el crupier deja de robar si tiene 17 o mas
					robarCartaCrupier();
				}
			
				for (i = 0; i < contadorCrupier; i++){
					mostrarCartaCrupier(manoCrupier[i], i); //muestra todas a la vez

				}
				segActual = devolverSeg();
			while (devolverSeg() - segActual < 4){
				//se mantienen en espera 
			}

			if (calcularPartida(cartasJugador, cartasCrupier) && devolverSeg() - segActual >= 4){// si se pierde la partida cambiar estado 
				ESTADO = GANAR;
				dinero = dinero + (2*apuesta); 
				victoria();
			}else if(!(calcularPartida(cartasJugador, cartasCrupier)) && devolverSeg() - segActual >= 4 ){
				ESTADO = FIN;
				partidaPerdida();
				vaciarVariables();
			}
		}else if (pos_pantalla.px >= 198 && pos_pantalla.px <= 246 &&
			pos_pantalla.py >= 64 && pos_pantalla.py < 96 && tocadoPantalla == false ) { //pulsa el boton de hit
			tocadoPantalla = true; 
			robarCartaJugador();
			mostrarCartaJugador(manoJugador[contadorJugador -1], contadorJugador -1);
			
		}
			
	}else if (ESTADO == PAUSA){
			for (i = 0; i < contadorJugador; i++){
				borrarCartaJugador(manoJugador[i], i);
			}
			if(crupierMostradas == true){
				for (i = 0; i < contadorCrupier; i++){
					borrarCartaCrupier(manoCrupier[i], i);
				}
			}
		if (pos_pantalla.px >= 71 && pos_pantalla.px <= 98 &&
			pos_pantalla.py >= 96 && pos_pantalla.py <= 134){// si se pulsa el boton de reanudar
			ESTADO = JUGAR;
			diseno();
				if (ESTADO == JUGAR){
					for (i = 0; i < contadorJugador; i++){
						mostrarCartaJugador(manoJugador[i], i);
				}
				if(crupierMostradas == true){
					for (i = 0; i < contadorCrupier; i++){
						mostrarCartaCrupier(manoCrupier[i], i);
					}
			}
			}
			
		}else if (pos_pantalla.px >= 152 && pos_pantalla.px <= 190 &&
			pos_pantalla.py >= 97 && pos_pantalla.py <= 134){// si se pulsa el boton de finalizar
			ESTADO = INICIO;
			construirBaraja(baraja); //barajar cartas y reiniciar
			shuffle(baraja, sizeof(baraja)/sizeof(baraja[0]));
			dinero = dinero + apuesta;
			vaciarVariables();
			portada();
		}
	}else if (ESTADO == FIN){
			for (i = 0; i < contadorJugador; i++){
				borrarCartaJugador(manoJugador[i], i);
			}
			
			for (i = 0; i < contadorCrupier; i++){
				borrarCartaCrupier(manoCrupier[i], i);
			}
			
		if (dinero <= 0){
			partidaPerdida();
		
			dinero = 100;
			vaciarVariables();
			portada();
			ESTADO = INICIO;
		
		}
		if ((TeclaPulsada() == A) || (pos_pantalla.px >= 1) && (pos_pantalla.px <= 254) &&
			(pos_pantalla.py >= 1) && (pos_pantalla.py <= 192)){ //tocar la pantalla o pulsar a
			ESTADO = APOSTAR;
			vaciarVariables();
			portada();
		}
	}else if (ESTADO == GANAR){
			for (i = 0; i < contadorJugador; i++){
				borrarCartaJugador(manoJugador[i], i);
			}

			for (i = 0; i < contadorCrupier; i++){
				borrarCartaCrupier(manoCrupier[i], i);
			}
			
			victoria();
			vaciarVariables();
			if (pos_pantalla.px >= 1 && pos_pantalla.px <= 254 &&
				pos_pantalla.py >= 1 && pos_pantalla.py <= 192){ //tocar la pantalla o pulsar a
				ESTADO = APOSTAR;
				seleccionarApuesta();
			}
			
	}
	
	//DeshabilitarInterrrupciones();
	// Inhibir las interrupciones al final
	} //FINAL WHILE PRINCIPAL 
}
/***********************2024-2025*******************************/


