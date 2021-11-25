/* InputOutput.c
 * Author: Alvarez Carolina*/
#include "InputOutput.h"
#define TRUE 1
#define FALSE 0

int ValidacionIngresoDeUnEnteroPositivo(char ingreso[]){
	int i;
	int retorno = -1;
	int longitud;
	longitud = strlen(ingreso);
		for(i=0; i< longitud; i++){
			if(isdigit(ingreso[i]) != 0){
				retorno = 0;
				break;
			}
		}
	return retorno;
}

int PedirNumeroEntero(int* ingresoValidado, char mensaje[], char mensajeError[], int minimo, int maximo, int reintentos){
	int retorno = -1;
	char ingreso[50];
	int buffer;
	if(ingresoValidado!=NULL && mensaje!=NULL && mensajeError != NULL && minimo<=maximo && reintentos >= 0){
		do{
			printf("%s", mensaje);
			fflush(stdin);
			scanf("%[^\n]", ingreso);
			if(ValidacionIngresoDeUnEnteroPositivo(ingreso)==0){
				buffer = atoi(ingreso);
			}if(buffer>=minimo && buffer<=maximo){
					*ingresoValidado = buffer;
					retorno = 0;
					break;
			}else{
				printf("%s", mensajeError);
				}
		reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

int GetString(char string[], char message[], int len){
	char auxiliarString[200];
	int retorno = -1;
	if (string != NULL && message != NULL){
		retorno = 0;
		printf(message);
		fflush(stdin);
		scanf("%[^\n]", auxiliarString);
		while (strlen(auxiliarString) > len){
			printf("Reingrese: ");
			fflush(stdin);
			scanf("%[^\n]", auxiliarString);
		}
		strcpy(string, auxiliarString);
	}
	return retorno;
}

void mostrarMenu(){
	printf(
	 "*****************************************************\n"
	 "1. Cargar datos de los libros desde archivo .csv (modo texto).\n"
	 "2. Cargar datos de las editoriales desde archivo .csv (modo texto).\n"
	 "3. Ordenar lista de libros según el criterio de ordenamiento “Autor” de manera ascendente.\n"
	 "4. Imprimir por pantalla datos de los libros, con nombre de editorial.\n"
	 "5. Realizar listado de libros de la editorial MINOTAURO. Guardar el listado en un archivo csv.\n"
	 "6. Generar el archivo de salida “mapeado.csv” luego de aplicar la función map.\n"
	 "7. Salir\n"
	"*****************************************************\n");
}



