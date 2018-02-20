#ifndef TAD_GRAFO
#define TAD_GRAFO

#define N    100000

typedef struct {
    int y;
    //int peso;
    struct Aresta *prox; // prox na lista de  adj  
}Aresta;

//estrutura do vertice
typedef struct {
    int x; // indice do vertice
    int peso;
    struct Aresta *prox; //apotador para a aresta 
}Vertice;

//estrutura do grafo 
// A estrutura do grafo possui um apontador para o vertice (que possui um para a aresta)
typedef struct {
    Vertice *Vertice[N];
    int grau[N];
    int nvertices;
    int nArestas;
 }Grafo;


void initialize_graph(Grafo **g);
void insert_Aresta(Vertice *v, Aresta *e);
void create_link(Grafo **g, int x, int y, int peso);
void print_graph(Grafo *g, int m_arestas);
void grafo_apaga(Grafo *g, int m_arestas);

#endif // TAD_GRAFO