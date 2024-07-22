#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include "producto.h"

//Funciones de productos
void agregarProducto(producto articulo[], int& numeroProducto, int& siguienteID);
void mostrarProductos(const producto articulo[], int numeroProducto);

//funciones Ventas
void registrarVenta(gestionDeventas ventas[],int &numeroVenta,producto articulo[], int &numeroProducto,const descuento descuentos[],int numeroDescuentos);
void mostrarVentas(const gestionDeventas ventas[], int numeroVenta);
void mostrarGanancias(gestionDeventas ventas[], int& numeroVenta);

//Funciones reclamos
void MenuReclamos(reclamo quejas[], int &numeroReclamo, int &siguienteIDReclamo);
//--- Menu de Reclamos ---//
void agregarReclamo(reclamo quejas[], int &numeroReclamo, int &siguienteIDReclamo);//Funcion Agregar un Reclamo
void mostrarReclamos(const reclamo quejas[], int numeroReclamo);//Funcion Mostrar un Reclamo
void eliminarReclamo(reclamo quejas[], int &numeroReclamo);//Funcion Eliminar un Reclamo

//Funciones de descuentos
void MenuDescuentos(descuento descuentos[], int &numeroDescuento,int &siguienteIDDescuento);
void agregarDescuento(descuento descuentos[], int &numeroDescuentos,int &siguienteIDDescuento);
void eliminarDescuento(descuento descuentos[], int &numeroDescuentos);
void mostrarDescuentos(const descuento descuentos[], int numeroDescuentos);
float calcularDescuento(float precioTotal, int cantidad, const descuento descuentos[], int numeroDescuentos);

#endif
