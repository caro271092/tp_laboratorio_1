/*Biblioteca_F_Matematicas_TP1.h
Author: Carolina Alvarez, 1E */
#ifndef BIBLIOTECA_F_MATEMATICAS_TP1_H_
#define BIBLIOTECA_F_MATEMATICAS_TP1_H_
#include <stdio.h>
#include <stdlib.h>

/// \fn float SumaDosNumerosIngresados(float, float)
/// \brief Realiza la sumatoria de dos n�meros flotantes
///
/// \param operandoUno Primer n�mero recibido
/// \param operandoDos Segundo n�mero recibido
/// \return Resultado de la sumatoria
float SumaDosNumerosIngresados(float operandoUno, float operandoDos);

/// \fn float RestaDosNumerosIngresados(float, float)
/// \brief Realiza la resta entre dos n�meros flotantes recibidos
///
/// \param operandoUno primer n�mero recibido al cual se le restara el segundo par�metro
/// \param operandoDos segundo entero recibido el cual se restar� del primero
/// \return resultado de la resta de operandoUno menos operandoDos
float RestaDosNumerosIngresados(float operandoUno, float operandoDos);

/// \fn int ValidacionParaRealizarDivision(float, float)
/// \brief valida si el segundo operando ingresado es igual a cero
///
/// \param operandoUno primer operando de una posterior divisi�n
/// \param operandoDos n�mero a validar si es cero ya que de ser as� no se puede utilizar de divisor
/// \return si el operandoDos es cero retorna un cero por lo tanto no puede ser un divisor de una posterior divisi�n
int ValidacionParaRealizarDivision(float operandoUno, float operandoDos);

/// \fn float DivideDosNumerosIngresados(float, float)
/// \brief realiza la divisi�n entre dos flotantes recibidos
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
/// \return producto, resultado de la multiplicaci�n
float MultiplicaDosNumerosIngresados(float operandoUno, float operandoDos);

/// \fn long CalculaFactorial(long)
/// \brief calcula el factorial del n�mero recibido
///
/// \param numeroIngresado n�mero a realizar factorial
/// \return resultado del factoreo
long CalculaFactorial(long numeroIngresado);

#endif /* BIBLIOTECA_F_MATEMATICAS_TP1_H_ */
