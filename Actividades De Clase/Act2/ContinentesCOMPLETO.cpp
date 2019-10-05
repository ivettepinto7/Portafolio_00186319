#include <iostream>
#include <conio.h>
using namespace std;

struct continente{
	string nombre,capital;
	int habitantes,edad;
	string nombcont;
};
void imprimirMenu(void);

int main(){
	string aux;
	string arreglo[5] = {"Europa", "America", "Asia", "Africa", "Oceania"};
	int total = 0 , mayor = 0, opc = 0;
	float promedio = 0;
	continente mundo[5][5];
	
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			mundo[i][j].nombcont = arreglo[i];
			cout << "Estamos en: " << arreglo[i] << endl;
			cout << "Ingrese el nombre del pais [" << i << "][" << j << "]" << endl;
			cin >> mundo[i][j].nombre;
			
			cout << "Ingrese la capital del pais [" << i << "][" << j << "]" << endl;
			cin >> mundo[i][j].capital;
			
			verificarHabit:
			cout << "Ingrese la cantidad de habitantes del pais [" << i << "][" << j << "]" << endl;
			cin >> mundo[i][j].habitantes;
			if(mundo[i][j].habitantes <=0){
				cout << "Cantidad invalida, intente de nuevo"<<endl;
				goto verificarHabit;
			}
			verificarEdad:
			cout << "Ingrese edad: " << "[" << i << "][" << j << "]"  << endl;
			cin >> mundo[i][j].edad;
			if(mundo[i][j].edad <= 0){
				cout << "Edad invalida, intente de nuevo" << endl;
				goto verificarEdad;
			}
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(mundo[i][j].habitantes > mayor){
				mayor = mundo[i][j].habitantes;
				aux =(string) mundo[i][j].capital;
			}
		}
	}
	cout << endl;
	cout << "La capital con mas habitantes en el mundo es " << aux << " con " << mayor << " habitantes" << endl;
	promedio = (float) ((mundo[0][0].edad + mundo[0][1].edad + mundo[0][2].edad + mundo[0][3].edad + mundo[0][4].edad) + (mundo[1][0].edad + mundo[1][1].edad + mundo[1][2].edad + mundo[1][3].edad + mundo[1][4].edad) + (mundo[2][0].edad + mundo[2][1].edad + mundo[2][2].edad + mundo[2][3].edad + mundo[2][4].edad) + (mundo[3][0].edad + mundo[3][1].edad + mundo[3][2].edad + mundo[3][3].edad + mundo[3][4].edad) + (mundo[4][0].edad + mundo[4][1].edad + mundo[4][2].edad + mundo[4][3].edad + mundo[4][4].edad))/25;
	cout << "Promedio de edad mundial: " << promedio << endl;
	cout << endl;
	
	cout << "De que continente desea saber el total de habitantes?"<<endl;
	imprimirMenu();
	cin >> opc;
	switch(opc){
		case 1:
			total = mundo[0][0].habitantes + mundo[0][1].habitantes + mundo[0][2].habitantes + mundo[0][3].habitantes + mundo[0][4].habitantes;
			cout << "Total de habitantes en Europa: " << total << endl;
		break;
		case 2:
			total = mundo[1][0].habitantes + mundo[1][1].habitantes + mundo[1][2].habitantes + mundo[1][3].habitantes + mundo[1][4].habitantes;
			cout << "Total de habitantes en America: " << total << endl;
		break;
		case 3:
			total = mundo[2][0].habitantes + mundo[2][1].habitantes + mundo[2][2].habitantes + mundo[2][3].habitantes + mundo[2][4].habitantes;
			cout << "Total de habitantes en Asia: " << total << endl;
		break;
		case 4:
			total = mundo[3][0].habitantes + mundo[3][1].habitantes + mundo[3][2].habitantes + mundo[3][3].habitantes + mundo[3][4].habitantes;
			cout << "Total de habitantes en Africa: " << total << endl;
		break;
		case 5:
			total = mundo[4][0].habitantes + mundo[4][1].habitantes + mundo[4][2].habitantes + mundo[4][3].habitantes + mundo[4][4].habitantes;
			cout << "Total de habitantes en Oceania: " << total << endl;
		break;
	}
	

	/*Este for es para imprimir la matriz
	for(int i=0; i<5;i++){
		for(int j=0;j<5;j++){
			cout << arreglo[i] << endl;
			cout << mundo[i][j].nombre << " ";
			cout << mundo[i][j].capital << " ";
			cout << mundo[i][j].habitantes << " ";
			cout << mundo[i][j].edad << " ";
		}
		cout << endl;
	}
	*/
	
	getch();
	return 0;
}
void imprimirMenu(void){
	cout << "1. Europa" << endl;
	cout << "2. America"<< endl;
	cout << "3. Asia" << endl;
	cout << "4. Africa" << endl;
	cout << "5. Oceania \tSU OPCION: ";
}
