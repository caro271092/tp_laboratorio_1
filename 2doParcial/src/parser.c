#include "parser.h"

int parser_Libros(FILE* pFile , LinkedList* pArrayListaLibros){
	int retorno =-1;
	char idLibro[11];
	char titulo[50];
	char autor[50];
	char precio[50];
	char idEditorial[50];
	libro* newLibro;
	if(pFile!=NULL && pArrayListaLibros!=NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idLibro,titulo,autor,precio,idEditorial);//falsa
		while(!feof(pFile)){//mientras no sea el final del archivo
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idLibro,titulo,autor,precio,idEditorial);
						//leer ^=hasta la coma dsp coma q separa el dato y en el ult leer hasta el salto y luego dar salto
			newLibro = libro_newParametros(idLibro,titulo,autor,precio,idEditorial);//convertir de fila de excel a estructura
			if(newLibro!=NULL){														//porque desde el archivo llega en texto, en newParametros lo convertimos
				ll_add(pArrayListaLibros, newLibro);
				retorno=0;
			}
		}
	}
    return retorno;
}

int parser_editoriales(FILE* pFile , LinkedList* pArrayEditoriales){
	int retorno =-1;
	char id[11];
	char nombre[50];
	editorial* newEditorial;
	if(pFile!=NULL && pArrayEditoriales!=NULL){
		fscanf(pFile, "%[^,],%[^\n]\n",id,nombre);
		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^\n]\n",id,nombre);
			newEditorial = editorial_newParametros(id, nombre);
			if(newEditorial!=NULL){
				ll_add(pArrayEditoriales, newEditorial);
				retorno=0;
			}
		}
	}
    return retorno;
}








/*
int parser_LibrosFromBinary(FILE* pFile , LinkedList* pArrayListaLibros){
	int retorno=-1;
	int retornoFRead;
	libro* auxLibro;
	if(pFile!=NULL && pArrayListaLibros!=NULL){
		while(!feof(pFile)){
			auxEmployee = employee_new();
			retornoFRead = fread(auxEmployee,sizeof(Employee),1,pFile);//se guardan datos de 1 empleado
			if(retornoFRead==1 && auxEmployee!=NULL){//retorna ctidad de datos leidos, si es menor a lo pedido=>error
					ll_add(pArrayListaLibros,auxEmployee);
					retorno = 0;
				}
			}
		}
	return retorno;
}*/

