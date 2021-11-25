/* editoriales.h
 */
#ifndef EDITORIALES_H_
#define EDITORIALES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"

typedef struct{
    int idEditorial;
    char nombre[128];
}editorial;

editorial* editorial_new();
editorial* editorial_newParametros(char* idStr, char* nombreStr);
void Editorial_delete(editorial* este);
int Editorial_setId(editorial* this,int id);
int Editorial_getId(editorial* this,int* id);
int Editorial_setNombre(editorial* this,char* nombre);
int Editorial_getNombre(editorial* this,char* nombre);
int Editorial_getNombreById(LinkedList* listaEditoriales, int idAComparar,char* nombre);

#endif /* EDITORIALES_H_ */
