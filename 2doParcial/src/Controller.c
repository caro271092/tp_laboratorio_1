#include "Controller.h"

int controller_loadFromTextLibro(char* path , LinkedList* listaLibros){
	int retorno = -1;
	FILE* pFile=NULL;
	int parser;
	if(path!=NULL && listaLibros!=NULL){
		pFile = fopen(path,"r"); //
		if(pFile != NULL){
			parser = parser_Libros(pFile,listaLibros);//para parsear a estructura
			if(parser==0){
				retorno=0;
				fflush(pFile);
				fclose(pFile);
			}
		}else{
			printf("\n--->No se pudo leer el archivo.");
		}
	}
	return retorno;
}

int controller_loadFromTextEditorial(char* path , LinkedList* listaEditoriales){
	int retorno = -1;
	FILE* pFile=NULL;
	int parser;
	if(path!=NULL && listaEditoriales!=NULL){
		pFile = fopen(path,"r"); //
		if(pFile != NULL){
			parser = parser_editoriales(pFile,listaEditoriales);
			if(parser==0){
				retorno=0;
				fflush(pFile);
				fclose(pFile);
			}
		}else{
			printf("\n--->No se pudo leer el archivo.");
		}
	}
	return retorno;
}

int controller_ListLibros(LinkedList* listaLibros, LinkedList* listaEditoriales){
	int retorno =-1;
	int i;
	libro* pLibro;
	int idLibro;
	char titulo[50];
	char autor[50];
	char nombre[50];
	float precio;
	int idEditorial;
	int tamLinkedList;
	tamLinkedList = ll_len(listaLibros);
	if(listaLibros!=NULL){
		for(i=0;i<tamLinkedList;i++){
			pLibro = (libro*)ll_get(listaLibros, i);
			libro_getId(pLibro,&idLibro);
			libro_getTitulo(pLibro,titulo);
			libro_getAutor(pLibro,autor);
			libro_getPrecio(pLibro,&precio);
			libro_getIdEditorial(pLibro,&idEditorial);
			Editorial_getNombreById(listaEditoriales, idEditorial,nombre);
			printf("%-10d %-20s %-20s %10.2f %20s\n", idLibro, titulo, autor, precio, nombre);
		}
		retorno =0;
	}
    return retorno;
}

int controller_ListEditoriales(LinkedList* listaEditoriales){
	int retorno =-1;
	int i;
	editorial* pEditorial;
	int id;
	char nombre[50];
	int tamLinkedList;
	tamLinkedList = ll_len(listaEditoriales);
	if(listaEditoriales!=NULL){
		for(i=0;i<tamLinkedList;i++){
			pEditorial = (editorial*)ll_get(listaEditoriales, i);
			Editorial_getId(pEditorial,&id);
			Editorial_getNombre(pEditorial,nombre);
			printf("%-10d %-20s \n", id, nombre);
		}
		retorno =0;
	}
    return retorno;
}

int controller_saveAsTextLibro(char* path , LinkedList* listaLibros){
	int retorno =-1;
	FILE* pFile;
	int idLibro;
	char titulo[50];
	char autor[50];
	float precio;
	int idEditorial;
	libro* auxLibro;
	int lenLinkedList;
	int i;
	lenLinkedList = ll_len(listaLibros);
	pFile = fopen(path,"w");
	if(pFile!=NULL && listaLibros!=NULL){
		for(i=0;i<lenLinkedList;i++){
			auxLibro = (libro*)ll_get(listaLibros,i);
			libro_getId(auxLibro, &idLibro);
			libro_getTitulo(auxLibro,titulo);
			libro_getAutor(auxLibro,autor);
			libro_getPrecio(auxLibro,&precio);
			libro_getIdEditorial(auxLibro,&idEditorial);
			fprintf(pFile,"%d,%s,%s,%.2f,%d\n",idLibro,titulo,autor,precio, idEditorial);
		}
		retorno=0;
		fflush(pFile);
		fclose(pFile);
	}
	return retorno;
}

int controller_saveAsTextEditorial(char* path , LinkedList* listaEditoriales){
	int retorno =-1;
	FILE* pFile;
	int id;
	char nombre[50];
	editorial* auxEditorial;
	int lenLinkedList;
	int i;
	lenLinkedList = ll_len(listaEditoriales);
	pFile = fopen(path,"w");
	if(pFile!=NULL && listaEditoriales!=NULL){
		for(i=0;i<lenLinkedList;i++){
			auxEditorial = (editorial*)ll_get(listaEditoriales,i);
			Editorial_getId(auxEditorial, &id);
			Editorial_getNombre(auxEditorial,nombre);
			fprintf(pFile,"%d,%s\n",id,nombre);
		}
		retorno=0;
		fflush(pFile);
		fclose(pFile);
	}
	return retorno;
}
