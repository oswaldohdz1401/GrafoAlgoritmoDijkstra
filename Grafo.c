#include  "prototipos.h"

main(){
    //Creamos una lista de tipo GRAFO
    Lista Grafo;
    inicializa(&Grafo);
	crea_grafo(&Grafo);
	dijkstra(&Grafo);
	//imprimeListaGrafo(Grafo);
	
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
	Dato *iniciar;
	Nodo * aux;
	aux= A->inicio;
	if(esVacia(*A)!=1){
		while(aux!=NULL){
			iniciar=(aux->contenido);
			iniDatoVertice(iniciar);
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
Dato regresaElInicio(Lista *A){
	Dato inicio;
	Nodo *aux;
	aux = A->inicio;
	inicio = (aux->contenido);
	Vertice *consulta = inicio;
	consulta -> distancia = 0;
	return (Dato)inicio;
}
Vertice* obtenenVerticeYBuscalo(Lista A, Lista ady){
	Nodo *master = A.inicio;
	Dato *datoMaster;
	Nodo *nodoAdy = ady.inicio;
	Dato *datoAdy;
	
	while(master != NULL && nodoAdy != NULL){
		datoMaster = master->contenido; //Vertice 
		datoAdy    = nodoAdy->contenido;//Aristas Ady
		Vertice* v_comparar = &(*(Vertice*)(datoMaster));//Convertimos a datoMaster a algo de tipo Vertice
		Arista*  a_comparar = &(*(Arista*)(datoAdy));
		if(v_comparar->id == a_comparar->destino){
			if(v_comparar -> visitado == 0){
				v_comparar -> visitado = 1;
			}
			v_comparar->distancia = a_comparar -> destino;
			return v_comparar;
		} 
		master = master->sig;
		nodoAdy = nodoAdy->sig;
	} 
}
/*
void relacion(Lista *caminoCorto, Vertice encontrado , Vertice mejor){
	if(encontrado.distancia + mejor.distancia < mejor->distancia){
		
	}
}*/
void dijkstra (Lista *A){
	int i;
	int tam;
	iniVertices(A);
	Lista caminoCorto;
	inicializa(&caminoCorto);
	insertaInicio(&caminoCorto,regresaElInicio(A));
	Nodo *aux = A->inicio;
	while(esVacia(caminoCorto) != 1 && aux!= NULL){
		Vertice *mejor = &(*(Vertice *)((Dato)regresaNodoMejorPeso(caminoCorto)));
		if(mejor->visitado == 0){
			mejor->visitado = 1;
			//obtenemos el tama�o de la lista de notos ayacentes
			Lista ady; inicializa(&ady); 
			ady = * ((Lista*)mejor->listaAristas);
			//Vamos a recorrer sus adyacentes del mejor
			for(i = 0; i< ady.tam; i++){
				//obtenemos el ID del vertice adyacente
				Vertice* verticeEncontrado = obtenenVerticeYBuscalo(*A,ady);
				//relacion(&caminoCorto,verticeEncontrado,mejor);
			}
		}
		
		aux = aux->sig;
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
