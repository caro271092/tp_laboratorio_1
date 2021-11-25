/*Clientes.h */
#ifndef CLIENTES_H_
#define CLIENTES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "Localidades.h"
#include "InputOutput.h"
#define EMPTY 1
#define FULL 0

typedef struct{
		int idCliente;
		char nombreEmpresa[51];
		int cuit;
		char direccion[51];
		int idLocalidad;
		int isEmpty;
	}eCliente;

/// \fn void IniciarEstructura(eCliente[], int)
/// \brief le otorga el valor vac�o al campo isEmpty, para identificarlo como espacio libre en el array de clientes
/// \param lista array de clientes
/// \param tam tama�o del array
void IniciarEstructura(eCliente lista[], int tam);

/// \fn int BuscarPrimerEspacioLibre(eCliente[], int)
/// \brief encuentra el primer lugar que se marc� empty
/// \param lista array de clientes
/// \param tam tama�o del array
/// \return retorna el �ndice de la posici�n del primer lugar libre en el array
int BuscarPrimerEspacioLibre(eCliente lista[], int tam);

/// \fn int BuscarPrimerEspacioOcupado(eCliente[], int)
/// \brief encuentra el primer lugar que se marc� full
/// \param lista array de clientes
/// \param tam tama�o del array
/// \return retorna el �ndice de la posici�n del primer lugar ocupado en el array
int BuscarPrimerEspacioOcupado(eCliente lista[], int tam);

/// \fn int AgregarCliente(eCliente[], int, int, char[], int, char[], int)
/// \brief guarda la informaci�n, que recibe por par�metro, en el primer lugar libre del array de clientes
/// \param lista array de clientes
/// \param tam tama�o del array
/// \param idCliente campo identificador del cliente
/// \param nombreEmpresa campo nombre de la empresa
/// \param cuit campo de CUIT
/// \param direccion campo direccion del cliente
/// \param localidad campo localidad del cliente
/// \return devuelve -1 si no logr� cargar el array y 0 si pudo hacerlo
int AgregarCliente(eCliente lista[], int tam, int idCliente, char nombreEmpresa[], int cuit, char direccion[], int localidad);

/// \fn int PedirCliente(eCliente[], int, int*)
/// \brief solicita los datos para cargar un cliente en el array de clientes
/// \param lista array de clientes
/// \param tam tama�o del array
/// \param idCliente identificador del cliente que se pasa por puntero al main para su incrementaci�n para el pr�ximo ingreso
/// \return devuelve -1 si no logr� cargar el array y 0 si pudo hacerlo
int PedirCliente(eCliente lista[], int tam, int *idCliente);

/// \fn int EncontrarClientePorId(eCliente[], int, int)
/// \brief busca un cliente determinado en el array de clientes
/// \param lista array de clientes
/// \param tam tama�o del array
/// \param idIngresado id del cliente a encontrar
/// \return retorna el �ndice de la posici�n del cliente en el array, si �ste no existe retorna -1
int EncontrarClientePorId(eCliente lista[], int tam, int idIngresado);

/// \fn int ModificarDireccion(eCliente[], int, int)
/// \brief modifica el campo direcci�n de un cliente determinado dentro del array de clientes
/// \param lista array de clientes
/// \param tam tama�o del array
/// \param id identificador del cliente a modificar, de existir
/// \return devuelve -1 si no logr� modificar y 0 si pudo hacerlo
int ModificarDireccion(eCliente lista[], int tam, int id);

/// \fn int ImprimirListadoClientes(eCliente[], int)
/// \brief muestra los clientes cargados en el array de clientes
/// \param lista array de clientes
/// \param tam tama�o del array
/// \return devuelve -1 si no logr� imprimir y 0 si pudo hacerlo
int ImprimirListadoClientes(eCliente lista[], int tam);

/// \fn int BajaCliente(eCliente[], int, int)
/// \brief cambia el estado del campo isEmpty a empty, para dar de baja a un cliente determinado del array de clientes
/// \param lista array de clientes
/// \param tam tama�o del array
/// \param idBaja identificador del cliente a dar de baja
/// \return devuelve -1 si no logr� cambiar el campo y 0 si pudo hacerlo
int BajaCliente(eCliente lista[], int tam, int idBaja);

#endif /* CLIENTES_H_ */
