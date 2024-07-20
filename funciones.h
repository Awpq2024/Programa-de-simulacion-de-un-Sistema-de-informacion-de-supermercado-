#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include "producto.h"

void agregarProducto(producto articulo[], int& numeroProducto, int& siguienteID);
void mostrarProductos(const producto articulo[], int numeroProducto);
void eliminarProducto(producto articulo[],int& numeroProducto);

#endif
