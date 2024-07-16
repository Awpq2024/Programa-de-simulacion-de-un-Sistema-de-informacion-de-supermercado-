#include <iostream>
#include "funciones.h"
#include "producto.h"
using namespace std;

void agregarProducto(producto articulo[], int& numeroProducto, int& siguienteID){
    if (numeroProducto < maximosProductos){
        producto auxiliar;
        cout<<"Ingrese el nombre del producto: ";
        cin>>auxiliar.nombre;
        cout<<"Ingrese el precio del producto: ";
        cin>>auxiliar.precio;
        cout<<"Ingrese la cantidad del producto: ";
        cin>>auxiliar.cantidad;
        auxiliar.id=siguienteID++;
        articulo[numeroProducto++]=auxiliar;
        cout<<"Producto agregado correctamente."<<endl;
    } else {
        cout<<"Limite de productos alcanzados."<<endl;
    }
}

void mostrarProductos(const producto articulo[], int numeroProducto){
    if (numeroProducto==0){
        cout<<"No hay productos agregados."<<endl;
    }else{
        cout<<"--- Productos agregados ---"<<endl;
        for (int i = 0; i < numeroProducto; ++i){
            cout<<"ID del producto: "<<articulo[i].id<<", Nombre: "<<articulo[i].nombre<<", Precio: $"<<articulo[i].precio<<", Cantidad: "<<articulo[i].cantidad<<endl;
        }
    }
}
