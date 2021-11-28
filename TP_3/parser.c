#include "parser.h"

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){
	int retorno =-1;
	char id[11];
	char nombre[50];
	char horasTrabajadas[50];
	char sueldo[50];
	Employee* newEmployee;
	if(pFile!=NULL && pArrayListEmployee!=NULL){
		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
		while(!feof(pFile)){//mientras no sea el final del archivo
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
						//leer ^=hasta la coma dsp coma q separa el dato y en el ult leer hasta el salto y luego dar salto
			newEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);//construir el empleado convertir de fila de excel a estructura
			if(newEmployee!=NULL){														//porque desde el archivo llega en texto, en newParametros lo convertimos
				ll_add(pArrayListEmployee, newEmployee);//agregar a linked list(es como el array pero en memoria din�mica)
				retorno=0;
			}
		}
	}
    return retorno;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee){
	int retorno=-1;
	Employee* auxEmployee;
	if(pFile!=NULL && pArrayListEmployee!=NULL){
		do{
			auxEmployee = employee_new();
				if(fread(auxEmployee,sizeof(Employee),1,pFile)== 1){//se guardan datos de 1 empleado
					ll_add(pArrayListEmployee, auxEmployee);
					retorno = 0;
				}
		}while(!feof(pFile));
	}
	return retorno;
}
