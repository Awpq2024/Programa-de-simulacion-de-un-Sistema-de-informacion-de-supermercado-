#include <iostream>
#include <string>
#include <windows.h>
#include "funciones.h"
#include "estructuras.h"
using namespace std;



void menuProductosCategorias(producto articulo[], int& numeroProducto, int& siguienteID,  gestionDeventas ventas[], int& numeroVenta, string& categoria){
	int opcionCategorias;
	do {//El menu se repite hasta elegir la opcion "6" del do while
    	system("cls");
    	setColor(14);
    	cout<<"==============================="<<endl;
    	setColor(14);
        cout<<"||        ";
        setColor(15);
		cout<<"Categorias";
		setColor(14);
		cout<<"       ||"<<endl;
        setColor(14);
      	cout<<"==============================="<<endl;
      	setColor(14);
        cout<<"1.";
        setColor(7);
		cout<<" Vestimenta "<<endl;
		setColor(14);
        cout<<"2.";
        setColor(7);
		cout<<" Lacteos"<<endl;
		setColor(14); 
        cout<<"3.";
        setColor(7);
		cout<<" Mobiliario"<<endl;
		setColor(14);      
        cout<<"4.";
        setColor(7);
		cout<<" Alimentos y Bebidas"<<endl;
		setColor(14);
        cout<<"5."; 
		setColor(7);
		cout<<" Limpieza e Higiene"<<endl;
		setColor(14);
        cout<<"6.";
        setColor(7);
		cout<<" Automotriz"<<endl;
		setColor(14);
		cout<<"7.";
		setColor(7);
		cout<<" Mascotas"<<endl;
		setColor(14);
		cout<<"8.";
        setColor(7);
		cout<<" Electrodomesticos"<<endl;
		setColor(14);
		cout<<"9.";
        setColor(7);
		cout<<" Electronica y Tecnologia"<<endl;
		setColor(14);
		cout<<"0.";
        setColor(7);
		cout<<" Volver al menu principal"<<endl;
		setColor(14);
		cout<<endl<<"-> Ingrese una opcion: ";
        setColor(15);
        cin>>opcionCategorias;//se introdusce la opcion para usarla en el switch
		if (opcionCategorias>=1 && opcionCategorias<=9){
					    switch(opcionCategorias){
			        		case 1: categoria="Vestimenta"; break;
			        		case 2: categoria="Lacteos"; break;
			       			case 3: categoria="Mobiliario"; break;
			 		        case 4: categoria="Alimentos y Bebidas"; break;
			    		    case 5: categoria="Limpieza e Higiene"; break;
			    		    case 6: categoria="Automotriz"; break;
			    		    case 7: categoria="Mascotas"; break;
			    		    case 8: categoria="Electrodomesticos"; break;
			    		    case 9: categoria="Electronica y Tecnologia"; break;
        		}
                funcionesDelMenuDeCategorias(articulo, numeroProducto, siguienteID, ventas, numeroVenta,categoria);

		}

    } while(opcionCategorias!=0);
}

void funcionesDelMenuDeCategorias(producto articulo[], int& numeroProducto, int& siguienteID, gestionDeventas ventas[], int& numeroVenta,const string& categoria) {
    int opcionesFunciones;
    do { // El menu se repite hasta elegir la opcion "3" del do while
        system("cls");
    	setColor(14);
    	cout<<"==============================="<<endl;
    	setColor(14);
        cout<<"       ";
        setColor(15);
		cout<<"Gestion de Categoria";
		setColor(14);
		cout<<"       "<<endl;
        setColor(14);
      	cout<<"==============================="<<endl;
      	setColor(14);
        cout<<"1.";
        setColor(7);
		cout<<" Agregar producto "<<endl;
		setColor(14);
        cout<<"2.";
        setColor(7);
		cout<<" Mostrar productos agregados"<<endl;
		setColor(14);
        cout<<"3.";
        setColor(7);
		cout<<" Actualizar producto"<<endl;
		setColor(14);
        cout<<"4.";
        setColor(7);
		cout<<" Eliminar producto"<<endl;
		setColor(14);      
        cout<<"0.";
        setColor(7);
		cout<<" Volver al menu de Categorias"<<endl;
		setColor(14);
		cout<<endl<<"-> Ingrese una opcion: ";
        setColor(15);
        cin >> opcionesFunciones;

        switch (opcionesFunciones) {
            case 1:
                system("cls");
                agregarProducto(articulo, numeroProducto, siguienteID,categoria);
                break;
            case 2:
                system("cls");
                menuDeMostrarProductos(articulo, numeroProducto, ventas, numeroVenta,categoria);
                break;
            case 3:
                system("cls");
                actualizarProducto(articulo, numeroProducto, siguienteID, categoria);
                break;
            case 4:
                system("cls");
                eliminarProducto(articulo, numeroProducto, siguienteID, categoria);
                break;
            case 0:
            	break;
            default:
                setColor(12);
				cout<<endl<<"*** OPCION NO VALIDA."<<endl;
				setColor(15);
                system("pause"); 
        }

    } while (opcionesFunciones != 0);
}


