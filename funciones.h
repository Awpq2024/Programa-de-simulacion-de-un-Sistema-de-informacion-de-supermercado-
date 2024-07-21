#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include "producto.h"

//Funciones de productos
void agregarProducto(producto articulo[], int& numeroProducto, int& siguienteID);
void mostrarProductos(const producto articulo[], int numeroProducto);


//funciones Ventas
void registrarVenta(gestionDeventas ventas[], int& numeroVenta, producto articulo[], int& numeroProducto);
void mostrarVentas(const gestionDeventas ventas[], int numeroVenta);
void mostrarGanancias(gestionDeventas ventas[], int& numeroVenta);


//Funciones reclamos
void MenuReclamos(reclamo quejas[], int &numeroReclamo, int &siguienteIDReclamo);
//--- Menu de Reclamos ---//
void agregarReclamo(reclamo quejas[], int &numeroReclamo, int &siguienteIDReclamo);//Funcion Agregar un Reclamo
void mostrarReclamos(const reclamo quejas[], int numeroReclamo);//Funcion Mostrar un Reclamo
void eliminarReclamo(reclamo quejas[], int &numeroReclamo);//Funcion Eliminar un Reclamo

#endif
