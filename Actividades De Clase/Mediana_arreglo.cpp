#include <iostream>
#include <conio.h>
using namespace std;

float mediana(int arr[], int tam){
	int p = tam / 2;//Esta variable se crea para usarla como una posicion
	float me;
	if(tam%2 == 0){//Si el arreglo es par
		me = (float)(arr[p-1] + arr[p])/2;
	}
	else{//Si el arreglo es impar
		me = arr[p];
	}
	return me;
}
int main(){
	int tam = 0,aux;
	
	cout << "Ingrese el tamanio de su arreglo: "<< endl; cin >> tam;
	int arr[tam];
	//Llenar el arreglo
	for(int i=0; i<tam; i++){
		cout << "Ingrese el elemento " << i+1 << " de su arreglo: " << endl;
		cin >> arr[i];
	}
	//Ordenar el arreglo
	for(int i=0;i<tam-1;i++){
		for(int j=i+1;j<tam;j++){
			if(arr[i] > arr[j]){
				aux = arr[i];
				arr[i] = arr[j];
				arr[j] = aux;
			}
		}
	}
	cout << "EL ARREGLO ORDENADO: " << endl;
	for(int i=0;i<tam;i++){
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "LA MEDIANA ES: " << mediana(arr,tam);

	return 0;
}
