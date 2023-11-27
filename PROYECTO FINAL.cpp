/*
Programa: Proyecto final - Sistema de gestión de inventario y ventas 
Autores: Andrés Felipe Rondón Lara - Andres Felipe Perez Motta - Andres Felipe Tovar Molina
Fecha: 27 de noviembre de 2023
*/
// Declaramos variables
#include <iostream>
#include <locale.h>
#include <string>
#include <sstream> 
#include <cstdlib> 

using namespace std;

// Struct para registrar los productos
struct tienda{
	int Codigo;
	string Nombre;
	int Valor;
	int Cantidad;
};


// Struct para registar las ventas 
struct venta {
    int Codigo;
    int CodigoCliente;
    string NombreCliente;
    string ApellidoCliente;
    string CorreoCliente;
    string Productos[10]; // Arreglo para nombres de productos vendidos
    int Cantidades[10];   // Arreglo para cantidades vendidas por producto
    int Codigos[10];  // Arreglo para los códigos de los productos vendidos
    int ValoresU[10];  // Arreglo para los valores unitarios por producto
    int CantidadProductos; // Almacena la cantidad actual de productos en la venta
    double ValorTotal;
};


// Struct para registrar las devoluciones
struct devolu {
    int CodigoDeVenta;
    int CodigoDeDevolucion;
    string Nombre;
    int Valor;
    int Cantidad;
};

// Incluimos funciones que utilizaremos para la ejecucuión del programa
void unistore();
bool esEntero(const string& str);
int obtenerEnteroValido(const string& mensaje);

// Funciones para los productos
int creaProduc(tienda* articulos, int contador);
void printProduc(tienda* articulos, int contador);
void addExist(tienda* articulos, int contador);

// Funciones para las ventas
int nuevaVenta(tienda* articulos, int contador, venta* moremo, int contador2);
void printVenta(venta* moremo, int contador2, tienda* articulos, int contador);

// Funciones para las devoluciones
int devolver(tienda* articulos, int contador, venta* moremo, int contador2, devolu* lessmo, int contador3);
void printDevo(devolu* lessmo, int contador3);




