#include <iostream>
using namespace std;

void mcd(int mayor, int menor,int aux);
int main(){
	int mayor =0, menor = 0,aux = 0;
	
	cout << "Ingrese el numero mayor: ";
	cin >> mayor;
	
	cout << "Ingrese el numero menor: ";
	cin >> menor;

	mcd(mayor,menor,aux);

	return 0;
}
void mcd(int mayor, int menor,int aux){
	if(mayor%menor == 0){
		cout << "El mcd es: " << menor << endl;
	}
	else{
		aux = mayor;
		mayor = menor;
		menor = aux%menor;
		return mcd(mayor,menor,aux);
	}
}
