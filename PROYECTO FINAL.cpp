/*
Programa: Proyecto final - Sistema de gestión de inventario y ventas 
Autores: Andrés Felipe Rondón Lara - Andres Felipe Perez Motta - Andres Felipe Tovar Molina
Fecha: 27 de noviembre de 2023
*/
//Declaramos variables
#include <iostream>
#include <locale.h>
#include <string>
#include <sstream> 
#include <cstdlib> 
using namespace std;
//Struct para registrar los productos
struct tienda{
	int Codigo;
	string Nombre;
	int Valor;
	int Cantidad;
};
//Struct para registar las ventas
struct venta{
	int Codigo;
	string Nombre;
	int Valor;
	int Cantidad;	
};
//Struct para registar los clientes
struct cliente{
	
};
//Struct para registrar las devoluciones
struct devolu{
	int Codigo;
	string Nombre;
	int Valor;
	int Cantidad;	
};
//Incluimos funciones que utilizaremos para la ejecucuión del programa
void unistore();
bool esEntero(const string& str);
int obtenerEnteroValido(const string& mensaje);
//Funciones para los productos
int creaProduc(tienda* articulos, int contador);
void printProduc(tienda* articulos, int contador);
void addExist(tienda* articulos, int contador);

//Funciones para las ventas

int nuevaVenta(tienda* articulos, int contador, venta* moremo, int contador2);
void printVenta(venta* moremo, int contador2);

