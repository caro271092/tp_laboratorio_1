/*Biblioteca_F_Matematicas_TP1.c
 Author: Carolina Alvarez, 1E */
#include "Biblioteca_F_Matematicas_TP1.h"

float SumaDosNumerosIngresados(float operandoUno, float operandoDos){
	float resultadoSuma;
	resultadoSuma = operandoUno + operandoDos;
	return resultadoSuma;
}

float RestaDosNumerosIngresados(float operandoUno, float operandoDos){
	float resultadoResta;
	resultadoResta =  operandoUno - operandoDos;
	return resultadoResta;
}

int ValidacionParaRealizarDivision(float operandoUno, float operandoDos){
	int respuesta = 1;
	if(operandoDos==0){
		respuesta = 0;
	}
	return respuesta;
}

float DivideDosNumerosIngresados(float operandoUno, float operandoDos){
	float resultadoDivision;
	resultadoDivision =  operandoUno/operandoDos;
	return resultadoDivision;
}

float MultiplicaDosNumerosIngresados(float operandoUno, float operandoDos){
	float resultadoMultiplicacion;
	resultadoMultiplicacion =  operandoUno*operandoDos;
	return resultadoMultiplicacion;
}

long CalculaFactorial(long numeroIngresado){
	int i;
	int resultado=1;
	for(i=1; i<=numeroIngresado; i++){
		resultado = resultado*i;
	}
	return resultado;
}


