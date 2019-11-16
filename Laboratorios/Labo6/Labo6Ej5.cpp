#include <iostream>
using namespace std;

struct Nodo{//struct para la lista (cola)
	int n;
	Nodo *sig;
};
struct nodo{//struct para el arbol binario de busqueda
    int dato;
    nodo *izq;
    nodo *der;
};

class ABB{
private:
    nodo *pArbol;
public:
    ABB(void);
    void operaciones(Nodo *lista);
    void mostrarPre(void);
    void mostrarIn(void);
    void mostrarIn(nodo *);
    void mostrarLista(Nodo *lista);
    void insNodo(int);
    void insNodo(nodo **, int);

};

ABB::ABB(void){
    pArbol = NULL;
}
void ABB::insNodo(int dato){
    insNodo(&pArbol, dato);
}
void ABB::insNodo(nodo **p, int dato){
    if(!(*p)){
        *p = new nodo;
        (*p)->dato = dato;
        (*p)->izq = (*p)->der = NULL;
    }
    else
        if(dato < (*p)->dato){
            insNodo(&((*p)->izq), dato);
        }
        else
            if(dato > (*p)->dato){
                insNodo(&((*p)->der), dato);
            }
            else
                cout << "El nodo ya existe\n";
}
void ABB::mostrarIn(void){
	mostrarIn(pArbol);
}
void ABB::mostrarIn(nodo *p){
	if(p != NULL){
        mostrarIn(p->izq);
        cout << " " << p ->dato;
        mostrarIn(p->der);
    }
}
void ABB::mostrarLista(Nodo *lista){
	if(!lista){
		return;
	}else{
		cout << " " << lista->n << endl;
		mostrarLista(lista->sig);
	}
}
void ABB::operaciones(Nodo *lista){
    int dato=0,cont=0;
    while(cont<5){
        dato = lista->n;
		insNodo(dato);
		lista = lista->sig;
		cont++;
    }
	cout << "\nMostrar in-orden:" << endl;
    mostrarIn();
}

int main(){
    ABB Arbol;
	int n=0,cont=0;
	
	Nodo *pInicio = NULL;
	do{
		Nodo *nuevo = new Nodo;
		cout << "Ingrese un numero: "; cin >> n;
		cont++;
		nuevo->sig = NULL;
		nuevo->n = n;
		if(!pInicio){
			pInicio = nuevo;
		}else{
			Nodo *aux = pInicio;
			
			while(aux->sig != NULL){
				aux = aux->sig;
			}
			aux->sig = nuevo;
		}
	}while(cont<5);
	cout << "LISTA: "<< endl;
	Arbol.mostrarLista(pInicio);
	Arbol.operaciones(pInicio);

    return 0;
}
