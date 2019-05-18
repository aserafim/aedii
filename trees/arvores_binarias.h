#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NUMNODES 20

typedef struct nodetype{
	int info; //retorna informacoes do ponteiro
	int left; //retorna o filho a esquerda
	int right; //retorna o filho a direita
	int father; //retorna o pai
}nodetype;

typedef struct nodetype node[NUMNODES];


//Funcao para inicializar uma arvore

bool createTree(node no){

	no = malloc(sizeof node);

	for(int i=0; i<20; i++){

		node[i] -> info = 0;
		node[i] -> left = 0;
		node[i] -> right = 0;
		node[i] -> father = 0;

	}

	//Definindo a raiz
	node[0] -> father = -1;

	return no;

}