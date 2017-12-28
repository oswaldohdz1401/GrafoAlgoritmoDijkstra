#include  "listas.h"
#include  "lecturaArchivos.h"
#define MAX 100
void crea_grafo(Lista *G);
void reserva_grafo(Lista *g,int n);
void setArista(Arista * A,int n);
void vertices_ady(Lista G);
void vertice_a_adyacente_b(Lista G);
Dato capturaIdVertice();
void imprimeListaGrafo(Lista A);
void dijkstra (Lista *A, int a, int b);