//Funciones para las devoluciones
void printDevo(devolu* lessmo, int contador3);
// <<------------------------------ Inicio del programa ----------------------------------->> 
int main(){
	//Esta orden permite los caracteres especiales
	setlocale(LC_ALL, "");
	system("cls");//Limpia pantalla
	int n;
	//Se crea la portada del programa
	system("color 6");
	unistore();
	system ("pause");
	system("cls");
	
	//Creamos un arreglo para los productos de la tienda
	tienda* articulos = new tienda[100];
	//Creamos un arreglo para las ventas de la tienda
	venta* moremo = new venta[200]; //moremo = more money = mas dinero
	//Creamos un arreglo para las devoluciones de la tienda
	devolu* lessmo = new devolu[100]; //lessmo = less money = menos dinero
    int contador, contador2, contador3 = 0;
	//Se ejecuta el menú principal que vera el usuario en pantalla 
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
    //Se ingresa el menú principal
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
		//Se limitan las respuestas del usuario
	    while (menu<0||menu>8){
	    	cout<<"La opción que seleccionaste no se encuentra en el menú \n";
	    	menu = obtenerEnteroValido("Por favor, selecciona una opción válida \n");
		}
		cout<<"\t\tSiempre disponible para ayudarte :D\n";
		//Se ejecutan las distintas opciones que pudo elegir el usuario en el menú principal
		switch(menu){
	    	case 1:
	    		system ("color 70");
	    		system ("cls");
	    		cout<<"\t\t¡¡Crear producto!! \n"<<endl;
	    		contador= creaProduc( articulos, contador); //Se invoca la función
	    		cout<<endl;
	    		system("cls");
	    		system("color 3F");
	    		break;
	    	case 2:
	    		system ("color 70");
	    		system ("cls");
	    		cout<<"\t\t¡¡Listar los productos!! \n" <<endl;
	    		printProduc( articulos, contador); //Se invoca la función
	    		cout<<endl;
	    		system("pause");
	    		system("cls");
	    		system("color 3F");
	    		break;
	    	case 3:
	    		system ("color 70");
	    		system ("cls");
	    		cout<<"\t\t¡¡Añadir existencia a un producto!! \n";
	    		addExist( articulos, contador); //Se invoca la función
	    		cout<<endl;
	    		system("pause");
	    		system("cls");
	    		system("color 3F");
	    		break;
	    	case 4:
	    		system ("color 70");
	    		system ("cls");
	    		cout<<"\t\t!!Registrar una nueva venta!! \n";

	    		nuevaVenta( articulos, contador, moremo, contador2);
	    		cout<<endl;
	    		system("pause");
	    		system("cls");
	    		system("color 3F");
	    		break;
	    	case 5:
	    		system ("color 70");
	    		system ("cls");
	    		cout<<"\t\t¡¡Registro de ventas!! \n";
	    		printVenta( moremo, contador2);
	    		cout<<endl;
	    		system("pause");
	    		system("cls");
	    		system("color 3F");
	    		break;
	    	case 6:
	    		system ("color 70");
	    		system ("cls");
	    		cout<<"\t\t!!Registrar una devolución!! \n";
	    		
	    		cout<<endl;
	    		system("pause");
	    		system("cls");
	    		system("color 3F");
				break;
	    	case 7:
	    		system ("color 70");
	    		system ("cls");
	    		cout<<"\t\t¡¡Registro de devoluciones!! \n";
	    		printDevo( lessmo, contador3);
	    		cout<<endl;
	    		system("pause");
	    		system("cls");
	    		system("color 3F");
	    		break;
		}	
	}while (menu!=8);
	system("cls");
	system("color 6");
	cout<<"\t\t\t\t\t¡¡¡Sigue así, vas por buen camino!!!\n";
	unistore();
	cout<<"\t\t\t\tNos vemos en una próxima ocasión, éxitos :D\n"<<endl;
	system("pause");
	system("cls");
	
	//Se añaden los creditos del programa
	cout<<"\t\t\t¡¡¡ Créditos del programa !!!\n"<<endl;
	cout<<"\tAutores: Andrés Felipe Rondón - Andrés Felipe Perez - Andrés Felipe Tovar\n"<<endl;
	cout<<"\tIngeniería de sistemas\n"<<endl;
	cout<<"\tProgramación Básica 2023-3\n"<<endl;
	system("pause");
	return 0;
}
//<<-----------------------------------------Se desarrollan las funciones------------------------------------------------------------>>
//Función que retorna true si el número ingresado es entero	
bool esEntero(const string& str) {
    stringstream ss(str); // Un stringstream se utiliza para operar en cadenas como si fueran flujos de entrada/salida.
    int n;
    return (ss >> n) && ss.eof(); //Esto será verdadero si se pudo extraer un número entero de la cadena str y no hay nada más después del número.
}
//Función para validar que la entrada por consola sea entero
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
//Función que crea un nuevo producto
int creaProduc(tienda* articulos, int contador){
	while(true){
		tienda produ;
		cout << "Por favor ingrese la información del producto: " << endl;
	    produ.Codigo = obtenerEnteroValido("Código (número): ");
	    while(produ.Codigo <0){
	        produ.Codigo = obtenerEnteroValido("Ingrese un código válido: "); //Se verifican que no ingrese números negativos
		}
		//Revisar que el codigo ya exista
	    for (int i = 0; i < contador; i++) {
    		while( articulos[i].Codigo == produ.Codigo){
		        produ.Codigo = obtenerEnteroValido("El código ya está en uso. Por favor ingrese otro código: "); //Se verifican que no hayan codigos repetidos
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
	        produ.Valor = obtenerEnteroValido("Ingrese un valor unitario válido: "); //Se verifican que no ingrese números negativos
	    }
		produ.Cantidad = obtenerEnteroValido("Existencias: ");
	    while (produ.Cantidad < 0) {
	        produ.Cantidad = obtenerEnteroValido("Ingrese una catidad de existencias válida: "); //Se verifican que no ingrese números negativos
	    }
	    articulos[contador] = produ;
	    contador++;
	    
	    int continuar = obtenerEnteroValido("¿Desea agregar otro producto? (cualquier número para sí, 0 para no): "); //Se asume un agregar un nuevo producto sin volver al menú
		system("cls");
        if (continuar == 0) {
            break;
        }
	}
	return contador;
}
//Función que lista los productos ingresados
void printProduc(tienda* articulos, int contador){
	if(contador == 0){
		cout<<"No hay productos guardados."<< endl;
	}else{
	    cout << "Los productos guardados son:\n";
	    for (int i = 0; i < contador; i++) {
	    	cout<< endl;
	        cout << "\tCódigo: " << articulos[i].Codigo << endl << "\tNombre: " << articulos[i].Nombre << endl << "\tValor unitario: " << articulos[i].Valor << endl << "\tExistencias: " << articulos[i].Cantidad<< endl; //Se imprimen los productos en pantalla
	    	cout<< endl;
		}
	}
}
//Función que añade existencias a productos
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
                cout << "Cantidad incorrecta, solo se admiten valores positivos" << endl;
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

//Fución para registrar una nueva venta y un posible nuevo cliente
int nuevaVenta(tienda* articulos, int contador, venta* moremo, int contador2){
	tienda produ;
	venta compra;
	cout << "Por favor ingrese la información de la venta: " << endl;
    produ.Codigo = obtenerEnteroValido("Código del producto (número): ");
    while(produ.Codigo <0){
        produ.Codigo = obtenerEnteroValido("Ingrese un código válido: "); //Se verifican que no ingrese números negativos
	}
	//Revisar que el codigo este asociado a un producto
    for (int i = 0; i < contador; i++) {
		if( articulos[i].Codigo == produ.Codigo){
			cout << "El artículo de nombre " << articulos[i].Nombre << " tiene actualmente " << articulos[i].Cantidad << " existencias." << endl;
			compra.Cantidad = obtenerEnteroValido("Ingrese las unidades por vender: ");
			while (compra.Cantidad < 0) {
        		compra.Cantidad = obtenerEnteroValido("Ingrese una catidad de existencias válida: "); //Se verifican que no ingrese números negativos
    		}
    		while (articulos[i].Cantidad - compra.Cantidad < 0) {//Se verifica que no sobrepase la cantidad de unidades del producto
        		compra.Cantidad = obtenerEnteroValido("La cantidad ingresada supera las existencias del producto.\n Ingrese una cantidad válida: "); 
    			while (compra.Cantidad < 0) {
	        		compra.Cantidad = obtenerEnteroValido("Ingrese una catidad de existencias válida: "); //Se verifican que no ingrese números negativos
	    		}
			}

			//actualizamos la información del producto vendido
			articulos[i].Cantidad -= compra.Cantidad;
			compra.Nombre = articulos[i].Nombre; 
			compra.Valor = articulos[i].Valor * compra.Cantidad;
			compra.Codigo = contador2;

			cout << "Se vendieron " << compra.Cantidad << " unidades de " << compra.Nombre << ", por un valor de " << compra.Valor << endl;

			moremo[contador2] = compra;
    		contador2++;

    		return contador2;
		} 	
	}
	cout << "El código ingresado no está asociado a ningún producto." << endl;
	return contador2;
}

//Funcion para imprimir en pantalla el total de ventas realizadas
void printVenta(venta* moremo, int contador2){
	if(contador2 == 0){
		cout<<"No se han realizado ventas."<< endl;
	}else{
	    cout << "Se han realizado las siguientes ventas:\n";
	    for (int i = 0; i < contador2; i++) {
	    	cout<< endl;
	        cout << "\tCódigo: " << moremo[i].Codigo << endl << "\tNombre: " << moremo[i].Nombre << endl << "\tValor unitario: " << moremo[i].Valor << endl << "\tExistencias: " << moremo[i].Cantidad<< endl; //Se imprimen los productos en pantalla
	    	cout<< endl;
		}
	}
}
//Función para registrar una nueva devolción

//Función para imprimir en pantalla el total de devoluciones realizadas
void printDevo(devolu* lessmo, int contador3){
	if(contador3 == 0){
		cout<<"No hay devoluciones registradas."<< endl;
	}else{
	    cout << "Se han realizado las siguientes ventas:\n";
	    for (int i = 0; i < contador3; i++) {
	    	cout<< endl;
	        cout << "\tCódigo: " << lessmo[i].Codigo << endl << "\tNombre: " << lessmo[i].Nombre << endl << "\tValor unitario: " << lessmo[i].Valor << endl << "\tExistencias: " << lessmo[i].Cantidad<< endl; //Se imprimen los productos en pantalla
	    	cout<< endl;
		}
	}
}
//Función para la presentación del programa
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
