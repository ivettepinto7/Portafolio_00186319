#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

struct TPersona{
	int carnet,edad,telefono;
	string nombre,apellido,correo;
};
typedef struct TPersona Persona;
Persona solicitarPersona(){
	Persona p;
	cout << "Ingrese el carnet: "; cin >> p.carnet;
	cout << "Ingrese nombre: "; cin >> p.nombre;
	cout << "Ingrese apellido: "; cin >> p.apellido;
	verifEdad:
		cout << "Ingrese edad: "; cin >> p.edad;
		if(p.edad <= 0){
			cout << "Edad invalida, intente de nuevo"<<endl;
			goto verifEdad;
		}
	cout << "Ingrese numero de telefono: "; cin >> p.telefono;
	cout << "Ingrese correo electronico: "; cin >> p.correo;
	return p;
}
void mostrarPersona(Persona p){
	cout << "Carnet: " << p.carnet << endl;
	cout << "Nombre: " << p.nombre << endl;
	cout << "Apellido: " << p.apellido << endl;
	cout << "Edad: " << p.edad << endl;
	cout << "Numero de telefono: " << p.telefono << endl;
	cout << "Correo electronico: " << p.correo << endl; 
}
struct TNodo{
	Persona dato;
	struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;
void agregarFinal(Persona p){
	Nodo *nuevo = new Nodo;
	nuevo->dato = p;
	nuevo->sig = NULL;
	
	if(pInicio == NULL){
		pInicio = nuevo;
	}else{
	Nodo *p = pInicio;
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
	}
}
void agregarPersona(){
	Persona p = solicitarPersona();
	agregarFinal(p);
}
void mostrarLista(){
	Nodo *s = pInicio;
	
	while(s != NULL){
		mostrarPersona(s->dato);
		s = s->sig;
		cout << endl;
	}
	cout << endl;
}
void eliminarPersona(){
	int unCarnet = 0;
	cout << "Ingrese el carnet de la persona a eliminar: "; cin >> unCarnet;
	
	Nodo *p = pInicio, *q = NULL;
	while(p != NULL && (p->dato).carnet != unCarnet){
		q = p;
		p = p->sig;
	}
	if(p == NULL){
		cout << "La persona a eliminar no existe"<<endl;
		return;
	}
	if(q == NULL){
		pInicio = p->sig;
	}else{
		q->sig = p->sig;
	}
	delete(p);
	cout << "Eliminando..."<<endl;
	cout << "Persona eliminada"<<endl;
}
void actualizarPersona(){
	int uncarnet = 0;
	cout << "Ingrese el carnet de la persona a actualizar datos: "; cin >> uncarnet;
	
	Nodo *p = pInicio, *q = NULL;
	while(p != NULL && (p->dato).carnet != uncarnet){
		q = p;
		p = p->sig;
	}
	if(p == NULL){
		cout << "La persona no existe en la lista"<<endl;
		return;
	}else{
		int opc = 0;
		cout << "Que desea actualizar: \n\t1. Carnet\n\t2. Nombre\n\t3. Apellido\n\t4. Edad\n\t5. Telefono\n\t6. Correo\n\t7. Todos\tSu opcion: ";
		cin >> opc;
		switch(opc){
			case 1: cout << "Nuevo carnet: "; cin >> (p->dato).carnet;
			break;
			case 2: cout << "Nuevo nombre: "; cin >> (p->dato).nombre;
			break;
			case 3: cout << "Nuevo apellido: "; cin >> (p->dato).apellido;
			break;
			case 4: cout << "Nueva edad: "; cin >> (p->dato).edad;
			break;
			case 5: cout << "Nuevo telefono: "; cin >> (p->dato).telefono;
			break;
			case 6: cout << "Nuevo correo: "; cin >> (p->dato).correo;
			break;
			case 7:
				cout << "Nuevo carnet: "; cin >> (p->dato).carnet;
				cout << "Nuevo nombre: "; cin >> (p->dato).nombre;
				cout << "Nuevo apellido: "; cin >> (p->dato).apellido;
				cout << "Nueva edad: "; cin >> (p->dato).edad;
				cout << "Nuevo telefono: "; cin >> (p->dato).telefono;
				cout << "Nuevo correo: "; cin >> (p->dato).correo;
			break;
			default: cout << "Opcion erronea!"<<endl;
			break;
		}
		cout << "Actualizando..."<<endl;
		cout << "Datos actualizados con exito!"<<endl;
	}
}
void mostrarMenu(){
	cout << "MENU PRINCIPAL"<<endl;
	cout << "\t 1. Llenar lista"<<endl;
	cout << "\t 2. Eliminar una persona"<<endl;
	cout << "\t 3. Actualizar los datos de una persona"<<endl;
	cout << "\t 4. Mostrar todas las personas"<<endl;
	cout << "\t 5. Salir \tSu opcion: ";
}
int main(){
	cout << "Inicializando..."<<endl;
	pInicio = NULL;
	
	bool continuar = true;
	do{
		int opcion=0;
		mostrarMenu();
		cin >> opcion;
		switch(opcion){
			case 1:
				cout << "Agregando..."<<endl;
				agregarPersona();
			break;
			case 2:
				eliminarPersona();
			break;
			case 3:
				actualizarPersona();
			break;
			case 4:
				cout << "Listando..."<<endl;
				mostrarLista();
			break;
			case 5:
				return 0;
			break;
			default: cout << "Opcion invalida"<<endl;
			break; 
		}
	}while(continuar);
	getch();
	return 0;
}
