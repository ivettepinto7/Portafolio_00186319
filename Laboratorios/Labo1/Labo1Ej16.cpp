#include <iostream>
using namespace std;

int main(){
	int a[10], i = 0,s=0;
	float p=0;
	
	for(i = 0; i<10; i++){
		cout << "Ingrese el elemento " << i + 1 << " del arreglo: " << endl;
		cin >>  a[i];
	}
	
	for(i=0 ; i<10; i++){
		s += a[i];
		p = (float)s/10;
	}
	cout << "La suma es: " << s << endl;
	cout << "EL promedio es: " << p << endl;
	
	return 0;
}
