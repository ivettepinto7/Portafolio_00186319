#include <iostream>
using namespace std;

void movimientos(int d,int t1, int t2, int t3);

int main(){
	int d=0,t1=1,t2=2,t3=3;
	
	cout << "Ingrese la cantidad de discos: ";
	cin >> d;
	
	movimientos(d,t1,t2,t3);

	return 0;
}
void movimientos(int d,int t1, int t2, int t3){
	if(d == 1){
		cout << "Se mueve el disco de la torre " << t1 << " a la torre " << t3 << endl;
	}
	else{
		movimientos(d-1,t1,t3,t2);
		cout << "Se mueve el disco de la torre " << t1 << " a la torre " << t3 <<endl;
		movimientos(d-1,t2,t1,t3);
	}
}
