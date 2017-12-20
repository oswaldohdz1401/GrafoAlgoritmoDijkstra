void dijkstra (Lista *A){
	inicializaListaDijkstra(A);
	
}
void inicializaListaDijkstra(Lista *A){
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
