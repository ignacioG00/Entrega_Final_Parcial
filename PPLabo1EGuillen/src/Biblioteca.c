#ifndef BIBLIOTECA_C_
#define BIBLIOTECA_C_

#include "Biblioteca.h"

//VALIDACIONES

int esCuil(char* cadena)
{
    int retorno=1;
    int i;
    char buffer[14];
    int contadorDigito;
    int contadorGuion;
    strncpy(buffer,cadena,14);

    for(i=0;buffer[i]!='\0';i++)
    {
        if((buffer[i]<'0' || buffer[i]>'9') && (buffer[i]!='-'))
        {
            retorno=0;
            break;
        }
        else
        {
        	if(isdigit(cadena[i])!=0)
			{
				contadorDigito++;
			}
			else
        	{
				if(cadena[i]=='-')
				{
					contadorGuion++;
        		}
        		else
        		{
					retorno=0;
					break;
        		}
        	}
        }
    }
	if(contadorDigito==11 && contadorGuion==2 && buffer[2]=='-' && buffer[11]=='-')
	{
		retorno=1;
	}
    return retorno;
}

int validate_OnlyNumberInt(char* pData)
{
	int retorno=1;
	if(strlen(pData)>0)
	{
		for(int i=0;i<strlen(pData);i++)
		{
			if(isdigit(pData[i])==0)
			{
				if(i==0)
				{
					if(pData[0]!='-')
					{
						retorno=0;
						break;
					}
				}else{
					retorno=0;
					break;
				}
			}
		}
	}else{
		retorno=0;
	}
	return retorno;
}

int validate_OnlyAlphabet(char *pData)
{
	int retorno = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				retorno = 0;
				break;
			}
		}
	} else {
		retorno = 0;
	}

	return retorno;
}

int validate_OnlyAlphabetWithSpaces(char *pData)
{
	int retorno = 1;

	if (strlen(pData) > 0) {
		for (int i = 0; i < strlen(pData); i++) {
			if (isalpha(pData[i]) == 0) {
				if (isspace(pData[i]) == 0) {
					retorno = 0;
					break;
				}
			}
		}
	} else {
		retorno = 0;
	}

	return retorno;
}

int validate_Exit_SN(char *msj,char *msjError)
{
	int retorno=0;
	char c;
	c = get_Char(msj,msjError);
	c = toupper(c);

	while(c!='S' && c!='N')
	{
		puts("> ERROR.OPCION NO VALIDA\n");
		c=get_Char(msj,msjError);
		c=toupper(c);
	}
	if(c=='S')
	{
		retorno=1;
	}
	return retorno;
}

//GETS

int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[5000];
	if(cadena!=NULL && longitud>0)
	{
		fflush(stdin);
		if(fgets(bufferString, sizeof(bufferString),stdin)!=NULL)
		{
			if(bufferString[strnlen(bufferString, sizeof(bufferString))-1] =='\n')
			{
				bufferString[strnlen(bufferString,sizeof(bufferString))-1] = '\0';
			}
			if(strnlen(bufferString, sizeof(bufferString))<=longitud)
			{
				strncpy(cadena, bufferString, longitud);
				retorno=0;
			}
		}
	}
	return retorno;
}

