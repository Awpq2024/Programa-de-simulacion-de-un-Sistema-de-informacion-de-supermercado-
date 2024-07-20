#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include "producto.h"

void agregarProducto(producto articulo[], int& numeroProducto, int& siguienteID);
void mostrarProductos(const producto articulo[], int numeroProducto);
void registrarVenta(gestionDeventas ventas[], int& numeroVenta, producto articulo[], int& numeroProducto);
void mostrarVentas(const gestionDeventas ventas[], int numeroVenta);
void mostrarGanancias(gestionDeventas ventas[], int& numeroVenta);

#endif
