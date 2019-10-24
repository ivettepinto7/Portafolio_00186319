#include <iostream>
using namespace std;

struct num{
	int n;
	num *sig;
};
struct sumas{
	int pares,impares;
};
void imprimirMenu();
sumas suma(num* lista, int pares,int impares);
int main(){
	sumas s;
	int n=0,opc=0,pares=0,impares=0;
	
	num *pInicio = NULL;
	do{
		imprimirMenu();
		cin >> opc;
		num *nuevo = new num;
		switch(opc){
			case 1:
				cout << "Ingrese un numero: "; cin >> n;
				nuevo->sig = NULL;
				nuevo->n = n;
				if(!pInicio){
					pInicio = nuevo;
				}
				else{
					nuevo->sig = pInicio;
					pInicio = nuevo;
				}
			break;
			case 2:
				cout << "SUMA DE LOS PARES E IMPARES"<<endl;
				s = suma(pInicio,pares,impares);
				cout << "PARES: " <<s.pares <<endl;
				cout << "IMPARES: " << s.impares << endl;
			break;
			default: cout << "Opcion erronea!"<<endl;
			break;
		}
	}while(opc!=0);
	
	
	return 0;
}
void imprimirMenu(){
	cout << "MENU PRINCIPAL"<<endl;
	cout << "\t1. Agregegar numero "<<endl;
	cout << "\t2. Mostrar suma de pares e impares"<<endl;
	cout << "\t0.Salir \tSu opcion: ";
}
sumas suma(num* lista,int pares, int impares){
	if(!lista){
		sumas s;
		s.impares = impares;
		s.pares = pares;
		return s;
	}
	else{
		if(lista->n % 2 == 0){
			pares += lista->n;
			suma(lista->sig,pares,impares);
		}
		else{
			impares += lista->n;
			suma(lista->sig,pares,impares);
		}
	}
}
