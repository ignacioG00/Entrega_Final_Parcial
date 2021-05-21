/*
 ============================================================================
 Name        : PP.c
 Author      : Ignacio Guillen
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"
#include "Informes.h"
#define TAM_CONTRIBUYENTE 50
#define TAM_RECAUDACIONES 50

int main(void) {
	setbuf(stdout, NULL);

	int opc;
//	int criterioDeOrdenamiento;
	int flagContrib = 0;

	//CREO ARRAY DE CONTRIBUYENTE
	eContribuyente Contribuyente[TAM_CONTRIBUYENTE];
	eRecaudaciones Recaudaciones[TAM_RECAUDACIONES];
	//INICIALIAZO ARRAY DE CONTRIBUYENTE
	eContribuyente_Inicializar(Contribuyente, TAM_CONTRIBUYENTE);
	eRecaudaciones_Inicializar(Recaudaciones, TAM_CONTRIBUYENTE);

	//BUCLE DE MENU
	do {
		//MENU PRINT
		menu();
		printf("* INGRESE OPCION DE MENU: ");
		scanf("%d", &opc);

		//MENU SWITCH
		switch (opc)
		{
		case 0:
			/** PREGUNTAR SI DESEA SALIR */
			opc = 0;
			break;
		case 1:
			//ALTA
			puts("\n\n\t *** CONTRIBUYENTE ***");
			puts("\t *** ALTA CONTRIBUYENTE ***\n\n");
			if (eContribuyente_Alta(Contribuyente, TAM_CONTRIBUYENTE))
			{
				eContribuyente_MostrarTodos(Contribuyente, TAM_CONTRIBUYENTE);
				puts(" * CONTRIBUYENTE DADO DE ALTA EXITOSAMENTE *\n");
			} else {
				puts(" * NO SE DIO DE ALTA.");
			}
			system("pause");
			flagContrib = 1;
			break;
		case 2:
			//MODIFICACION
			puts("\n\n\t *** CONTRIBUYENTE ***");
			puts("\t *** MODIFICACION CONTRIBUYENTE ***\n");
			if (eContribuyente_Modificacion(Contribuyente, TAM_CONTRIBUYENTE))
			{
				puts("\n * MODIFICACION DE CONTRIBUYENTE EXITOSA *\n");
				eContribuyente_MostrarTodos(Contribuyente, TAM_CONTRIBUYENTE);
			} else {
				puts("\n * MODIFICACION DE Contribuyente CANCELADA *\n");
			}
			system("pause");
			break;
		case 3:
			//BAJA
			if(flagContrib==1){
				puts("\t *** RECAUDACIONES ***\n\n");
			if (bajaDeContribuyente(Recaudaciones, TAM_RECAUDACIONES, Contribuyente, TAM_CONTRIBUYENTE))
			{
				puts("\n * BAJA DE CONTRIBUYENTE EXITOSA *\n");

				eContribuyente_MostrarTodos(Contribuyente, TAM_CONTRIBUYENTE);
			} else {
				puts("\n * BAJA DE CONTRIBUYENTE CANCELADA");
			}
			system("pause");
			}else{
				opc=1;
				printf("*DEBE EXISTIR UN CONTRIBUYENTE*\n");
			}
			break;

		case 4:
			//ALTA RECAUDACIONES
			if(flagContrib==1){
				puts("\n\n\t *** RECAUDACIONES ***");
				puts("\t *** ALTA CONTRIBUYENTE ***\n\n");
			if (eRecaudacionesContribuyente_Alta(Recaudaciones, TAM_RECAUDACIONES, Contribuyente, TAM_CONTRIBUYENTE))
			{
				puts("\n* RECAUDACION DADA DE ALTA EXITOSAMENTE *\n");
				eRecaudaciones_MostrarTodos(Recaudaciones,TAM_RECAUDACIONES);
			} else {
				puts(" * NO SE DIO DE ALTA.");
			}
			system("pause");
			}else{
				opc=1;
				printf("\n* DEBE EXISTIR UN CONTRIBUYENTE *\n");
			}
			break;
		case 5:
			//CAMBIAR ESTADO A REFINANCIAR
			if(flagContrib==1){
				puts("\n\n\t *** RECAUDACIONES ***");
				puts("\t *** CAMBIO DE ESTADO A 'REFINANCIAR' ***\n\n");
				eRecaudaciones_MostrarTodos(Recaudaciones,TAM_RECAUDACIONES);
				refinanciar_Recaudacion(Recaudaciones,Contribuyente,TAM_CONTRIBUYENTE,TAM_RECAUDACIONES);
				puts("\n * ESTADO DE RECAUDACION CAMBIADO EXITOSAMENTE *\n");
				eRecaudaciones_MostrarTodos(Recaudaciones,TAM_RECAUDACIONES);
				system("pause");
			}else{
				opc=1;
				printf("*DEBE EXISTIR UN/A CONTRIBUYENTE/RECAUDACION*\n");
			}
			break;
		case 6:
			//CAMBIAR ESTADO A SALDADO
			if(flagContrib==1){
				puts("\n\n\t *** RECAUDACIONES ***");
				puts("\t *** CAMBIO DE ESTADO A 'SALDADO' ***\n\n");
			eRecaudaciones_MostrarTodos(Recaudaciones,TAM_RECAUDACIONES);
			saldar_Recaudacion(Recaudaciones,Contribuyente,TAM_CONTRIBUYENTE,TAM_RECAUDACIONES);
			eRecaudaciones_MostrarTodos(Recaudaciones,TAM_RECAUDACIONES);
			puts(" \n* ESTADO DE RECAUDACION CAMBIADO EXITOSAMENTE *\n");
			system("pause");
			}else{
				opc=1;
				printf("\n* DEBE EXISTIR UN/A CONTRIBUYENTE/RECAUDACION *\n");
			}
			break;
		case 7:
			 //IMPRIMIR CONTRIBUYENTE
			if(flagContrib==1){
				puts("\n\n\t *** CONTRIBUYENTE ***");
				puts("\t*** IMPRIMIR CONTRIBUCIONES ***\n\n");
			if(imprimir_Contribuyentes(Recaudaciones, TAM_RECAUDACIONES
					,Contribuyente, TAM_CONTRIBUYENTE))
			{
				puts(" \n* IMPRESION EXITOSA *\n");
				system("pause");
			}
			}else{
				puts("NO EXISTE CONTRIBUYENTE CARGADO.");
				}
			break;
		case 8:
			//IMPRIMIR RECAUDACIONES
			if(flagContrib==1){
				puts("\n\n\t *** RECAUDACIONES ***");
				puts("\t *** IMPRIMIR RECAUDACIONES SALDADAS ***\n\n");
			if(imprimir_Recaudaciones(Recaudaciones, TAM_RECAUDACIONES
					,Contribuyente, TAM_CONTRIBUYENTE))
			{
				puts(" \n* IMPRESION EXITOSA *\n");
				system("pause");
			}
			}else{
				puts("NO EXISTE CONTRIBUYENTE CARGADO.");
				}
			break;
		case 9:
			if(flagContrib==1){
				puts("\n\n\t *** CONTRIBUYENTE ***");
				puts("\t *** IMPRIMIR CONTRIBUYENTE CON TIPO DE RECAUDACION ***\n\n");
			if(informe_ContribDeTipoRec(Recaudaciones, TAM_RECAUDACIONES
					,Contribuyente, TAM_CONTRIBUYENTE))
			{
				puts(" \n* IMPRESION EXITOSA *\n");
				system("pause");
			}
			}else{
				puts("NO EXISTE CONTRIBUYENTE CARGADO.");
				}
			break;
		case 10:
			if(flagContrib==1){
				puts("\n\n\t *** CONTRIBUYENTES ***");
				puts("\t *** IMPRIMIR CONTRIBUYENTES QUE PAGARON EN FEBRERO ***\n\n");
			if(pagaronEnFebrero(Recaudaciones, TAM_RECAUDACIONES
					,Contribuyente, TAM_CONTRIBUYENTE))
			{
				puts(" \n* IMPRESION EXITOSA *\n");
				system("pause");
			}
			}else{
				puts("NO EXISTE CONTRIBUYENTE CARGADO.");
				}
			break;
		case 11:
			if(flagContrib==1){
				puts("\n\n\t *** RECAUDACIONES ***");
				puts("\t *** IMPRIMIR CANTIDAD RECAUDACIONES MAYORES A 1000 ***\n\n");
			if(cantRecaudaciones(Recaudaciones, TAM_RECAUDACIONES
					,Contribuyente, TAM_CONTRIBUYENTE))
			{
				puts(" \n* IMPRESION EXITOSA *\n");
				system("pause");
			}
			}else{
				puts("NO EXISTE CONTRIBUYENTE CARGADO.");
				}
			break;

		}
	} while (opc != 0);

	puts("\n... FIN PROGRAMA");

	return 0;
}
