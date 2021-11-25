/*
 * libros.h
 */
#ifndef LIBROS_H_
#define LIBROS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int idLibro;
    char titulo[50];
    char autor[50];
    float precio;
    int idEditorial;
}libro;
/// \fn libro libro_new*()
/// \brief crea el espacio en memoria para la nueva estructura
/// \return estructura creada
libro* libro_new();
/// \fn libro libro_newParametros*(char*, char*, char*, char*, char*)
/// \brief setea los campos del dato de tipo libro que recibe
/// \param idStr
/// \param tituloStr
/// \param autorStr
/// \param precioStr
/// \param idEditorial
/// \return dato con campos completos
libro* libro_newParametros(char* idStr, char* tituloStr,char* autorStr, char* precioStr, char* idEditorial);
/// \fn void libro_delete(libro*)
/// \brief elimina dato de tipo libro de memoria
/// \param este
void libro_delete(libro* este);
/// \fn int libro_setId(libro*, int)
/// \brief
/// \param this
/// \param id
/// \return
int libro_setId(libro* this,int id);
/// \fn int libro_getId(libro*, int*)
/// \brief
/// \param this
/// \param id
/// \return
int libro_getId(libro* this,int* id);
/// \fn int libro_setTitulo(libro*, char*)
/// \brief
/// \param this
/// \param titulo
/// \return
int libro_setTitulo(libro* this,char* titulo);
/// \fn int libro_getTitulo(libro*, char*)
/// \brief
/// \param this
/// \param titulo
/// \return
int libro_getTitulo(libro* this,char* titulo);
/// \fn int libro_setAutor(libro*, char*)
/// \brief
/// \param this
/// \param autor
/// \return
int libro_setAutor(libro* this,char* autor);
/// \fn int libro_getAutor(libro*, char*)
/// \brief
/// \param this
/// \param autor
/// \return
int libro_getAutor(libro* this,char* autor);
/// \fn int libro_setPrecio(libro*, float)
/// \brief
/// \param this
/// \param precio
/// \return
int libro_setPrecio(libro* this, float precio);
/// \fn int libro_getPrecio(libro*, float*)
/// \brief
/// \param this
/// \param precio
/// \return
int libro_getPrecio(libro* this, float* precio);
/// \fn int libro_setIdEditorial(libro*, int)
/// \brief
/// \param this
/// \param idEditorial
/// \return
int libro_setIdEditorial(libro* this, int idEditorial);
/// \fn int libro_getIdEditorial(libro*, int*)
/// \brief
/// \param this
/// \param idEditorial
/// \return
int libro_getIdEditorial(libro* this, int* idEditorial);
/// \fn int libro_sortByAutor(void*, void*)
/// \brief
/// \param thisA
/// \param thisB
/// \return
int libro_sortByAutor(void* thisA, void* thisB);
/// \fn int libro_EditorialMinotauro(void*)
/// \brief
/// \param elemento
/// \return
int libro_EditorialMinotauro(void* elemento);
/// \fn int libro_AgregarDescuentos(void*)
/// \brief
/// \param elemento
/// \return
int libro_AgregarDescuentos(void* elemento);

#endif /* LIBROS_H_ */
