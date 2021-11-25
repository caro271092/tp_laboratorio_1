/* InputOutput.h  */
#ifndef INPUTOUTPUT_H_
#define INPUTOUTPUT_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "LinkedList.h"
/// \fn int ValidacionIngresoDeUnEnteroPositivo(char[])
/// \brief valida que el ingreso sea un número entero positivo
/// \param ingreso ingreso recibido como cadena de caracteres
/// \return 0 si el ingreso es un entero positivo, -1 si no lo es
int ValidacionIngresoDeUnEnteroPositivo(char ingreso[]);

/// \fn int PedirNumeroEntero(int*, char[], char[], int, int, int)
/// \brief solicita al usuario un número entero positivo dentro de un rango
/// \param ingresoValidado devuelve por parámetro el ingreso si es válido
/// \param mensaje mensaje para pedir el ingreso
/// \param mensajeError mensaje si el ingreso no es un entero positivo dentro del rango
/// \param minimo mínimo valor aceptado del ingreso
/// \param maximo mayor valor aceptado del ingreso
/// \param reintentos cantidad de veces que se vuelve a pedir el ingreso en caso de no ser válido
/// \return 0 ok, -1 si el ingreso es inválido
int PedirNumeroEntero(int* ingresoValidado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos);

/// \fn int GetString(char[], char[], int)
/// \brief solicita una cadena de caracteres
/// \param string cadena validada devuelta por parámetro
/// \param message mensaje para solicitar el ingreso
/// \param len largo de la cadena
/// \return
int GetString(char string[], char message[], int len);

///// \fn void mostrarMenu()
///// \brief imprime el menú de opciones
void mostrarMenu();

#endif /* INPUTOUTPUT_H_ */
