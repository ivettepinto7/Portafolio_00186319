#include <iostream>
#include <string>
using namespace std;

struct TOrden{
    int revueltas;
    int frijolConQueso;
    int queso;
    bool arroz;
    ;
};
typedef struct TOrden Orden;

Orden solicitarOrden(){
    Orden p;
    cout << "Cantidad de revueltas: "; cin >> p.revueltas;
    cout << "Cantidad de frijol con queso: ";   cin >> p.frijolConQueso;
    cout << "Cantidad de queso: "; cin >> p.queso;
  	cout << "1. Arroz \t0. Maiz "; cin >> p.arroz;
    return p;
}

void mostrarOrden(Orden p){
    cout << "Revueltas: " << p.revueltas << endl;
    cout << "Frijol con queso: " << p.frijolConQueso << endl;
    cout << "Queso: " << p.queso << endl;
    if(p.arroz){
    	cout << "La orden es de arroz" << endl;
	}else{
		cout << "La orden es de maiz" << endl;
	}
    cout << endl;
}

struct TNodo{
    Orden dato;
    struct TNodo *sig;
};
typedef struct TNodo Nodo;
Nodo *pInicio;

void insertarInicio(Orden p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = pInicio;
    
    pInicio = nuevo;
}

void insertarFinal(Orden p) {
    Nodo *nuevo = new Nodo;
    nuevo->dato = p;
    nuevo->sig = NULL;
    
    if (pInicio == NULL) {
        pInicio = nuevo;
    } else {
        Nodo *p = pInicio;
        Nodo *q = NULL;
        while (p != NULL) {
            q = p;
            p = p->sig;
        }
        q->sig = nuevo;
    }
}

void agregarOrden(){
    Orden p = solicitarOrden();
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "\t1) Al principio\n\t2) Al final"
            << "\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: insertarInicio(p);
                continuar = false;
            break;
            case 2: insertarFinal(p);
                continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);
}

void mostrarLista() {
    Nodo *s = pInicio;

    while (s != NULL) {
        mostrarOrden(s->dato);
        s = s->sig;
    }
}

int main(){
    cout << "Inicializando..." << endl;
    pInicio = NULL;
    
    bool continuar = true;
    do{
        int opcion = 0;
        cout << "Menu: \n\t1) Agregar Orden\n\t2) Ver Orden"
            << "\n\t3) Salir\n\tOpcion elegida: ";
        cin >> opcion;
        switch(opcion){
            case 1: cout << "Agregando..." << endl;
                agregarOrden();
            break;
            case 2: cout << "Listando..." << endl;
                mostrarLista();
            break;
            case 3: continuar = false;
            break;
            default: cout << "Opcion erronea!" << endl;
            break;
        }
    }while(continuar);

    return 0;
}
