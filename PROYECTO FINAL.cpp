/*
Programa: Proyecto final - Sistema de gesti�n de inventario y ventas 
Autores: Andr�s Felipe Rond�n Lara - Andres Felipe Perez Motta - Andres Felipe Tovar Molina
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
    int Codigos[10];  // Arreglo para los c�digos de los productos vendidos
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

// Incluimos funciones que utilizaremos para la ejecucui�n del programa
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
	// Se invoca la funci�n de la portada del programa
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
	// Se ejecuta el men� principal que vera el usuario en pantalla 
	system("color 3F");
	cout<<"\t\t         **********************************************************************         \n";
	cout<<"\t\t       **************************************************************************       \n";
	cout<<"\t\t     ******************************************************************************     \n";
	cout<<"\t\t   ************                                                          ************   \n";
	cout<<"\t\t *************         ���BIENVENIDO A LA GESTI�N DE UNISTORE!!!          ************* \n";
	cout<<"\t\t   ************                                                          ************   \n";
	cout<<"\t\t     ******************************************************************************     \n";
	cout<<"\t\t       **************************************************************************       \n";
	cout<<"\t\t         **********************************************************************         \n";
    cout<<endl<<endl;
    int menu;
    // Se ingresa el men� principal
    do{
    	cout<<"\t\t�Que deseas hacer hoy? \n";
    	cout<<endl;
		cout<<"\t\tRevisar tus productos \n";
		cout<<"\t1. Crear producto. \n";
		cout<<"\t2. Lista de productos. \n";
		cout<<"\t3. A�adir existencia a un producto. \n";
		cout<<endl;
		cout<<"\t\tVentas\n";
		cout<<"\t4. Registrar una nueva venta. \n ";
		cout<<"\t5. Registro de ventas. \n";
		cout<<endl;
		cout<<"\t\tDevoluciones\n";
		cout<<"\t6. Registra una nueva devoluci�n\n";
		cout<<"\t7. Registro de devoluciones\n";
		cout<<endl;
		cout<<"\t\tFin del programa\n";
		cout<<"\t8. Salir\n"<<endl;
		menu = obtenerEnteroValido("Por favor, ingresa una opci�n: ");
		cout<<endl<<endl;
		// Se limitan las respuestas del usuario
	    while (menu<0||menu>8){
	    	cout<<"La opci�n que seleccionaste no se encuentra en el men� \n";
	    	menu = obtenerEnteroValido("Por favor, selecciona una opci�n v�lida \n");
		}
		cout<<"\t\tSiempre disponible para ayudarte :D\n";
		// Se ejecutan las distintas opciones que pudo elegir el usuario en el men� principal
		switch(menu){
	    	case 1:
	    		system ("color 70");
	    		system ("cls");
	    		cout<<"\t\t��Crear producto!! \n"<<endl;
	    		contador= creaProduc( articulos, contador); // Se invoca la funci�n
	    		cout<<endl;
	    		system("cls");
	    		system("color 3F");
    			break;
	    	case 2:
	    		system ("color 70");
	    		system ("cls");
	    		cout<<"\t\t��Listar los productos!! \n" <<endl;
	    		printProduc( articulos, contador); // Se invoca la funci�n
	    		cout<<endl;
	    		system("pause");
	    		system("cls");
	    		system("color 3F");
	    		break;
	    	case 3:
	    		do{
		    		system ("color 70");
		    		system ("cls");
		    		cout<<"\t\t��A�adir existencia a un producto!! \n";
		    		addExist( articulos, contador); // Se invoca la funci�n
		    		cout<<endl;
		    		system("pause");
		    		system("cls");
		    		system("color 70");
		    		int continuar = obtenerEnteroValido("\t\t\n\n�Desea agregar existencias para otro producto? (cualquier n�mero para s�, 0 para no): ");
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
					contador2 = nuevaVenta( articulos, contador, moremo, contador2); // Se invoca la funci�n
		    		cout<<endl;
		    		system("pause");
		    		system("cls");
		    		system("color 70");
		    		int continuar = obtenerEnteroValido("\t\t\n\n�Desea registrar otra venta? (cualquier n�mero para s�, 0 para no): ");
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
	    		cout<<"\t\t��Registro de ventas!! \n";
	    		printVenta( moremo, contador2, articulos, contador); // Se invoca la funci�n
	    		cout<<endl;
	    		system("pause");
	    		system("cls");
	    		system("color 3F");
	    		break;
	    	case 6:
	    		do{
		    		system ("color 70");
		    		system ("cls");
		    		cout<<"\t\t!!Registrar una devoluci�n!! \n";
		    		contador3 = devolver(articulos, contador, moremo, contador2, lessmo, contador3); // Se invoca la funci�n
		    		cout<<endl;
		    		system("pause");
		    		system("cls");
		    		system("color 70");
		    		int continuar = obtenerEnteroValido("\t\t\n\n�Desea registrar otra devoluci�n? (cualquier n�mero para s�, 0 para no): ");
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
	    		cout<<"\t\t��Registro de devoluciones!! \n";
	    		printDevo( lessmo, contador3); // Se invoca la funci�n
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
	cout<<"\t\t\t\t\t���Sigue as�, vas por buen camino!!!\n";
	unistore();
	cout<<"\t\t\t\tNos vemos en una pr�xima ocasi�n, �xitos :D\n"<<endl;
	system("pause");
	system("cls");
	
	// Se a�aden los creditos del programa
	cout<<"\t\t\t��� Cr�ditos del programa !!!\n"<<endl;
	cout<<"\tAutores: Andr�s Felipe Rond�n - Andr�s Felipe Perez - Andr�s Felipe Tovar\n"<<endl;
	cout<<"\tIngenier�a de sistemas\n"<<endl;
	cout<<"\tProgramaci�n B�sica 2023-3\n"<<endl;
	system("pause");
	return 0;
}


//<<-----------------------------------------Se desarrollan las funciones------------------------------------------------------------>>

// Funci�n que retorna true si el n�mero ingresado es entero	
bool esEntero(const string& str) {
    stringstream ss(str); // Un stringstream se utiliza para operar en cadenas como si fueran flujos de entrada/salida.
    int n;
    return (ss >> n) && ss.eof(); //Esto ser� verdadero si se pudo extraer un n�mero entero de la cadena str y no hay nada m�s despu�s del n�mero.
}
// Funci�n para validar que la entrada por consola sea entero
int obtenerEnteroValido(const string& mensaje) {
    string entrada;
    while (true) {
        cout << mensaje;
        cin >> entrada;
        if (esEntero(entrada)) {
            return atoi(entrada.c_str()); // Utiliza atoi para convertir la entrada a un entero y lo devuelve
        } else {
            cout << "Entrada no v�lida. Por favor, ingrese un n�mero entero." << endl;
        }
    }
}

// Funci�n que crea un nuevo producto
int creaProduc(tienda* articulos, int contador){
	while(true){
		tienda produ;
		cout << "Por favor ingrese la informaci�n del producto: " << endl;
	    produ.Codigo = obtenerEnteroValido("C�digo (n�mero): ");
	    while(produ.Codigo <0){
	        produ.Codigo = obtenerEnteroValido("Ingrese un c�digo v�lido: "); // Se verifican que no ingrese n�meros negativos
		}
		//Revisar que el codigo ya exista
	    for (int i = 0; i < contador; i++) {
    		while( articulos[i].Codigo == produ.Codigo){
		        produ.Codigo = obtenerEnteroValido("El c�digo ya est� en uso. Por favor ingrese otro c�digo: "); // Se verifican que no hayan codigos repetidos
			}
		}
		cin.ignore(); // Limpia el b�fer de entrada
		cout << "Nombre: ";
	    getline(cin, produ.Nombre);
	    while (produ.Nombre.empty()) {
            cout << "Debe ingresar un nombre para el producto." << endl;
            cout << "Nombre: ";
            getline(cin, produ.Nombre);
        }
	    produ.Valor = obtenerEnteroValido("Valor unitario: ");
	    while (produ.Valor < 0) {
	        cout << "Ingrese un valor unitario v�lido: ";
	        produ.Valor = obtenerEnteroValido("Ingrese un valor unitario v�lido: "); // Se verifican que no ingrese n�meros negativos
	    }
		produ.Cantidad = obtenerEnteroValido("Existencias: ");
	    while (produ.Cantidad < 0) {
	        produ.Cantidad = obtenerEnteroValido("Ingrese una catidad de existencias v�lida: "); // Se verifican que no ingrese n�meros negativos
	    }
	    articulos[contador] = produ;
	    contador++;
	    
	    int continuar = obtenerEnteroValido("�Desea agregar otro producto? (cualquier n�mero para s�, 0 para no): "); // Se asume un agregar un nuevo producto sin volver al men�
		system("cls");
        if (continuar == 0) {
            break;
        }
	}
	return contador;
}

// Funci�n que lista los productos ingresados
void printProduc(tienda* articulos, int contador){
	if(contador == 0){
		cout<<"No hay productos guardados."<< endl;
	}else{
	    cout << "Los productos guardados son:\n";
	    for (int i = 0; i < contador; i++) {
	    	cout<< endl;
	        cout << "\tC�digo: " << articulos[i].Codigo << endl;
			cout << "\tNombre: " << articulos[i].Nombre << endl;
			cout << "\tValor unitario: " << articulos[i].Valor;
			cout << endl << "\tExistencias: " << articulos[i].Cantidad<< endl; // Se imprimen los productos en pantalla
	    	cout<< endl;
		}
	}
}

// Funci�n que a�ade existencias a productos
void addExist(tienda* articulos, int contador) {
    int cod;
    int nuevos;
    if (contador == 0) {
        cout << "No hay productos guardados." << endl;
        return; // Salir de la funci�n si no hay productos
    }
    cod = obtenerEnteroValido("Ingrese el c�digo del producto al que agregar existencias: ");
    for (int i = 0; i < contador; i++) {
        if (articulos[i].Codigo == cod) {
            cout << "El art�culo de nombre " << articulos[i].Nombre << " tiene actualmente " << articulos[i].Cantidad << " existencias." << endl;
            nuevos = obtenerEnteroValido("�Cuantas existencias le gustar�a agregar? \n");
            while (nuevos < 0) {
                cout << "Cantidad incorrecta, solo se admiten valores positivos" << endl; // Se verifican que no ingrese n�meros negativos
                nuevos = obtenerEnteroValido("�Cuantas existencias le gustar�a agregar?\n");
                cout << endl;
            }
            articulos[i].Cantidad += nuevos;
            cout << "El art�culo de nombre " << articulos[i].Nombre << " ahora tiene " << articulos[i].Cantidad << " existencias." << endl;
            return; // Salir de la funci�n despu�s de actualizar las existencias
        }
    }
    cout << "El c�digo ingresado no est� asociado a ning�n producto." << endl;
}

// Funci�n para registrar una nueva venta y un posible nuevo cliente
int nuevaVenta(tienda* articulos, int contador, venta* moremo, int contador2) {
    venta compra;
    compra.CantidadProductos = 0;

    cout << "\nPor favor ingrese la informaci�n de la venta: " << endl;

    // Captura de los datos del cliente
    cout << "Por favor ingrese los datos del cliente: " << endl;
    compra.CodigoCliente = obtenerEnteroValido("C�digo del cliente (n�mero): ");
    //Revisar que el codigo ya exista
    for (int i = 0; i < contador2; i++) {
		while( moremo[i].CodigoCliente == compra.CodigoCliente){
	        compra.CodigoCliente = obtenerEnteroValido("El c�digo ya est� en uso. Por favor ingrese otro c�digo: "); // Se verifican que no hayan codigos repetidos
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

        codigo = obtenerEnteroValido("C�digo del producto (n�mero): ");
	    while(codigo <0){
	        codigo = obtenerEnteroValido("Ingrese un c�digo v�lido: "); // Se verifican que no ingrese n�meros negativos
		}

        // Buscar el producto en el inventario
        bool encontrado = false;
        int indexProducto = -1;
        for (int i = 0; i < contador; ++i) {
            if (articulos[i].Codigo == codigo) {
                encontrado = true;
                cout << "El art�culo de nombre " << articulos[i].Nombre << " tiene actualmente " << articulos[i].Cantidad << " existencias." << endl;
                indexProducto = i;
                break;
            }
        }

        if (!encontrado) {
            cout << "El producto ingresado no est� en el inventario." << endl;
        } else {
            cantidadProducto = obtenerEnteroValido("Ingrese la cantidad vendida: ");
            // Verificar si la cantidad vendida es v�lida
            if (cantidadProducto > 0 && cantidadProducto <= articulos[indexProducto].Cantidad) {
                compra.Productos[compra.CantidadProductos] = articulos[indexProducto].Nombre;
                compra.Codigos[compra.CantidadProductos] = articulos[indexProducto].Codigo;
                compra.ValoresU[compra.CantidadProductos] = articulos[indexProducto].Valor;
                compra.Cantidades[compra.CantidadProductos] = cantidadProducto;
                articulos[indexProducto].Cantidad -= cantidadProducto; // Actualizar existencias
                compra.CantidadProductos++;

                cout << "Producto agregado a la venta." << endl;
            } else {
                cout << "La cantidad ingresada no es v�lida o supera las existencias del producto." << endl;
            }
        }

        continuar = obtenerEnteroValido("�Desea agregar otro producto a la venta? (1 - S�, 0 - No): ");
        system("cls");
    } while (continuar != 0);

    // C�lculo del valor total de la venta
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

// Funci�n para imprimir en pantalla el total de ventas realizadas
void printVenta(venta* moremo, int contador2, tienda* articulos, int contador) {
    if (contador2 == 0) {
        cout << "No se han realizado ventas." << endl;
    } else {
        cout << "Se han realizado las siguientes ventas:\n\n";
        for (int i = 0; i < contador2; i++) {
            cout << "N�mero de venta: " << moremo[i].Codigo << endl;
            cout << "C�digo del cliente: " << moremo[i].CodigoCliente << endl;
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

// Funci�n para registrar una nueva devoluci�n
int devolver(tienda* articulos, int contador, venta* moremo, int contador2, devolu* lessmo, int contador3) {
    tienda produ;
    devolu regreso;
    venta compra;

    cout << "Por favor ingrese la informaci�n de la devoluci�n: " << endl;
    regreso.CodigoDeVenta = obtenerEnteroValido("C�digo de la venta (n�mero): ");
    while (regreso.CodigoDeVenta < 0) {
        regreso.CodigoDeVenta = obtenerEnteroValido("Ingrese un c�digo v�lido: ");
    }

    // Buscar la venta asociada
    bool ventaEncontrada = false;
    int indiceVentaEncontrada = -1;  // Nuevo variable para almacenar el �ndice de la venta encontrada
    for (int i = 0; i < contador2; i++) {
        if (moremo[i].Codigo == regreso.CodigoDeVenta) {
            cout << "Se vendieron " << moremo[i].CantidadProductos << " productos en la venta asociada." << endl;
            compra = moremo[i];
            ventaEncontrada = true;
            indiceVentaEncontrada = i;  // Almacenar el �ndice de la venta encontrada
            break;
        }
    }

    if (!ventaEncontrada) {
        cout << "No se encontr� la venta asociada al c�digo ingresado." << endl;
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
        cout << "No se pueden registrar m�s devoluciones para esta venta. Todos los productos vendidos ya han sido devueltos." << endl;
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

    // Registrar la devoluci�n
    cout << "Productos vendidos en esta venta:" << endl;
    for (int i = 0; i < compra.CantidadProductos; i++) {
        cout << "Producto: " << compra.Productos[i] << ", Cantidad: " << compra.Cantidades[i] << ", Valor unitario: ";

        // Buscar y mostrar el valor unitario del producto
        for (int j = 0; j < contador; j++) {
            if (articulos[j].Nombre == compra.Productos[i]) {
                cout << articulos[j].Valor << ", C�digo: " << articulos[j].Codigo << "." << endl;
                break;
            }
        }
    }

    // Registrar la devoluci�n para cada producto vendido
    
    cout << "Ingrese las unidades por regresar para cada producto:" << endl;
    for (int i = 0; i < compra.CantidadProductos; i++) {
        cout << "Producto: " << compra.Productos[i] << endl;
        regreso.Cantidad = obtenerEnteroValido("Cantidad: ");
        while (regreso.Cantidad < 0 || regreso.Cantidad > compra.Cantidades[i] - devolucionesPrevias) {
            regreso.Cantidad = obtenerEnteroValido("Ingrese una cantidad v�lida: ");
        }
		if(regreso.Cantidad > 0){
	        regreso.Nombre = compra.Productos[i];
	        regreso.Valor = compra.ValoresU[i] * regreso.Cantidad;
	        regreso.CodigoDeDevolucion = contador3 + 1;
	
	        cout << "Se regresaron " << regreso.Cantidad << " unidades de " << regreso.Nombre << endl;
	        cout << "El valor de la devoluci�n para este producto es: " << regreso.Valor  << endl;
	
	        lessmo[contador3] = regreso;
	        contador3++;
	    }
    }

    // Actualizar la cantidad de productos vendidos en la venta original
    moremo[indiceVentaEncontrada].CantidadProductos -= contador3;

    return contador3;
}


// Funci�n para imprimir en pantalla el total de devoluciones realizadas
void printDevo(devolu* lessmo, int contador3){
	if(contador3 == 0){
		cout<<"No hay devoluciones registradas."<< endl;
	}else{
	    cout << "Se han realizado las siguientes devoluciones:\n";
	    for (int i = 0; i < contador3; i++) {
	    	cout<< endl;
	        cout << "\tC�digo de devoluci�n: " << lessmo[i].CodigoDeDevolucion << endl << "\tNombre: " << lessmo[i].Nombre << endl << "\tValor: " << lessmo[i].Valor << endl << "\tExistencias: " << lessmo[i].Cantidad<< endl; //Se imprimen las devoluciones en pantalla
	    	cout<< endl;
		}
	}
}


// Funci�n para la presentaci�n del programa
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
