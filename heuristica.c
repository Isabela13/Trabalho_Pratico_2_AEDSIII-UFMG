#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"
#include "operacoes_heuristica.h"




int main() {
    Grafo *g = malloc(sizeof(Grafo));
    int i,count=1;
    int n_filiais, m_arestas,z_demada,x,y;
    //vetor para guardar os pesos de cada vertice -no indice 1 guarda o peso do vetor 1-
    int *vet= (int*) malloc((n_filiais + 1)*sizeof(int)); 
    // vetor para gerar as combinacoes de todas as filiais 
    int  *vet_filial = (int*) malloc((n_filiais)*sizeof(int)); 

    initialize_graph(&g);

    if (scanf("%d %d",&n_filiais,&m_arestas) == 0){
        exit(-1);
    }

    for (i = 1; i <= n_filiais; i++){
        vet[i]=0;
    }

    for (i = 1; i <= n_filiais; i++){
        if (scanf("%d",&vet[i]) == 0){
            exit(-1);
        }
        
    }


    for ( i = 1; i <= m_arestas; i++){
        if(scanf("%d %d",&x,&y) == 0 ) exit(-1);
        z_demada=vet[x];
        //passa o peso do vertive x para a funcao
        create_link(&g,x,y,z_demada);
        z_demada=vet[y];
        create_link(&g,y,x,z_demada);
    }


    for ( i = 1; i <=n_filiais ; i++){
    	vet_filial[i]=count++;
    	//printf("%d\n",vet_filial[i] );
    }
   // print_graph(g,m_arestas);
    
    combinacao( g,  n_filiais) ;
   

    //free(vet);
   // free(vet_filial);
   // grafo_apaga(g, n_filiais);
    return 0;
}
