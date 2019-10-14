#include <iostream>
#include <conio.h>
#include <string>
using namespace std;
struct TLibro{
	string titulo;
	int numPaginas;
	TLibro *sig;
};
typedef struct TLibro Libro;
void imprimirMenu(){
	cout << "Menu"<<endl;
	cout << "\t1. Agregar libro"<<endl;
	cout << "\t2. Buscar numero de paginas de cierto libro \tSu opcion: ";
}
void buscarLibro(Libro* lista, string titulo){
	if(!lista){
		return;
	}else{
		if(lista->titulo == titulo){
			cout << "Numero de paginas: " << lista->numPaginas <<endl;
		}else{
			buscarLibro(lista->sig,titulo);
		}
	}
}
int main(){
	string titulo;
	int numPaginas = 0,opc=0;
	Libro *pInicio = NULL;
	do{
		Libro *nuevo = new Libro;
		imprimirMenu();
		cin >> opc;
		switch(opc){
			case 1:
				cout << "Titulo: "; cin >> titulo;
				cout << "Numero de paginas: "; cin >> numPaginas;
		
				nuevo->sig = NULL;
				nuevo->titulo = titulo;
				nuevo->numPaginas = numPaginas;
				if(!pInicio){
					pInicio = nuevo;
				}else{
					nuevo->sig = pInicio;
					pInicio = nuevo;
					}
			break;
			case 2:
				cout << "Libro del que desea saber numero de paginas: "; cin >> titulo;
				buscarLibro(pInicio,titulo);
			break;
		}
	}while(opc != 0);
	getch();
	return 0;
}

