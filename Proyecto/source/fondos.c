// Curso 2024-2025

#include <nds.h> 		
#include <stdio.h>		
#include <stdlib.h>		
#include <unistd.h>		

/* Si queremos visualizar distintos fondos, aquí se debe incluir el fichero de cabecera (fichero .h) de cada fondo. Estos ficheros de cabecera se generan automáticamente durante la compilación */

#include "fondos.h"
#include "graficos.h"
#include "diseno.h"
#include "partidaPerdida.h"
#include "portada.h"
#include "seleccionarApuesta.h"


/* Se elige el canal de DMA que se utilizará para copiar las imágenes en memoria */
static const int DMA_CHANNEL = 3;

/* Para cada fondo que se quiera visualizar hay que escribir un procedimiento como el siguiente */


void diseno() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     disenoBitmap, // Variable que se genera automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal
                     disenoBitmapLen); // Longitud en bytes, variable que se genera automáticamente
}

void partidaPerdida() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     partidaPerdidaBitmap, // Variable que se genera automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal
                     partidaPerdidoBitmapLen); // Longitud en bytes, variable que se genera automáticamente
}

void portada() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                     portadaBitmap, // Variable que se genera automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal
                     portadaBitmapLen); // Longitud en bytes, variable que se genera automáticamente
}

void seleccionarApuesta() {
		
    dmaCopyHalfWords(DMA_CHANNEL,
                    seleccionarApuestaBitmap, // Variable que se genera automáticamente
                     (uint16 *)BG_BMP_RAM(0), // Dirección del fondo principal
                     seleccionarApuestaBitmapLen); // Longitud en bytes, variable que se genera automáticamente
}

/***********************2024-2025*******************************/

