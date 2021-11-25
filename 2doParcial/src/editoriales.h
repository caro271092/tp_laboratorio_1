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
/// \fn editorial editorial_new*()
/// \brief crea el espacio en memoria para la nueva estructura
/// \return estructura creada
editorial* editorial_new();
/// \fn editorial editorial_newParametros*(char*, char*)
/// \brief setea los campos del dato de tipo editorial que recibe
/// \param idStr
/// \param nombreStr
/// \return datos con campos completos
editorial* editorial_newParametros(char* idStr, char* nombreStr);
/// \fn void Editorial_delete(editorial*)
/// \brief elimina dato de tipo editorial de memoria
/// \param este
void Editorial_delete(editorial* este);
/// \fn int Editorial_setId(editorial*, int)
/// \brief
/// \param this
/// \param id
/// \return
int Editorial_setId(editorial* this,int id);
/// \fn int Editorial_getId(editorial*, int*)
/// \brief
/// \param this
/// \param id
/// \return
int Editorial_getId(editorial* this,int* id);
/// \fn int Editorial_setNombre(editorial*, char*)
/// \brief
/// \param this
/// \param nombre
/// \return
int Editorial_setNombre(editorial* this,char* nombre);
/// \fn int Editorial_getNombre(editorial*, char*)
/// \brief
/// \param this
/// \param nombre
/// \return
int Editorial_getNombre(editorial* this,char* nombre);
/// \fn int Editorial_getNombreById(LinkedList*, int, char*)
/// \brief
/// \param listaEditoriales
/// \param idAComparar
/// \param nombre
/// \return
int Editorial_getNombreById(LinkedList* listaEditoriales, int idAComparar,char* nombre);

#endif /* EDITORIALES_H_ */