void agregarProducto(producto articulo[], int& numeroProducto, int& siguienteID,const string& categoria) {
    if (numeroProducto < maximosProductos) {
        producto auxiliar;
        setColor(14);
        cout<<"*. ";
        setColor(15);
        cout << "Ingrese el nombre del producto: ";
        cin.ignore();
        getline(cin,auxiliar.nombre);
        setColor(14);
        cout<<"*. ";
        setColor(15);
        cout << "Ingrese el precio del producto: ";
        cin >> auxiliar.precio;
        setColor(14);
        cout<<"*. ";
        setColor(15);
        cout << "Ingrese la cantidad del producto: ";
        cin >> auxiliar.cantidad;
        auxiliar.id = siguienteID++;
        auxiliar.categoria=categoria;
        articulo[numeroProducto++] = auxiliar;
        setColor(11);
        cout << endl << "+++ Producto agregado correctamente." << endl;
        setColor(15);
        system("pause");
    } else {
        setColor(14);
        cout<<"*. ";
        setColor(15);
        cout << "Limite de productos alcanzado." << endl;
        system("pause");
    }
}
void actualizarProducto(producto articulo[], int& numeroProducto, int& siguienteID,const string& categoria)
{
	string nombreActualizar;
	setColor(14);
	cout<<"*. ";
	setColor(15);
    cout<<"Ingrese el nombre del producto a actualizar: ";
    cin.ignore();
    getline(cin, nombreActualizar);

    for (int i = 0; i < numeroProducto; ++i) 
	{
        if (articulo[i].nombre == nombreActualizar) 
		{
			setColor(14);
			cout<<"*. ";
			setColor(15);	
            cout << "Ingrese el nuevo nombre del producto: ";
            getline(cin, articulo[i].nombre);
        	setColor(14);
			cout<<"*. ";
			setColor(15);	
            cout << "Ingrese el nuevo precio por unidad del producto: ";
            cin >> articulo[i].precio;
            setColor(14);
			cout<<"*. ";
			setColor(15);	
            cout << "Ingrese la cantidad producto: ";
            cin >> articulo[i].cantidad;
           	setColor(11);
            cout << "=== Producto actualizado correctamente.\n";
			setColor(15);
            break;  
        }
    }
}
void eliminarProducto(producto articulo[], int& numeroProducto, int& siguienteID,const string& categoria)
{
	string nombreEliminar;
	setColor(14);
	cout<<"*. ";
	setColor(15);
	cout<<"Ingrese el nombre del producto: ";
	cin.ignore();
	getline(cin, nombreEliminar);
	for (int i=0; i <numeroProducto; i++)
	{
        if (articulo[i].nombre == nombreEliminar) 
		{
            for (int j=i; j<numeroProducto-1; j++)
			{
                articulo[j] = articulo[j + 1];
            }
            numeroProducto--;
            for (int k = i; k < numeroProducto; ++k) {
                articulo[k].id = k + 1; // Asumiendo que el ID comienza en 1 y es continuo
            }
            // Actualiza el siguiente ID
            siguienteID = numeroProducto + 1; // El siguiente ID será el número total de productos + 1
			setColor(11);
            cout << "--- Producto eliminado exitosamente." << endl;
            setColor(15);
            break;

        }
    }
}

void menuDeMostrarProductos(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVenta,const string& categoria ) {
    int opcionMostrar;
    do {
        system("cls");
    	setColor(14);
    	cout<<"==============================="<<endl;
    	setColor(14);
        cout<<"       ";
        setColor(15);
		cout<<"Mostrar Productos";
		setColor(14);
		cout<<"       "<<endl;
        setColor(14);
      	cout<<"==============================="<<endl;
      	setColor(14);
        cout<<"1.";
        setColor(7);
		cout<<" Mostrar productos "<<endl;
		setColor(14);
        cout<<"2.";
        setColor(7);
		cout<<" Mostrar productos alfabeticamente"<<endl;
		setColor(14);      
        cout<<"3.";
        setColor(7);
		cout<<" Mostrar productos por precio"<<endl;
		setColor(14);
		cout<<"0.";
        setColor(7);
		cout<<" Volver al menu anterior"<<endl;
		setColor(14);
		cout<<endl<<"-> Ingrese una opcion: ";
        setColor(15);
        cin >> opcionMostrar;

        switch (opcionMostrar) {
            case 1:
                system("cls");
                mostrarProductos(articulo, numeroProducto, ventas, numeroVenta, categoria);
                system("pause");
                break;
            case 2:
                system("cls");
                mostrarProductosAlfabeticamente(articulo, numeroProducto, ventas, numeroVenta, categoria);
                system("pause");
                break;
            case 3:
                system("cls");
                mostrarProductosPorPrecio(articulo, numeroProducto, ventas, numeroVenta, categoria);
                system("pause");
                break;
            case 0:
                break;
            default:
            	setColor(12);
                cout << "*** OPCION NO VALIDA" << endl;
                setColor(15);
                system("pause");
        }
    } while (opcionMostrar != 0);
}

void mostrarProductos(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVenta, const string& categoria) {
    if (numeroProducto == 0) {
    	setColor(12);
        cout << "*** No hay productos agregados." << endl;
        setColor(15);
        
    } else {
    	setColor(14);
    	cout<<"================================================================"<<endl;
    	setColor(15);
        cout << "--- Productos agregados en la categoria: " << categoria << " ---" << endl;
    	setColor(14);
    	cout<<"================================================================"<<endl;
    	setColor(15);
        for (int i = 0; i < numeroProducto; ++i) {
            if (articulo[i].categoria == categoria) { // Solo muestra productos en la categoría seleccionada
                cout << "ID del producto: " << articulo[i].id << ", Nombre: " << articulo[i].nombre
                     << ", Precio: $" << articulo[i].precio << ", Cantidad: " << articulo[i].cantidad
                     << ", Categoria: " << articulo[i].categoria;
                int cantidadVendida = 0;
                for (int j = 0; j < numeroVenta; ++j) {
                    if (ventas[j].nombreProducto == articulo[i].nombre) {
                        cantidadVendida += ventas[j].cantidad;
                    }
                }
                cout << "Cantidad vendida: " << cantidadVendida << endl;
                cout << endl;
            }
        }
        
    }
}


