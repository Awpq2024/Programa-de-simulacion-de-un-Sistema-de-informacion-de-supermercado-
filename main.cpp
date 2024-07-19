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
    	system("cls");
        cout<<"--- Supermercado ---"<<endl;
        cout<<"1. Agregar producto"<<endl;
        cout<<"2. Mostrar productos agregados"<<endl;
        cout<<"3. Salir"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcion;

        switch (opcion){
            case 1:
            	system("cls");
                agregarProducto(articulo, numeroProducto, siguienteID);
                break;
                
            case 2:
            	system("cls");
                mostrarProductos(articulo, numeroProducto);
                break;
            case 3:
                cout<<"Saliendo del programa..."<<endl;
                break;
            default:
                cout<<endl<<"Opcion no valida."<<endl<<endl;
                system("pause");
        }

    } while(opcion!=3);

    return 0;
}
