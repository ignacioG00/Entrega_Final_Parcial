/*
 * Entidades.c
 *
 *  Created on: 12 may. 2021
 *      Author: ignac
 */
#ifndef ENTIDADES_C_
#define ENTIDADES_C_

#include "Contribuyente.h"
#include "Recaudaciones.h"

int eRecaudacionesContribuyente_Alta(eRecaudaciones arrayRecaudaciones[], int TAM_Recaudaciones,eContribuyente arrayContribuyente[], int TAM_Contribuyente)
{

	int rtn = 0;
	eRecaudaciones auxRecaudaciones;
	int idContribuyente;

	int index = eRecaudaciones_ObtenerIndexLibre(arrayRecaudaciones, TAM_Recaudaciones);

	if (index != -1) {
		auxRecaudaciones = eRecaudaciones_CargarDatos();

		//ID DE Contribuyente
		eContribuyente_MostrarTodos(arrayContribuyente, TAM_Contribuyente);
		idContribuyente = get_Int("SELECCIONE ID DE CONTRIBUYENTE A QUIEN PONER LA RECAUDACION:\n ",
				"ERROR. REINGRESE: ");

		while (eContribuyente_BuscarPorID(arrayContribuyente, TAM_Contribuyente, idContribuyente) == -1) {
			puts("ID NO EXISTE.");
			idContribuyente = get_Int("SELECCIONE ID DE CONTRIBUYENTE PARA VER RECAUDACIONES: ",
					"ERROR. REINGRESE: ");
		}
		auxRecaudaciones.idContribuyente = idContribuyente;

		//TENGO TODO CARGADO
		if (validate_Exit_SN("\n CONTINUAR SI[S] - NO[N]: ",
				"ERROR. REINGRESE: ")) {
			auxRecaudaciones.idRecaudaciones = eRecaudaciones_ObtenerID()+99;
			auxRecaudaciones.isEmpty = OCUPADO;
			arrayRecaudaciones[index] = auxRecaudaciones;
			rtn = 1;
		}
	}
	return rtn;
}

/*3) Baja de contribuyente: Se ingresa el ID del contribuyente y se listarán todas las
recaudaciones de dicho contribuyente. Luego se preguntará si se quiere confirmar la
eliminación, la cual implicará la eliminación de todos las recaudaciones y del contribuyente.*/

int bajaDeContribuyente(eRecaudaciones arrayRecaudaciones[], int TAM_Recaudaciones,eContribuyente arrayContribuyente[], int TAM_Contribuyente)
{
	int rtn =0;
	int idContribuyente;

	eContribuyente_MostrarTodos(arrayContribuyente, TAM_Contribuyente);
	idContribuyente = get_Int("SELECCIONE ID DE CONTRIBUYENTE PARA VER RECAUDACIONES: ",
			"ERROR. REINGRESE: ");

	while (eContribuyente_BuscarPorID(arrayContribuyente, TAM_Contribuyente, idContribuyente) == -1) {
		puts("ID NO EXISTE.");
	idContribuyente = get_Int("SELECCIONE ID DE CONTRIBUYENTE PARA VER RECAUDACIONES: ",
				"ERROR. REINGRESE: ");
	}
	puts("\t ***RECAUDACIONES***");

	for(int i=0;i<TAM_Recaudaciones;i++)
	{
		if(arrayRecaudaciones[i].idContribuyente==idContribuyente)
		{
			eRecaudaciones_MostrarUno(arrayRecaudaciones[i]);
		}
	}

	if (validate_Exit_SN("DESEA DAR DE BAJA ESTE CONTRIBUYENTE? SI[S] - NO[N]: ",
					"ERROR. REINGRESE: "))
	{
		for(int i=0;i<TAM_Recaudaciones;i++)
			{
				if(arrayRecaudaciones[i].idContribuyente==idContribuyente)
				{
					arrayRecaudaciones[i].isEmpty=BAJA;
				}
			}
		eContribuyente_Baja(arrayContribuyente, TAM_Contribuyente);
		rtn=1;
	}
	return rtn;
}

/*
5) Refinanciar Recaudación: Se pedirá el ID de la recaudación y se imprimirá la información
del contribuyente al que pertenece, luego se pedirá confirmación para cambiarse de estado y
se cambiará al estado "refinanciar".*/

