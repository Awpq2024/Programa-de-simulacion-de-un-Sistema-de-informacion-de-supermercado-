#include <iostream>
#include <string>
#include "producto.h"
#include "funciones.h"
 
using namespace std;

producto articulo[maximosProductos];
int numeroProducto=0;

int main() {
    int siguienteID=1;

    int opcion;
    do {
        cout<<"--- Supermercado ---"<<endl;
        cout<<"1. Agregar producto"<<endl;
        cout<<"2. Mostrar productos agregados"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch (opcion){
            case 1:
                agregarProducto(articulo, numeroProducto, siguienteID);
                break;
            case 2:
                mostrarProductos(articulo, numeroProducto);
                break;
            case 3:
                cout<<"Saliendo del programa..."<<endl;
                break;
            default:
                cout<<"Opcion no valida."<<endl;
        }

    } while(opcion!=3);

    return 0;
}
