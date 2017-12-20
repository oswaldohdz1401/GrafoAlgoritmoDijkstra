#include<string.h>
#include<stdio.h>
typedef struct arista Arista;
typedef struct vertice Vertice;
typedef void* Dato;
struct arista{
	int destino;
	int peso;
};
struct vertice{
	int id;
 	int n_aristas;
 	/*---------*/
 	int distancia;
    int visitado;
	int previo;
	void* listaAristas;
};
Dato creaDatoArista(int d,int p,Arista *aux){
	aux->destino = d;
	aux->peso = p;
	return (Dato*)aux;
}
Dato creaDatoVertice(int idVertice,int cantidadDeAristas,void* aristas,Vertice  *nuevo){
	nuevo->id = idVertice;
	nuevo->n_aristas += cantidadDeAristas;
	nuevo->listaAristas = aristas;
	return  (Dato)nuevo;
}
void imprimeDatoVertice(Vertice  consulta){
	printf("ID de Vertice: %d\n",consulta.id);
	printf("Numero de Aristas Adyacentes a este VERTICE: %d\n", consulta.n_aristas);
}

