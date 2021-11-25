/*Biblioteca_F_Matematicas_TP1.h
Author: Carolina Alvarez, 1E */
#ifndef BIBLIOTECA_F_MATEMATICAS_TP1_H_
#define BIBLIOTECA_F_MATEMATICAS_TP1_H_
#include <stdio.h>
#include <stdlib.h>

/// \fn float SumaDosNumerosIngresados(float, float)
/// \brief Realiza la sumatoria de dos números flotantes
///
/// \param operandoUno Primer número recibido
/// \param operandoDos Segundo número recibido
/// \return Resultado de la sumatoria
float SumaDosNumerosIngresados(float operandoUno, float operandoDos);

/// \fn float RestaDosNumerosIngresados(float, float)
/// \brief Realiza la resta entre dos números flotantes recibidos
///
/// \param operandoUno primer número recibido al cual se le restara el segundo parámetro
/// \param operandoDos segundo entero recibido el cual se restará del primero
/// \return resultado de la resta de operandoUno menos operandoDos
float RestaDosNumerosIngresados(float operandoUno, float operandoDos);

/// \fn int ValidacionParaRealizarDivision(float, float)
/// \brief valida si el segundo operando ingresado es igual a cero
///
/// \param operandoUno primer operando de una posterior división
/// \param operandoDos número a validar si es cero ya que de ser así no se puede utilizar de divisor
/// \return si el operandoDos es cero retorna un cero por lo tanto no puede ser un divisor de una posterior división
int ValidacionParaRealizarDivision(float operandoUno, float operandoDos);

/// \fn float DivideDosNumerosIngresados(float, float)
/// \brief realiza la división entre dos flotantes recibidos
///
/// \param operandoUno dividendo
/// \param operandoDos divisor
/// \return cociente
float DivideDosNumerosIngresados(float operandoUno, float operandoDos);

/// \fn float MultiplicaDosNumerosIngresados(float, float)
/// \brief multiplica dos flotantes recibidos
///
/// \param operandoUno primer factor
/// \param operandoDos segundo factor
/// \return producto, resultado de la multiplicación
float MultiplicaDosNumerosIngresados(float operandoUno, float operandoDos);

/// \fn long CalculaFactorial(long)
/// \brief calcula el factorial del número recibido
///
/// \param numeroIngresado número a realizar factorial
/// \return resultado del factoreo
long CalculaFactorial(long numeroIngresado);

#endif /* BIBLIOTECA_F_MATEMATICAS_TP1_H_ */
