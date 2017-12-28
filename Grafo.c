#include  "prototipos.h"

main(){
    //Creamos una lista de tipo GRAFO
    Lista Grafo;
    inicializa(&Grafo);
	crea_grafo(&Grafo);
	//dijkstra(&Grafo);
	imprimeListaGrafo(Grafo);
	
}
void crea_grafo(Lista *G){
	FILE *archivo;
	char caracter;
	archivo = fopen("prueba.txt","r");
	int n = 0;
	if (archivo == NULL){printf("\nError de apertura del archivo. \n\n");exit(1);}
	else{
	    while(!feof(archivo)){
			caracter = fgetc(archivo);
            if(fgetc(archivo) == ':'){
            	n = caracter;
			}  
        }
        reserva_grafo(G,(int)n-48);
	}
}
void reserva_grafo(Lista *g,int n){
    int i=0,j=0,k=0;
    int cantidadAristas = 0;
    if((n>1)||(n != 0)){
        for(i=0;i<n;i++){
        	Dato nuevoDatoVertice;
    		Vertice *v = (Vertice *)malloc(sizeof(Vertice));
    		
			Lista *aristas = (Lista*)malloc(sizeof(Lista));
			Dato nuevoDatoArista;
			
    		inicializa(aristas);
        	cantidadAristas = saleCantAristasAdyacentes(i);
        	for(j=0;j<cantidadAristas;j++){
        		
        		Arista *A = (Arista*)malloc(sizeof(Arista));
        		setArista(A,j+k);
        		nuevoDatoVertice = (Dato)(A);
        		insertaFinal(aristas,nuevoDatoVertice);
			}
			printf("\n\n");
			nuevoDatoVertice=creaDatoVertice(i,cantidadAristas,(void*)(aristas),v);
			insertaFinal(g, nuevoDatoVertice);
			k=j;
		}
	}	
}
void setArista(Arista * A,int n){
    int destino = 0;
    int peso = 0;
    destino = saleDestino(n);
    peso = salePeso(n);
    creaDatoArista(destino,peso,A);
}
/*----------------------------------------------------------------------------*/
void iniDatoVertice(Vertice *consulta){
	consulta -> distancia = MAX;
	consulta -> visitado = 0;
	consulta -> previo = -1;
}
void iniVertices(Lista *A){
	Dato *ni;
	Nodo * aux;
	aux= A->inicio;
	if(esVacia(*A)!=1){
		while(aux!=NULL){
			ni=(aux->contenido);
			iniDatoVertice(ni);
			aux= aux->sig;
		}
	}else{
		 printf("Lista vacia");
	}
}
Dato regresaNodoMejorPeso(Lista A){
	Nodo *aux;
	aux = A.inicio;
	Vertice a_comparar;
	int mejorDistancia = 0;
	int comparador;
	Nodo *pos = A.inicio;
	Dato *mejor;
	while(esVacia(A) != 1 && aux!=NULL){
		a_comparar = (*(Vertice *)(aux->contenido));
		comparador = a_comparar.distancia;
		if(comparador <= mejorDistancia){
			mejorDistancia = comparador;
			mejor = pos->contenido;
			pos = pos->sig;
		}
		aux = aux->sig;
	}
	return (Dato)mejor;
}
Dato regresarElFinal(Lista A){
	Dato final;
	Nodo *aux;
	aux = A.fin;
	final = aux->contenido;
	return (Dato)final;
}
Dato regresaElInicio(Lista *A){
	Dato inicio;
	Nodo *aux;
	aux = A->inicio;
	inicio = (aux->contenido);
	Vertice *consulta = inicio;
	consulta -> distancia = 0;
	return (Dato)inicio;
}
Dato obtenenVerticeYBuscalo(Lista A, int d){
	Nodo *aux = A.inicio;
	Vertice a;
	while(aux != NULL){
		a = (*(Vertice *)(aux->contenido));
		if (a.id == d){
			return (Dato)aux->contenido;
		}
		aux = aux->sig;
	}
}
/*
void relacion(Lista *caminoCorto, Vertice encontrado , Vertice mejor){
	if(encontrado.distancia + mejor.distancia < mejor->distancia){
		
	}
}*/
int verificaEnGrafo(Lista A,int a, int b){
	int primero = 0;
	int segundo = 0;
	Nodo *aux = A.inicio;
	Dato dComparar;
	Vertice *vComparar;
	while(aux != NULL){
		dComparar = aux->contenido;
		vComparar = &(*(Vertice *)(dComparar)); 
		if(vComparar->id == a){primero = 1;}
		if(vComparar->id == b){segundo = 1;}
		if(primero && segundo){
			return 1;
		}
		aux = aux->sig;
	}
	return 0; 
}
int obtenDistanciaDeAdyacente(Lista A,int d){
	Nodo *aux = A.inicio;
	Vertice a;
	while(aux != NULL){
		a = (*(Vertice *)(aux->contenido));
		if (a.id == d){
			return a.distancia;
		}
		aux = aux->sig;
	}
}
void dijkstra (Lista *A,int a, int b){
	Vertice *mejor = (Vertice *)malloc(sizeof(Vertice));
	int i;
	int tam;
	int w = 0;
	Lista caminoCorto;	inicializa(&caminoCorto);
	Vertice *ultimo = (Vertice *)malloc(sizeof(Vertice));
	Lista *ady;
	if(verificaEnGrafo(*A,a,b)){
		printf("HOLA");
		iniVertices(A);
		insertaInicio(&caminoCorto,regresaElInicio(A));
			ultimo = &(*(Vertice *)((Dato)regresarElFinal(caminoCorto)));
			if(ultimo->visitado == 0){
				ultimo->visitado = 1;
				//obtenemos el tama�o de la lista de notos ayacentes
				inicializa(&ady); 
				ady = &(*((Lista*)ultimo->listaAristas));
				//Vamos a recorrer sus adyacentes del ultimo
				//Tenos que recorrer cada uno de los vertices adyacentes de la arista
				//Encontrando el mejor camino
				Nodo *AUX = ady->inicio;
				Arista *a = (Arista*)malloc(sizeof(Arista));
				while(AUX != NULL && ultimo->id != b){
					a = &(*((Arista*)(AUX->contenido)));
					if(a->visitado == 0 && ultimo->distancia + a->peso < obtenDistanciaDeAdyacente(*A,(int)a->destino)){
						mejor -> id = ultimo->id;
						mejor->distancia = ultimo->distancia + a->peso ;
						if(mejor -> distancia > ultimo->distancia + a->peso){
							mejor -> distancia = ultimo->distancia + a->peso;
							mejor -> visitado = 1;
						}
					}
					a->visitado = 1;
					AUX = AUX->sig;
				}
				insertaFinal(&caminoCorto,(Dato)obtenenVerticeYBuscalo(*A,mejor->id));
			}
	}
	imprimeListaGrafo(caminoCorto);	
}
/*-----------------------------------------*/
void imprimeArista(Arista A){
	printf("\tDestino: %d  Peso: %d\n", A.destino,A.peso);
	
}
void imprimeListaVertices(Lista A){
	Arista a;
	Nodo *aux;
	if(esVacia(A)==0){
		aux= A.inicio;
		while(aux!=NULL){
			a =*((Arista*)(aux->contenido));
			imprimeArista(a);
			aux= aux->sig;
		}
	}else{
		 printf("NO existen aristas adayacentes en el VERTICE");
	}
}
void imprimeVertices(Dato consultando){
	Lista vertices;
	Vertice a_imprimir=(*(Vertice *)(consultando));
	imprimeDatoVertice(a_imprimir);
	vertices =   * ((Lista*)a_imprimir.listaAristas);
	imprimeListaVertices(vertices);
}
void imprimeListaGrafo(Lista A){
	Dato  aimprimir;
	Nodo * aux;
	aux= A.inicio;
	if(esVacia(A)!=1){
		while(aux!=NULL){
			aimprimir=(aux->contenido);
			imprimeVertices(aimprimir);
			aux= aux->sig;
		}
	}else{
		 printf("Lista vacia");
	}
}
