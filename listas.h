#include  "dato.h"
#include <stdlib.h>
typedef struct Nodo Nodo;
typedef struct Lista Lista;


struct Nodo{
	Dato contenido;
	Nodo * sig;
};
struct Lista{
	int tam;
	Nodo * inicio;
	Nodo * fin;
};
Nodo* creaNodo(Dato nuevo){
	Nodo * aux;
	aux = (Nodo*) malloc(1*sizeof(Nodo));
	aux->contenido = nuevo;
	aux->sig=NULL;
	return aux;
}
void inicializa(Lista * A){
	A->tam=0;
	A->inicio=NULL;
	A->fin= NULL;
}
int esVacia(Lista A){
	if(A.inicio==NULL && A.fin==NULL && A.tam==0){
		return 1;
	}
	return 0;
}
void insertaFinal(Lista *A,Dato nuevo){
	Nodo *porInsertar=creaNodo(nuevo);
	if(esVacia(*A)==1){
		A->inicio=porInsertar;
	}else{
		A->fin->sig=porInsertar; 
	}
	A->fin=porInsertar;
	A->tam++;
}
void insertaInicio(Lista *A,Dato nuevo){
	Nodo *porInsertar=creaNodo(nuevo);
	if(esVacia(*A)==1){
		A->fin=porInsertar;
	}else{
		porInsertar->sig=A->inicio;
	}
	A->inicio=porInsertar;
	A->tam++;
}
