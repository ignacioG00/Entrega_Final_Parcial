/*
 * Biblioteca.h
 *
 *  Created on: 11 may. 2021
 *      Author: ignac
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM_BUFFER 10000

//Validaciones

int esCuil(char* cadena);
int validate_OnlyNumberInt(char* pData);
int validate_OnlyAlphabet(char *pData);
int validate_OnlyAlphabetWithSpaces(char *pData);
int validate_Exit_SN(char *msj,char *msjError);

//GET

int myGets(char* cadena, int longitud);
int get_Cuil(char* pResultado, char* mensaje, char* mensajeError, int reintentos);
float get_FloatRange(float* pResult,char *msj,char *msjError,float minimo, float maximo,int reintentos);
int get_Int(char *msj, char *msjError);
int get_IntRange(char *msj,char *msjError,int minimo, int maximo);
void get_String(char *msj, char *msjError, char *pString, int TAM);
char get_Char(char *msj, char *msjError);
int get_IntNegative(char *msj, char *errorMsj);
int get_IntPositive(char *msj, char *errorMsj);
void get_OnlyAlphabetString(char *msj,char *msjError,char *pString,int TAM);
void get_OnlyAlphabetStringWithSpaces(char *msj,char *msjError,char *pString, int TAM);

//Utilities
void Format_NameLastname(char *pName, char *pLastname, char *pFormatName);
int ArraySort_Int(int *pArray,int TAM, int criterio);
float ArraySort_Float(float *pArray,int TAM, int criterio);
void ArrayPrint_Int(int *pArray, int TAM);
void ArrayPrint_Float(float *pArray, int TAM);
void menu(void);
#endif /* BIBLIOTECA_H_ */
