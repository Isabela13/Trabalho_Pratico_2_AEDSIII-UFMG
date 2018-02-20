#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grafo.h"


int calculapeso(Grafo *g , int *vet, int tamanho_vet ){
    Vertice *v;
    Aresta *e;
    int peso=0,peso_max=0;
    int i,indice,count=1; 
    


    for (i = 1; i <= tamanho_vet; i++){
        indice=vet[i];
        v = g->Vertice[indice];
        if (v){
            peso=(v->peso);
            if(peso>peso_max){
                peso_max=peso;
            }            
        }

    }

    return peso_max;
        
} 


int combinacao(Grafo *g, int n_vertices) {
    int i,j,k=1,flag=0,count=1, indice,l,peso_max=0,m,n,peso_total=0;
    Vertice *v;
    Aresta *e;
    int *vet_filial_excluida , *vet_combinacao, *vet_restantes , *vet_entrada;
    vet_filial_excluida = (int*) malloc((n_vertices)*sizeof(int));
    vet_combinacao = (int*) malloc((n_vertices)*sizeof(int));
    vet_restantes = (int*) malloc((n_vertices)*sizeof(int));
    vet_entrada = (int*) malloc((n_vertices)*sizeof(int));
    int tam_vet=1, tam_vet_com=1, tam_vet_resta=1;
    vet_filial_excluida[1]=0;

    
    for (i = 1; i <= n_vertices; i++){
        vet_entrada[i]=count++;
        vet_restantes[i]=vet_entrada[i];
    }

    for ( i=1; i<= n_vertices ; i++){
	    v = g->Vertice[i];
	    if (v){
            peso_max=calculapeso(g,vet_restantes,n_vertices) ;
            if(v->peso==peso_max){ // se for o peso max enao tiver na filial que for esquina
		        for(j = 1; j <= tam_vet; j++){
		            if (v->x == vet_filial_excluida[j]){
		                    flag=1;
		                    break;
		                    }else{
		                        flag=0;
		                    }
		            }
		            if(flag==0){ // marca as esquinas dela no vetor filial excuido
		                vet_combinacao[tam_vet_com]=v->x;
		                tam_vet_com++;
		                for (e = (Aresta*) v->prox; e; e = (Aresta*) e->prox) {
		                    vet_filial_excluida[tam_vet]=e->y;
		                    tam_vet++;
		                }
                        for (m= 1; m <= n_vertices; m++){
                            for (n = 1; n <= tam_vet; n++){
                                if(vet_filial_excluida[n]==vet_entrada[m] || vet_entrada[m]==v->x){
                                    vet_restantes[m]=0;
                                }
                            }
                        }
                    peso_total=peso_total+peso_max;

		            }

            }

	    }

	}
    printf("%d %d\n",(tam_vet_com-1),peso_total );
    for (i = 1; i < tam_vet_com; i++){
        printf("%d ", vet_combinacao[i]);
    }
    
    
}
