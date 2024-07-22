#include <iostream>
#include <string>
#include "funciones.h"
#include "producto.h"
using namespace std;

void agregarProducto(producto articulo[], int& numeroProducto, int& siguienteID){
    if (numeroProducto<maximosProductos){
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

void mostrarProductos(const producto articulo[], int numeroProducto, const gestionDeventas ventas[], int& numeroVenta){
   if (numeroProducto == 0){
        cout << "No hay productos agregados.\n" << endl;
        system("pause");
    } else {
        cout << "--- Productos agregados ---" << endl;
        for (int i = 0; i < numeroProducto; ++i){
            cout<<"ID del producto: "<<articulo[i].id<<", Nombre: "<<articulo[i].nombre<<", Precio: $"<<articulo[i].precio<<", Cantidad: "<<articulo[i].cantidad<<endl; 
            int cantidadVendida = 0;
            for (int j = 0; j < numeroVenta; ++j){
                if (ventas[j].nombreProducto == articulo[i].nombre){
                    cantidadVendida += ventas[j].cantidad;
                }
            }
            cout<<"Cantidad vendida: " <<cantidadVendida<<endl;
            cout<< endl;
        }
        system("pause");    
    }
}

void mostrarProductosAlfabeticamente(producto articulo[], int numeroProducto, const gestionDeventas ventas[], int& numeroVenta){
	if (numeroProducto == 0){
        cout << "No hay productos agregados.\n" << endl;
        system("pause");
    } else {
		for (int i = 0; i < numeroProducto-1 ; ++i)
		{
			for (int j = 0; j < numeroProducto-1-i ; ++j)
			{
				if (articulo[j].nombre > articulo[j+1].nombre) 
				{
                	producto temp = articulo[j];
                	articulo[j] = articulo[j + 1];
                	articulo[j + 1] = temp;
            	}
			
			}                   
   		}
	    cout << "--- Productos ordenados alfabeticamente ---" << endl;
    	for (int i = 0 ; i < numeroProducto ; ++i)
   		{
        	cout<<"ID del producto: "<<articulo[i].id<<", Nombre: "<<articulo[i].nombre<<", Precio: $"<<articulo[i].precio<<", Cantidad: "<<articulo[i].cantidad<<endl; 
       		int cantidadVendida = 0;
        	for (int j = 0; j < numeroVenta; ++j){
            	if (ventas[j].nombreProducto == articulo[i].nombre){
           		cantidadVendida += ventas[j].cantidad;
            	}
            cout<<"Cantidad vendida: " <<cantidadVendida<<endl;
        	cout<< endl;
        	}       
       		system("pause");    
		}
	}
}

void mostrarProductosPorPrecio(producto articulo[], int numeroProducto, const gestionDeventas ventas[], int& numeroVenta ){
	if (numeroProducto == 0){
        cout << "No hay productos agregados.\n" << endl;
        system("pause");
    } else {	
		for (int i=0; numeroProducto-1 ; ++i)
		{
			for (int j=0; j < numeroProducto-1-i ; ++j)
			{
				if (articulo[j].precio > articulo[j+1].precio) 
				{
            	    producto temp = articulo[j];
                	articulo[j] = articulo[j + 1];
                	articulo[j + 1] = temp;
            	}
			
			}                   
    	}
    	cout << "--- Productos ordenado por precio (Mayor a menor) ---" << endl;
    	for (int i=numeroProducto-1 ; i >= 0 ; --i)
    	{
        	cout<<"ID del producto: "<<articulo[i].id<<", Nombre: "<<articulo[i].nombre<<", Precio: $"<<articulo[i].precio<<", Cantidad: "<<articulo[i].cantidad<<endl; 
        	int cantidadVendida = 0;
        	for (int j = 0; j < numeroVenta; ++j){
            	if (ventas[j].nombreProducto == articulo[i].nombre){
            	cantidadVendida += ventas[j].cantidad;
            	}
            cout<<"Cantidad vendida: " <<cantidadVendida<<endl;
        	cout<< endl;
        	}       
        	system("pause");   
		}
	}
}


void registrarVenta(gestionDeventas ventas[],int &numeroVenta,producto articulo[], int &numeroProducto,const descuento descuentos[],int numeroDescuentos){
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
                    float precioSinDescuento = temporal.cantidad * articulo[i].precio;
                    float descuento = calcularDescuento(precioSinDescuento, temporal.cantidad, descuentos, numeroDescuentos);
                    ventas[numeroVenta].precioTotal = temporal.cantidad * articulo[i].precio;
                    cout << "El precio total es: $" << ventas[numeroVenta].precioTotal<<"con un descuento de: "<<descuento<<endl;
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
        cout<<"Eliga una opcion: ";
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
        cout<<"Reclamo agregado correctamente"<<endl;
    } else {
        cout<<"Limite de reclamos alcanzados"<<endl;
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

float calcularDescuento(float precioTotal, int cantidad, const descuento descuentos[], int numeroDescuentos) {
    float descuento=0.0;
    for (int i=0;i<numeroDescuentos;++i) {
        if (precioTotal>=descuentos[i].precioMinimo && cantidad>=descuentos[i].cantidadMinima){
            descuento+=precioTotal*(descuentos[i].porcentaje/100);
        }
    }
    return descuento;
}
void MenuDescuentos(descuento descuentos[], int &numeroDescuentos,int &siguienteIDDescuento){
    int opcionDescuentos;
    do {
        system("cls");
        cout<<"--- Supermercado ---"<<endl;
        cout<<"---- Descuentos ----"<<endl;
        cout<<"1. Agregar descuento"<<endl;
        cout<<"2. Eliminar descuento"<<endl;
        cout<<"3. Mostrar descuentos"<<endl;
        cout<<"4. Volver al menu principal"<<endl;
        cout<<"Ingrese una opcion: ";
        cin>>opcionDescuentos;
        switch(opcionDescuentos){
                case 1:
                    system("cls");
                    agregarDescuento(descuentos, numeroDescuentos, siguienteIDDescuento);
                    system("pause");
                    break;
                case 2:
                    system("cls");
                    eliminarDescuento(descuentos, numeroDescuentos);
                    system("pause");
                    break;
                case 3:
                    system("cls");
                    mostrarDescuentos(descuentos, numeroDescuentos);
                    system("pause");
                    break;
                case 4:
                    break;
                default:
                    cout<<endl<<"Opcion no valida."<<endl<<endl;
                    system("pause");
                    break;
                    }
    }while(opcionDescuentos!=4);
    return;
}

void agregarDescuento(descuento descuentos[], int &numeroDescuentos,int &siguienteIDDescuento){
    if (numeroDescuentos<maximosDescuentos){
        descuento nuevoDescuento;//se crea una nuevo descuento con la estructura descuento, y se ingresan sus variables
        nuevoDescuento.id=siguienteIDDescuento++;
		cout<<"Ingrese el precio minimo para el descuento: ";
        cin>>nuevoDescuento.precioMinimo;
        cout<<"Ingrese la cantidad minima para el descuento: ";
        cin>>nuevoDescuento.cantidadMinima;
        cout<<"Ingrese el porcentaje de descuento: ";
        cin>>nuevoDescuento.porcentaje;
        descuentos[numeroDescuentos++]=nuevoDescuento;//Se agrega el nuevo descuento y se aumenta la cantidad de descuentos
        cout<<"Descuento agregado exitosamente"<<endl;
    }else{//Se muestra un enunciado al llegar al  limite de descuentos 
        cout<<"Limite de descuentos alcanzados"<<endl;
    }
}
//Funcion para eliminar un descuento agregado
void eliminarDescuento(descuento descuentos[], int &numeroDescuentos){
    if (numeroDescuentos==0){//Si no hay ningun descuento registrado se muestra un enunciado
        cout<<"No hay descuentos para eliminar"<<endl;
        return;
    }
    int idAuxiliar;//se crea una variable 
    cout<<"Ingrese el ID del descuento a eliminar: ";
    cin>>idAuxiliar;
    bool encontrado=false;//Se crea un variable para indicar si el descuento fue encontrado
    for (int i=0;i<numeroDescuentos;++i){
        if (descuentos[i].id==idAuxiliar){//Se verifica si el id ingresado coincide con el id del for
            for (int j=i;j<numeroDescuentos-1;++j){//se usa un for para reordenar el arreglo de las estructuras
                descuentos[j]=descuentos[j+1];
            }
            --numeroDescuentos;//se elimina una posicion del total de descuentos registrados
            encontrado=true;//el producto fue encontrado y es eliminado
            cout<<"Descuento eliminado exitosamente"<<endl;
            break;
        }
    }
    if (!encontrado){
        cout<<"Descuento no encontrado"<<endl;
    }
}

// Función para mostrar los descuentos
void mostrarDescuentos(const descuento descuentos[], int numeroDescuentos) {
    if (numeroDescuentos==0){//Muestra un enunciado si no hay ningun descuento agregado
        cout<<"No hay descuentos disponibles."<<endl;
        return;
    }
    cout<<"--- Descuentos disponibles ---"<<endl;//Se muestra los descuentos
    for (int i=0;i<numeroDescuentos;++i){//Se usa un for para mostrar todos los descuentos registrados
        cout<<"ID del descuento: "<<descuentos[i].id//Id del descuento
			<<", precio para el descuento: $"<<descuentos[i].precioMinimo//precio minimo para el descuento
            <<", Cantidad para el descuento: "<<descuentos[i].cantidadMinima//cantidad minima para el descuento
            <<", Porcentaje del descuento: "<<descuentos[i].porcentaje<<"%"<<endl;//Descuento registrado previamente
    }
}