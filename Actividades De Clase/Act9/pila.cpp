#include <iostream>
#include <stack>
using namespace std;

struct num{
	int n;
	num *sig;
};
typedef struct num *Pila;

void initialize(Pila *s){
	*s = NULL;
}

bool empty(Pila *s){
	return *s == NULL;
}

void push(Pila *s,int n){
	struct num *unNum;
	unNum = (struct num *)malloc(sizeof(struct num));
	unNum->n = n;
	unNum->sig = *s;

	*s = unNum;
}

int pop(Pila *s){
	if(!empty(s)){
		struct num *unNum = *s;
		int n = (*s)->n;
		*s = (*s)->sig;
		delete(unNum);
		return n;
	}
	else{
		cout << "Underflow: ";
		return -1;
	}
}
int main(){
	int n;
	Pila unaPila;
	initialize(&unaPila);
	cout << "Digite un numero: ";
	while(cin >> n){
        push(&unaPila,n);
        cout << "Digite un numero: ";
	}
	pop(&unaPila);
	cout << "El segundo numero es: " << pop(&unaPila);
	return 0;
}