// <<------------------------------ Inicio del programa ----------------------------------->> 
int main(){
	setlocale(LC_ALL, ""); // Esta orden permite los caracteres especiales
	system("cls");
	// Se invoca la función de la portada del programa
	system("color 6");
	unistore();
	system ("pause");
	system("cls");
	
	// Creamos un arreglo para los productos de la tienda
	tienda* articulos = new tienda[100];
	// Creamos un arreglo para las ventas de la tienda
	venta* moremo = new venta[200]; //moremo = more money = mas dinero
	// Creamos un arreglo para las devoluciones de la tienda
	devolu* lessmo = new devolu[100]; //lessmo = less money = menos dinero
    // Declaramos variables que se usaran en el programa
	int contador = 0;
    int contador2 = 0;
    int contador3 = 0;
    int contador4 = 0;
	// Se ejecuta el menú principal que vera el usuario en pantalla 
	system("color 3F");
	cout<<"\t\t         **********************************************************************         \n";
	cout<<"\t\t       **************************************************************************       \n";
	cout<<"\t\t     ******************************************************************************     \n";
	cout<<"\t\t   ************                                                          ************   \n";
	cout<<"\t\t *************         ¡¡¡BIENVENIDO A LA GESTIÓN DE UNISTORE!!!          ************* \n";
	cout<<"\t\t   ************                                                          ************   \n";
	cout<<"\t\t     ******************************************************************************     \n";
	cout<<"\t\t       **************************************************************************       \n";
	cout<<"\t\t         **********************************************************************         \n";
    cout<<endl<<endl;
    int menu;
    // Se ingresa el menú principal
    do{
    	cout<<"\t\t¿Que deseas hacer hoy? \n";
    	cout<<endl;
		cout<<"\t\tRevisar tus productos \n";
		cout<<"\t1. Crear producto. \n";
		cout<<"\t2. Lista de productos. \n";
		cout<<"\t3. Añadir existencia a un producto. \n";
		cout<<endl;
		cout<<"\t\tVentas\n";
		cout<<"\t4. Registrar una nueva venta. \n ";
		cout<<"\t5. Registro de ventas. \n";
		cout<<endl;
		cout<<"\t\tDevoluciones\n";
		cout<<"\t6. Registra una nueva devolución\n";
		cout<<"\t7. Registro de devoluciones\n";
		cout<<endl;
		cout<<"\t\tFin del programa\n";
		cout<<"\t8. Salir\n"<<endl;
		menu = obtenerEnteroValido("Por favor, ingresa una opción: ");
		cout<<endl<<endl;
		// Se limitan las respuestas del usuario
	    while (menu<0||menu>8){
	    	cout<<"La opción que seleccionaste no se encuentra en el menú \n";
	    	menu = obtenerEnteroValido("Por favor, selecciona una opción válida \n");
		}
		cout<<"\t\tSiempre disponible para ayudarte :D\n";
		// Se ejecutan las distintas opciones que pudo elegir el usuario en el menú principal
		switch(menu){
	    	case 1:
	    		system ("color 70");
	    		system ("cls");
	    		cout<<"\t\t¡¡Crear producto!! \n"<<endl;
	    		contador= creaProduc( articulos, contador); // Se invoca la función
	    		cout<<endl;
	    		system("cls");
	    		system("color 3F");
    			break;
	    	case 2:
	    		system ("color 70");
	    		system ("cls");
	    		cout<<"\t\t¡¡Listar los productos!! \n" <<endl;
	    		printProduc( articulos, contador); // Se invoca la función
	    		cout<<endl;
	    		system("pause");
	    		system("cls");
	    		system("color 3F");
	    		break;
	    	case 3:
	    		do{
		    		system ("color 70");
		    		system ("cls");
		    		cout<<"\t\t¡¡Añadir existencia a un producto!! \n";
		    		addExist( articulos, contador); // Se invoca la función
		    		cout<<endl;
		    		system("pause");
		    		system("cls");
		    		system("color 70");
		    		int continuar = obtenerEnteroValido("\t\t\n\n¿Desea agregar existencias para otro producto? (cualquier número para sí, 0 para no): ");
			        system("cls");
			        if (continuar == 0) {
			            break;
			        }
        	    } while (true);
	    		system("cls");
	    		system("color 3F");
    			break;
	    	case 4:
	    		do{
		    		system ("color 70");
		    		system ("cls");
		    		cout<<"\t\t!!Registrar una nueva venta!! \n";
					contador2 = nuevaVenta( articulos, contador, moremo, contador2); // Se invoca la función
		    		cout<<endl;
		    		system("pause");
		    		system("cls");
		    		system("color 70");
		    		int continuar = obtenerEnteroValido("\t\t\n\n¿Desea registrar otra venta? (cualquier número para sí, 0 para no): ");
			        system("cls");
			        if (continuar == 0) {
			            break;
			        }
        	    } while (true);
	    		system("cls");
	    		system("color 3F");
	    		break;
	    	case 5:
	    		system ("color 70");
	    		system ("cls");
	    		cout<<"\t\t¡¡Registro de ventas!! \n";
	    		printVenta( moremo, contador2, articulos, contador); // Se invoca la función
	    		cout<<endl;
	    		system("pause");
	    		system("cls");
	    		system("color 3F");
	    		break;
	    	case 6:
	    		do{
		    		system ("color 70");
		    		system ("cls");
		    		cout<<"\t\t!!Registrar una devolución!! \n";
		    		contador3 = devolver(articulos, contador, moremo, contador2, lessmo, contador3); // Se invoca la función
		    		cout<<endl;
		    		system("pause");
		    		system("cls");
		    		system("color 70");
		    		int continuar = obtenerEnteroValido("\t\t\n\n¿Desea registrar otra devolución? (cualquier número para sí, 0 para no): ");
			        system("cls");
			        if (continuar == 0) {
			            break;
			        }
        	    } while (true);
	    		system("cls");
	    		system("color 3F");
				break;
	    	case 7:
	    		system ("color 70");
	    		system ("cls");
	    		cout<<"\t\t¡¡Registro de devoluciones!! \n";
	    		printDevo( lessmo, contador3); // Se invoca la función
	    		cout<<endl;
	    		system("pause");
	    		system("cls");
	    		system("color 3F");
	    		break;
		}	
	}while (menu!=8);
	system("cls");
	system("color 6");
	// Se imprime en pantalla el final del programa
	cout<<"\t\t\t\t\t¡¡¡Sigue así, vas por buen camino!!!\n";
	unistore();
	cout<<"\t\t\t\tNos vemos en una próxima ocasión, éxitos :D\n"<<endl;
	system("pause");
	system("cls");
	
	// Se añaden los creditos del programa
	cout<<"\t\t\t¡¡¡ Créditos del programa !!!\n"<<endl;
	cout<<"\tAutores: Andrés Felipe Rondón - Andrés Felipe Perez - Andrés Felipe Tovar\n"<<endl;
	cout<<"\tIngeniería de sistemas\n"<<endl;
	cout<<"\tProgramación Básica 2023-3\n"<<endl;
	system("pause");
	return 0;
}