int refinanciar_Recaudacion(eRecaudaciones arrayRecaudaciones[],eContribuyente arrayContribuyente[]
							,int TAM_Contribuyente,int TAM_Recaudaciones)
{
	int rtn = 0;
	puts("\t *** RECAUDACIONES ***");
	puts("\t *** CAMBIO DE ESTADO A 'REFINANCIACION' ***");
	int auxID = get_Int("SELECCIONE ID DE RECAUDACION PARA DAR CON EL CONTRIBUYENTE: \n",
			"ERROR. REINGRESE: \n");
	int aux;
	int indexC;
	int indexR;

	while(eRecaudaciones_BuscarPorID(arrayRecaudaciones,TAM_Recaudaciones,auxID)==-1)
	{
		auxID = get_Int("SELECCIONE ID DE RECAUDACION PARA DAR CON EL CONTRIBUYENTE: \n",
					"ERROR. REINGRESE: \n");
	}

	indexR= eRecaudaciones_BuscarPorID(arrayRecaudaciones,TAM_Recaudaciones,auxID);

	aux= arrayRecaudaciones[indexR].idContribuyente;

	indexC= eContribuyente_BuscarPorID(arrayContribuyente,TAM_Recaudaciones,aux);

	puts("\n\t| LISTADO Contribuyente |");
	printf("| %5s | %15s | %15s | %15s |\n\n ","ID" ,"NOMBRE","APELLIDO","CUIL");
	eContribuyente_MostrarUno(arrayContribuyente[indexC]);

	if (validate_Exit_SN("DESEA CAMBIAR EL ESTADO A 'REFINANCIAR'? SI[S] - NO[N]: ",
						"ERROR. REINGRESE: "))
		{
			strcpy(arrayRecaudaciones[indexR].estado,"REFINANCIAR");
			rtn = 1;
		}
	return rtn;
}

int saldar_Recaudacion(eRecaudaciones arrayRecaudaciones[],eContribuyente arrayContribuyente[]
							,int TAM_Contribuyente,int TAM_Recaudaciones)
{
	int rtn = 0;

	int auxID = get_Int("SELECCIONE ID DE RECAUDACION PARA DAR CON EL CONTRIBUYENTE: \n",
			"ERROR. REINGRESE: \n");
	int indexC;
	int indexR;
	int aux;

	while(eRecaudaciones_BuscarPorID(arrayRecaudaciones,TAM_Recaudaciones,auxID)==-1)
		{
			auxID = get_Int("SELECCIONE ID DE RECAUDACION PARA DAR CON EL CONTRIBUYENTE: \n",
						"ERROR. REINGRESE: \n");
		}

	indexR= eRecaudaciones_BuscarPorID(arrayRecaudaciones,TAM_Recaudaciones,auxID);

	aux= arrayRecaudaciones[indexR].idContribuyente;

	indexC= eContribuyente_BuscarPorID(arrayContribuyente,TAM_Recaudaciones,aux);

	puts("\n\t| LISTADO CONTRIBUYENTE |");
	printf("| %5s | %15s | %15s | %15s |\n\n ","ID" ,"NOMBRE","APELLIDO","CUIL");
	eContribuyente_MostrarUno(arrayContribuyente[indexC]);

	if (validate_Exit_SN("DESEA CAMBIAR EL ESTADO A 'SALDADO'? SI[S] - NO[N]: ",
						"ERROR. REINGRESE: "))
		{
			strcpy(arrayRecaudaciones[indexR].estado,"SALDADO");
			rtn = 1;
		}
	return rtn;
}

