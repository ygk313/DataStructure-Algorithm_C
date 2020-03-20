#include <stdio.h>
#include <stdlib.h>

typedef char TElement;
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

int get_count(TNode* n){
	if (n==NULL) return 0;
	else return 1+get_count(n->left)+get_count(n->right);
}

int get_leaf_count(TNode*n){
	if (n==NULL) return 0;
	else if (n->left == NULL && n->right==NULL) return 1;
	else return get_leaf_count(n->left)+get_leaf_count(n->right);
}

int get_height(TNode*n){
	int hLeft, hRight;
	if (n==NULL) return 0;
	hLeft = get_height(n->left);
	hRight = get_height(n->right);
	return (hLeft>hRight)?hLeft+1:hRight+1;
}

void preorder(TNode*n){
	if(n!=NULL){
		printf("%c ", n->data);
		preorder(n->left);
		preorder(n->right);
	}
}

void inorder(TNode*n){
	if (n!=NULL){
		inorder(n->left);
		printf("%c ", n->data);
		inorder(n->right);
	}
}

void postorder(TNode* n){
	if (n!=NULL){
		postorder(n->left);
		postorder(n->right);
		printf("%c ", n->data);
	}
}

//void levelorder(TNode*n){
//	TNode* new;
//	if (root == NULL) return ;
//	init_queue();
//	enqueue(n);
//	while(!is_empty_queue()){
//		new = dequeue(n);
//		if (new!=NULL){
//		printf("%d", new->data);
//		enqueue(new->left);
//		enqueue(new->right);
//		}
//		}
//}

void main(){
	TNode* n[5];
	init_tree();
	n[0] = create_tree('D', NULL, NULL);
	n[1] = create_tree('E', NULL, NULL);
	n[2] = create_tree('B', n[0], n[1]);
	n[3] = create_tree('F', NULL, NULL);
	n[4] = create_tree('C', n[3], NULL);
	root = create_tree('A', n[2], n[4]);
	printf("Inorder:"); inorder(root);
	printf("\npreorder:"); preorder(root);
	printf("\npostorder:"); postorder(root);
	
	printf("\n노드의 개수: %d\n", get_count(root));
	printf("단말의 개수: %d\n", get_leaf_count(root));
	printf("트리의 높이: %d\n", get_height(root));
}