//<<-----------------------------------------Se desarrollan las funciones------------------------------------------------------------>>

// Función que retorna true si el número ingresado es entero	
bool esEntero(const string& str) {
    stringstream ss(str); // Un stringstream se utiliza para operar en cadenas como si fueran flujos de entrada/salida.
    int n;
    return (ss >> n) && ss.eof(); //Esto será verdadero si se pudo extraer un número entero de la cadena str y no hay nada más después del número.
}
// Función para validar que la entrada por consola sea entero
int obtenerEnteroValido(const string& mensaje) {
    string entrada;
    while (true) {
        cout << mensaje;
        cin >> entrada;
        if (esEntero(entrada)) {
            return atoi(entrada.c_str()); // Utiliza atoi para convertir la entrada a un entero y lo devuelve
        } else {
            cout << "Entrada no válida. Por favor, ingrese un número entero." << endl;
        }
    }
}

// Función que crea un nuevo producto
int creaProduc(tienda* articulos, int contador){
	while(true){
		tienda produ;
		cout << "Por favor ingrese la información del producto: " << endl;
	    produ.Codigo = obtenerEnteroValido("Código (número): ");
	    while(produ.Codigo <0){
	        produ.Codigo = obtenerEnteroValido("Ingrese un código válido: "); // Se verifican que no ingrese números negativos
		}
		//Revisar que el codigo ya exista
	    for (int i = 0; i < contador; i++) {
    		while( articulos[i].Codigo == produ.Codigo){
		        produ.Codigo = obtenerEnteroValido("El código ya está en uso. Por favor ingrese otro código: "); // Se verifican que no hayan codigos repetidos
			}
		}
		cin.ignore(); // Limpia el búfer de entrada
		cout << "Nombre: ";
	    getline(cin, produ.Nombre);
	    while (produ.Nombre.empty()) {
            cout << "Debe ingresar un nombre para el producto." << endl;
            cout << "Nombre: ";
            getline(cin, produ.Nombre);
        }
	    produ.Valor = obtenerEnteroValido("Valor unitario: ");
	    while (produ.Valor < 0) {
	        cout << "Ingrese un valor unitario válido: ";
	        produ.Valor = obtenerEnteroValido("Ingrese un valor unitario válido: "); // Se verifican que no ingrese números negativos
	    }
		produ.Cantidad = obtenerEnteroValido("Existencias: ");
	    while (produ.Cantidad < 0) {
	        produ.Cantidad = obtenerEnteroValido("Ingrese una catidad de existencias válida: "); // Se verifican que no ingrese números negativos
	    }
	    articulos[contador] = produ;
	    contador++;
	    
	    int continuar = obtenerEnteroValido("¿Desea agregar otro producto? (cualquier número para sí, 0 para no): "); // Se asume un agregar un nuevo producto sin volver al menú
		system("cls");
        if (continuar == 0) {
            break;
        }
	}
	return contador;
}

// Función que lista los productos ingresados
void printProduc(tienda* articulos, int contador){
	if(contador == 0){
		cout<<"No hay productos guardados."<< endl;
	}else{
	    cout << "Los productos guardados son:\n";
	    for (int i = 0; i < contador; i++) {
	    	cout<< endl;
	        cout << "\tCódigo: " << articulos[i].Codigo << endl;
			cout << "\tNombre: " << articulos[i].Nombre << endl;
			cout << "\tValor unitario: " << articulos[i].Valor;
			cout << endl << "\tExistencias: " << articulos[i].Cantidad<< endl; // Se imprimen los productos en pantalla
	    	cout<< endl;
		}
	}
}

