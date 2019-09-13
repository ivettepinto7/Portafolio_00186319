//ESTE ARCHIVO SOLO CONTIENE LOS PUNTOS 1 Y 2 DEL EJERCICIO
//IVETTE PINTO 00186319
#include <iostream>
#include <conio.h>
using namespace std;

struct continente{
	string nombre,capital;
	int habitantes;
	string nombcont;//SE UTILIZA EN EL MAIN PARA SABER EN QUE CONTINENTE SE ESTA INGRESANDO DATOS
};

int main(){
	string arreglo[5] = {"Europa", "America", "Asia", "Africa", "Oceania"};//ARREGLO DE TIPO STRING PARA TENER YA DEFINIDOS LOS 5 CONTINENTES
	
	continente mundo[5][5];//SE CREA UNA SOLA MATRIZ QUE CONTENDRA LOS 5 CONTINENTES CON LOS 5 PAISES Y SUS DATOS
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			mundo[i][j].nombcont = arreglo[i]; //SE UTILIZA PARA SABER EN QUE CONTINENTE ESTAMOS INGRESANDO DATOS
			cout << "Estamos en: " << arreglo[i] << endl;
			
			//EN ESTE ESPACIO ES DONDE IRAN LAS LINEAS DE CODIGO PARA QUE EL USUARIO LLENE LA MATRIZ
		}
	}
	//IGUALMENTE SE USA UN DOBLE FOR PARA IMPRIMIR EL ARREGLO
	for(int i=0; i<5;i++){
		for(int j=0;j<5;j++){
			cout << arreglo[i] << endl;
			cout << mundo[i][j].nombre <<endl;
			cout << mundo[i][j].capital << endl;
			cout << mundo[i][j].habitantes <<endl;
		}
		cout << endl;
	}
	
	
	getch();
	return 0;
}
