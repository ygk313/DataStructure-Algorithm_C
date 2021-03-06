#include <stdio.h>
#include <stdlib.h>

typedef int TElement;
typedef struct LinkedNode{
	TElement data;
	struct LinkedNode* left;
	struct LinkedNode* right;
}TNode;

TNode* root;

void init_tree(){ root = NULL;
}
int is_empty(){ return root == NULL;
}

TNode* create_tree(TElement e, TNode* left, TNode* right){
	TNode* new = (TNode*)malloc(sizeof(TNode));
	new->data = e;
	new->left = left;
	new->right = right;
	return new;
}

TNode* get_root(){ return root;
}

int calc_size(TNode*n){
	if (n==NULL) return 0;
	else return n->data + calc_size(n->left)+calc_size(n->right);
}

//int evaluate(TNode*n){
//	int op1, op2;
//	if (n==NULL) return 0;
//	if (n->left == NULL && n->right == NULL) return n->data;
//	else{
//		op1 = evaluate(n->left);
//		op2 = evaluate(n->right);
//		switch(n->data){
//			case '+': return op1+op2;
//			case '-': return op1-op2;
//			case '/': return op/op2;
//			case '*': return op1*op2;
//		}
//		return 0;
//	}
//}

void print_value(TNode* n, int value){
	if (n==NULL) return;
	if (n->data<value) {
		printf("\n%d보다 작은 노드: %d", value, n->data);
		print_value(n->left, value);
		print_value(n->right, value);
	}
}	

int total(TNode*n){
	if (n==NULL) return 0;
	else return n->data+total(n->left)+total(n->right);
}
void main(){
	TNode* n[4];
	int value;
	init_tree();
	n[0] = create_tree(200, NULL, NULL);
	n[1] = create_tree(500, NULL, NULL);
	n[2] = create_tree(100, n[0], n[1]);
	n[3] = create_tree(50, NULL, NULL);
	root = create_tree(0, n[2], n[3]);
	
	printf("값을 입력하세요:");
	scanf("%d", &value);
	print_value(root, value);
	
	printf("\ntotal: %d", total(root));
}