// Función que añade existencias a productos
void addExist(tienda* articulos, int contador) {
    int cod;
    int nuevos;
    if (contador == 0) {
        cout << "No hay productos guardados." << endl;
        return; // Salir de la función si no hay productos
    }
    cod = obtenerEnteroValido("Ingrese el código del producto al que agregar existencias: ");
    for (int i = 0; i < contador; i++) {
        if (articulos[i].Codigo == cod) {
            cout << "El artículo de nombre " << articulos[i].Nombre << " tiene actualmente " << articulos[i].Cantidad << " existencias." << endl;
            nuevos = obtenerEnteroValido("¿Cuantas existencias le gustaría agregar? \n");
            while (nuevos < 0) {
                cout << "Cantidad incorrecta, solo se admiten valores positivos" << endl; // Se verifican que no ingrese números negativos
                nuevos = obtenerEnteroValido("¿Cuantas existencias le gustaría agregar?\n");
                cout << endl;
            }
            articulos[i].Cantidad += nuevos;
            cout << "El artículo de nombre " << articulos[i].Nombre << " ahora tiene " << articulos[i].Cantidad << " existencias." << endl;
            return; // Salir de la función después de actualizar las existencias
        }
    }
    cout << "El código ingresado no está asociado a ningún producto." << endl;
}

// Función para registrar una nueva venta y un posible nuevo cliente
int nuevaVenta(tienda* articulos, int contador, venta* moremo, int contador2) {
    venta compra;
    compra.CantidadProductos = 0;

    cout << "\nPor favor ingrese la información de la venta: " << endl;

    // Captura de los datos del cliente
    cout << "Por favor ingrese los datos del cliente: " << endl;
    compra.CodigoCliente = obtenerEnteroValido("Código del cliente (número): ");
    //Revisar que el codigo ya exista
    for (int i = 0; i < contador2; i++) {
		while( moremo[i].CodigoCliente == compra.CodigoCliente){
	        compra.CodigoCliente = obtenerEnteroValido("El código ya está en uso. Por favor ingrese otro código: "); // Se verifican que no hayan codigos repetidos
		}
	}
    cout << "Nombre del cliente: ";
    cin >> compra.NombreCliente;
    cout << "Apellido del cliente: ";
    cin >> compra.ApellidoCliente;
    cout << "Correo del cliente: ";
    cin >> compra.CorreoCliente;
	system("cls");
    // Captura de productos vendidos
    int continuar;
    do {
        int codigo;
        int cantidadProducto;

        codigo = obtenerEnteroValido("Código del producto (número): ");
	    while(codigo <0){
	        codigo = obtenerEnteroValido("Ingrese un código válido: "); // Se verifican que no ingrese números negativos
		}

        // Buscar el producto en el inventario
        bool encontrado = false;
        int indexProducto = -1;
        for (int i = 0; i < contador; ++i) {
            if (articulos[i].Codigo == codigo) {
                encontrado = true;
                cout << "El artículo de nombre " << articulos[i].Nombre << " tiene actualmente " << articulos[i].Cantidad << " existencias." << endl;
                indexProducto = i;
                break;
            }
        }

        if (!encontrado) {
            cout << "El producto ingresado no está en el inventario." << endl;
        } else {
            cantidadProducto = obtenerEnteroValido("Ingrese la cantidad vendida: ");
            // Verificar si la cantidad vendida es válida
            if (cantidadProducto > 0 && cantidadProducto <= articulos[indexProducto].Cantidad) {
                compra.Productos[compra.CantidadProductos] = articulos[indexProducto].Nombre;
                compra.Codigos[compra.CantidadProductos] = articulos[indexProducto].Codigo;
                compra.ValoresU[compra.CantidadProductos] = articulos[indexProducto].Valor;
                compra.Cantidades[compra.CantidadProductos] = cantidadProducto;
                articulos[indexProducto].Cantidad -= cantidadProducto; // Actualizar existencias
                compra.CantidadProductos++;

                cout << "Producto agregado a la venta." << endl;
            } else {
                cout << "La cantidad ingresada no es válida o supera las existencias del producto." << endl;
            }
        }

        continuar = obtenerEnteroValido("¿Desea agregar otro producto a la venta? (1 - Sí, 0 - No): ");
        system("cls");
    } while (continuar != 0);

    // Cálculo del valor total de la venta
    compra.ValorTotal = 0.0;
    for (int i = 0; i < compra.CantidadProductos; ++i) {
        int index = -1;
        for (int j = 0; j < contador; ++j) {
            if (articulos[j].Nombre == compra.Productos[i]) {
                index = j;
                break;
            }
        }
        compra.ValorTotal += compra.Cantidades[i] * articulos[index].Valor;
        cout << "Se vendieron " << compra.Cantidades[i] << " unidades de " << compra.Productos[i] << ", por un valor de " << articulos[index].Valor * compra.Cantidades[i] << ". Unidad a " << articulos[index].Valor << "." << endl;
    }
    
    if(compra.ValorTotal == 0){
    	return contador2;
	} else {
		cout << "El valor total de la venta fue de " << compra.ValorTotal;
		compra.Codigo = contador2 + 1;
	    moremo[contador2] = compra;
	    contador2++;
	
	    return contador2;
	}
}

