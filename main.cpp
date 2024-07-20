#include <iostream>
#include <string>
#include "producto.h"
#include "funciones.h"

 
using namespace std;

producto articulo[maximosProductos];
gestionDeventas ventas[maximasVentas];
int numeroProducto=0;
int numeroVenta=0;

int main() {
    int siguienteID=0;

    int opcion;
    do {
    	system("cls");
        cout<<"--- Supermercado ---"<<endl;
        cout<<"1. Agregar producto"<<endl;
        cout<<"2. Mostrar productos agregados"<<endl;
        cout<<"3. Ventas realizadas"<<endl;
        cout<<"4. Salir"<<endl;
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
            	int opcionVentas;
            	do{
            		system("cls");
					cout<<"1. Registrar una venta "<<endl;
            		cout<<"2. Mostrar ventas"<<endl;
       				cout<<"3. Mostrar ganancias"<<endl;
       				cout<<"4. Volver al menu principal "<<endl;
       				cout<<"Ingrese una opcion: ";
       				cin>>opcionVentas;
       			
       				switch(opcionVentas)
            		{
            			case 1:
            				system("cls");
            				registrarVenta(ventas, numeroVenta, articulo, numeroProducto);
            				break;
            			case 2:
            				system("cls");
            				mostrarVentas(ventas, numeroVenta);
            				break;
            			case 3:
            				system("cls");
            				mostrarGanancias(ventas, numeroVenta);
            				break;  
						case 4:
						    cout<<"Volviendo al menu principal..."<<endl;
               				break;     			
            			default:
            				cout<<endl<<"Opcion no valida."<<endl<<endl;
            				system("pause");
               				break;
					}
				}while(opcionVentas!=4);
				break;
            case 4:
                cout<<"Saliendo del programa..."<<endl;
                break;
            default:
                cout<<endl<<"Opcion no valida."<<endl<<endl;
                system("pause");
        }

    } while(opcion!=4);

    return 0;
}
