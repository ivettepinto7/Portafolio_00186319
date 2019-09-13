#include <iostream>
#include <conio.h>
using namespace std;

int main(){
	int n = 0,cont1 = 3,cont2 = 0;//son utoles para moverse dentro de la matriz y colocar los numeros en las diagonales
	int f = 0,c = 0,i = 0,j = 0,k = 0,l = 0,m[5][5];//para evitar declararlas en el for 
	
	//primero hay que inicializar todas las casillas de la matriz con 0
	for(i = 0; i < 5; i++){
		for(j=0;j<5;j++){
			m[i][j] = 0;
		}
	}
	for(k = 0; k < 5; k++){
		if(k == 1){
			cont1--;
		}
		else if(k == 2){
			cont1 = 1;
			cont2++;
		}
		else if(k == 3){
			cont1 = 0;
			cont2++;
		}
		else if(k == 4){
			cont2++;
		}
		for(l=cont2;l<5 -(cont1); l++){//se llena la matriz
			cout << "Ingrese un numero: " << endl;
			cin >> n;
			m[k][l] = n;
		}
	}
	cout << endl;
	cout << "La matriz llena se ve asi: " << endl;
	//se imprime la matriz en consola
	for(f = 0; f < 5; f++){
		for(c = 0; c < 5; c++){
			cout << m[f][c] << " " ;
		}
		cout << endl;
	}
	
	return 0;
}