void mostrarProductosAlfabeticamente(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVenta, const string& categoria) {
    if (numeroProducto == 0) {
    	setColor(12);
        cout << "*** No hay productos agregados." << endl;
        setColor(15);
        
    } else {
        // Implementación de la ordenación alfabética
        for (int i = 0; i < numeroProducto - 1; ++i) {
            for (int j = i + 1; j < numeroProducto; ++j) {
                if (articulo[i].categoria == categoria && articulo[j].categoria == categoria) {
                    if (articulo[i].nombre > articulo[j].nombre) {
                        // Intercambiar productos
                        producto temp = articulo[i];
                        articulo[i] = articulo[j];
                        articulo[j] = temp;
                    }
                }
            }
        }
		setColor(14);
    	cout<<"============================================================================"<<endl;
    	setColor(15);
        cout << "--- Productos ordenados alfabeticamente en la categoria: " << categoria << " ---" << endl;
		setColor(14);
    	cout<<"============================================================================"<<endl;
    	setColor(15);
        for (int i = 0; i < numeroProducto; ++i) {
            if (articulo[i].categoria == categoria) {
                cout << "ID del producto: " << articulo[i].id << ", Nombre: " << articulo[i].nombre
                     << ", Precio: $" << articulo[i].precio << ", Cantidad: " << articulo[i].cantidad
                     << ", Categoria: " << articulo[i].categoria;
                int cantidadVendida = 0;
                for (int j = 0; j < numeroVenta; ++j) {
                    if (ventas[j].nombreProducto == articulo[i].nombre) {
                        cantidadVendida += ventas[j].cantidad;
                    }
                }
                cout << "Cantidad vendida: " << cantidadVendida << endl;
                cout << endl;
            }
        }
       
    }
}

void mostrarProductosPorPrecio(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVenta, const string& categoria) {
    if (numeroProducto == 0) {
    	setColor(12);
        cout << "*** No hay productos agregados." << endl;
        setColor(15);
        
    } else {
        // Ordenar productos por precio (de menor a mayor)
        for (int i = 0; i < numeroProducto - 1; ++i) {
            for (int j = i + 1; j < numeroProducto; ++j) {
                if (articulo[i].categoria == categoria && articulo[j].categoria == categoria) {
                    if (articulo[i].precio > articulo[j].precio) {
                        // Intercambiar productos
                        producto temp = articulo[i];
                        articulo[i] = articulo[j];
                        articulo[j] = temp;
                    }
                }
            }
        }
		setColor(14);
    	cout<<"==================================================================================="<<endl;
    	setColor(15);
        cout << "--- Productos ordenados por precio en la categoria: " << categoria << " ---" << endl;
    	setColor(14);
    	cout<<"=================================================================================="<<endl;
    	setColor(15);
        for (int i = 0; i < numeroProducto; ++i) {
            if (articulo[i].categoria == categoria) {
                cout << "ID del producto: " << articulo[i].id << ", Nombre: " << articulo[i].nombre
                     << ", Precio: $" << articulo[i].precio << ", Cantidad: " << articulo[i].cantidad
                     << ", Categoria: " << articulo[i].categoria;
                int cantidadVendida = 0;
                for (int j = 0; j < numeroVenta; ++j) {
                    if (ventas[j].nombreProducto == articulo[i].nombre) {
                        cantidadVendida += ventas[j].cantidad;
                    }
                }
                cout << "Cantidad vendida: " << cantidadVendida << endl;
                cout << endl;
            }
        }
     
    }
}

void menuBuscarProducto(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVenta) {
    int opcionesBusqueda;
    do { // El menu se repite hasta elegir la opcion "3" del do while
        system("cls");
    	setColor(14);
    	cout<<"==============================="<<endl;
    	setColor(15);
        cout<<"       ";
        setColor(15);
		cout<<"Buscar productos";
		setColor(14);
		cout<<"       "<<endl;
        setColor(14);
      	cout<<"==============================="<<endl;
      	setColor(14);
        cout<<"1.";
        setColor(7);
		cout<<" Buscar producto por nombre "<<endl;
		setColor(14);
        cout<<"2.";
        setColor(7);
		cout<<" Buscar producto por ID"<<endl;
		setColor(14);
        cout<<"0.";
        setColor(7);
		cout<<" Volver al menu principal"<<endl;
		setColor(14);
		cout<<endl<<"-> Ingrese una opcion: ";
        setColor(15);
        cin >> opcionesBusqueda;

        switch (opcionesBusqueda) {
            case 1:
                system("cls");
				buscarProductoPorNombre(articulo, numeroProducto, ventas, numeroVenta);
                break;
            case 2:
                system("cls");
				buscarProductoPorID(articulo, numeroProducto, ventas, numeroVenta);
                break;
            case 0:
                break;
            default:
            	setColor(12);
                cout << endl << "*** OPCION NO VALIDA." << endl << endl;
                setColor(15);
                system("pause");
        }

    } while (opcionesBusqueda != 0);
}

