#include <iostream>
#include <conio.h>
using namespace std;

struct num{
	int n;
	num *sig;
}*frente,*final;
void push(int n);
void mostrarCola();

int main(){
	int n = 0;
	cout << "Ingrese un numero: ";
	while(cin >> n){
		push(n);
		cout << "Ingrese un numero: ";
	}
	mostrarCola();
	getch();
	return 0;
}
void push(int n){
	num *nuevo = new num;
	nuevo->n = n;
	if(frente == NULL){
		frente = nuevo;
		frente->sig = nuevo;
		final = frente;
	}else{
		final->sig = nuevo;
		nuevo->sig = frente;
		final = nuevo;
	}
}
void mostrarCola(){
	num* actual = new num();
	actual = frente;
	if(frente != NULL){
		cout << "\t LA LISTA: ";
		do{
			cout << endl; cout << actual->n;
			actual = actual->sig;
		}while(actual != frente);
	}
	else{
		cout << "LISTA VACIA"<<endl;
	}
}
