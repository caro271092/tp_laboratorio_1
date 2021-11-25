#ifndef __CONTROLLER_H_
#define __CONTROLLER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "LinkedList.h"
#include "InputOutput.h"
#include "parser.h"
#include "editoriales.h"
#include "libros.h"
/// \fn int controller_loadFromText(char*, LinkedList*)
/// \brief Carga los datos de los libros desde el archivo .csv informado (modo texto).
/// \param path nombre del archivo o ruta hacia él en caso que no esté en la misma carpeta de ejecucion del programa
/// \param listaLibros array de libros (puntero al inicio)
/// \return -1 si no logró la acción, 0 si ok
int controller_loadFromTextLibro(char* path , LinkedList* listaLibros);
/// \fn int controller_loadFromTextEditorial(char*, LinkedList*)
/// \brief
/// \param path
/// \param listaEditoriales
/// \return
int controller_loadFromTextEditorial(char* path , LinkedList* listaEditoriales);
/// \fn int controller_ListLibros(LinkedList*)
/// \brief muestra por pantalla los datos de la lista
/// \param listaLibros listado generado
/// \return -1 si no logró listar, 0 ok
int controller_ListLibros(LinkedList* listaLibros, LinkedList* listaEditoriales);
/// \fn int controller_ListEditoriales(LinkedList*)
/// \brief muestra por pantalla los datos de la lista
/// \param listaEditoriales
/// \return -1 si no logró listar, 0 ok
int controller_ListEditoriales(LinkedList* listaEditoriales);
/// \fn int controller_saveAsTextLibro(char*, LinkedList*)
/// \brief guarda datos en archivo de tipo csv
/// \param path nombre del directorio o archivo donde debe guardar
/// \param listaLibros lista con datos a guardar
/// \return 0 si ok o -1 si no se logró ejecutar correctamente
int controller_saveAsTextLibro(char* path , LinkedList* listaLibros);
/// \fn int controller_saveAsTextEditorial(char*, LinkedList*)
/// \brief guarda datos en archivo de tipo csv
/// \param path nombre del directorio o archivo donde debe guardar
/// \param listaEditoriales lista con datos a guardar
/// \return 0 si ok o -1 si no se logró ejecutar correctamente
int controller_saveAsTextEditorial(char* path , LinkedList* listaEditoriales);

#endif
