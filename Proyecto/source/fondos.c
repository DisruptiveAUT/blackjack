// Curso 2024-2025

#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

/* Si queremos visualizar distintos fondos, aquí se debe incluir el fichero de cabecera (fichero .h) de cada fondo. Estos ficheros de cabecera se generan automáticamente durante la compilación */

#include "fondos.h"
#include "graficos.h"
#include "Puerta.h"
#include "PuertaAbierta.h"
#include "Verde.h";

/* Se elige el canal de DMA que se utilizará para copiar las imágenes en memoria */
static const int DMA_CHANNEL = 3;

/* Para cada fondo que se quiera visualizar hay que escribir un procedimiento como el siguiente */

void visualizarPuerta() {
	
	dmaCopyHalfWords(DMA_CHANNEL,
                     PuertaBitmap, // Variable que se genera automáticamente 
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal 
                     PuertaBitmapLen); // Longitud en bytes, variable que se genera automáticamente 
}

void visualizarPuertaAbierta() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     PuertaAbiertaBitmap, // Variable que se genera automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal
                     PuertaAbiertaBitmapLen); // Longitud en bytes, variable que se genera automáticamente
}

void Verde() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     VerdeBitmap, // Variable que se genera automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal
                     VerdeBitmapLen); // Longitud en bytes, variable que se genera automáticamente
}

/***********************2024-2025*******************************/

