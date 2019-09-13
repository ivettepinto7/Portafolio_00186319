#include <iostream>
using namespace std;

void conteo(int n, int num);

int main(){
	int n=0,num=1;
	
	verifNum:
	cout << "Ingrese un numero: " << endl;
	cin >> n;
	if(n<=0){
		cout << "Ingrese un numero positivo" << endl;
		goto verifNum;
	}
	cout << endl;
	conteo(n,num);
	return 0;
}
void conteo(int n,int num){
	if(num == n){
		cout << num << endl;
		return;
	}
	else{
		cout << num << endl;
		conteo(n,num+1);
		cout << num << endl;
		return;
	}
}
