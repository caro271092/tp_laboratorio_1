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

int controller_loadFromTextEditorial(char* path , LinkedList* listaEditoriales);
/// \fn int controller_ListLibros(LinkedList*)
/// \brief genera listado de libros
/// \param listaLibros listado generado
/// \return -1 si no logró listar, 0 ok
int controller_ListLibros(LinkedList* listaLibros, LinkedList* listaEditoriales);

int controller_ListEditoriales(LinkedList* listaEditoriales);

int controller_saveAsTextLibro(char* path , LinkedList* listaLibros);

int controller_saveAsTextEditorial(char* path , LinkedList* listaEditoriales);
/// \fn int controller_sortEmployee(LinkedList*)
/// \brief ordenar empleados
/// \param pArrayListEmployee listado de empleados
/// \return 0 si se ordenó segun algun criterio, -1 si no se pudo ordenar
//int controller_sortEmployee(LinkedList* pArrayListEmployee);
/// \fn int controller_saveAsText(char*, LinkedList*)
/// \brief Guarda los datos de los empleados en el archivo data.csv (modo texto)
/// \param path archivo
/// \param pArrayListEmployee listado de empleados
/// \return -1 si algo salió mal, 0 si ok
//int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);
#endif
