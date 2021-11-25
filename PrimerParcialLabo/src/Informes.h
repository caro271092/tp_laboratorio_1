/* Informes.h */
#ifndef INFORMES_H_
#define INFORMES_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include "Pedidos.h"
#include "Clientes.h"
#include "InputOutput.h"
#define EMPTY 1
#define FULL 0

/// \fn void MostrarCliente(eCliente)
/// \brief muestra la informaci�n ingresada en los campos de un cliente
/// \param cliente �ndice del cliente en el array de clientes
void MostrarCliente(eCliente cliente);

/// \fn void MostrarCuitYDireccionCliente(eCliente[], int, int)
/// \brief imprime cuit y direcci�n del cliente cuyo id recibe por par�metro
/// \param listaClientes array de clientes
/// \param tamClientes tama�o del array
/// \param idClienteRecibido id a imprimir datos
void MostrarCuitYDireccionCliente(eCliente listaClientes[], int tamClientes, int idClienteRecibido);

/// \fn void DetallePedidosPendientes(ePedido[], int, eCliente[], int)
/// \brief imprime Cuit del cliente, direcci�n del cliente y cantidad de kilos a recolectar de cada pedido que est� pendiente
/// \param listaPedidos array de pedidos
/// \param tamPedidos tama�o del array de pedidos
/// \param listaClientes array de clientes
/// \param tamClientes tama�o del array de clientes
void DetallePedidosPendientes(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes);

/// \fn void DetallePedidosProcesados(ePedido[], int, eCliente[], int)
/// \brief imprime Cuit y direcci�n del cliente, junto con cantidad de kilos reciclados de cada tipo de pl�stico, de cada pedido que est� completado
/// \param listaPedidos array de pedidos
/// \param tamPedidos tama�o del array de pedidos
/// \param listaClientes array de clientes
/// \param tamClientes tama�o del array de clientes
void DetallePedidosProcesados(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes);

/// \fn int ContadorEstadoPedidoCliente(ePedido[], int, char[], int)
/// \brief cuenta la cantidad de pedidos que hay en determinado estado en determinado cliente
/// \param listaPedidos array de pedidos
/// \param tam tama�o del array de pedidos
/// \param estadoRequerido estado a chequear
/// \param idAchequear id del cliente que se quiere consultar
/// \return cantidad de pedidos del cliente en el estado solicitado
int ContadorEstadoPedidoCliente(ePedido listaPedidos[], int tam, char estadoRequerido[], int idAchequear);

/// \fn void MostrarCantidadDePedidosPendientesPorCliente(ePedido[], int, eCliente[], int)
/// \brief muestra el listado de clientes con la cantidad de pedidos en estado pendiente de cada uno
/// \param listaPedidos array de pedidos
/// \param tamPedidos tama�o del array de pedidos
/// \param listaClientes array de clientes
/// \param tamClientes tama�o del array de clientes
void MostrarCantidadDePedidosPendientesPorCliente(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes);

/// \fn int CantidadPedidosPendientesPorLocalidad(ePedido[], int, eCliente[], int)
/// \brief calcula la cantidad de pedidos pendientes en localidad ingresada
/// \param listaPedidos array de pedidos
/// \param tamPedidos tama�o del array de pedidos
/// \param listaClientes array de clientes
/// \param tamClientes tama�o del array de clientes
/// \param idLocalidadIngresada identificador de la localidad devuelto por puntero
/// \return cantidad de pedidos pendientes en la localidad determinada
int CantidadPedidosPendientesPorLocalidad(ePedido listaPedidos[], int tamPedidos, eCliente listaClientes[], int tamClientes, int* idLocalidadIngresada);

/// \fn int ContadorPedidosPorCliente(ePedido[], int, int)
/// \brief cuenta la cantidad de pedidos que tiene determinado cliente del cual se recibe el id por par�metro
/// \param listaPedidos array de pedidos
/// \param tam tama�o del array de pedidos
/// \param idAchequear id del cliente del cual se calcular� cantidad de pedidos
/// \return cantidad de pedidos del cliente indicado
int ContadorPedidosPorCliente(ePedido listaPedidos[], int tam, int idAchequear);

/// \fn int ClienteConMasPedidos(ePedido[], int)
/// \brief encuentra el id del cliente con mayor cantidad de pedidos de recolecci�n
/// \param listaPedidos array de pedidos
/// \param tamPedidos tama�o del array de pedidos
/// \return id del cliente que tiene m�s pedidos cargados
int ClienteConMasPedidos(ePedido listaPedidos[], int tamPedidos);

/// \fn int ClienteConMasPedidosEstado(ePedido[], int, char[])
/// \brief encuentra el id del cliente con mayor cantidad de pedidos de recolecci�n de determinado estado
/// \param listaPedidos array de pedidos
/// \param tamPedidos tama�o del array de pedidos
/// \param estadoDeseado estado de pedidos que se desea consultar
/// \return id del cliente que tiene m�s pedidos cargados con el estado deseado
int ClienteConMasPedidosEstado(ePedido listaPedidos[], int tamPedidos, char estadoDeseado[]);

#endif /* INFORMES_H_ */
