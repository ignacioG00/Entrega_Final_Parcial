/*
 * Recaudaciones.h
 *
 *  Created on: 13 may. 2021
 *      Author: ignac
 */

#ifndef RECAUDACIONES_H_
#define RECAUDACIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** DEFINE

#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


//*** ESTRUCTURA
typedef struct {
	int idRecaudaciones;
	int mes;
	float importe;
	char tipoRecaudacion[20];
	int idContribuyente;
	int isEmpty;
	char estado[20];
} eRecaudaciones;
//***

/** INICIO CABECERAS DE FUNCION*/
void eRecaudaciones_Inicializar(eRecaudaciones array[], int TAM);
int eRecaudaciones_ObtenerID(void);
int eRecaudaciones_ObtenerIndexLibre(eRecaudaciones array[], int TAM);
int eRecaudaciones_BuscarPorID(eRecaudaciones array[], int TAM, int ID);
void eRecaudaciones_MostrarUno(eRecaudaciones Recaudaciones);
int eRecaudaciones_MostrarTodos(eRecaudaciones array[], int TAM);
int eRecaudaciones_MostrarDadosDeBaja(eRecaudaciones array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eRecaudaciones_Sort(eRecaudaciones array[], int TAM, int criterio);

//ABM
eRecaudaciones eRecaudaciones_CargarDatos(void);
eRecaudaciones eRecaudaciones_ModificarUno(eRecaudaciones Recaudaciones);
int eRecaudaciones_Alta(eRecaudaciones array[], int TAM);
int eRecaudaciones_Baja(eRecaudaciones array[], int TAM);
int eRecaudaciones_Modificacion(eRecaudaciones array[], int TAM);
/** FIN CABECERAS DE FUNCION*/



#endif /* RECAUDACIONES_H_ */