void buscarProductoPorID(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVenta) {
    int escribirIdDelProducto;
    setColor(14);
    cout<<"*. ";
    setColor(15);
    cout << "Digite el ID del producto: ";
    cin >> escribirIdDelProducto;
    producto buscarID;
    bool encontrar = false;
    for (int i = 0; i < numeroProducto; i++) {
        if (escribirIdDelProducto == articulo[i].id) {
            buscarID = articulo[i];
            encontrar = true;
            break;
        }
    }
    if (encontrar) {
    	setColor(14);
    	cout<<"*. ";
    	setColor(15);
        cout << "ID del producto: " << buscarID.id << ", Nombre: " << buscarID.nombre
             << ", Precio: $" << buscarID.precio << ", Cantidad: " << buscarID.cantidad;
        int cantidadVendida = 0;
        for (int j = 0; j < numeroVenta; ++j) {
            if (ventas[j].id == buscarID.id) {
                cantidadVendida += ventas[j].cantidad;
            }
        }
        cout << "Cantidad vendida: " << cantidadVendida << endl;
        cout << endl;
    } else {
    	setColor(12);
        cout << "*** No se encontro el producto." << endl;
        setColor(15);
    }
    system("pause");
}
void buscarProductoPorNombre(producto articulo[], int& numeroProducto, gestionDeventas ventas[], int& numeroVenta) {
    string escribirNombreDelProducto;
    setColor(14);
    cout<<"*. ";
    setColor(15);
	cout << "Escriba el nombre del producto: ";
    cin.ignore();
    getline(cin, escribirNombreDelProducto);
    producto buscarNombre;
    bool encontrar = false;
    for (int i = 0; i < numeroProducto; i++) {
        if (escribirNombreDelProducto == articulo[i].nombre) {
            buscarNombre = articulo[i];
            encontrar = true;
            break;
        }
    }
    if (encontrar) {
    	setColor(14);
    	cout<<"*. ";
    	setColor(15);
        cout << "ID del producto: " << buscarNombre.id << ", Nombre: " << buscarNombre.nombre
             << ", Precio: $" << buscarNombre.precio << ", Cantidad: " << buscarNombre.cantidad;
        int cantidadVendida = 0;
        for (int j = 0; j < numeroVenta; ++j) {
            if (ventas[j].id == buscarNombre.id) {
                cantidadVendida += ventas[j].cantidad;
            }
        }
        cout << "Cantidad vendida: " << cantidadVendida << endl;
        cout << endl;
    } else {
    	setColor(12);
        cout << "*** No se encontro el producto." << endl;
        setColor(15);
    }
    system("pause");
}

void menuDeVentas(gestionDeventas ventas[],int &numeroVenta,producto articulo[], int &numeroProducto,const descuento descuentos[],int numeroDescuentos){
    int opcionVentas;
    do{
    	system("cls");
   		setColor(14);
    	cout<<"==============================="<<endl;
    	setColor(15);
        cout<<"       ";
        setColor(15);
		cout<<"Menu de Ventas";
		setColor(14);
		cout<<"       "<<endl;
        setColor(14);
      	cout<<"==============================="<<endl;
      	setColor(14);
        cout<<"1.";
        setColor(7);
		cout<<" Registrar una venta "<<endl;
		setColor(14);
        cout<<"2.";
        setColor(7);
		cout<<" Mostrar ventas"<<endl;
		setColor(14);      
        cout<<"3.";
        setColor(7);
		cout<<" Mostrar ganancias"<<endl;
		setColor(14);
		cout<<"4.";
        setColor(7);
		cout<<" Producto mas vendido"<<endl;
		setColor(14);      
        cout<<"5.";
        setColor(7);
		cout<<"Eliminar venta"<<endl;
		setColor(14);      
        cout<<"0.";
        setColor(7);
		cout<<" Volver al menu principal"<<endl;
		setColor(14);
		cout<<endl<<"-> Ingrese una opcion: ";
        setColor(15);
    	cin>>opcionVentas;
    		
    	switch(opcionVentas)
    	{
    		case 1://llama a la funcion que permite registrar una venta,actualiza el inventario, y aplica los descuentos si es necesario
    			system("cls");
    			registrarVenta(ventas, numeroVenta, articulo, numeroProducto, descuentos, numeroDescuentos);
    			system("pause"); 
				break; 		
    		case 2://llama a la funcion que muestra las ventas realizadas
    			system("cls");
    			mostrarVentas(ventas, numeroVenta);
    			system("pause");    		 
    			break;
    		case 3://Se llama a la funcion que muestra las ganancias 
    			system("cls");
    			mostrarGanancias(ventas, numeroVenta);  	
    	 		system("pause");
    			break;  
			case 4://Se llama a la funcion que muestra las ganancias 
		    system("cls");
				productoMasVendido(ventas, numeroVenta, articulo, numeroProducto);	
				system("pause");		 
    			break;
    		case 5:
    			system("cls");
    			eliminarVenta(ventas,  numeroVenta);
    			system("pause");
    			break;
			case 0://Se vuelve al menu principal
            	break; 			
            default://Se muestra un mensaje de error al no 
            	setColor(12);
            	cout<<endl<<"Opcion no valida."<<endl<<endl;
            	setColor(15);
            	system("pause");
           		break;
    	}
	}while(opcionVentas!=0);//El menu de ventas
			
}	


void registrarVenta(gestionDeventas ventas[],int &numeroVenta,producto articulo[], int &numeroProducto,const descuento descuentos[],int numeroDescuentos){
    bool productoEncontrado = false; 
	if (numeroVenta < maximasVentas) {
        gestionDeventas temporal;
        setColor(14);      
        cout<<"*.";
        setColor(7);
        cout << "Ingrese el nombre del producto: ";
        cin >> temporal.nombreProducto;

        for (int i = 0; i < numeroProducto; i++) {
            if (temporal.nombreProducto == articulo[i].nombre) {
       	        setColor(14);      
       	 		cout<<"*.";
        		setColor(7);
                cout << "Ingrese la cantidad: ";
                cin >> temporal.cantidad;

                if (temporal.cantidad <= articulo[i].cantidad) {
                	temporal.id = articulo[i].id;
                    ventas[numeroVenta] = temporal;
                    articulo[i].cantidad -= temporal.cantidad;
                    
                    float precioSinDescuento = temporal.cantidad * articulo[i].precio;
                    float descuento = calcularDescuento(precioSinDescuento, temporal.cantidad, descuentos, numeroDescuentos);
                    ventas[numeroVenta].precioTotal = precioSinDescuento - descuento;
                    setColor(14);      
       				cout<<"*.";
        			setColor(7);
                    cout << "El precio total es: $" << ventas[numeroVenta].precioTotal<<" con un descuento de: "<<descuento<<endl;
                    setColor(11);
                    cout << "+++ Venta registrada correctamente." << endl;
                    setColor(15);
                    numeroVenta++;
                } else {
                	setColor(12);
                    cout << "*** No hay suficiente cantidad de " << temporal.nombreProducto << " en el inventario." << endl;
                    setColor(15);
                }               
        
                productoEncontrado=true;
                break; 
        	}
        	
			
		}
		if(!productoEncontrado)
		{
			setColor(12);
			cout<<"*** NO EXISTE"<<endl;
			setColor(15);
		}
    }
    else
    {
    	setColor(12);
    	cout << "*** No hay productos para registrar una venta o limite de ventas alcanzado" << endl;
    	setColor(15);
	}
	
    		
}

