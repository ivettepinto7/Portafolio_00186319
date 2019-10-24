#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	int cola[10];
	int datos=0,n=1,opc=1,posi=0,frente=0;
	while(opc != 0){
		switch(opc){
			case 0:
				return 0;
			break;
			case 1:
				cout << "Digite un numero: "; cin >> n;
				posi=(frente + datos)%5;
				cola[posi]=n;
				datos++;
			break;
		}
		cout << "1. Agregar un numero " << endl;
		cout << "0. Salir \t Su opcion: ";
		cin >> opc;
	}
	getch();
	return 0;
}
