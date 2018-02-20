#ifndef OPERACAO
#define OPERACAO

int comb(Grafo *g, int *input , int n) ;
int conjIdependente(Grafo *g, int n_filiais,int *vet , int tamanho_vet);
int calculapeso(Grafo *g, int n_filiais,int *vet , int tamanho_vet);
int imprime(Grafo *g, int *input , int n, int peso_max) ;


#endif //OPERACAO