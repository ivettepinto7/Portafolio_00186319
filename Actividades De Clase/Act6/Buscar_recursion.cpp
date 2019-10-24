#include <iostream>
using namespace std;

int arreglo[8] = {1 , 3, 4, 5, 17, 18, 31, 33};
int low = 0, high = 7;
int mid = (low+high) / 2;

int buscar(int n);

int main(){
	int n ;
	verifyPosi:
	cout << "Digite un numero: " << endl;
	cin >> n;
	if(n <= 0){
		cout << "Digite un numero positivo" << endl;
		goto verifyPosi;
	}
		cout << "Se encontro el numero en la posicion: " << 	buscar(n)<< endl;
	return 0;
}
int buscar(int n){
	if(n!=arreglo[mid] &&(mid==low || mid==high) ){
		return (-1);
			}
	if(n == arreglo[mid]){
		return (mid);
	}
	if(n <arreglo[mid]){
	mid--;
	return buscar(n);
	}
	else{
		mid++;
	return	buscar(n);
	}
}
