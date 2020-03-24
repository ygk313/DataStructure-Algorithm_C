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

int is_empty_tree(){ return root == NULL;
}

TNode* get_root(){ return root;
}
TNode* search_iter(TNode* n, int key){
	while(n!=NULL){
		if (key == n->data) return n;
		else if (key>n->data) n = n->right;
		else n= n->left;
	}
	return NULL;
}

void search_BST(int key){
	TNode* n = search_iter(root, key);
	
	if (n!=NULL)
		printf("%d를 찾음\n", key);
	else
		printf("key가 존재하지 않음\n");
}

int insert(TNode* root, TNode* n){
	if (root->data == n->data) return 0;
	
	else if (root->data > n->data){
			if (root->left == NULL) root->left = n;
			else  insert(root->left, n);
	}
	
	else{
		if (root->right == NULL) root->right = n;
		else insert(root->right, n);
		}
	
	return 1;
 
}

void insert_BST(int key){
	TNode* node = (TNode*)malloc(sizeof(TNode));
	node->data  = key;
	node->left = NULL;
	node->right = NULL;
	
	if (is_empty_tree())
		root = node;
	else
		if (insert(root, node)==0)
			free(node);
	
}

void delete(TNode* parent, TNode* node){
	TNode* succ, *succp, *child;
	
	if (node->left == NULL && node->right == NULL){
		if (parent == NULL) root = NULL;
		else{
			if (parent->left == node) root=node->left;
			else root = node->right;
		}
	}
	
	else if (node->left == NULL || node->right == NULL){
		child = (node->left!=NULL)?node->left:node->right;
		if (node==root) root = child;
		else{
			if (parent->left = node) parent->left = child;
			else parent->right = child;
		}
	}
	
	else{
		succp = node;
		succ = node->right;
		
		while(succ->left !=NULL){
			succp = succ;
			succ = succ->left;
		}
		
		if (succp->left == succ)
			succp->left = succ->right;
		else succp->right = succ->right;
		
		node->data = succ->data;
		node = succ;
	}
	free(node);
}

void delete_BST(int key){
	TNode* parent = NULL;
	TNode* node = root;
	
	if (node==NULL) return;
	
	while(node!=NULL && node->data != key){
		parent = node;
		node= (key<node->data)?node->left:node->right;
	}
	
	if (node==NULL)
		printf("Error: key is not in the tree\n");
	else{
		delete(parent, node);
	}
}

void inorder(TNode* root){
	
	if(root!=NULL){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
void main(){
	printf("삽입연산 : 35, 14, 29, 28, 49\n");
	
	init_tree();
	insert_BST(35); insert_BST(14); insert_BST(29); insert_BST(28); insert_BST(49);
	
	printf("중위순회:");
	inorder(root);
	
	delete_BST(14);
	printf("\n12지우기\n순회:");
	inorder(root);
	
	printf("\n");
	search_BST(35);
}