int imprimir_Contribuyentes(eRecaudaciones arrayRecaudaciones[], int TAM_Recaudaciones
		,eContribuyente arrayContribuyente[], int TAM_Contribuyente)
{
	int retorno=-1;
	int flagPrimerContrib=0;
	if(arrayRecaudaciones!=NULL && arrayContribuyente!=NULL && TAM_Recaudaciones>0 && TAM_Contribuyente>0)
	{
		for(int i=0; i<TAM_Contribuyente; i++)
		{
			if(arrayContribuyente[i].isEmpty)
			{

				puts("\n\t | CONTRIBUYENTE |");
				printf("| %5s | %15s | %15s | %15s |\n\n ","ID" ,"NOMBRE","APELLIDO","CUIL");
				eContribuyente_MostrarUno(arrayContribuyente[i]);
				flagPrimerContrib=1;

				for(int b=0;b<TAM_Recaudaciones;b++)
				{
					if(arrayRecaudaciones[b].idContribuyente==arrayContribuyente[i].idContribuyente)
					{
						if(flagPrimerContrib){
						puts("\n\t| LISTADO RECAUDACIONES | ");
						printf("| %5s | %5s | %10s | %15s | %15s | %10s |\n\n ",
								"ID RECAUDACION" ,
								"MES","IMPORTE",
								"TIPO RECAUDACION",
								"ID CONTRIBUYENTE",
								"ESTADO");
						flagPrimerContrib=0;
						}
						eRecaudaciones_MostrarUno(arrayRecaudaciones[b]);
					}
				}
			}else{
				continue;
			}
		}
		retorno=1;
	}
	return retorno;
}

int imprimir_Recaudaciones(eRecaudaciones arrayRecaudaciones[], int TAM_Recaudaciones
		,eContribuyente arrayContribuyente[], int TAM_Contribuyente)
{
	int retorno=-1;
	int flagPrimerRec=0;
	if(arrayRecaudaciones!=NULL && arrayContribuyente!=NULL && TAM_Recaudaciones>0 && TAM_Contribuyente>0)
	{
		for(int i=0; i<TAM_Recaudaciones; i++)
		{
			if(arrayRecaudaciones[i].isEmpty && strcmp(arrayRecaudaciones[i].estado,"SALDADO")==0)
			{
				if(flagPrimerRec==0){
				puts("\n\t| LISTADO RECAUDACIONES | ");
				printf("| %5s | %5s | %10s | %15s | %15s | %10s | %15s | %15s | %15s | \n\n ",
						"ID RECAUDACION" ,"MES","IMPORTE","TIPO RECAUDACION", "ID CONTRIBUYENTE", "ESTADO","CUIL","NOMBRE","APELLIDO");
				flagPrimerRec=1;
				}

				for(int b=0;b<TAM_Contribuyente;b++)
				{
					if(arrayRecaudaciones[i].idContribuyente==arrayContribuyente[b].idContribuyente)
					{

							printf("%5d %15d %15f %10s %20d %20s %15s %15s %15s \n\n",
									arrayRecaudaciones[i].idRecaudaciones,
									arrayRecaudaciones[i].mes,
									arrayRecaudaciones[i].importe,
									arrayRecaudaciones[i].tipoRecaudacion,
									arrayRecaudaciones[i].idContribuyente,
									arrayRecaudaciones[i].estado,
									arrayContribuyente[b].cuil,
									arrayContribuyente[b].nombre,
									arrayContribuyente[b].apellido);

					}
				}
			}else{
				continue;
			}
		}
		retorno=1;
	}
	return retorno;
}
/*
a) Contribuyentes con más recaudaciones en estado “refinanciar”.
*/

int contribMasRecaudaciones(eRecaudaciones arrayRecaudaciones[], int TAM_Recaudaciones
		,eContribuyente arrayContribuyente[], int TAM_Contribuyente)
{
	int retorno=-1;
	int flagPrimerContrib=0;
	int cantRecXContribuyente[TAM_Contribuyente];

	if(arrayRecaudaciones!=NULL && arrayContribuyente!=NULL && TAM_Recaudaciones>0 && TAM_Contribuyente>0)
	{
		for(int i=0; i<TAM_Contribuyente; i++)
		{
			if(arrayContribuyente[i].isEmpty)
			{

				puts("\n\t | CONTRIBUYENTE |");
				printf("| %5s | %15s | %15s | %15s |\n\n ","ID" ,"NOMBRE","APELLIDO","CUIL");
				eContribuyente_MostrarUno(arrayContribuyente[i]);

				for(int b=0;b<TAM_Recaudaciones;b++)
				{
					if(arrayRecaudaciones[i].isEmpty && strcmp(arrayRecaudaciones[i].estado,"REFINANCIAR")==0)
					{
						cantRecXContribuyente[i] +=1;

						eRecaudaciones_MostrarUno(arrayRecaudaciones[b]);
					}
				}
			}else{
				continue;
			}
		}
		ArraySort_Int(cantRecXContribuyente,TAM_Contribuyente,1);

		printf("El contribuyente con mas recaudaciones en 'refinanciar' es : %s "),
		retorno=1;
	}
	return retorno;
}

