#include <iostream>
using namespace std;

struct nodo{
    int info;
    struct nodo *izq;
    struct nodo *der;
};
typedef struct nodo Nodo;
typedef struct nodo *Arbol;
Arbol crearArbol(int n);
void asignarIzq(Arbol a, int unDato);
void asignarDer(Arbol a, int unDato);
void agregarNodo(Arbol a);
int contarPares(Arbol a);
int contarImp(Arbol a);
int contarPosi(Arbol a);
int contarCeros(Arbol a);
int contarNega(Arbol a);
int sumaPares(Arbol a);
int sumaImp(Arbol a);

int main(){
	int raiz = 0;
	cout << "Inicializando...\nValor contenido en la raiz ";
	cin >> raiz;
	
	Arbol arbol = crearArbol(raiz);
	
	bool continuar = true;	
	do{
		int opcion = 0;
		cout << "\nMenu:\n\t1) Agregar nodo\n\t2) Cantidad de nodos pares e impares"
			 << "\n\t3) Suma de nodos pares\n\t4) Suma de nodos impares\n\t5) Cantidad de nodos negativos, ceros y positivos"
		 	 << "\n\t6) Salir \tSu eleccion: ";
		cin >> opcion;
		switch(opcion){
			case 1: agregarNodo(arbol);
			break;
			case 2: 
				cout << "El arbol contiene "<< contarPares(arbol) << " nodo/s pares y " << contarImp(arbol) << " nodo/s impares";
			break;
			case 3: cout << "La suma de los nodos pares es: " << sumaPares(arbol);
			break;
			case 4: cout << "La suma de los nodos impares es: " << sumaImp(arbol);
			break;
			case 5:
				cout << "El arbol contiene: \n" << contarNega(arbol);
				cout << " nodo/s negativos \n" << contarCeros(arbol);
				cout << " nodo/s que son 0 \n" << contarPosi(arbol);
				cout << " nodo/s que son positivos";
			break;
			case 6: continuar = false;
			break;
		}
	}while(continuar);

	return 0;
}
Arbol crearArbol(int n){
    Arbol p = new Nodo;
    p->info = n;
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
int contarPares(Arbol a){
	if(a == NULL){
		return 0;
	}
	else{
		if(a->info % 2 == 0){
			return 1 + contarPares(a->izq) + contarPares(a->der);
		}else{
			return contarPares(a->izq) + contarPares(a->der);
		}
	}
}
int contarImp(Arbol a){
	if(a == NULL){
		return 0;
	}
	else{
		if(a->info % 2 != 0){
			return 1 + contarImp(a->izq) + contarImp(a->der);
		}else{
			return contarImp(a->izq) + contarImp(a->der);
		}
	}
}
int contarPosi(Arbol a){
	if(a == NULL){
		return 0;
	}
	else{
		if(a->info > 0){
			return 1 + contarPosi(a->izq) + contarPosi(a->der);
		}else{
			return contarPosi(a->izq) + contarPosi(a->der);
		}
	}
}
int contarCeros(Arbol a){
	if(a == NULL){
		return 0;
	}
	else{
		if(a->info == 0){
			return 1 + contarCeros(a->izq) + contarCeros(a->der);
		}else{
			return contarCeros(a->izq) + contarCeros(a->der);
		}
	}
}
int contarNega(Arbol a){
	if(a == NULL){
		return 0;
	}
	else{
		if(a->info < 0){
			return 1 + contarNega(a->izq) + contarNega(a->der);
		}else{
			return contarNega(a->izq) + contarNega(a->der);
		}
	}
}
int sumaPares(Arbol a){
	if(a == NULL){
		return 0;
	}
	else{
		if(a->info % 2 == 0){
			return a->info + sumaPares(a->izq) + sumaPares(a->der);
		}else{
			return sumaPares(a->izq) + sumaPares(a->der);
		}
	}
}
int sumaImp(Arbol a){
	if(a == NULL){
		return 0;
	}
	else{
		if(a->info % 2 != 0){
			return a->info + sumaImp(a->izq) + sumaImp(a->der);
		}else{
			return sumaImp(a->izq) + sumaImp(a->der);		}
	}
}
