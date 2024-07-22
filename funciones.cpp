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
	
	for (int i = 0; i < numeroProducto ; ++i)
    {
        for (int j = 0; j < numeroProducto ; ++j)
        {
            if (articulo[j].nombre < articulo[j+1].nombre) 
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
        cout << "ID del producto: " << articulo[i].id<< ", Nombre: " << articulo[i].nombre<< ", Precio: $" << articulo[i].precio<< ", Cantidad: " << articulo[i].cantidad << endl; 
        int cantidadVendida = 0;
        for (int j = 0; j < numeroVenta; ++j)
        {
            if (ventas[j].nombreProducto == articulo[i].nombre)
            {
                cantidadVendida += ventas[j].cantidad;
            }
        }
        cout << "Cantidad vendida: " << cantidadVendida << endl;
        cout << endl;
    }
    system("pause");	
}

void mostrarProductosPorPrecio(producto articulo[], int numeroProducto, const gestionDeventas ventas[], int& numeroVenta ){
		
	for (int i = 0; i < numeroProducto ; ++i) {
        for (int j = 0; j < numeroProducto ; ++j) {
            if (articulo[j].precio < articulo[j + 1].precio) {
                producto temp = articulo[j];
                articulo[j] = articulo[j + 1];
                articulo[j + 1] = temp;
            }
        }
    }

    cout << "--- Productos ordenados por precio (Mayor a menor) ---" << endl;
    for (int i = 0; i < numeroProducto; ++i) {
        cout << "ID del producto: " << articulo[i].id << ", Nombre: " << articulo[i].nombre << ", Precio: $" << articulo[i].precio << ", Cantidad: " << articulo[i].cantidad << endl;
        int cantidadVendida = 0;
        for (int j = 0; j < numeroVenta; ++j) {
            if (ventas[j].nombreProducto == articulo[i].nombre) {
                cantidadVendida += ventas[j].cantidad;
            }
        }
        cout << "Cantidad vendida: " << cantidadVendida << endl;
        cout << endl;
    }
    system("pause");
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


void inicializarDatos(producto articulo[], int &numeroProducto, reclamo quejas[], int &numeroReclamo, descuento descuentos[], int &numeroDescuentos, gestionDeventas ventas[], int &numeroVenta) {
    // Inicializar productos predefinidos
    articulo[0].id = 1;
    articulo[0].nombre = "Smartphone";
    articulo[0].precio = 800;
    articulo[0].cantidad = 25;

    articulo[1].id = 2;
    articulo[1].nombre = "Laptop";
    articulo[1].precio = 1200;
    articulo[1].cantidad = 10;

    articulo[2].id = 3;
    articulo[2].nombre = "Tablet";
    articulo[2].precio = 600;
    articulo[2].cantidad = 15;

    articulo[3].id = 4;
    articulo[3].nombre = "Smartwatch";
    articulo[3].precio = 300;
    articulo[3].cantidad = 30;

    articulo[4].id = 5;
    articulo[4].nombre = "Auriculares Bluetooth";
    articulo[4].precio = 150;
    articulo[4].cantidad = 50;

    articulo[5].id = 6;
    articulo[5].nombre = "Teclado Mecanico";
    articulo[5].precio = 100;
    articulo[5].cantidad = 20;

    articulo[6].id = 7;
    articulo[6].nombre = "Monitor 4K";
    articulo[6].precio = 400;
    articulo[6].cantidad = 8;

    articulo[7].id = 8;
    articulo[7].nombre = "Camara DSLR";
    articulo[7].precio = 700;
    articulo[7].cantidad = 5;

    articulo[8].id = 9;
    articulo[8].nombre = "Impresora 3D";
    articulo[8].precio = 1000;
    articulo[8].cantidad = 3;

    articulo[9].id = 10;
    articulo[9].nombre = "Router Wi-Fi";
    articulo[9].precio = 200;
    articulo[9].cantidad = 25;

    numeroProducto = 10;

    // Inicializar quejas predefinidas
    quejas[0].id = 1;
    quejas[0].descripcion = "Falla en el sistema operativo del Smartphone";

    quejas[1].id = 2;
    quejas[1].descripcion = "Pantalla rota de la Tablet";

    quejas[2].id = 3;
    quejas[2].descripcion = "Entrega retrasada del Monitor 4K";

    quejas[3].id = 4;
    quejas[3].descripcion = "Bateria de la Laptop no dura lo suficiente";

    quejas[4].id = 5;
    quejas[4].descripcion = "Auriculares Bluetooth con baja calidad de sonido";

    numeroReclamo = 5;

    // Inicializar descuentos predefinidos
    descuentos[0].precioMinimo=100;
    descuentos[0].cantidadMinima = 2;
    descuentos[0].porcentaje = 10;

    descuentos[1].precioMinimo = 1000;
    descuentos[1].cantidadMinima = 1;
    descuentos[1].porcentaje = 15;

    descuentos[2].precioMinimo = 150;
    descuentos[2].cantidadMinima = 3;
    descuentos[2].porcentaje = 5;

    descuentos[3].precioMinimo = 2000;
    descuentos[3].cantidadMinima = 1;
    descuentos[3].porcentaje = 20;

    descuentos[4].precioMinimo = 300;
    descuentos[4].cantidadMinima = 5;
    descuentos[4].porcentaje = 7;

    numeroDescuentos = 5;

    // Inicializar ventas predefinidas
    ventas[0].id = 1;
    ventas[0].nombreProducto = "Smartphone";
    ventas[0].cantidad = 2;
    ventas[0].precioTotal = 1440; // Descuento aplicado: 160 (10%)

    ventas[1].id = 2;
    ventas[1].nombreProducto = "Laptop";
    ventas[1].cantidad = 1;
    ventas[1].precioTotal = 1020; // Descuento aplicado: 180 (15%)

    ventas[2].id = 3;
    ventas[2].nombreProducto = "Tablet";
    ventas[2].cantidad = 3;
    ventas[2].precioTotal = 1710; // Descuento aplicado: 90 (5%)

    ventas[3].id = 4;
    ventas[3].nombreProducto = "Smartwatch";
    ventas[3].cantidad= 2;
    ventas[3].precioTotal = 600; // Sin descuento

    ventas[4].id = 5;
    ventas[4].nombreProducto = "Auriculares Bluetooth";
    ventas[4].cantidad = 5;
    ventas[4].precioTotal = 712.5; // Descuento aplicado: 37.5 (5%)

    ventas[5].id = 6;
    ventas[5].nombreProducto = "Teclado Mecánico";
    ventas[5].cantidad= 4;
    ventas[5].precioTotal = 400; // Sin descuento

    ventas[6].id = 7;
    ventas[6].nombreProducto = "Monitor 4K";
    ventas[6].cantidad = 1;
    ventas[6].precioTotal = 320; // Descuento aplicado: 80 (20%)

    ventas[7].id = 8;
    ventas[7].nombreProducto = "Camara DSLR";
    ventas[7].cantidad = 1;
    ventas[7].precioTotal = 700; // Sin descuento

    ventas[8].id = 9;
    ventas[8].nombreProducto = "Impresora 3D";
    ventas[8].cantidad = 1;
    ventas[8].precioTotal = 800; // Descuento aplicado: 200 (20%)

    ventas[9].id = 10;
    ventas[9].nombreProducto = "Router Wi-Fi";
    ventas[9].cantidad = 3;
    ventas[9].precioTotal = 570; // Descuento aplicado: 30 (5%)

    numeroVenta = 10;
}