/*
b) Cantidad de recaudaciones saldadas de importe mayor a 1000: Se imprimirá
la cantidad de recaudaciones en estado “saldado” con ese importe o mayor.*/

int cantRecaudaciones(eRecaudaciones arrayRecaudaciones[], int TAM_Recaudaciones
		,eContribuyente arrayContribuyente[], int TAM_Contribuyente)
{
	int retorno=-1;
	int contadorRecaudaciones=0;
	if(arrayRecaudaciones!=NULL && arrayContribuyente!=NULL && TAM_Recaudaciones>0 && TAM_Contribuyente>0)
	{
		for(int i=0; i<TAM_Recaudaciones; i++)
		{
			if(arrayRecaudaciones[i].isEmpty && strcmp(arrayRecaudaciones[i].estado,"SALDADO")==0 && arrayRecaudaciones[i].importe >999)
			{
				contadorRecaudaciones ++;
			}else{
				continue;
			}
		}
		printf("la cantidad de recaudaciones 'saldadas' de importe mayor a 1000 es de: %d\n", contadorRecaudaciones);
		retorno=1;
	}
	return retorno;
}
/*
c) Informar todos los datos de los contribuyentes de un tipo de recaudación
ingresada por el usuario (ARBA, IIBB, GANANCIAS)*/

int informe_ContribDeTipoRec(eRecaudaciones arrayRecaudaciones[], int TAM_Recaudaciones
		,eContribuyente arrayContribuyente[], int TAM_Contribuyente)
{
	int retorno=-1;
	char tipoRec[20];
	int opc=get_IntRange("\t1- ARBA \n\t2 - IIBB \n\t3 - GANANCIAS","ERROR REINGRESE EL TIPO DE RECAUDACION:\n "
				"\t1- ARBA \n\t2 - IIBB \n\t3 - GANANCIAS",1,3);
		switch(opc){
		case 1:
			strcpy(tipoRec, "ARBA");
			break;
		case 2:
			strcpy(tipoRec, "IIBB");
			break;
		case 3:
			strcpy(tipoRec, "GANANCIAS");
			break;
		}
	if(arrayRecaudaciones!=NULL && arrayContribuyente!=NULL && TAM_Recaudaciones>0 && TAM_Contribuyente>0)
	{
		for(int i=0; i<TAM_Recaudaciones; i++)
		{
			if(arrayRecaudaciones[i].isEmpty && strcmp(arrayRecaudaciones[i].tipoRecaudacion,tipoRec)==0)
			{
				for(int b=0;b<TAM_Contribuyente;b++)
				{
					if(arrayRecaudaciones[i].idContribuyente==arrayContribuyente[b].idContribuyente)
					{
						eContribuyente_MostrarUno(arrayContribuyente[i]);
					}
				}
			}else{
				continue;
			}
		}
		retorno=1;
	}
	return retorno;
}



/*
d)Nombre y c.u.i.l. de los Contribuyentes que pagaron impuestos en el mes de
FEBRERO.
*/

int pagaronEnFebrero(eRecaudaciones arrayRecaudaciones[], int TAM_Recaudaciones
		,eContribuyente arrayContribuyente[], int TAM_Contribuyente)
{
	int retorno=-1;
	if(arrayRecaudaciones!=NULL && arrayContribuyente!=NULL && TAM_Recaudaciones>0 && TAM_Contribuyente>0)
	{
		for(int i=0; i<TAM_Recaudaciones; i++)
		{
			if(arrayRecaudaciones[i].isEmpty && strcmp(arrayRecaudaciones[i].estado,"SALDADO")==0 && arrayRecaudaciones[i].mes == 2)
			{
				for(int b=0;b<TAM_Contribuyente;b++)
				{
					if(arrayRecaudaciones[i].idContribuyente==arrayContribuyente[b].idContribuyente)
					{
						puts("\n\tPAGARON EN FEBRERO\n");
						printf(" %15s %15s %15s \n\n",
								arrayContribuyente[b].cuil,
								arrayContribuyente[b].nombre,
								arrayContribuyente[b].apellido);
					}
				}
			}else{
				continue;
			}
		}
		retorno=1;
	}
	return retorno;
}


#endif /* ENTIDADES_C_ */