void mostrarVentas(gestionDeventas ventas[], int numeroVenta ){
	if (numeroVenta==0){
		setColor(12);
        cout<<"*** No hay ventas registradas.\n"<<endl;
        setColor(15);
        
    }else{
		setColor(14);
      	cout<<"==============================="<<endl;
      	setColor(15);
        cout<<"--- Ventas registradas ---"<<endl;
        setColor(14);
      	cout<<"==============================="<<endl;
      	setColor(15);
        for (int i = 0; i < numeroVenta; ++i){
        	setColor(14);
        	cout<<"*. ";
        	setColor(7);
            cout<<"ID del producto: "<<ventas[i].id<<", Nombre: "<<ventas[i].nombreProducto<<", Cantidad: $"<<ventas[i].cantidad<<", Precio total: $"<<ventas[i].precioTotal<<endl;
            cout<<endl;
        }
        
    }	
}
void mostrarGanancias(gestionDeventas ventas[], int& numeroVenta)
{
	if(numeroVenta == 0)
	{
		setColor(12);
		cout<<"*** No hay ganancias registradas."<<endl;
		setColor(15);
	}
	else
	{
		int sumaTotal=0;
		setColor(14);
        cout<<"*.";
        setColor(7);
		cout<<"La cantidad total de ventas realizadas: "<<numeroVenta<<endl;
		for (int i=0; i<numeroVenta; i++ )
		{
			sumaTotal+=ventas[i].precioTotal;
		}
		setColor(14);
        cout<<"*.";
        setColor(7);
		cout<<"Ganancia total de las ventas realizadas: $ "<<sumaTotal<<endl;
		cout<<endl;
	}
}
void productoMasVendido(gestionDeventas ventas[], int& numeroVenta, producto articulo[], int& numeroProducto)
{
	if(numeroVenta == 0)
	{
		setColor(12);
		cout<<"*** No se registro ninguna venta."<<endl;
		setColor(15);
	}
	else
	{
		int ventaMaxima=0;
		for(int i = 0; i < numeroVenta ; i++){
		
			if(ventas[i].cantidad > ventaMaxima)
			{	
				ventaMaxima = ventas[i].cantidad;			
			}		
		}
		setColor(14);
      	cout<<"=========================================="<<endl;
      	setColor(14);
		cout << "El/Los productos mas vendidos fueron:\n" << endl;
		setColor(14);
      	cout<<"=========================================="<<endl;
      	setColor(14);
	    bool encontrado = false;
	    for (int i = 0; i < numeroProducto; ++i) {
	        int cantidadVendida = 0;
    	    for (int j = 0; j < numeroVenta; ++j) {
    	        if (ventas[j].nombreProducto == articulo[i].nombre) {
            	
    	            cantidadVendida += ventas[j].cantidad;
        	    }
       	 	}
        	if (cantidadVendida == ventaMaxima) {
        	    encontrado = true;
        	    setColor(14);
      			cout<<"*. "<<endl;
      			setColor(7);
        	    cout << "Nombre: " << articulo[i].nombre << endl;
        	    cout << "ID del producto: " << articulo[i].id << ", Precio: $" << articulo[i].precio << ", Cantidad en inventario: " << articulo[i].cantidad << ", Cantidad vendida: " << cantidadVendida << endl;
        	    cout << endl;
        	}
    	}

    	if (!encontrado) {
    		setColor(12);
    	    cout << "*** No se encontraron productos más vendidos." << endl;
    	    setColor(15);
    	}
	}
}
void eliminarVenta(gestionDeventas ventas[], int& numeroVenta)
{
	if(numeroVenta==0)
	{
		setColor(12);
		cout<<"*** No hay una venta registrada."<<endl;
		setColor(15);
	}
	else
	{
		string nombreAEliminar;
		setColor(14);
		cout<<"*. ";
		setColor(15);
		cout<<"Escriba el nombre del producto: ";
		cin.ignore();
		getline(cin, nombreAEliminar);
		int ultimoIndice=-1;
		for (int i = numeroVenta - 1; i >= 0; i--) {
            if (ventas[i].nombreProducto == nombreAEliminar) {
                ultimoIndice = i;
                break;
            }
        }
        if (ultimoIndice != -1) {
            // Eliminar la venta en el índice encontrado
            for (int i = ultimoIndice; i < numeroVenta - 1; i++) {
                ventas[i] = ventas[i + 1];
            }
            numeroVenta--;  // Decrementa el número de ventas
            ventas[numeroVenta] = {};  // Limpia la última posición
			setColor(14);
			cout<<"*. ";
			setColor(7);
            cout << "Última venta del producto '" << nombreAEliminar << "' eliminada." << endl;
        } else {
        	setColor(12);
            cout << "No se encontraron ventas para el producto '" << nombreAEliminar << "'." << endl;
            setColor(15);
        }
    }
}

