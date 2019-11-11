#include <iostream>
using namespace std;

struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;
Arbol crearArbol(int x);
void asignarIzq(Arbol a, int unDato);
void asignarDer(Arbol a, int unDato);
void agregarNodo(Arbol a);
int izq = 0,der = 0;
void recorrerIzq(Arbol a);
void recorrerDer(Arbol a);
int suma(Arbol aux);
int contar(Arbol &a);

int main(){
    int raiz = 0,total=0,izquierda=0;
    cout << "Inicializando arbol...\nValor contenido en la raiz: ";
    cin >> raiz;
    
    Arbol arbol = crearArbol(raiz);
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar\n\t2) Cantidad de niveles\n\t3) Cantidad de nodos"
            << "\n\t4) Suma de los nodos\n\t5) Salir\tSu opcion: ";
        cin >> opcion;
        switch(opcion){
            case 1: agregarNodo(arbol);
            break;
            case 2:
				izq=0, der=0; 
				recorrerIzq(arbol->izq);
				recorrerDer(arbol->der);
				if(der>=izq){
					cout << "El arbol posee: "<< der << " niveles" << endl;
				}else{
					cout << "El arbol posee: "<<izq<<" niveles" << endl;
				}
            break;
			case 3:
				cout << "Total de nodos: " << contar(arbol) <<endl;
            break;
            case 4:
            	total = suma(arbol);
				cout << "La suma de los nodos es: " << total << endl;
            break;
        	case 5: continuar = false;
        	break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
    
    return 0;
}
Arbol crearArbol(int x){
    Arbol p = new Nodo;
    p->info = x;
    p->izq = NULL;
    p->der = NULL;
    return p;
}
void asignarIzq(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->izq != NULL)
        cout << "Error: subarbol IZQ ya existe" << endl;
    else
        a->izq = crearArbol(unDato);
}
void asignarDer(Arbol a, int unDato){
    if(a == NULL)
        cout << "Error: arbol vacio" << endl;
    else if(a->der != NULL)
        cout << "Error: subarbol DER ya existe" << endl;
    else
        a->der = crearArbol(unDato);
}
void agregarNodo(Arbol a){
    int numero = 0;
    cout << "Numero a agregar: ";
    cin >> numero;
    
    Arbol p = a;
    while(true){
        if(numero == p->info){
            cout << "Error: " << numero << " ya existe" << endl;
            return;
        }
        else if(numero < p->info){//ir a la izquierda
            if(p->izq == NULL)
                break;
            else
                p = p->izq;
        }
        else{
            if(p->der == NULL)
                break;
            else
                p = p->der;
        }
    }
    if(numero < p->info)
        asignarIzq(p, numero);
    else
        asignarDer(p, numero);
}
void recorrerIzq(Arbol a){
	if (!a)
	return;
	else{
		izq++;
		recorrerIzq(a->izq);
	}
}
void recorrerDer(Arbol a){
	if (!a)
	return;
	else{
		der++;
		recorrerDer(a->der);
	}
}
int suma(Arbol aux){
	if(aux != NULL){
		int raiz = aux->info;
		int i = suma(aux->izq);
		int d = suma(aux->der);
		return raiz + i + d;
	}
	return 0;
}
int contar(Arbol &a){
	if(a != NULL){
		int r = 1;
		int i = contar(a->izq);
		int d = contar(a->der);
		return r + i + d;
	}
	return 0;
}
