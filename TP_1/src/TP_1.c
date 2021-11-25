/*============================================================================
 Name        : TP_1.c
 Author      : Carolina Alvarez, 1E
 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) “El resultado de A+B es: r”
 b) “El resultado de A-B es: r”
 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 d) “El resultado de A*B es: r”
 e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir
 • Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
 que contenga las funciones para realizar las cinco operaciones.
 • En el menú deberán aparecer los valores actuales cargados en los operandos A y B
 (donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
 • Deberán contemplarse los casos de error (división por cero, etc)
 • Documentar todas las funciones
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Biblioteca_F_Otras_TP1.h"
#include "Biblioteca_F_Matematicas_TP1.h"
#define T 10

int main(void){
	setbuf(stdout, NULL);
	char respuesta;
	char ingresoA[T] = "x";
	char ingresoB[T]= "y";
	float primerOperando;
	int ingresoValidado;
	float segundoOperando;
	float resultadoSuma;
	float resultadoResta;
	char opcionSeleccionada;
	float resultadoDivision;
	float resultadoMultiplicacion;
	int resultadoFactorialPrimerOperando =0;
	int resultadoFactorialSegundoOperando =0;

	do{
	opcionSeleccionada=MostrarMensajeYSeleccionarOpcionChar(
			"\n-------------------------------------------------\n"
			"A. Ingresar 1er operando A= %.1f\n"
			"B. Ingresar 2do operando B= %.1f\n"
			"C. Calcular todas las operaciones\n"
			"   1- Calcular la suma (A+B)\n"
			"   2- Calcular la resta (A-B)\n"
			"   3- Calcular la division (A/B)\n"
			"   4- Calcular la multiplicacion (A*B)\n"
			"   5- Calcular el factorial (A!)\n"
			"D. Informar resultados\n"
			"E. Salir\n\n"
			"---> Seleccione la operación que desea ejecutar:\n\n"
			"-------------------------------------------------\n", primerOperando, segundoOperando);
		switch(opcionSeleccionada){
			case 'a':
				do{
					printf("\n--->  1. Ingrese el primer operando A: ");
					fflush(stdin);
					scanf("%s", ingresoA);
					ingresoValidado = ValidacionIngresoDeUnNumerico(ingresoA);
				}while(ingresoValidado == -1);
				primerOperando = atof(ingresoA);
				respuesta =1;
			break;
			case 'b':
				do{
					printf("\n--->  2. Ingrese el segundo operando B: ");
					fflush(stdin);
					scanf("%s", ingresoB);
					ingresoValidado = ValidacionIngresoDeUnNumerico(ingresoB);
				}while(ingresoValidado == -1);
				segundoOperando = atof(ingresoB);
				respuesta =1;
			break;
			case 'c':
				if((strcmp(ingresoA,"x")==0)||(strcmp(ingresoB,"y")==0)){
				printf("\n--->  No se pueden realizar calculos sin haber ingresado ambos operandos.\n");
				respuesta =1;
				}else{
					resultadoSuma=SumaDosNumerosIngresados(primerOperando, segundoOperando);
					resultadoResta = RestaDosNumerosIngresados(primerOperando, segundoOperando);
					if(ValidacionParaRealizarDivision(primerOperando, segundoOperando)== 1){
						resultadoDivision = DivideDosNumerosIngresados(primerOperando, segundoOperando);
					}
					resultadoMultiplicacion = MultiplicaDosNumerosIngresados(primerOperando, segundoOperando);
					if((primerOperando==(int)primerOperando) && (ValidacionEnteroDentroDeUnRango(primerOperando, 0, 12) == 1)){
						resultadoFactorialPrimerOperando = CalculaFactorial(primerOperando);
						}
					if((segundoOperando==(int)segundoOperando) && (ValidacionEnteroDentroDeUnRango(segundoOperando, 0, 12) == 1)){
						resultadoFactorialSegundoOperando = CalculaFactorial(segundoOperando);
					}
					printf("\n--->  Se han realizado los cálculos con los operandos ingresados.\n");
					respuesta =1;
				}
			break;
			case 'd':
				if((strcmp(ingresoA,"x")==0)||(strcmp(ingresoB,"y")==0)){
				printf("\n--->  No se pueden mostrar los resultados sin realizar calculos.\n");
				respuesta =1;
				}else{
				printf("1- El resultado de %.2f + %.2f es: %.2f\n", primerOperando, segundoOperando, resultadoSuma);
				printf("2- El resultado de %.2f - %.2f es: %.2f\n", primerOperando, segundoOperando, resultadoResta);
				if(ValidacionParaRealizarDivision(primerOperando, segundoOperando)== 1){
				printf("3- El resultado de %.2f/%.2f es: %.2f\n", primerOperando, segundoOperando, resultadoDivision);
					}else{
						printf("3- No es posible dividir por cero.\n");
						}
				printf("4- El resultado de %.2f * %.2f es: %.2f\n", primerOperando, segundoOperando, resultadoMultiplicacion);
				if(resultadoFactorialPrimerOperando!=0){
				printf("5- El factorial de %.2f es: %d y ", primerOperando, resultadoFactorialPrimerOperando);
				}else{
					printf("5- El factorial de %.2f no se puede realizar en esta calculadora, y ", primerOperando);
					}
				if(resultadoFactorialSegundoOperando!=0){
				printf("el factorial de %.2f es: %d\n", segundoOperando, resultadoFactorialSegundoOperando);
				}else{
					printf("el factorial de %.2f no se puede realizar en esta calculadora.", segundoOperando);
					}
				respuesta = DeseaContinuar("\n\n--->  Si desea realizar otro cálculo, presione la letra s: ");
				}
			break;
			case 'e':
				respuesta =0;
			break;
		}
	}while(respuesta == 1);
	if(respuesta != 1){
		printf("\n--->  Ha salido de la calculadora. Gracias.");
	}
	return EXIT_SUCCESS;
}





	/*respuesta = DeseaContinuar("Bienvenido. Si desea realizar un cálculo presione la letra s: ");

	while(respuesta == 1){
		do {
			printf("1. Ingrese el primer operando A: ");
			fflush(stdin);
			scanf("%s", ingreso);
			ingresoValidado = ValidacionIngresoDeUnNumerico(ingreso);
			primerOperando = atof(ingreso);
		} while (ingresoValidado == 0);
		do {
			printf("2. Ingrese el segundo operando B: ");
			fflush(stdin);
			scanf("%s", ingreso);
			ingresoValidado = ValidacionIngresoDeUnNumerico(ingreso);
			segundoOperando = atof(ingreso);
		} while (ingresoValidado == 0);

		opcionSeleccionada = MostrarMensajeYSeleccionarOpcionChar(
				"Seleccione la operación que desea realizar:\n"
						"a) Calcular la suma (A+B)\n"
						"b) Calcular la resta (A-B)\n"
						"c) Calcular la division (A/B)\n"
						"d) Calcular la multiplicación (A*B)\n"
						"e) Calcular el factorial (A! y B!)\n"
						"f) Realizar todas las operaciones\n"
						"Opción seleccionada: ");
		switch(opcionSeleccionada){
		case 'a':
			resultadoSuma = SumaDosNumerosIngresados(primerOperando, segundoOperando);
			printf("a) El resultado de %.2f + %.2f es: %.2f", primerOperando, segundoOperando, resultadoSuma);
			break;
		case 'b':
			resultadoResta = RestaDosNumerosIngresados(primerOperando, segundoOperando);
			printf("b) El resultado de %.2f - %.2f es: %.2f", primerOperando, segundoOperando, resultadoResta);
			break;
		case 'c':
			if (ValidacionParaRealizarDivision(primerOperando, segundoOperando)== 1) {
				resultadoDivision = DivideDosNumerosIngresados(primerOperando, segundoOperando);
				printf("c) El resultado de %.2f/%.2f es: %.2f", primerOperando, segundoOperando, resultadoDivision);
				}
			else {
				printf("No es posible dividir por cero.");
			}
			break;
		case 'd':
			resultadoMultiplicacion = MultiplicaDosNumerosIngresados(primerOperando, segundoOperando);
			printf("d) El resultado de %.2f * %.2f es: %.2f", primerOperando, segundoOperando, resultadoMultiplicacion);
			break;
		case 'e':
			if((primerOperando==(int)primerOperando) && (ValidacionEnteroDentroDeUnRango(primerOperando, 0, 12) == 1)){
				resultadoFactorialPrimerOperando = CalculaFactorial(primerOperando);
				printf("e) El factorial de %.2f es: %d y ", primerOperando, resultadoFactorialPrimerOperando);
			}
			else {
				printf("e) El factorial de %.2f no se puede realizar en esta calculadora, y ", primerOperando);
			}
			if((segundoOperando==(int)segundoOperando) && (ValidacionEnteroDentroDeUnRango(segundoOperando, 0, 12) == 1)){
				resultadoFactorialSegundoOperando = CalculaFactorial(segundoOperando);
				printf("el factorial de %.2f es: %d", segundoOperando, resultadoFactorialSegundoOperando);
			}
			else {
				printf("el factorial de %.2f no se puede realizar en esta calculadora.", segundoOperando);
			}
			break;
		case 'f':
			resultadoSuma = SumaDosNumerosIngresados(primerOperando, segundoOperando);
				printf("a) El resultado de %.2f + %.2f es: %.2f", primerOperando, segundoOperando, resultadoSuma);
			resultadoResta = RestaDosNumerosIngresados(primerOperando, segundoOperando);
				printf("\nb) El resultado de %.2f - %.2f es: %.2f", primerOperando, segundoOperando, resultadoResta);
			if (ValidacionParaRealizarDivision(primerOperando, segundoOperando) == 1) {
				resultadoDivision = DivideDosNumerosIngresados(primerOperando, segundoOperando);
				printf("\nc) El resultado de %.2f/%.2f es: %.2f", primerOperando, segundoOperando, resultadoDivision);
			}
			if (ValidacionParaRealizarDivision(primerOperando, segundoOperando)== 0) {
				printf("\nc) No es posible dividir por cero.");
			}
			resultadoMultiplicacion = MultiplicaDosNumerosIngresados(primerOperando, segundoOperando);
				printf("\nd) El resultado de %.2f * %.2f es: %.2f", primerOperando, segundoOperando, resultadoMultiplicacion);
			if((primerOperando==(int)primerOperando) && (ValidacionEnteroDentroDeUnRango(primerOperando, 0, 12) == 1)){
				resultadoFactorialPrimerOperando = CalculaFactorial(primerOperando);
				printf("\ne) El factorial de %.2f es: %d y ", primerOperando, resultadoFactorialPrimerOperando);
			} else {
				printf("\ne) El factorial de %.2f no se puede realizar en esta calculadora, y ", primerOperando);
			}
			if((segundoOperando==(int)segundoOperando) && (ValidacionEnteroDentroDeUnRango(segundoOperando, 0, 12) == 1)){
				resultadoFactorialSegundoOperando = CalculaFactorial(segundoOperando);
				printf("el factorial de %.2f es: %d", segundoOperando, resultadoFactorialSegundoOperando);
			} else {
				printf("el factorial de %.2f no se puede realizar en esta calculadora.", segundoOperando);
			}
			break;
		}
	respuesta = DeseaContinuar("\n\nSi desea realizar otro cálculo, presione la letra s: ");
	}
	if(respuesta != 1){
		printf("Ha salido de la calculadora. Gracias.");
		}
	return EXIT_SUCCESS;
}*/

