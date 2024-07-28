#include <iostream>
#include <string>
#include <windows.h>
#include "producto.h"
#include "funciones.h"
using namespace std;

//Se define el limite de las estructuras usadas
producto articulo[maximosProductos];
gestionDeventas ventas[maximasVentas];
reclamo quejas[maximosReclamos];
descuento descuentos[maximosDescuentos];

//Se inicializan los numeros de distintas estructuras en 0
int numeroProducto=10;
int numeroVenta=10;
int numeroReclamo=5;
int numeroDescuentos=5;


int main() {
	//Se inicializan los ID para las estructuras de producto, reclamo y descuento
    int siguienteID=11;
	int siguienteIDReclamo=6;
	int siguienteIDDescuento=6;
    int opcion;//se crea la variable opcion
    
    // Inicializar productos predefinidos
    inicializarDatos(articulo, numeroProducto, quejas, numeroReclamo, descuentos, numeroDescuentos, ventas, numeroVenta);
    

    do {//El menu se repite hasta elegir la opcion "6" del do while
    	system("cls");
    	setColor(14);
    	cout<<"==============================="<<endl;
    	setColor(14);
        cout<<"||        ";
        setColor(15);
		cout<<"Supermercado";
		setColor(14);
		cout<<"       ||"<<endl;
        setColor(14);
      	cout<<"==============================="<<endl;
      	setColor(14);
        cout<<"1.";
        setColor(7);
		cout<<" Mostrar Inventario"<<endl;
		setColor(14);
        cout<<"2.";
        setColor(7);
		cout<<" Gestionar Productos"<<endl;
		setColor(14);      
        cout<<"3.";
        setColor(7);
		cout<<" Gestionar Ventas"<<endl;
		setColor(14);
        cout<<"4."; 
		setColor(7);
		cout<<" Gestionar Reclamos"<<endl;
		setColor(14);
        cout<<"5.";
        setColor(7);
		cout<<" Gestionar Descuentos"<<endl;
		setColor(14);
		cout<<"6.";
		setColor(7);
		cout<<" Buscar producto"<<endl;
		setColor(14);
		cout<<"7.";
		setColor(7);
		cout<<" Salir del programa"<<endl;
		setColor(14);
		cout<<" Ingrese una opcion: ";
        setColor(15);
        cin>>opcion;//se introduce la opcion para usarla en el switch

        switch (opcion){//se usa un switch para comparar la opcion ingresada con las disponibles
    
            case 1://Se hace un sub menu para mostrar los productos predefinidos  y los registrados
            	int opcionMostrarProductos;
            	do{
            		system("cls");
					cout<<"1. Mostrar productos "<<endl;
            		cout<<"2. Mostrar productos por precio Mayor al menor "<<endl;
       				cout<<"3. Mostrar productos alfabeticamente "<<endl;
       				cout<<"4. Volver al menu principal "<<endl;
       				cout<<"Ingrese una opcion: ";
       				cin>>opcionMostrarProductos;
       			
       				switch(opcionMostrarProductos)
            		{
            			case 1://llama a la funcion mostrar producto
					        system("cls");
            				mostrarProductos(articulo, numeroProducto, ventas, numeroVenta);
            				break;
            			case 2://llama a la funcion mostrar producto por precio de mayor a menor
            				system("cls");
            				mostrarProductosPorPrecio(articulo, numeroProducto, ventas, numeroVenta);
            				break;
            			case 3://llama a la funcion mostrar producto por orden alfabetico
            				system("cls");
            				mostrarProductosAlfabeticamente(articulo, numeroProducto, ventas, numeroVenta);
            				break;  
						case 4://Opcion para volver al menu principal
						    cout<<"Volviendo al menu principal..."<<endl;
               				break;     			
            			default:
            				cout<<endl<<"Opcion no valida."<<endl<<endl;
            				system("pause");
               				break;
					}
				}while(opcionMostrarProductos!=4);
				break;
			case 2://Se llama a la funcion que permite agregar un producto
            	system("cls");
                agregarProducto(articulo, numeroProducto, siguienteID);
                break;
                
            case 3:// se despliega un Menu secundario que permite Gestionar las ventas
            	int opcionVentas;
            	do{
            		system("cls");
					cout<<"1. Registrar una venta "<<endl;
            		cout<<"2. Mostrar ventas"<<endl;
       				cout<<"3. Mostrar ganancias"<<endl;
       				cout<<"4. Producto mas vendido"<<endl;
       				cout<<"5. Volver al menu principal "<<endl;
       				cout<<"Ingrese una opcion: ";
       				cin>>opcionVentas;
       			
       				switch(opcionVentas)
            		{
            			case 1://llama a la funcion que permite registrar una venta,actualiza el inventario, y aplica los descuentos si es necesario
            				system("cls");
            				registrarVenta(ventas, numeroVenta, articulo, numeroProducto, descuentos, numeroDescuentos);
            			case 2://llama a la funcion que muestra las ventas realizadas
            				system("cls");
            				mostrarVentas(ventas, numeroVenta);
            				break;
            			case 3://Se llama a la funcion que muestra las ganancias 
            				system("cls");
            				mostrarGanancias(ventas, numeroVenta);
            				break;  
						case 4:
						    system("cls");
							productoMasVendido(ventas, numeroVenta, articulo, numeroProducto);
            				break;
						case 5://Se vuelve al menu principal
							cout<<"Volviendo al menu principal..."<<endl;
               				break; 			
            			default://Se muestra un mensaje de error al no 
            				cout<<endl<<"Opcion no valida."<<endl<<endl;
            				system("pause");
               				break;
					}
				}while(opcionVentas!=4);//El menu de ventas
				break;
            case 4://Se despliega el menu de reclamos 
                system("cls");
                MenuReclamos(quejas,numeroReclamo, siguienteIDReclamo);
                break;
			case 5://Se despliega el menu de descuentos
				system("cls");
                MenuDescuentos(descuentos, numeroDescuentos,siguienteIDDescuento);
                break;
            case 6://Buscar producto
                system("cls");
				buscarProducto( articulo, numeroProducto, ventas, numeroVenta);
            	break;                 
            case 7://Se cumple con el requirimiento del do while, y se cierra el programa
                cout<<"Saliendo del programa..."<<endl;
                break;
            default://Se muestra un mensaje de error al no coincidir la opcion elegida con las disponibles en el menu, y se reinicia el programa
                cout<<endl<<"Opcion no valida."<<endl<<endl;
                system("pause");
        }

    } while(opcion!=7);//El menu aparece nuevamente a menos que se seleccione la opcion 6. (Salir del programa)
    return 0;//Finaliza el programa
}
