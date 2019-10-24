#include <iostream>//ejercicio 7
using namespace std; 
struct num{
       int numero;   
       num *sig;
}; 
typedef struct num *Tlista;

void imprimirMenu(); 
void insertar(Tlista &lista, int n);
void mostrarLista(Tlista lista);
void ocurrencias(Tlista &lista, int n);  

int main()
{
    Tlista unaLista = NULL;
    int opc,n;  
    do{   
		imprimirMenu();
		cin>> opc; 
        switch(opc)
        {  
            case 1: 
                 cout<< "\n Ingrese un numero: "; 
				 cin>> n;
                 insertar(unaLista, n );
            break;  
            case 2:  
                mostrarLista(unaLista);
            break; 
            case 3:
                cout<<"Numero a eliminar ocurrencias: "; 
				cin>> n;
                ocurrencias(unaLista, n);
            break; 
            default:
            	cout << "Opcion erronea!"<<endl;
            break;
         } 
        cout<<endl; 
    }while(opc != 0); 
   return 0;
}
void imprimirMenu(){
	cout<<"MENU PRINCIPAL" << endl;
	cout << "\t1) Agregar numero" << endl;
	cout << "\t2) Mostrar lista" << endl;
	cout << "\t3) Eliminar ocurrencias" << endl;
	cout << "\t0) Salir \tSu opcion: ";
}
void insertar(Tlista &lista, int n){
    Tlista t, q = new(struct num); 
    q->numero  = n;
    q->sig = NULL; 
    if(lista == NULL){
        lista = q;
    }else{
        t = lista;
        while(t->sig != NULL){
            t = t->sig;
        }
        t->sig = q;
    } 
}  
void mostrarLista(Tlista lista){
     while(lista != NULL){
          cout << lista->numero << endl;
          lista = lista->sig;
     }
}  
void ocurrencias(Tlista &lista, int n){
    Tlista q, aux;
    q = lista;
    aux = lista; 
    while(q != NULL){
        if(q->numero == n){
            if(q == lista){
                lista = lista->sig;
                delete(q);
                q = lista;
            }else{
                aux->sig = q->sig;
                delete(q);
                q = aux->sig;
            }
        }else{
            aux = q;
            q = q->sig;
        } 
    } 
    cout<<"Ocurrencias eliminadas con exito"<<endl;
}  
