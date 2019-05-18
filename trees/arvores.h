#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 300

//Size of the nodes
//and Key type
#define t 2
typedef int Key;

//Node structure
typedef struct node{
	Key keys[2 * t - 1];
	struct node* sons[2 * t];
	int numKeys;
	bool leaf;
}node;

//Creating an empty B-Tree
node BTreeCreate(){
	node *root, exit;
	root = malloc(sizeof(node));
	root->leaf = true;
	root->numKeys = 0;
	exit = *root;
	// return *root;
	return exit;
}

int BTreeSearch(node *root, Key k){
	//First considering only one node
	int i = 0;
	while(i < (2*t-1) && k > root -> keys[i]) i++;
	if ((i < (2*t-1)) && (k == root -> keys[i])) return i;
	else return -1;
}

//Inserting a key into a node
bool insertKey(Key k, node *root){

	//testing insertion
	
	root ->keys[0] = k;
	return true;
}
