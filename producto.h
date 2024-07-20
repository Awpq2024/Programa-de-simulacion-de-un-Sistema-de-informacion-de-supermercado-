#ifndef PRODUCTO_H
#define PRODUCTO_H

const int maximosProductos=100;
const int maximasVentas=100;

struct producto
{
    std::string nombre;
    float precio;
    int cantidad;
    int id;
};
struct gestionDeventas
{
	std::string nombreProducto;
	int cantidad;
	float precioTotal;
	int id;
};

#endif