void MenuReclamos(reclamo quejas[], int &numeroReclamo, int &siguienteIDReclamo){
	int opcionReclamo;
	do {
    	system("cls");
    	setColor(14);
    	cout<<"==============================="<<endl;
    	setColor(15);
        cout<<"       ";
        setColor(15);
		cout<<"Menu de Reclamos";
		setColor(14);
		cout<<"       "<<endl;
        setColor(14);
      	cout<<"==============================="<<endl;
      	setColor(14);
        cout<<"1.";
        setColor(7);
		cout<<" Agregar reclamo "<<endl;
		setColor(14);
        cout<<"2.";
        setColor(7);
		cout<<" Eliminar reclamo"<<endl;
		setColor(14);      
        cout<<"3.";
        setColor(7);
		cout<<" Mostrar reclamos"<<endl;
		setColor(14);
        cout<<"0.";
        setColor(7);
		cout<<" Volver al menu principal"<<endl;
		setColor(14);
		cout<<endl<<"-> Ingrese una opcion: ";
        setColor(15);
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
            case 0:
                break;
            default:
            	setColor(12);
                cout<<endl<<"Opcion no valida."<<endl<<endl;
                setColor(15);
                system("pause");
        }
    }while(opcionReclamo!=0);
 
}
void agregarReclamo(reclamo quejas[], int &numeroReclamo, int &siguienteIDReclamo){
    if (numeroReclamo<maximosReclamos){
        reclamo auxiliar;
        auxiliar.id=siguienteIDReclamo++;
        setColor(14);
        cout<<"*. ";
        setColor(15);
        cout<<"Ingrese la descripcion del reclamo: ";
        cin.ignore();
        getline(cin,auxiliar.descripcion);
        quejas[numeroReclamo++]=auxiliar;
        setColor(2);
        cout<<"+++ Reclamo agregado correctamente"<<endl;
        setColor(15);
    } else {
    	setColor(12);
        cout<<"*** Limite de reclamos alcanzados"<<endl;
        setColor(15);
    }
}
void eliminarReclamo(reclamo quejas[], int &numeroReclamo){
    int indice=-1;
    int id;
    setColor(14);
    cout<<"*. ";
    setColor(15);
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
        setColor(11);
        cout<<"--- Reclamo eliminado exitosamente."<<endl;
        setColor(15);
    } else {
    	setColor(12);
        cout<<"*** Reclamo no encontrado."<<endl;
        setColor(15);
    }
}
void mostrarReclamos(const reclamo quejas[], int numeroReclamo){
    if (numeroReclamo==0){
    	setColor(12);
        cout<<"*** No hay reclamos."<<endl;
        setColor(15);
    } else {
        for (int i=0;i<numeroReclamo;++i){
        	setColor(14);
        	cout<<"*. ";
        	setColor(15);
            cout<<"ID: "<<quejas[i].id<<", Descripcion: "<<quejas[i].descripcion<<endl;
        }
    }
}

float calcularDescuento(float precioTotal, int cantidad, const descuento descuentos[], int numeroDescuentos) {
    float descuentoMaximo=0.0;
     for (int i=0;i<numeroDescuentos;++i) {
        if (precioTotal>=descuentos[i].precioMinimo && cantidad>=descuentos[i].cantidadMinima){
            float descuentoActual=precioTotal  * (descuentos[i].porcentaje/100);
            if (descuentoActual>descuentoMaximo){
                descuentoMaximo=descuentoActual;
            }
        }
    }
    return descuentoMaximo;
}
void MenuDescuentos(descuento descuentos[], int &numeroDescuentos,int &siguienteIDDescuento){
    int opcionDescuentos;
    do {
        system("cls");
    	setColor(14);
    	cout<<"==============================="<<endl;
    	setColor(15);
        cout<<"       ";
        setColor(15);
		cout<<"Menu de Descuentos";
		setColor(14);
		cout<<"       "<<endl;
        setColor(14);
      	cout<<"==============================="<<endl;
      	setColor(14);
        cout<<"1.";
        setColor(7);
		cout<<" Agregar descuento "<<endl;
		setColor(14);
        cout<<"2.";
        setColor(7);
		cout<<" Eliminar descuento"<<endl;
		setColor(14);      
        cout<<"3.";
        setColor(7);
		cout<<" Mostrar descuentos"<<endl;
		setColor(14);
        cout<<"0.";
        setColor(7);
		cout<<" Volver al menu principal"<<endl;
		setColor(14);
		cout<<endl<<"-> Ingrese una opcion: ";
        setColor(15);
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
                	setColor(12);
                    cout<<endl<<"Opcion no valida."<<endl<<endl;
                    setColor(15);
                    system("pause");
                    break;
                    }
    }while(opcionDescuentos!=0);
}

void agregarDescuento(descuento descuentos[], int &numeroDescuentos,int &siguienteIDDescuento){
    if (numeroDescuentos<maximosDescuentos){
        descuento nuevoDescuento;//se crea una nuevo descuento con la estructura descuento, y se ingresan sus variables
        nuevoDescuento.id=siguienteIDDescuento++;
        setColor(14);
        cout<<"*. ";
        setColor(15);
		cout<<"Ingrese el precio minimo para el descuento: ";
        cin>>nuevoDescuento.precioMinimo;
        setColor(14);
        cout<<"*. ";
        setColor(15);
        cout<<"Ingrese la cantidad minima para el descuento: ";
        cin>>nuevoDescuento.cantidadMinima;
        setColor(14);
        cout<<"*. ";
        setColor(15);
        cout<<"Ingrese el porcentaje de descuento: ";
        cin>>nuevoDescuento.porcentaje;
        descuentos[numeroDescuentos++]=nuevoDescuento;//Se agrega el nuevo descuento y se aumenta la cantidad de descuentos
        setColor(11);
        cout<<"+++ Descuento agregado exitosamente"<<endl;
        setColor(15);
    }else{//Se muestra un enunciado al llegar al  limite de descuentos 
    	setColor(12);
        cout<<"*** Limite de descuentos alcanzados"<<endl;
        setColor(15);
    }
}
//Funcion para eliminar un descuento agregado
void eliminarDescuento(descuento descuentos[], int &numeroDescuentos){
    if (numeroDescuentos==0){//Si no hay ningun descuento registrado se muestra un enunciado
        setColor(12);
        cout<<"No hay descuentos para eliminar"<<endl;
        setColor(15);
		return;
    }
    int idAuxiliar;//se crea una variable 
    setColor(14);
    cout<<"*. ";
    setColor(15);
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
            setColor(11);
            cout<<"--- Descuento eliminado exitosamente"<<endl;
            setColor(15);
            break;
        }
    }
    if (!encontrado){
    	setColor(12);
        cout<<"*** Descuento no encontrado"<<endl;
        setColor(15);
    }
}

