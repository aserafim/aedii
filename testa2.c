#include <stdio.h>
#include<stdlib.h>
#include "grafo_listaadj.h"


int main(){
	
	//Declara os grafos
	//para testes
	TipoGrafo grafo1, grafo2, grafo3;
	
	//Inicializa os grafos
	//de teste
	inicializaGrafo(&grafo1, 8);
	inicializaGrafo(&grafo2, 3);
	
	//Declara arestas
	//para testes
	TipoAresta t1, t2, t3;
	
	//Inicaliza as arestas teste
	t1.vdest = 1;
	t1.peso = 8;
	t1.prox = NULL;

	t2.vdest = 3;
	t2.peso = 4;
	t2.prox = NULL;

	//Testando insercao de
	//arestas
//	grafo1.listaAdj[0] = &t1;
//	grafo1.listaAdj[1] = &t2;


//	grafo.listaAdj[0] = &t1; 
//	printf("%d\n", grafo.listaAdj[0] -> vdest);	
	
	//Testando a funcao existeAresta()
	if(existeAresta(0, 1, &grafo1)) printf("Aresta encontrada\n");
	else printf("Aresta inexistente neste grafo\n");

	//Testando funcao insereAresta()
	insereAresta(1,2,4,&grafo1);

	return 0;
}

