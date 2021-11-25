/* Name: 2doParcial.c / Author: Carolina Alvarez
1. Leer un archivo con los datos de libros, guardándolos en un linkedList de entidades eLibro.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de comandos.
2. Leer un archivo con los datos de editoriales, guardándolos en un linkedList de entidades eEditorial.
ACLARACIÓN: El nombre del archivo se debe pasar como parámetro por línea de comandos.
3. Ordenar la lista generada en el ítem anterior, con la función ll_sort,
según el criterio de ordenamiento “Autor” de manera ascendente.
4. Imprimir por pantalla todos los datos de los libros.
ACLARACIÓN: Se deberá imprimir la descripción de la editorial.
5. Realizar un listado de los libros de la editorial MINOTAURO. Para ello deberá utilizar la función ll_filter*
del LinkedList. Guardar el listado en un archivo csv.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>
#include "LinkedList.h"
#include "Controller.h"
#include "editoriales.h"
#include "libros.h"
#include "InputOutput.h"

int main(){
	setbuf(stdout,NULL);
    int opcionIngresada;
    int flagCargaListadoLibros=-1;
    int flagCargaListadoEditoriales=-1;
    char nombreArchivo[50];
    int retornoF;
    LinkedList* listaFiltradaMinotauro;
    LinkedList* listaFiltradaConDescuentos;
    LinkedList* listaLibros = ll_newLinkedList();
    LinkedList* listaEditoriales = ll_newLinkedList();

    do{
    	mostrarMenu();
    	PedirNumeroEntero(&opcionIngresada,"\n--->Ingrese la opción que desea ejecutar: ","---> ERROR. Ingrese una opción válida.", 1, 7, 2);
        switch(opcionIngresada){
            case 1:
            	GetString(nombreArchivo, "Por favor ingrese el nombre del archivo de libros que desea cargar: ", 50);
				if(strcmp(nombreArchivo,"libros")==0){
            		if(controller_loadFromTextLibro("libros.csv",listaLibros)==0){
						flagCargaListadoLibros=0;
						printf("\n------------->Los datos se cargaron exitosamente\n\n");
					}else{
						printf("\n------------->No se pudieron cargar los datos\n\n");
					}
				}else{
					printf("\n------------->No se encontró un archivo con el nombre ingresado\n\n");
				}
                break;
            case 2:
            	GetString(nombreArchivo, "Por favor ingrese el nombre del archivo de editoriales que desea cargar: ", 50);
            	if(strcmp(nombreArchivo,"editoriales")==0){
					if(controller_loadFromTextEditorial("editoriales.csv",listaEditoriales)==0){
						flagCargaListadoEditoriales=0;
						printf("\n------------->Los datos se cargaron exitosamente\n\n");
					}else{
						printf("\n------------->No se pudieron cargar los datos\n\n");
					}
            	}else{
					printf("\n------------->No se encontró un archivo con el nombre ingresado\n\n");
				}
            	break;
            case 3:
            	if(flagCargaListadoLibros==-1||flagCargaListadoEditoriales==-1){
            		printf("\n-->No puede acceder a esta opción sin haber cargado los archivos correspondientes primero\n\n");
				}else{
					if(ll_sort(listaLibros, libro_sortByAutor, 1)==0){
						printf("\n------------->Los datos se ordenaron exitosamente\n\n");
					}else{
						printf("\n------------->No se logró ordenar la lista\n\n");
					}
				}
                break;
            case 4:
            	if(flagCargaListadoLibros==-1||flagCargaListadoEditoriales==-1){
            	    printf("\n-->No puede acceder a esta opción sin haber cargado los archivos correspondientes primero\n\n");
				}else{
					controller_ListLibros(listaLibros, listaEditoriales);
				}
                break;
            case 5:
            	if(flagCargaListadoLibros==-1||flagCargaListadoEditoriales==-1){
					printf("\n-->No puede acceder a esta opción sin haber cargado los archivos correspondientes primero\n\n");
				}else{
					listaFiltradaMinotauro = ll_filter(listaLibros,libro_EditorialMinotauro);
					if(listaFiltradaMinotauro!=NULL){
						retornoF=controller_saveAsTextLibro("minotauro.csv", listaFiltradaMinotauro);
						if(retornoF==0){
						printf("\n------------->Se filtró la lista y se guardó en un nuevo archivo\n\n");
						}else{
							printf("\n------------->No se logró guardar la nueva lista filtrada\n\n");
						}
					}else{
						printf("\n------------->No se logró filtrar la lista\n\n");
					}
            	}
            	break;
            case 6:
				if(flagCargaListadoLibros==-1||flagCargaListadoEditoriales==-1){
					printf("\n-->No puede acceder a esta opción sin haber cargado los archivos correspondientes primero\n\n");
				}else{
					listaFiltradaConDescuentos = ll_map(listaLibros, libro_AgregarDescuentos);
					if(listaFiltradaConDescuentos!=NULL){
						retornoF=controller_saveAsTextLibro("mapeado.csv", listaFiltradaConDescuentos);
						if(retornoF==0){
						printf("\n------------->Se filtró la lista y se guardó en un nuevo archivo\n\n");
						}else{
							printf("\n------------->No se logró guardar la nueva lista filtrada\n\n");
						}
					}else{
						printf("\n------------->No se logró filtrar la lista\n\n");
					}
				}
				break;
        }
    }while(opcionIngresada != 7);
    printf("-->Ha salido del programa.");
    return 0;
}