int get_Cuil(char* pResultado, char* mensaje, char* mensajeError, int reintentos)
{
    int maxTamanio=14; //con guiones 13 elementos
    int minTamanio=11;  // sin puntos
    int retorno=-1;
    char bufferStr[maxTamanio];
    if(mensaje!=NULL && mensajeError!=NULL && maxTamanio>minTamanio && reintentos>=0 && pResultado!=NULL)
    {
        do
        {
        	printf("%s",mensaje);
            if((myGets(bufferStr, 14)==0) && (esCuil(bufferStr)==1))
			{
                strncpy(pResultado,bufferStr,maxTamanio);
                retorno=0;
                break;
            }
            else
            {
                printf("%s",mensajeError);
                reintentos--;
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

int get_Int(char *msj, char *msjError)
{
	char buffer[TAM_BUFFER];
	int retorno;

		printf("%s", msj);
		fflush(stdin);
		gets(buffer);

	while(validate_OnlyNumberInt(buffer)==0)
	{
		printf("%s", msjError);
		fflush(stdin);
		gets(buffer);
	}

	retorno=atoi(buffer);
	return retorno;
}

int get_IntRange(char *msj,char *msjError,int minimo, int maximo)
{
	int retorno = get_Int(msj, msjError);
	while(retorno<minimo || retorno>maximo)
	{
		printf("Error.Fuera de rango -> [Minimo]= %d [Maximo]= %d. /n", minimo,maximo);
		retorno= get_Int(msj,msjError);
	}
	return retorno;
}

int get_IntPositive(char *msj, char *errorMsj)
{
	int retorno= get_Int(msj,errorMsj);
	while(retorno<0)
	{
		printf("Solo numeros positivos!!");
		retorno=get_Int(msj,errorMsj);
	}
	return retorno;
}

int get_IntNegative(char *msj, char *errorMsj)
{
	int retorno= get_Int(msj,errorMsj);
	while(retorno>=0)
	{
		printf("Solo numeros negativos!!");
		retorno=get_Int(msj,errorMsj);
	}
	return retorno;
}


float get_FloatRange(float* pResult,char *msj,char *msjError,float minimo, float maximo,int reintentos)
{
	int retorno = -1;
		float bufferInterno;
		if(pResult != NULL && msj != NULL && msjError != NULL && minimo <= maximo && reintentos>0)
		{

			do
			{
				printf("%s", msj);
				scanf("%f", &bufferInterno);
				if(bufferInterno>=minimo && bufferInterno<=maximo)
				{
					*pResult=bufferInterno;
					retorno=0;
					break;
				}
				else
				{
					printf("%s", msjError);
					reintentos--;
				}
			}while(reintentos>=0);
		}
		return retorno;
}

void get_String(char *msj, char *msjError, char *pString, int TAM)
{
	char buffer[TAM_BUFFER];
	printf("%s",msj);
	fflush(stdin);
	gets(buffer);
	while(strlen(buffer)>TAM||strlen(buffer)==0)
	{
		printf("Error.Fuera de rango. CARACTERES [Minimo]= 1 [Maximo]= %d. /n", TAM);
		printf("%s", msjError);
		fflush(stdin);
		gets(buffer);
	}
	strcpy(pString,buffer);
}

void get_OnlyAlphabetString(char *msj,char *msjError,char *pString,int TAM)
{
	char buffer[TAM_BUFFER];
	printf("%s",msj);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer)>TAM || strlen(buffer)==0 || validate_OnlyAlphabet(buffer)==0)
	{
		if(strlen(buffer)>TAM || strlen(buffer)==0)
		{
			printf("Error.Fuera de rango. CARACTERES [minimo]=1 [maximo]=%d. \n",TAM);
		}else{
			printf("Error.Solo caracteres alfabeticos Validos.\n");
		}
		printf("%s",msjError);
		fflush(stdin);
		gets(buffer);
	}
	strcpy(pString,buffer);
}

void get_OnlyAlphabetStringWithSpaces(char *msj,char *msjError,char *pString, int TAM)
{
	char buffer[TAM_BUFFER];
	printf("%s",msj);
	fflush(stdin);
	gets(buffer);

	while(strlen(buffer)>TAM || strlen(buffer)==0 || validate_OnlyAlphabetWithSpaces(buffer)==0)
		{
			if(strlen(buffer)>TAM || strlen(buffer)==0)
			{
				printf("Error.Fuera de rango CARACTERES [minimo]=1 [maximo]=%d. \n",TAM);
			}else{
				printf("Error.Solo caracteres alfabeticos Validos.\n");
			}
			printf("%s",msjError);
			fflush(stdin);
			gets(buffer);
		}
	strcpy(pString,buffer);
}


char get_Char(char *msj, char *msjError)
{
	char buffer[TAM_BUFFER];
	char retorno;

	printf("%s",msj);
	fflush(stdin);
	gets(buffer);
	while(strlen(buffer)>1 || validate_OnlyAlphabet(buffer)==0)
	{
		printf("%s", msjError);
		fflush(stdin);
		gets(buffer);
	}
	retorno = buffer[0];
	return retorno;
}

//UTILITIES

void Format_NameLastname(char *pName, char *pLastname, char *pFormatName) {

	strcpy(pFormatName, pLastname);
	strcat(pFormatName, ", ");
	strcat(pFormatName, pName);

	strlwr(pFormatName);

	if (strlen(pName) > 0 && strlen(pLastname) > 0) {
		for (int i = 0; i < strlen(pFormatName); i++) {

			if (i == 0 && isspace(pFormatName[i]) == 0) {
				pFormatName[0] = toupper(pFormatName[0]);

			} else {
				if (isspace(pFormatName[i]) && i < strlen(pFormatName) - 1) {
					pFormatName[i + 1] = toupper(pFormatName[i + 1]);
				}
			}
		}
	}
}

void ArrayPrint_Int(int *pArray,int TAM)
{
	for(int i=0;i<TAM;i++)
	{
		printf("%d\n", pArray[i]);
	}
}

void ArrayPrint_Float(float *pArray,int TAM)
{
	for(int i=0;i<TAM;i++)
	{
		printf("%.2f\n", pArray[i]);
	}
}

int ArraySort_Int(int *pArray,int TAM, int criterio)
{
	int retorno =0;
	int aux;
	if(pArray!=NULL && TAM>0)
	{
		switch(criterio){
		//si se ingresa -1, entonces es de menor a mayor
		case -1:
			for(int i = 0;i<TAM;i++)
			{
				for(int j=i+1;j<TAM;j++)
				{
					if(pArray[i]>pArray[j])
					{
					aux=pArray[i];
					pArray[i]=pArray[j];
					pArray[j]= aux;
					}
				}
			}
		retorno =1;
		break;
		//si se ingresa 1 entonces es de mayor a menor
		case 1:
			for(int i=0;i<TAM-1;i++)
			{
				for(int j=i + i;j<TAM;j++)
				{
					if(pArray[i]<pArray[j])
					{
						aux = pArray[i];
						pArray[i]=pArray[j];
						pArray[j]=aux;
					}
				}
			}
			retorno=1;
			break;
		default:
			//ordenamiento mal ingresado.
			retorno=0;
			break;
		}
	}
	return retorno;
}

float ArraySort_Float(float *pArray,int TAM, int criterio)
{
	int retorno =0;
	float aux;
	if(pArray!=NULL && TAM>0)
	{
		switch(criterio){
		//si se ingresa -1, entonces es de menor a mayor
		case -1:
			for(int i = 0;i<TAM;i++)
			{
				for(int j=i+1;j<TAM;j++)
				{
					if(pArray[i]>pArray[j])
					{
					aux=pArray[i];
					pArray[i]=pArray[j];
					pArray[j]= aux;
					}
				}
			}
		retorno =1;
		break;
		//si se ingresa 1 entonces es de mayor a menor
		case 1:
			for(int i=0;i<TAM-1;i++)
			{
				for(int j=i + i;j<TAM;j++)
				{
					if(pArray[i]<pArray[j])
					{
						aux = pArray[i];
						pArray[i]=pArray[j];
						pArray[j]=aux;
					}
				}
			}
			retorno=1;
			break;
		default:
			//ordenamiento mal ingresado.
			retorno=0;
			break;
		}
	}
	return retorno;
}

void menu(void)
{
	puts("BIENVENIDOS\n");
	puts("1 - ALTA CONTRIBUYENTE");
	puts("2 - MODIFICAR CONTRIBUYENTE");
	puts("3 - BAJA DE CONTRIBUYENTE");
	puts("4 - ALTA RECAUDACIONES");
	puts("5 - CAMBIAR ESTADO A REFINANCIAR");
	puts("6 - CAMBIAR ESTADO A SALDADO");
	puts("7 - IMPRIMIR CONTRIBUYENTE");
	puts("8 - IMPRIMIR RECAUDACIONES SALDADAS");
	puts("9 - IMPRIMIR CONTRIBUYENTE CON TIPO DE RECAUDACION");
	puts("10 - IMPRIMIR CONTRIBUYENTES QUE PAGARON EN FEBRERO");
	puts("11 - IMPRIMIR CANTIDAD RECAUDACIONES MAYORES A 1000");
}


#endif
