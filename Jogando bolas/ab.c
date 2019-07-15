#include "ab.h"
#include <stdlib.h>
#include <math.h>


struct node{
	int value;
	int flag; // 0-->FALSE & 1-->TRUE
};

struct bt{
	NODE *vet[MAX];
	int size;
};


BT *create_bt(int h){
	BT *new = (BT *) malloc(sizeof(BT));
	new->size = pow(2, h);
	for(int i=0; i<new->size; i++)
		new->vet[i] = create_node(i+1);	
	return new;
}

NODE *create_node(int value){
	NODE *new = (NODE *) malloc(sizeof(NODE));
	if(new != NULL){
		new->value = value;
		new->flag = 0;
	}
	return new;
}

void delete_bt(BT *tree){
	if(tree != NULL){
		for(int i=0; i<tree->size; i++){
			free((tree->vet)[i]);
		}
		free(tree);
	}
	tree = NULL;
}

int put_ball(BT *tree){
	if(tree == NULL) return -1;
	int f=0, s=0, flag;
	while(s < tree->size-1){
		f = s;
		flag = tree->vet[f]->flag;
		if(flag == 0)
			s = 2*f+1;
		else 
			s = 2*f+2;
		tree->vet[f]->flag = (flag + 1) % 2;
	}
	return tree->vet[f]->value;
}