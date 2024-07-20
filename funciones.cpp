#include <iostream>
#include <string>
#include "funciones.h"
#include "producto.h"
using namespace std;

void agregarProducto(producto articulo[], int& numeroProducto, int& siguienteID){
    if (numeroProducto < maximosProductos){
    	int opcion;
        producto auxiliar;
        cout<<"Ingrese el nombre del producto: ";
        cin>>auxiliar.nombre;
        cout<<"Ingrese el precio del producto: ";
        cin>>auxiliar.precio;
        cout<<"Ingrese la cantidad del producto: ";
        cin>>auxiliar.cantidad;
        auxiliar.id=siguienteID++;
        articulo[numeroProducto++]=auxiliar;
        cout<<endl<<"Producto agregado correctamente.\n"<<endl;
        cout<<endl;
		system("pause");
    } else {
        cout<<"Limite de productos alcanzados."<<endl;
    }
}

void mostrarProductos(const producto articulo[], int numeroProducto){
    if (numeroProducto==0){
        cout<<"No hay productos agregados.\n"<<endl;
        system("pause");
    }else{
        cout<<"--- Productos agregados ---"<<endl;
        for (int i = 0; i < numeroProducto; ++i){
            cout<<"ID del producto: "<<articulo[i].id<<", Nombre: "<<articulo[i].nombre<<", Precio: $"<<articulo[i].precio<<", Cantidad: "<<articulo[i].cantidad<<endl;
            cout<<endl;
        }
        system("pause");
    }
}


void registrarVenta(gestionDeventas ventas[], int& numeroVenta, producto articulo[], int& numeroProducto) {
    if (numeroVenta < maximasVentas) {
        gestionDeventas temporal;
        cout << "Ingrese el nombre del producto: ";
        cin >> temporal.nombreProducto;

        for (int i = 0; i < numeroProducto; i++) {
            if (temporal.nombreProducto == articulo[i].nombre) {
                cout << "Ingrese la cantidad: ";
                cin >> temporal.cantidad;

                if (temporal.cantidad <= articulo[i].cantidad) {
                	temporal.id = articulo[i].id;
                    ventas[numeroVenta] = temporal;
                    articulo[i].cantidad -= temporal.cantidad;
                    ventas[numeroVenta].precioTotal = temporal.cantidad * articulo[i].precio;

                    cout << "El precio total es: $" << ventas[numeroVenta].precioTotal << endl;
                    cout << "Venta registrada correctamente." << endl;
                    numeroVenta++;
                } else {
                    cout << "No hay suficiente cantidad de " << temporal.nombreProducto << " en el inventario." << endl;
                }
                break;
            }
        }
    } else {
        cout << "Limite de ventas alcanzados." << endl;
    }
    system("pause");
}

void mostrarVentas(const gestionDeventas ventas[], int numeroVenta ){
	if (numeroVenta==0){
        cout<<"No hay ventas registradas.\n"<<endl;
        system("pause");
    }else{
        cout<<"--- Ventas registradas ---"<<endl;
        for (int i = 0; i < numeroVenta; ++i){
            cout<<"ID del producto: "<<ventas[i].id<<", Nombre: "<<ventas[i].nombreProducto<<", Cantidad: $"<<ventas[i].cantidad<<", Precio total: $"<<ventas[i].precioTotal<<endl;
            cout<<endl;
        }
        system("pause");
    }	
}
void mostrarGanancias(gestionDeventas ventas[], int& numeroVenta)
{
	int sumaTotal=0;
	cout<<"La cantidad total de ventas realizadas: "<<numeroVenta<<endl;
	for (int i=0; i<numeroVenta; i++ )
	{
		sumaTotal+=ventas[i].precioTotal;
	}
	cout<<"Ganancia total de las ventas realizadas: "<<sumaTotal<<endl;
	cout<<endl;
	system("pause");
}