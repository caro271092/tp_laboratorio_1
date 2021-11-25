#include "libros.h"
libro* libro_new(){ //CONSTRUCTOR por defecto, para el espacio
    libro* newlibro = NULL; //si devuelve null es que no se pudo cargar
    newlibro= (libro*)malloc(sizeof(libro));
    if(newlibro != NULL){
    	libro_setId(newlibro,0);
    	libro_setTitulo(newlibro,"\0");
    	libro_setAutor(newlibro,"\0");
    	libro_setPrecio(newlibro,0);
    	libro_setIdEditorial(newlibro,0);
    }
    return newlibro;
}

libro* libro_newParametros(char* idStr, char* tituloStr,char* autorStr, char* precioStr, char* idEditorial){//CONSTRUCTOR parametrizado
    libro* newlibro=libro_new();
    if(newlibro!=NULL && idStr!=NULL && tituloStr!=NULL && autorStr!=NULL && precioStr!=NULL && idEditorial!=NULL){
    	libro_setId(newlibro,atoi(idStr));
    	libro_setTitulo(newlibro,tituloStr);
    	libro_setAutor(newlibro,autorStr);
    	libro_setPrecio(newlibro,atof(precioStr));
    	libro_setIdEditorial(newlibro,atoi(idEditorial));
    }else{
    	libro_delete(newlibro);
    	newlibro=NULL;
    }
    return newlibro;
}

void libro_delete(libro* este){
	if(este!=NULL){
		free(este);
	}
}

int libro_setId(libro* this,int id){
	int retorno=-1;
	if(this!=NULL && id >= 0){
		this->idLibro = id;
		retorno=0;
	}
	return retorno;
}

int libro_getId(libro* this,int* id){
	int retorno=-1;
	if(this!=NULL && id!=NULL){
		*id = this->idLibro;
		retorno=0;
	}
	return retorno;
}

int libro_setTitulo(libro* this,char* titulo){
	int retorno=-1;
	if(this!= NULL && titulo != NULL){
		strcpy(this->titulo, titulo);
		retorno=0;
	}
	return retorno;
}

int libro_getTitulo(libro* this,char* titulo){
	int retorno=-1;
	if(this!=NULL && titulo != NULL){
		strcpy(titulo, this->titulo);
		retorno=0;
	}
	return retorno;
}

int libro_setAutor(libro* this,char* autor){
	int retorno=-1;
	if(this!= NULL && autor != NULL){
		strcpy(this->autor, autor);
		retorno=0;
	}
	return retorno;
}

int libro_getAutor(libro* this,char* autor){
	int retorno=-1;
	if(this!=NULL && autor != NULL){
		strcpy(autor, this->autor);
		retorno=0;
	}
	return retorno;
}

int libro_setPrecio(libro* this, float precio){
	int retorno=-1;
	if(this!=NULL && precio>0){
		this->precio = precio;
		retorno=0;
	}
	return retorno;
}

int libro_getPrecio(libro* this, float* precio){
	int retorno=-1;
	if(this !=NULL && precio != NULL){
		*precio = this->precio;
		retorno=0;
	}
	return retorno;
}

int libro_setIdEditorial(libro* this, int idEditorial){
	int retorno=-1;
	if(this!=NULL && idEditorial>0){
		this->idEditorial = idEditorial;
		retorno=0;
	}
	return retorno;
}

int libro_getIdEditorial(libro* this, int* idEditorial){
	int retorno=-1;
	if(this!=NULL && idEditorial!=NULL){
		*idEditorial = this->idEditorial;
		retorno=0;
	}
	return retorno;
}

int libro_sortByAutor(void* thisA, void* thisB){
	int criterio = -1;
	char autor1[50];
	char autor2[50];
	libro_getAutor(thisA,autor1);
	libro_getAutor(thisB,autor2);
	if(strcmp(autor1,autor2) == 0){
		criterio =0;
	}else if(strcmp(autor1,autor2)>0){
		criterio=1;
	}else{
		criterio=-1;
	}
	return criterio;
}

int libro_EditorialMinotauro(void* elemento){//q devuelva 1 si es
	int retorno = -1;
	int idEditorialObtenido;
	libro_getIdEditorial(elemento, &idEditorialObtenido);
	if(elemento != NULL && (idEditorialObtenido==2004)){
				retorno =1;
	}
	return retorno;
}