// Función para mostrar los descuentos
void mostrarDescuentos(const descuento descuentos[], int numeroDescuentos) {
    if (numeroDescuentos==0){//Muestra un enunciado si no hay ningun descuento agregado
    	setColor(12);
        cout<<"*** No hay descuentos disponibles."<<endl;
        setColor(15);
        return;
    }
    setColor(14);
    cout<<"==============================="<<endl;
    setColor(15);
    cout<<"--- Descuentos disponibles ---"<<endl;//Se muestra los descuentos
    setColor(14);
    cout<<"==============================="<<endl;
    setColor(15);
    for (int i=0;i<numeroDescuentos;++i){//Se usa un for para mostrar todos los descuentos registrados
    	setColor(14);
    	cout<<"*. ";
    	setColor(15);
        cout<<"ID del descuento: "<<descuentos[i].id//Id del descuento
			<<", precio para el descuento: $"<<descuentos[i].precioMinimo//precio minimo para el descuento
            <<", Cantidad para el descuento: "<<descuentos[i].cantidadMinima//cantidad minima para el descuento
            <<", Porcentaje del descuento: "<<descuentos[i].porcentaje<<"%"<<endl;//Descuento registrado previamente
    }
}



void inicializarDatos(producto articulo[], int &numeroProducto, reclamo quejas[], int &numeroReclamo, descuento descuentos[], int &numeroDescuentos, gestionDeventas ventas[], int &numeroVenta,const string& categoria) {
    // Inicializar productos predefinidos
   //productos predeterminados de la categoria vestimenta
	articulo[0].id = 1;
    articulo[0].nombre = "Zapatillas";
    articulo[0].precio = 20;
    articulo[0].categoria="Vestimenta";
    articulo[0].cantidad = 25;
    
    articulo[1].id = 2;
    articulo[1].nombre = "Casaca";
    articulo[1].precio = 50;
    articulo[1].categoria="Vestimenta";
    articulo[1].cantidad = 10;

    articulo[2].id = 3;
    articulo[2].nombre = "Pantalon";
    articulo[2].precio = 30;
    articulo[2].categoria="Vestimenta";
    articulo[2].cantidad = 20;

    articulo[3].id = 4;
    articulo[3].nombre = "Blusa";
    articulo[3].precio = 20;
    articulo[3].categoria="Vestimenta";
    articulo[3].cantidad = 30;
    
    
    //productos predeterminados de la categoria Lacteos
	articulo[4].id = 5;
    articulo[4].nombre = "Mantequilla";
    articulo[4].precio = 5;
    articulo[4].categoria="Lacteos";
    articulo[4].cantidad = 25;

    articulo[5].id = 6;
    articulo[5].nombre = "Yogurt";
    articulo[5].precio = 6.5;
    articulo[5].categoria="Lacteos";
    articulo[5].cantidad = 10;

    articulo[6].id = 7;
    articulo[6].nombre = "Leche";
    articulo[6].precio = 2.5;
    articulo[6].categoria="Lacteos";
    articulo[6].cantidad = 20;

    articulo[7].id = 8;
    articulo[7].nombre = "Queso";
    articulo[7].precio = 20;
    articulo[7].categoria="Lacteos";
    articulo[7].cantidad = 30;

    //productos predeterminados de la categoria Mobiliario
	articulo[8].id = 9;
    articulo[8].nombre = "Sillas";
    articulo[8].precio = 75;
    articulo[8].categoria="Mobiliario";
    articulo[8].cantidad = 25;

    articulo[9].id = 10;
    articulo[9].nombre = "Mesa";
    articulo[9].precio = 110;
    articulo[9].categoria="Mobiliario";
    articulo[9].cantidad = 10;

    articulo[10].id = 11;
    articulo[10].nombre = "Sofa";
    articulo[10].precio = 400;
    articulo[10].categoria="Mobiliario";
    articulo[10].cantidad = 20;

    articulo[11].id = 12;
    articulo[11].nombre = "Cama";
    articulo[11].precio = 150;
    articulo[11].categoria="Mobiliario";
    articulo[11].cantidad = 30;

    //productos predeterminados de la categoria Alimentos y Bebidas
	articulo[12].id = 13;
    articulo[12].nombre = "Atun";
    articulo[12].precio = 6;
    articulo[12].categoria="Alimentos y Bebidas";
    articulo[12].cantidad = 25;

    articulo[13].id = 14;
    articulo[13].nombre = "Gaseosa";
    articulo[13].precio = 6;
    articulo[13].categoria="Alimentos y Bebidas";
    articulo[13].cantidad = 10;

    articulo[14].id = 15;
    articulo[14].nombre = "Jugo";
    articulo[14].precio = 6;
    articulo[14].categoria="Alimentos y Bebidas";
    articulo[14].cantidad = 20;

    articulo[15].id = 16;
    articulo[15].nombre = "Ramen";
    articulo[15].precio = 15;
    articulo[15].categoria="Alimentos y Bebidas";
    articulo[15].cantidad = 30;

    //productos predeterminados de la categoria Limpieza e Higiene
	articulo[16].id = 17;
    articulo[16].nombre = "Poett";
    articulo[16].precio = 20;
    articulo[16].categoria="Limpieza e Higiene";
    articulo[16].cantidad = 25;

    articulo[17].id = 18;
    articulo[17].nombre = "Ayudin";
    articulo[17].precio = 5.5;
    articulo[17].categoria="Limpieza e Higiene";
    articulo[17].cantidad = 10;

    articulo[18].id = 19;
    articulo[18].nombre = "Jabon";
    articulo[18].precio = 2.5;
    articulo[18].categoria="Limpieza e Higiene";
    articulo[18].cantidad = 20;

    articulo[19].id = 20;
    articulo[19].nombre = "Shampoo";
    articulo[19].precio = 10;
    articulo[19].categoria="Limpieza e Higiene";
    articulo[19].cantidad = 30;

    //productos predeterminados de la categoria Automotriz
	articulo[20].id = 21;
    articulo[20].nombre = "Llantas";
    articulo[20].precio = 25;
    articulo[20].categoria="Automotriz";
    articulo[20].cantidad = 25;

    articulo[21].id = 22;
    articulo[21].nombre = "Lubricante";
    articulo[21].precio = 20;
    articulo[21].categoria="Automotriz";
    articulo[21].cantidad = 10;

    articulo[22].id = 23;
    articulo[22].nombre = "Cintas";
    articulo[22].precio = 8;
    articulo[22].categoria="Automotriz";
    articulo[22].cantidad = 20;

    articulo[23].id = 24;
    articulo[23].nombre = "Laminas";
    articulo[23].precio = 6;
    articulo[23].categoria="Automotriz";
    articulo[23].cantidad = 30;

	//productos predeterminados de la categoria Mascotas
	articulo[24].id = 25;
    articulo[24].nombre = "Cepillo";
    articulo[24].precio = 20;
    articulo[24].categoria="Mascotas";
    articulo[24].cantidad = 25;

    articulo[25].id = 26;
    articulo[25].nombre = "Ropa para perro";
    articulo[25].precio = 30;
    articulo[25].categoria="Mascotas";
    articulo[25].cantidad = 10;

    articulo[26].id = 27;
    articulo[26].nombre = "Comida para perro";
    articulo[26].precio = 30;
    articulo[26].categoria="Mascotas";
    articulo[26].cantidad = 20;

    articulo[27].id = 28;
    articulo[27].nombre = "Collares";
    articulo[27].precio = 8;
    articulo[27].categoria="Mascotas";
    articulo[27].cantidad = 30;

	//productos predeterminados de la categoria Electrodomesticos
	articulo[28].id = 29;
    articulo[28].nombre = "Licuadora";
    articulo[28].precio = 50;
    articulo[28].categoria="Electrodomesticos";
    articulo[28].cantidad = 25;

    articulo[29].id = 30;
    articulo[29].nombre = "Batidora";
    articulo[29].precio = 75;
    articulo[29].categoria="Electrodomesticos";
    articulo[29].cantidad = 10;

    articulo[30].id = 31;
    articulo[30].nombre = "Aspiradora";
    articulo[30].precio = 150;
    articulo[30].categoria="Electrodomesticos";
    articulo[30].cantidad = 20;

    articulo[31].id = 32;
    articulo[31].nombre = "Hervidor electrico";
    articulo[31].precio = 200;
    articulo[31].categoria="Electrodomesticos";
    articulo[31].cantidad = 30;

    // Inicializar productos predefinidos Electronica y Tecnologia
    articulo[32].id = 33;
    articulo[32].nombre = "Smartphone";
    articulo[32].precio = 800;
    articulo[32].categoria="Electronica y Tecnologia";
    articulo[32].cantidad = 25;

    articulo[33].id = 34;
    articulo[33].nombre = "Laptop";
    articulo[33].precio = 1200;
    articulo[33].categoria="Electronica y Tecnologia";
    articulo[33].cantidad = 10;

    articulo[34].id = 35;
    articulo[34].nombre = "Tablet";
    articulo[34].precio = 600;
    articulo[34].categoria="Electronica y Tecnologia";
    articulo[34].cantidad = 15;
	
	articulo[35].id = 36;
    articulo[35].nombre = "Smartwatch";
    articulo[35].precio = 300;
    articulo[35].categoria="Electronica y Tecnologia";
    articulo[35].cantidad = 30;
    
    articulo[36].id = 37;
    articulo[36].nombre = "Auriculares";
    articulo[36].precio = 150;
    articulo[36].categoria="Electronica y Tecnologia";
    articulo[36].cantidad = 50;

    numeroProducto = 37;
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
    descuentos[0].id=1;
    descuentos[0].precioMinimo=100;
    descuentos[0].cantidadMinima = 2;
    descuentos[0].porcentaje = 10;

	descuentos[1].id=2;
    descuentos[1].precioMinimo = 1000;
    descuentos[1].cantidadMinima = 1;
    descuentos[1].porcentaje = 15;

	descuentos[2].id=3;
    descuentos[2].precioMinimo = 150;
    descuentos[2].cantidadMinima = 3;
    descuentos[2].porcentaje = 5;

	descuentos[3].id=4;
    descuentos[3].precioMinimo = 2000;
    descuentos[3].cantidadMinima = 1;
    descuentos[3].porcentaje = 20;

	descuentos[4].id=5;
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
    ventas[4].nombreProducto = "Auriculares";
    ventas[4].cantidad = 5;
    ventas[4].precioTotal = 712.5; // Descuento aplicado: 37.5 (5%)

	ventas[5].id = 6;
    ventas[5].nombreProducto = "Atun";
    ventas[5].cantidad = 6;
    ventas[5].precioTotal = 36; 

	ventas[6].id = 7;
    ventas[6].nombreProducto = "Blusa";
    ventas[6].cantidad = 3;
    ventas[6].precioTotal = 60;

    ventas[7].id = 8;
    ventas[7].nombreProducto = "Sillas";
    ventas[7].cantidad = 4;
    ventas[7].precioTotal = 300;
    numeroVenta = 8;
}

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}