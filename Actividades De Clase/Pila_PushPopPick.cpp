#include <iostream>
using namespace std;

struct Pila{
	float elementos[4];
	int top;
};
void initialize(Pila *s){
	s->top = -1;
}
bool empty(Pila *s){
	return s->top < 0;
}
void push(Pila *s, float e){
	if(s->top < 3){
		(s->top)++;
		s->elementos[s->top] = e;
	}
}
void pop(Pila *s, float *e){
	if(s->top >= 0){
		*e = s->elementos[s->top];
		(s->top)--;
	}
}

float pick(Pila *s){
	if(empty(s))
		return -1;
	float a = 0, b = 0,c=0,d=0;
	pop(s, &a);
	if(empty(s))
		return -1;
	pop(s, &b);
	pop(s,&c);
	pop(s,&d);
	push(s,d);
	push(s, c);
	push(s, b);
	push(s, a);
	return d;
}
float obtenerult(Pila *s){
	if(empty(s))
		return -1;
	float a = 0, b = 0,c=0,d=0;
	pop(s, &a);
	if(empty(s))
		return -1;
	pop(s, &b);
	pop(s,&c);
	pop(s,&d);
	return d;
}

int main(){
	Pila unaPila;
	initialize(&unaPila);
	
	push(&unaPila, 2);
	push(&unaPila, 5);
	push(&unaPila, 10);
	push(&unaPila, 1);

	
	float ult = pick(&unaPila);
	cout << "Ultimo con pila intacta: " << ult <<endl;
	
	float u = obtenerult(&unaPila);
	cout << "Ultimo con pila vacia: " << u << endl;
	
return 0;
}
