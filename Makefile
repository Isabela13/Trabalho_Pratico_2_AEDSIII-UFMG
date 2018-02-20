all: exato heuristica
exato: grafo.o operacoes_exato.o
	gcc exato.c grafo.o operacoes_exato.o -o exato -g -Wall -Wextra -Werror -std=c99 -pedantic -O2

grafo.o: grafo.c
	gcc -c grafo.c -g

operacoes_exato.o: operacoes_exato.c
	gcc -c operacoes_exato.c -g

heuristica: grafo.o operacoes_heuristica.o
	gcc heuristica.c grafo.o operacoes_heuristica.o -o heuristica  -Wall -Wextra -Werror -std=c99 -pedantic -O2

operacoes_heuristica.o: operacoes_heuristica.c
	gcc -c operacoes_heuristica.c -g

clean:  
	rm *.o
