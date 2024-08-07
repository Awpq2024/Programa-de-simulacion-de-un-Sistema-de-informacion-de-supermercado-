#ifndef FUNCIONES_H
#define FUNCIONES_H
#include <iostream>
#include <windows.h>
#include "estructuras.h"
using namespace std;

//Funcion para aplicar colores
void setColor(int color);

//Funcion para inicializar los datos predeterminados
void inicializarDatos(producto articulo[], int &numeroProducto, reclamo quejas[], int &numeroReclamo, descuento descuentos[], int &numeroDescuento,gestionDeventas ventas[], int &numeroVenta, const string& categoria);


//1. Funciones de categorias
void menuProductosCategorias(producto articulo[], int& numeroProducto, int& siguienteID,  gestionDeventas ventas[], int& numeroVenta, string& categoria);
void funcionesDelMenuDeCategorias(producto articulo[], int& numeroProducto, int& siguienteID, gestionDeventas ventas[], int& numeroVenta,const string& categoria);
//1.1 Funciones de productos
void agregarProducto(producto articulo[], int& numeroProducto, int& siguienteID,const string& categoria);
void actualizarProducto(producto articulo[], int& numeroProducto, int& siguienteID,const string& categoria);
void eliminarProducto(producto articulo[], int& numeroProducto, int& siguienteID,const string& categoria);
//1.1.1 Funciones para mostrar productos
void menuDeMostrarProductos(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVenta,const string& categoria);
void mostrarProductos(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVenta,const string& categoria);
void mostrarProductosAlfabeticamente(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVent,const string& categoriaa);
void mostrarProductosPorPrecio(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVenta, const string& categoria);


//2. Funciones para buscar productos
void menuBuscarProducto(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVenta);
void buscarProductoPorNombre(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVenta); 
void buscarProductoPorID(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVenta);


//3. Funciones para gestionar ventas.
void menuDeVentas( gestionDeventas ventas[],int &numeroVenta,producto articulo[], int &numeroProducto,const descuento descuentos[],int numeroDescuentos);
void registrarVenta( gestionDeventas ventas[],int &numeroVenta,producto articulo[], int &numeroProducto,const descuento descuentos[],int numeroDescuentos);
void mostrarVentas( gestionDeventas ventas[], int numeroVenta);
void mostrarGanancias( gestionDeventas ventas[], int& numeroVenta);
void productoMasVendido( gestionDeventas ventas[], int& numeroVenta, producto articulo[], int &numeroProducto);
void eliminarVenta(gestionDeventas ventas[], int& numeroVenta);


//Funciones reclamos
void MenuReclamos(reclamo quejas[], int &numeroReclamo, int &siguienteIDReclamo);
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