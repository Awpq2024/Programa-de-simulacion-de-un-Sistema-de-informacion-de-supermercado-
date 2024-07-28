#include <iostream>
#include <string>
#include <windows.h>
#include "estructuras.h"
#include "funciones.h"
using namespace std;

//Se define el limite de las estructuras usadas
producto articulo[maximosProductos];
gestionDeventas ventas[maximasVentas];
reclamo quejas[maximosReclamos];
descuento descuentos[maximosDescuentos];

//Se inicializan los numeros de distintas estructuras en 0
int numeroProducto=5;
int numeroVenta=5;
int numeroReclamo=5;
int numeroDescuentos=5;


int main() {
	//Se inicializan los ID para las estructuras de producto, reclamo y descuento
    int siguienteID=6;
	int siguienteIDReclamo=6;
	int siguienteIDDescuento=6;
    int opcion;//se crea la variable opcion
    string categoria;
    
    // Inicializar productos predefinidos
    inicializarDatos(articulo, numeroProducto, quejas, numeroReclamo, descuentos, numeroDescuentos, ventas, numeroVenta, categoria);
    

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
		cout<<" Categorias "<<endl;
		setColor(14);
        cout<<"2.";
        setColor(7);
		cout<<" Buscar Producto"<<endl;
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
		cout<<" Salir del programa"<<endl;
		setColor(14);
		cout<<" Ingrese una opcion: ";
        setColor(15);
        cin>>opcion;//se introduce la opcion para usarla en el switch

        switch (opcion)
        {
        	case 1:
            	system("cls");
				menuProductosCategorias(articulo, numeroProducto, siguienteID,  ventas, numeroVenta, categoria);
                break;                     
            case 2://Busqueda de un producto 
                system("cls");
				menuBuscarProducto(articulo, numeroProducto, ventas, numeroVenta);
            	break;
            case 3:				
				system("cls");
				menuDeVentas(ventas, numeroVenta, articulo, numeroProducto, descuentos, numeroDescuentos);
    			break;            
            case 4://Se despliega el menu de reclamos 
                system("cls");
                MenuReclamos(quejas,numeroReclamo, siguienteIDReclamo);
                break;
			case 5://Se despliega el menu de descuentos
				system("cls");
                MenuDescuentos(descuentos, numeroDescuentos,siguienteIDDescuento);
                break;                  
            case 6://Se cumple con el requirimiento del do while, y se cierra el programa
                cout<<"Saliendo del programa..."<<endl;
                break;
            default://Se muestra un mensaje de error al no coincidir la opcion elegida con las disponibles en el menu, y se reinicia el programa
                cout<<endl<<"Opcion no valida."<<endl<<endl;
                system("pause");   
		}
    	
	}while(opcion!=6);
    //El menu aparece nuevamente a menos que se seleccione la opcion 6. (Salir del programa)
    return 0;//Finaliza el programa
}
