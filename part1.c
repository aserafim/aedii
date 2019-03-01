#include <stdio.h>
#include<stdlib.h>
#include "grafo_matrizadj.h"

int main(){
	
	TipoGrafo grafo;
	int nv, v1, v2, peso;

	printf("Entre com o numero de vertices do grafo\n");
	scanf("%d", &nv);

	if(inicializaGrafo(&grafo,nv)) printf("Deu certo\n");
	
	printf("Entre com os vertices e o peso da aresta\n");
	scanf("%d %d %d", &v1, &v2, &peso);

	if(insereAresta(v1,v2,peso,&grafo)) printf("Aresta inserida!\n");
	
	printf("Aresta inserida: (%d,%d)=%d\n", v1,v2,peso);

	return 0;

}
