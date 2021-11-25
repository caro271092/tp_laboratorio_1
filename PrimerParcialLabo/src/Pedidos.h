/*Pedidos.h */
#ifndef PEDIDOS_H_
#define PEDIDOS_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "Clientes.h"
#include "InputOutput.h"
#define EMPTY 1
#define FULL 0

typedef struct{
		int idPedido;
		int idCliente;
		float cantidadKilosARecolectar;
		char estado[30];
		float kilosHDPE;
		float kilosLDPE;
		float kilosPP;
		int isEmpty;
	}ePedido;

/// \fn void IniciarEstructuraPedido(ePedido[], int)
/// \brief le otorga el valor vac�o al campo isEmpty, para identificarlo como espacio libre en el array de pedidos
/// \param lista array de pedidos
/// \param tam tama�o del array
void IniciarEstructuraPedido(ePedido lista[], int tam);

/// \fn int BuscarPrimerEspacioLibrePedidos(ePedido[], int)
/// \brief encuentra el primer lugar que se marc� empty
/// \param lista array de pedidos
/// \param tam tama�o del array
/// \return retorna el �ndice de la posici�n del primer lugar libre en el array
int BuscarPrimerEspacioLibrePedidos(ePedido lista[], int tam);

/// \fn int AgregarPedido(ePedido[], int, int, float, float, float, float, int)
/// \brief guarda la informaci�n, que recibe por par�metro, en el primer lugar libre del array de pedidos
/// \param lista array de pedidos
/// \param tam tama�o del array
/// \param idPedido campo de identificador de pedido
/// \param cantidadKilosARecolectar campo de cantidad de kilos a recolectar
/// \param kilosHDPE campo de kilos de HDPE "a reciclar"
/// \param kilosLDPE campo de kilos de LDPE "a reciclar"
/// \param kilosPP campo de kilos de PP "a reciclar"
/// \param idClienteIngresado campo del identificador del cliente al cual pertenece el pedido
/// \return devuelve -1 si no logr� cargar el array y 0 si pudo hacerlo
int AgregarPedido(ePedido lista[], int tam, int idPedido, float cantidadKilosARecolectar, float kilosHDPE, float kilosLDPE, float kilosPP, int idClienteIngresado);

/// \fn int IngresarDatosDePedido(ePedido[], int, int*, int)
/// \brief carga un pedido de recoleccion al cliente ingresado
/// \param lista array de pedidos
/// \param tam tama�o del array
/// \param idPedido identificador del pedido
/// \param idClienteIngresado identificador del cliente al cual se le cargar� el pedido
/// \return devuelve -1 si no logr� cargar el array y 0 si pudo hacerlo
int IngresarDatosDePedido(ePedido lista[], int tam, int *idPedido, int idClienteIngresado);

/// \fn int ImprimirListadoPedidos(ePedido[], int)
/// \brief muestra los pedidos cargados en el array de pedidos
/// \param lista array de pedidos
/// \param tam tama�o del array
/// \return devuelve -1 si no logr� imprimir y 0 si pudo hacerlo
int ImprimirListadoPedidos(ePedido lista[], int tam);

/// \fn int BuscarPrimerEspacioOcupadoPedidos(ePedido[], int)
/// \brief encuentra el primer lugar que se marc� full
/// \param lista array de pedidos
/// \param tam tama�o del array
/// \return retorna el �ndice de la posici�n del primer lugar ocupado en el array
int BuscarPrimerEspacioOcupadoPedidos(ePedido lista[], int tam);

/// \fn int EncontrarPedidoPorId(ePedido[], int, int)
/// \brief busca un pedido determinado en el array de pedidos
/// \param lista array de pedidos
/// \param tam tama�o del array
/// \param idPedidoIngresado id del pedido a encontrar
/// \return retorna el �ndice de la posici�n del pedido en el array, si �ste no existe retorna -1
int EncontrarPedidoPorId(ePedido lista[], int tam, int idPedidoIngresado);

/// \fn int ClasificarPlastico(ePedido[], int, int)
/// \brief completa los campos a reciclar del array de pedidos
/// \param lista array de pedidos
/// \param tam tama�o del array
/// \param id identificador del pedido a cargar kilos reciclados
/// \return devuelve -1 si no logr� cargar el array y 0 si pudo hacerlo
int ClasificarPlastico(ePedido lista[], int tam, int id);

/// \fn float KilosTotalesDePPObtenidos(ePedido[], int)
/// \brief realiza la sumatoria de los kilos de PP obtenidos en todos los pedidos
/// \param listaPedidos array de pedidos
/// \param tamPedidos tama�o del array
/// \return devuelve la sumatoria de kilos de PP reciclados de todos los pedidos del array
float KilosTotalesDePPObtenidos(ePedido listaPedidos[], int tamPedidos);

#endif /* PEDIDOS_H_ */
