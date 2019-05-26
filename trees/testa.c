#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "arvores.h"

//Variaveis globais
node root, nodeOne, nodeTwo, nodeThree;
int valorBuscado = 15;

int main(){

	//Initializing nodes
	nodeOne = BTreeCreate();
	nodeTwo = BTreeCreate();
	nodeThree = BTreeCreate();

	//Inserting keys on nodeOne
	nodeOne.keys[0] = 10;
	nodeOne.numKeys++;
	nodeOne.keys[1] = 18;
	nodeOne.numKeys++;
	nodeOne.keys[2] = 30;
	nodeOne.numKeys++;
	nodeOne.leaf = false;	//not a leaf anymore
	nodeOne.sons[0] = &nodeTwo;
	nodeOne.sons[1] = &nodeThree;
	
	//Inserting keys on nodeTwo
	nodeTwo.keys[0] = 3;
	nodeTwo.numKeys++;
	nodeTwo.keys[1] = 8;
	nodeTwo.numKeys++;
	nodeTwo.keys[2] = 9;
	nodeTwo.numKeys++;

	//Inserting keys on nodeThree
	nodeThree.keys[0] = 15;
	nodeThree.numKeys++;
	/*
	nodeThree.keys[1] = 8;
	nodeThree.numKeys++;
	nodeThree.keys[2] = 9;
	nodeThree.numKeys++; */

	int result = BTreeSearch(&nodeOne, valorBuscado);

	//Printing the key we are looking for, k = 8
	//printf("Chave buscada: %d\n", nodeOne.sons[0] ->keys[1]);

	if(result >= 0) printf("Valor buscado: %d. Valor encontrado na posicao: %d\n", valorBuscado, result + 1);
	else printf("Valor buscado: %d. Valor nao encontrado!\n", valorBuscado);

	// printf("%d\n", root.keys[0]);



	return 0;
}
