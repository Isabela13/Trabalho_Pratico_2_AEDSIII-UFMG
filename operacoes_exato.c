#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "grafo.h"


int conjIdependente(Grafo *g, int n_filiais,int *vet , int tamanho_vet){
    Vertice *v;
    Aresta *e;
    int i,j,l,count=1,flag=0, indice=0;
    int *vet_vizinhos =  (int*) malloc((tamanho_vet)*sizeof(int));
    tamanho_vet--;


    for (i = 1; i <= tamanho_vet; i++){
        count=1;
        indice=vet[i];
        v = g->Vertice[indice];
        if (v){
            for (e = (Aresta*) v->prox; e; e = (Aresta*) e->prox) {
                vet_vizinhos[count]=e->y;
                count++;        
            }

            for ( j = 1; j <= tamanho_vet; j++){
                for ( l = 1; l <= count-1; l++){
                    if ( vet_vizinhos[l]==vet[j] ){
                        return 1;
                    }
                }
            }
                
        }

    }
    //free(vet_vizinhos);
    return 0;
        
}


int calculapeso(Grafo *g, int n_filiais,int *vet , int tamanho_vet ){
    Vertice *v;
    Aresta *e;
    int peso=0;
    int i,j,l,count=1, indice=0; 
    tamanho_vet--;


    for (i = 1; i <= tamanho_vet; i++){
        count=1;
        indice=vet[i];
        v = g->Vertice[indice];
        if (v){
            peso=peso+(v->peso);                
        }

    }

    
    return peso;
        
} 





int comb(Grafo *g, int *input , int n) {
    unsigned int MAX, MASK, NUM ;
    int i, j, r, k ,dependente, peso_max=0,peso=0;
    int *vet_combina;
    for (r=2;r<=n;r++){
        vet_combina=(int*) malloc((n)*sizeof(int)); 
     
        int l = 0;
        for(i=1; i<=n;i++) l++;
            /* Manda o bit 1 para a n-ésima posição. Os bits são invertidos para que a posição n esteja com o bit zero, a fim de marcar
              o final do processo.*/
            MAX = ~(1 << l) ;
         
            // Primeiro número é o 1. 
            NUM = 1;

         
            // Quando o número alcançar MAX, o loop será encerrado.
            while ( MAX & NUM ) {
                /* Conta os bits 1's. */
                MASK = 1 ;
                k = 0 ;
                while ( MAX & MASK ) {
                    if ( NUM & MASK ) k++ ;
                    MASK = MASK << 1 ;
                }
         
                // Monta o resultado somente se a quantidade de bits k é igual a r.
                if ( k == r ) {
                    MASK = 1 ;
                    i = j = 1 ;
         
                    while ( MAX & MASK ) {
                        // Verdadeiro se NUM tem um bit 1 na posição indicada por MASK. 
                        if ( NUM & MASK ) {
                            // Gera a combinação em vet_combina
                            vet_combina[i] = input[j] ;
                            i++ ;
                        }
                        j++ ;
                        // Desloca a máscara 
                        MASK = MASK << 1 ;
                    }
                    // As combinações estão no vetor.

                    dependente=0;
                    //chama a funcao que verifica se o conjunto é idependente
                    dependente=(conjIdependente(g,n,vet_combina,i));
                    //se o confunto NAO for dependente calcula o peso max dele
                    if (!dependente){
                        peso=(calculapeso(g,n,vet_combina,i));
                        if (peso>peso_max){
                            peso_max=peso;
                        }
                        
                    }
                    
                }
        
                NUM++ ;
        }
    }
    free(vet_combina);
    return peso_max;
}



int imprime(Grafo *g, int *input , int n, int peso_max) {
    unsigned int MAX, MASK, NUM ;
    int i, j, r, k ,dependente, peso=0;
    int *vet_combina;
    for (r=n;r<=n;r--){
        vet_combina=(int*) malloc((n)*sizeof(int)); 
     
        int l = 0;
        for(i=1; i<=n;i++) l++;
            /* Manda o bit 1 para a n-ésima posição. Os bits são invertidos para que a posição n esteja com o bit zero, a fim de marcar
              o final do processo.*/
            MAX = ~(1 << l) ;
         
            // Primeiro número é o 1. 
            NUM = 1;

         
            // Quando o número alcançar MAX, o loop será encerrado.
            while ( MAX & NUM ) {
                /* Conta os bits 1's. */
                MASK = 1 ;
                k = 0 ;
                while ( MAX & MASK ) {
                    if ( NUM & MASK ) k++ ;
                    MASK = MASK << 1 ;
                }
         
                // Monta o resultado somente se a quantidade de bits k é igual a r.
                if ( k == r ) {
                    MASK = 1 ;
                    i = j = 1 ;
         
                    while ( MAX & MASK ) {
                        // Verdadeiro se NUM tem um bit 1 na posição indicada por MASK. 
                        if ( NUM & MASK ) {
                            // Gera a combinação em vet_combina
                            vet_combina[i] = input[j] ;
                            i++ ;
                        }
                        j++ ;
                        // Desloca a máscara 
                        MASK = MASK << 1 ;
                    }
                    // As combinações estão no vetor
                    dependente=0;
                    dependente=(conjIdependente(g,n,vet_combina,i));

                    if (!dependente){
                        peso=(calculapeso(g,n,vet_combina,i));
                        if (peso==peso_max){
                            printf("%d %d\n",i-1, peso );
                            for ( l= 1; l < i; l++){
                                printf("%d ",vet_combina[l] );
                            }
                            printf("\n");
                            exit(-1); // ja posso abortar o programa pois ele tera printado o que tem maior numero de vizinhos
                        }
                        
                    }
                    
                }
        
                NUM++ ;
        }
    }
    
    free(vet_combina);
}
