/*
 * Contribuyente.h
 *
 *  Created on: 12 may. 2021
 *      Author: ignac
 */

#ifndef Contribuyente_H_
#define Contribuyente_H_
#include "biblioteca.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//*** DEFINE
#define MAX_CHARS_CADENAS 20
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1


//*** ESTRUCTURA

typedef struct {
	int idContribuyente;
	char nombre[MAX_CHARS_CADENAS];
	char apellido[MAX_CHARS_CADENAS];
	char cuil[MAX_CHARS_CADENAS];
	int isEmpty;
} eContribuyente;
//***

/** INICIO CABECERAS DE FUNCION*/
void eContribuyente_Inicializar(eContribuyente array[], int TAM);
int eContribuyente_ObtenerID(void);
int eContribuyente_ObtenerIndexLibre(eContribuyente array[], int TAM);
int eContribuyente_BuscarPorID(eContribuyente array[], int TAM, int ID);
void eContribuyente_MostrarUno(eContribuyente Contribuyente);
int eContribuyente_MostrarTodos(eContribuyente array[], int TAM);
int eContribuyente_MostrarDadosDeBaja(eContribuyente array[], int TAM);

/** SORT */
//CRITERIO -> -1 = MENOR A MAYOR
//CRITERIO ->  1 = MAYOR A MENOR
int eContribuyente_Sort(eContribuyente array[], int TAM, int criterio);

//ABM
eContribuyente eContribuyente_CargarDatos(void);//modificar
eContribuyente eContribuyente_ModificarUno(eContribuyente Contribuyente);//modificar
int eContribuyente_Alta(eContribuyente array[], int TAM);
int eContribuyente_Baja(eContribuyente array[], int TAM);
int eContribuyente_Modificacion(eContribuyente array[], int TAM);
/** FIN CABECERAS DE FUNCION*/

#endif /* Contribuyente_H_ */
