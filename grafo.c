#include "grafo.h"
#include <stdlib.h>
#include <stdio.h>


void initialize_graph(Grafo **g) {
    int i;

    (*g)->nvertices = 0;
    (*g)->nArestas = 0;

    for (i = 0; i < N ; i++) { 
        (*g)->grau[i]=0;
        (*g)->Vertice[i]=NULL;
    }
}


// cria a ligação que o vertice x tem com y
void insert_Aresta(Vertice *v, Aresta *e) {
    e->prox = v->prox;
    v->prox = (struct Aresta*) e;

}



void create_link(Grafo **g, int x, int y, int peso) { // a funcao cria uma ligaçao entre o vertice passado e o peso pra esse vertice, ele aloca o vertice aqui
    Vertice *v;
    Aresta *e;
    if (!(*g)->Vertice[x]) {
        v = malloc(sizeof(Vertice));
        if (!v) {
            return;
        }
        v->x = x;
        v->peso=peso;
        (*g)->Vertice[x] = v;
        (*g)->nvertices+=1;
    }else {
        v = (*g)->Vertice[x];
    }

    e = malloc(sizeof(Aresta));
    e->y = y;
    insert_Aresta(v, e);

}

void print_graph(Grafo *g, int m_arestas) {
    int i;
    Vertice *v;
    Aresta *e;

   
    for (i=0; i<m_arestas+1; i++) {
        v = g->Vertice[i];
        if (v) {
            printf("Vertice %d(%d): ", v->x,v->peso);
            for (e = (Aresta*) v->prox; e; e = (Aresta*) e->prox) {
                printf("%d\t",e->y );
            }
            printf("\n");
        }
    }
}


void grafo_apaga(Grafo *g, int m_arestas) {
    if (g == NULL){
     return;
    }
    int i;
    Vertice *v;
    Aresta *e;
    Aresta *aux;
    for (i=0; i<m_arestas+1; i++) {
        v = g->Vertice[i];
        if (v) {
            for (e = (Aresta*) v->prox; e; e = (Aresta*) e->prox) {
               //aux=e->y;

               ///free(aux);
            }
          
        }
    }
    free(g->Vertice);
    free(g);
}


