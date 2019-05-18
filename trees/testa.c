#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include "arvores.h"

int main(){

	node root, teste;

	// printf("%d\n", root.keys[0]);

	// insertKey(3, &root);

	teste = BTreeCreate();
	printf("%d\n", teste.numKeys);
	teste.keys[0] = 1;
	teste.keys[1] = 4;
	teste.keys[2] = 7;

	printf("Posicao: %d\n", BTreeSearch(&teste, 13) + 1);

	// printf("%d\n", root.keys[0]);



	return 0;
}
