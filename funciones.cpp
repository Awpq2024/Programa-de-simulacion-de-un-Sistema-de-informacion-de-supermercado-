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




void registrarVenta(gestionDeventas ventas[], int& numeroVenta, producto articulo[], int& numeroProducto){
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

void MenuReclamos(reclamo quejas[], int &numeroReclamo, int &siguienteIDReclamo){
	int opcionReclamo;
	do {
    	system("cls");
        cout<<"--- Supermercado ---"<<endl;
        cout<<"---- Reclamos ----"<<endl;
        cout<<"1. Agregar reclamo"<<endl;
        cout<<"2. Eliminar reclamo"<<endl;
        cout<<"3. Mostrar reclamos"<<endl;
        cout<<"4. volver al menu"<<endl;
        cout<<"eliga una opcion: ";
        cin>>opcionReclamo;
		switch(opcionReclamo){
			case 1:
                system("cls");
                agregarReclamo(quejas, numeroReclamo, siguienteIDReclamo);
                system("pause");
                break;
            case 2:
                system("cls");
                eliminarReclamo(quejas, numeroReclamo);
                system("pause");
                break;
            case 3:
                system("cls");
                mostrarReclamos(quejas, numeroReclamo);
                system("pause");
                break;
            case 4:
                break;
            default:
                cout<<endl<<"Opcion no valida."<<endl<<endl;
                system("pause");
        }
    }while(opcionReclamo!=4);
    return;
}
void agregarReclamo(reclamo quejas[], int &numeroReclamo, int &siguienteIDReclamo){
    if (numeroReclamo<maximosReclamos){
        reclamo auxiliar;
        auxiliar.id=siguienteIDReclamo++;
        cout<<"Ingrese la descripcion del reclamo: ";
        cin.ignore();
        getline(cin,auxiliar.descripcion);
        quejas[numeroReclamo++]=auxiliar;
        cout<<"Reclamo agregado exitosamente."<<endl;
    } else {
        cout<<"No se pueden agregar más reclamos."<<endl;
    }
}
void eliminarReclamo(reclamo quejas[], int &numeroReclamo){
    int indice=-1;
    int id;
    cout<<"Ingrese el ID del reclamo a eliminar: ";
    cin>>id;
    for (int i=0;i<numeroReclamo;++i){
        if (quejas[i].id==id){
            indice=i;
            break;
        }
    }
    if (indice!=-1){
        for (int i=indice;i<numeroReclamo-1;++i){
            quejas[i]=quejas[i+1];
        }
        --numeroReclamo;
        cout<<"Reclamo eliminado exitosamente."<<endl;
    } else {
        cout<<"Reclamo no encontrado."<<endl;
    }
}
void mostrarReclamos(const reclamo quejas[], int numeroReclamo){
    if (numeroReclamo==0){
        cout<<"No hay reclamos."<<endl;
    } else {
        for (int i=0;i<numeroReclamo;++i){
            cout<<"ID: "<<quejas[i].id<<", Descripcion: "<<quejas[i].descripcion<<endl;
        }
    }
}

