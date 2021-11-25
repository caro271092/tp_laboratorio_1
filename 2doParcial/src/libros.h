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

libro* libro_new();
libro* libro_newParametros(char* idStr, char* tituloStr,char* autorStr, char* precioStr, char* idEditorial);
void libro_delete(libro* este);
int libro_setId(libro* this,int id);
int libro_getId(libro* this,int* id);
int libro_setTitulo(libro* this,char* titulo);
int libro_getTitulo(libro* this,char* titulo);
int libro_setAutor(libro* this,char* autor);
int libro_getAutor(libro* this,char* autor);
int libro_setPrecio(libro* this, float precio);
int libro_getPrecio(libro* this, float* precio);
int libro_setIdEditorial(libro* this, int idEditorial);
int libro_getIdEditorial(libro* this, int* idEditorial);
int libro_sortByAutor(void* thisA, void* thisB);
int libro_EditorialMinotauro(void* elemento);

#endif /* LIBROS_H_ */