// Función para imprimir en pantalla el total de ventas realizadas
void printVenta(venta* moremo, int contador2, tienda* articulos, int contador) {
    if (contador2 == 0) {
        cout << "No se han realizado ventas." << endl;
    } else {
        cout << "Se han realizado las siguientes ventas:\n\n";
        for (int i = 0; i < contador2; i++) {
            cout << "Número de venta: " << moremo[i].Codigo << endl;
            cout << "Código del cliente: " << moremo[i].CodigoCliente << endl;
            cout << "Nombre del cliente: " << moremo[i].NombreCliente << " " << moremo[i].ApellidoCliente << endl;
            cout << "Correo del cliente: " << moremo[i].CorreoCliente << endl;

            cout << "\nProductos vendidos:\n";
            for (int j = 0; j < moremo[i].CantidadProductos; ++j) {
                cout << "\tNombre: " << moremo[i].Productos[j] << endl;
                cout << "\tCantidad: " << moremo[i].Cantidades[j] << endl;

                // Buscar y mostrar el valor unitario del producto
                for (int k = 0; k < contador; ++k) {
                    if (articulos[k].Nombre == moremo[i].Productos[j]) {
                        cout << "\tValor unitario: " << articulos[k].Valor << endl;
                        cout << "\tValor: " << articulos[k].Valor * moremo[i].Cantidades[j] << endl;
                        break;
                    }
                }

                cout << endl;
            }

            cout << "Valor total de la venta: " << moremo[i].ValorTotal << endl;
            cout << endl;
        }
    }
}

// Función para registrar una nueva devolución
int devolver(tienda* articulos, int contador, venta* moremo, int contador2, devolu* lessmo, int contador3) {
    tienda produ;
    devolu regreso;
    venta compra;

    cout << "Por favor ingrese la información de la devolución: " << endl;
    regreso.CodigoDeVenta = obtenerEnteroValido("Código de la venta (número): ");
    while (regreso.CodigoDeVenta < 0) {
        regreso.CodigoDeVenta = obtenerEnteroValido("Ingrese un código válido: ");
    }

    // Buscar la venta asociada
    bool ventaEncontrada = false;
    int indiceVentaEncontrada = -1;  // Nuevo variable para almacenar el índice de la venta encontrada
    for (int i = 0; i < contador2; i++) {
        if (moremo[i].Codigo == regreso.CodigoDeVenta) {
            cout << "Se vendieron " << moremo[i].CantidadProductos << " productos en la venta asociada." << endl;
            compra = moremo[i];
            ventaEncontrada = true;
            indiceVentaEncontrada = i;  // Almacenar el índice de la venta encontrada
            break;
        }
    }

    if (!ventaEncontrada) {
        cout << "No se encontró la venta asociada al código ingresado." << endl;
        return contador3;
    }

    // Calcular la cantidad total devuelta hasta el momento para esta venta
    int devolucionesPrevias = 0;
    for (int i = 0; i < contador3; i++) {
        if (lessmo[i].CodigoDeVenta == regreso.CodigoDeVenta) {
            devolucionesPrevias += lessmo[i].Cantidad;
        }
    }

    int unidadesRestantes = compra.CantidadProductos - devolucionesPrevias;

    if (unidadesRestantes == 0) {
        cout << "No se pueden registrar más devoluciones para esta venta. Todos los productos vendidos ya han sido devueltos." << endl;
        return contador3;
    }

    // Restaurar las existencias de cada producto vendido
    for (int j = 0; j < compra.CantidadProductos; j++) {
        for (int k = 0; k < contador; k++) {
            if (articulos[k].Nombre == compra.Productos[j]) {
                articulos[k].Cantidad += compra.Cantidades[j];
            }
        }
    }

    // Registrar la devolución
    cout << "Productos vendidos en esta venta:" << endl;
    for (int i = 0; i < compra.CantidadProductos; i++) {
        cout << "Producto: " << compra.Productos[i] << ", Cantidad: " << compra.Cantidades[i] << ", Valor unitario: ";

        // Buscar y mostrar el valor unitario del producto
        for (int j = 0; j < contador; j++) {
            if (articulos[j].Nombre == compra.Productos[i]) {
                cout << articulos[j].Valor << ", Código: " << articulos[j].Codigo << "." << endl;
                break;
            }
        }
    }

    // Registrar la devolución para cada producto vendido
    
    cout << "Ingrese las unidades por regresar para cada producto:" << endl;
    for (int i = 0; i < compra.CantidadProductos; i++) {
        cout << "Producto: " << compra.Productos[i] << endl;
        regreso.Cantidad = obtenerEnteroValido("Cantidad: ");
        while (regreso.Cantidad < 0 || regreso.Cantidad > compra.Cantidades[i] - devolucionesPrevias) {
            regreso.Cantidad = obtenerEnteroValido("Ingrese una cantidad válida: ");
        }
		if(regreso.Cantidad > 0){
	        regreso.Nombre = compra.Productos[i];
	        regreso.Valor = compra.ValoresU[i] * regreso.Cantidad;
	        regreso.CodigoDeDevolucion = contador3 + 1;
	
	        cout << "Se regresaron " << regreso.Cantidad << " unidades de " << regreso.Nombre << endl;
	        cout << "El valor de la devolución para este producto es: " << regreso.Valor  << endl;
	
	        lessmo[contador3] = regreso;
	        contador3++;
	    }
    }

    // Actualizar la cantidad de productos vendidos en la venta original
    moremo[indiceVentaEncontrada].CantidadProductos -= contador3;

    return contador3;
}


