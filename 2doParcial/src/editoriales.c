#include "editoriales.h"
editorial* editorial_new(){
    editorial* newEditorial = NULL;
    newEditorial= (editorial*)malloc(sizeof(editorial));
    if(newEditorial != NULL){
    	Editorial_setId(newEditorial,0);
    	Editorial_setNombre(newEditorial,"\0");
    }
    return newEditorial;
}

editorial* editorial_newParametros(char* idStr, char* nombreStr){
    editorial* newEditorial=editorial_new();
    if(newEditorial!=NULL && idStr!=NULL && nombreStr!=NULL){
    	Editorial_setId(newEditorial,atoi(idStr));
    	Editorial_setNombre(newEditorial,nombreStr);
    }else{
    	Editorial_delete(newEditorial);
    	newEditorial=NULL;
    }
    return newEditorial;
}

void Editorial_delete(editorial* este){
	if(este!=NULL){
		free(este);
	}
}

int Editorial_setId(editorial* this,int id){
	int retorno=-1;
	if(this!=NULL && id >= 0){
		this->idEditorial = id;
		retorno=0;
	}
	return retorno;
}

int Editorial_getId(editorial* this,int* id){
	int retorno=-1;
	if(this!=NULL && id!=NULL){
		*id = this->idEditorial;
		retorno=0;
	}
	return retorno;
}

int Editorial_setNombre(editorial* this,char* nombre){
	int retorno=-1;
	if(this!= NULL && nombre != NULL){
		strcpy(this->nombre, nombre);
		retorno=0;
	}
	return retorno;
}

int Editorial_getNombre(editorial* this,char* nombre){
	int retorno=-1;
	if(this!=NULL && nombre != NULL){
		strcpy(nombre, this->nombre);
		retorno=0;
	}
	return retorno;
}

int Editorial_getNombreById(LinkedList* listaEditoriales, int idAComparar,char* nombre){
	int retorno = -1;
	int i;
	int len;
	int idObtenido;
	len=ll_len(listaEditoriales);
	editorial* auxEditorial;
	if(listaEditoriales != NULL){
		for(i=0;i<len;i++){
			auxEditorial=ll_get(listaEditoriales, i);
			Editorial_getId(auxEditorial, &idObtenido);
			if(idAComparar == idObtenido){
				strcpy(nombre, auxEditorial->nombre);
				retorno =0;
				break;
			}
		}
	}
	return retorno;
}
