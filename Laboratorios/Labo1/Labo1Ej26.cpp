#include <iostream>
using namespace std;

struct complejo{
	int real=0,imag=0;
};

int main(){
	int conju=0,real=0,imag=0;
	cout << "Ingrese la parte real: " << endl;
	cin >> real;
	cout << "Ingrese la parte imaginaria: " << endl;
	cin >> imag;
	
	if(imag < 0){
		conju = (-1)*(imag);
		cout << "La conjugada es: " << real << " + " << conju << "j" << endl;
	}
	else if(imag > 0){
		conju = (-1)*(imag);
		cout << "La comjugada es: " << real << conju << "j " << endl;
	}
	return 0;
}
