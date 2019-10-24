#include <iostream>
using namespace std;

int main(){
	int a[10][20];
	int posi=99,i,j;
	
	for(i = 0; i<10; i++){
		for(j = 0; j<20; j++){
			posi++;
			cout << "DIRECCION DE [ " << i << " ]" << "[ " << j << " ] = " << posi << endl;
		}
	}
	
	return 0;
}
