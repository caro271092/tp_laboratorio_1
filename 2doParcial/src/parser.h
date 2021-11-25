#ifndef PARSER_H_
#define PARSER_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "LinkedList.h"
#include "libros.h"
#include "editoriales.h"

int parser_Libros(FILE* pFile , LinkedList* pArrayListaLibros);
int parser_editoriales(FILE* pFile , LinkedList* pArrayEditoriales);


#endif /* PARSER_H_ */
