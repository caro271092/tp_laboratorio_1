/*
 * Biblioteca_F_Otras_TP1.h
 *      Author: Carolina Alvarez, 1E */
#ifndef BIBLIOTECA_F_OTRAS_TP1_H_
#define BIBLIOTECA_F_OTRAS_TP1_H_
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

/// \fn int DeseaContinuar(char[])
/// \brief informa si se ingresó s o S, indicando que se desea continuar iterando
///
/// \param mensaje mensaje para preguntar si se desea continuar con la iteración
/// \return 1 si se ingresa s, es decir que se desea continuar
int DeseaContinuar(char mensaje[]);

/// \fn int ValidacionOpcionIngresada(char)
/// \brief valida que se ingrese una de las opciones de char ofrecidas (a, b, c, d, e, f)
///
/// \param letraElegida ingreso seleccionado
/// \return 1 si se ingresó una de las opciones ofrecidas, 0 si se seleccionó algún otro caracter no contemplado en las opciones
int ValidacionOpcionIngresada (char letraElegida);


/// \fn char MostrarMensajeYSeleccionarOpcionChar(char[])
/// \brief muestra opciones de char a seleccionar (a, b, c, d, e, f)
///
/// \param mensaje mensaje para consultar la opción de char que se desea elegir entre: a, b, c, d, e ó f
/// \return char elegido entre opciones válidas
char MostrarMensajeYSeleccionarOpcionChar(char mensaje[], float primerOperando, float segundoOperando);

/// \fn int ValidacionEnteroDentroDeUnRango(int, int, int)
/// \brief valida que un entero esté dentro de un rango númerico
///
/// \param numeroIngresado entero a validar dentro de un rango determinado
/// \param minimo mínimo valor del rango
/// \param maximo máximo valor del rango
/// \return 1 si se encuentra dentro del rango, 0 si está fuera dentro del rango deseado
int ValidacionEnteroDentroDeUnRango(int numeroIngresado, int minimo, int maximo);

/// \fn int ValidacionIngresoDeUnNumerico(char[])
/// \brief valida que se ingrese un número y no una letra
///
/// \param ingreso lo que se ingresa, parámetro a validar
/// \return 1 si es un entero positivo o negativo, 0 si no es un entero
int ValidacionIngresoDeUnNumerico(char ingreso[]);

#endif /* BIBLIOTECA_F_OTRAS_TP1_H_ */