// Función para imprimir en pantalla el total de devoluciones realizadas
void printDevo(devolu* lessmo, int contador3){
	if(contador3 == 0){
		cout<<"No hay devoluciones registradas."<< endl;
	}else{
	    cout << "Se han realizado las siguientes devoluciones:\n";
	    for (int i = 0; i < contador3; i++) {
	    	cout<< endl;
	        cout << "\tCódigo de devolución: " << lessmo[i].CodigoDeDevolucion << endl << "\tNombre: " << lessmo[i].Nombre << endl << "\tValor: " << lessmo[i].Valor << endl << "\tExistencias: " << lessmo[i].Cantidad<< endl; //Se imprimen las devoluciones en pantalla
	    	cout<< endl;
		}
	}
}


// Función para la presentación del programa
void unistore(){
	cout<<endl<<endl;
	cout<<"\t                            *****************              *****************                                  \n";
	cout<<"\t                            *****************              *****************                                  \n";
	cout<<"\t                            *****************              *****************                                  \n";
	cout<<"\t                                *********                      *********                                      \n";
	cout<<"\t                                *********                      *********                                      \n";
	cout<<"\t                                *********                      *********                                      \n";
	cout<<"\t                                *********                      *********                                      \n";
	cout<<"\t                                                                                                              \n";
	cout<<"\t ****    ****  ****       ***   *****  ************  ************  ************   ************  ************  \n";
	cout<<"\t ****    ****  *****      ***   *****  ************  ************  ************   ****    ****  ************  \n";
	cout<<"\t ****    ****  *** **     ***   *****  ****              ****      ****    ****   ****    ****  ****          \n";
	cout<<"\t ****    ****  ***  **    ***   *****  ************      ****      ****    ****   ************  ************  \n";
	cout<<"\t ****    ****  ***   **   ***   *****  ************      ****      ****    ****   **** ****     ************  \n";
	cout<<"\t ****    ****  ***    **  ***   *****          ****      ****      ****    ****   ****  ****    ****          \n";
	cout<<"\t ************  ***     ** ***   *****  ************      ****      ************   ****   ****   ************  \n";
	cout<<"\t ************  ***      *****   *****  ************      ****      ************   ****    ****  ************  \n";
	cout<<"\t                                                                                                              \n";
	cout<<"\t                                *********                      *********                                      \n";
	cout<<"\t                                *********                      *********                                      \n";
	cout<<"\t                                *********                      *********                                      \n";
	cout<<"\t                                *********                      *********                                      \n";
	cout<<"\t                                ****************************************                                      \n";
	cout<<"\t                                ****************************************                                      \n";
	cout<<"\t                                ****************************************                                      \n";
	cout<<endl<<endl;
}
