#include <iostream>
using namespace std;

void digitos(int n, int cont);

int main(){
	int n=0,con=0;
	
	verifNum:
	cout << "Ingrese un numero: ";
	cin>> n;
	if(n < 0){
		cout << "Ingrese un numero positivo" << endl;
		goto verifNum;
	}
	digitos(n,con);
	
	return 0;
}
void digitos(int n,int cont){
	if(n > 0){
		return digitos(n / 10, cont+1);
	}
	cout << "Tiene " << cont << " digitos";

}
