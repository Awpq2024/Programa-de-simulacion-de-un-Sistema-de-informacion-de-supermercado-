#ifndef PRODUCTO_H
#define PRODUCTO_H
  
//Cantidades maximas de las estructuras
const int maximosProductos=100;
const int maximasVentas=100;
const int maximosReclamos=100;
const int maximosDescuentos=10;

struct producto//Estructura de los productos
{
    std::string nombre;//Nombre del producto
    float precio;//Precio del producto
    int cantidad;//Cantidad del producto
    int id;//ID del producto
};
struct gestionDeventas//Estructura de las ventas de productos
{
	std::string nombreProducto;//Nombre del producto vendido
	int cantidad;//Cantidad de producto vendido
	float precioTotal;//Variable para definir el precio total de las ventas
	int id;//ID del producto vendido
};
struct reclamo//Estructura de los Reclamos
{
    int id;//ID del reclamo
    std::string descripcion;//Texto del reclamo
};
struct descuento//Estructura de los descuentos
{
	int id;// ID del descuento
    float precioMinimo;//Precio necesario para el descuento
    int cantidadMinima;//Cantidad necesaria para el descuento
    float porcentaje;//Porcentaje del descuento
};
#endif

