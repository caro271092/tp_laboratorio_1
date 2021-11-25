/*Biblioteca_F_Otras_TP1.c
 *Author: Carolina Alvarez, 1E */
#include "Biblioteca_F_Otras_TP1.h"

int DeseaContinuar(char mensaje[]){
	int respuesta=0;
	char opcionElegida;
	printf(mensaje);
	fflush(stdin);
	scanf("%c", &opcionElegida);
	opcionElegida = tolower(opcionElegida);
	if(opcionElegida=='s'){
		respuesta =1;
	}
	return respuesta;
}

int ValidacionOpcionIngresada(char letraElegida){
	letraElegida = tolower(letraElegida);
	int opcionValida = 1;
	if(letraElegida!='a' && letraElegida!='b' && letraElegida!='c' && letraElegida!='d' && letraElegida!='e' && letraElegida!='f'){
		opcionValida = 0;
	}
	return opcionValida;
}

char MostrarMensajeYSeleccionarOpcionChar(char mensaje[], float primerOperando, float segundoOperando){
		char opcionElegida;
		printf(mensaje, primerOperando, segundoOperando);
		fflush(stdin);
		scanf("%c", &opcionElegida);
		while(ValidacionOpcionIngresada(opcionElegida)==0){
			printf("Seleccione una opción válida (a, b, c, d, e): ");
			fflush(stdin);
			scanf("%c", &opcionElegida);
		}
	return opcionElegida;
}

int ValidacionEnteroDentroDeUnRango(int numeroIngresado, int minimo, int maximo){
	int retorno = 1;
	if(numeroIngresado<minimo||numeroIngresado>maximo){
		retorno=0;
	}
	return retorno;
}

int ValidacionIngresoDeUnNumerico(char ingreso[]){
	int retorno = 0;
	int i;
	for(i=0; i<strlen(ingreso); i++){
		if(((ingreso[0]!='-') && (ingreso[i]!='.') && (!(isdigit(ingreso[i]))))){
		printf("Ingreso inválido. Intente nuevamente.\n");
		retorno=-1;
		}
	}
	return retorno;
}
