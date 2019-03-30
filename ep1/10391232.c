/***************************************************
* DISCIPLINA: ALGORITMOS E ESTRUTURAS DE DADOS II
* PROFESSOR: HELTON HIDERALDO BISCARO		
* EP1 - ALGORITMO DE PRIM
* ALEFE SERAFIM - NUSP: 10391232*/
/**************************************************/

#include <stdio.h>
#include <stdlib.h>
#define MAXARQ 350 			//tamanho maximo de entradas para o vetor que armazena o grafo

//VARIAVEIS GLOBAIS
FILE *grafo, *saida;			//ponteiro para o arquivo grafo a ser lido e para a saida
int vetorGrafo[MAXARQ];
int ch1 = 0, ch2 =0 , ch3 = 0;		//variavel de apoio para leitura dos caracteres do arquivo grafo

//Funcao principal
int main(int argc, char *argv[]){
	
	int i = 2, j = 0;		//variaveis de iteracao


	//Lendo o arquivo e armazendo no vetor
	grafo = fopen(argv[1], "r");
	fscanf(grafo, "%d %d", &ch1, &ch2);
	vetorGrafo[0] = ch1;
	vetorGrafo[1] = ch2;

	while(!feof(grafo)){
		fscanf(grafo, "\n%d %d %d\n", &ch1, &ch2, &ch3);
		vetorGrafo[i] = ch1;
		i++;
		vetorGrafo[i] = ch2;
		i++;
		vetorGrafo[i] = ch3;
		i++;
	}

	fclose(grafo);
	
	//Abrindo arquivo de saida
	saida = fopen(argv[2], "a");

	//Testando entrada e saida - APAGAR!!!
	while(j != i){

		fprintf(saida, "%d\n",vetorGrafo[j]);
		j++;
	}
	fclose(saida);

	return 0;
}
