#include <iostream>
using namespace std;

int multi(int a, int b);

int main(){
	int a = 0,b = 0;
	cout << "Digite el primer numero: ";
	cin >> a;
	
	cout << "Digite el segundo numero: ";
	cin >> b;
	
	cout << multi(a,b);
	
	return 0;
}
int multi(int a,int b){
	if(b == 1){
		return a;
	}
	else{
		return a + multi(a,b-1);
	}
}

