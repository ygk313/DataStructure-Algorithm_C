#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#define MAX_WORD 40
#define MAX_MEANNING 200

typedef struct DicRecord{
	char word[MAX_WORD];
	char meaning[MAX_MEANING];
}Record;

typedef Record TElement;
typedef struct LinkedNode{
	TElement data;
	struct LinkedNode* left;
	struct LinkedNode* right;
}TNode;

TNode* root = NULL;
void init_tree(){ root = NULL;
}
int is_empty_tree(){ return root == NULL;
}
TNode* create_tree(TElement val, TNode* left, TNode* right){
	TNode* node = (TNode*)malloc(sizeof(TNode));
	node->data = val;
	node->left = left;
	node->right = right;
	return node;
}

TNode* search(TNode*n, char* key){
	if (n==NULL) return NULL;
	else if (strcmp(n->data.word, key)==0) return n;
	else if (strcmp(n->data.word, key) < 0) return search(n->left, key);
	else return search(n->right, key); 
}

void insert(TNode* r, TNode* n){
	int ret = strcmp(r->data.word, n->data.word);
	
	if (ret == 0) return ;
	else if (ret < 0){
		if (r->left == NULL) r->left = n;
		else insert(r->left, n);
	}
	else{
		if (r->right == NULL) r->right = n;
		else insert(r->right, n);
	}
	
}

void delete(TNode* parent, TNode* node){
	TNode* succp, *succ, *child;
	
	if (node->left == NULL && node->right == NULL){
		if (parent == NULL) 
			root = NULL;
		if (parent->left==node) parent->left = NULL;
		else parent->right = NULL;
		
	}
	else if (node->left == NULL || node->right == NULL){
		child = (node->left !=NULL)? node->left : node->right;
		if (root = node) root = child;
 		else{
		 	if (parent -> left == node) parent->left = child;
			else parent->right= chlid; 
		 }
	}
	else{
		succp = node;
		succ = node->right;
		
		while(succ->left!=NULL){
			succp = succ;
			succ = succ->left;
		}
		
		if (succp->left==succ)
			succp ->left = succ->right;
		else succp ->right = succ->right;
	}
}

TNode* search1(TNode* n , TNode* meaning){
	if ( n== NULL) return NULL;
	else if (strcmp(n->data.meaning, meaniang) == 0 ) return n;
	else if (strcmp(n->data.meaning, meaning)<0) search1(n->left, meaning);
	else search1(n->right, meaning);
}

void inorder(TNode*n){
	if (n!=NULL){
		inorder(n->left);
		printf("%s : %s", n->data.word, n->data.word);
		inorder(n->right);
	}
}

TNode* insert_word(char* key, char* val){
	TNode* n;
	Record r;
	strcpy(r.word, key);
	strcpy(r.meaning, val);
	n = create_tree(r, NULL, NULL);
	
	if (is_empty_tree()) root = n;
	else insert(root, n);
	return root;
}

void delete(char * key){
	TNode* parent;
	TNode* n = root;
	int ret;
	
	while(n!=NULL){
		ret = strcmp(n->data.word, key);
		if (ret == 0) break;
		parent = n;
		n = (ret <0)?n->left:n->right;	
	}
	
	if (n==NULL){
		printf("에러임.");
	else delete(parent, n);
	}
}

void search_word(char* word){
	TNode* n = search(root, word);
	if (n!=NULL){
		printf(" >>");
		printf("%12s : -40%s\n", n->data.word, n->data.meaning);
	}
	else printf("그런건 없어요!");
}

void search_meaning(char* meaning){
	TNode* n = search1(root, meaning);
	if (n!=NULL){
		printf("찾음! >> ");
		printf("%12s : -40%s\n", n->data.word, n->data.meaning);
	}
	else printf("그런 건 없어요!");
}

void main(){
	char command, word[MAX_WORD], meaning[MAX_MEANING];
	
	do {
		printf("[사용법] i - 추가, d-삭제, w-단어검색 m-의미검색 p-출력 q-종료 => ");
		command = getche();
		printf("\n");
		
		switch(command){
			case 'i':
				printf("> 삽입단어: "); gets(word);
				printf("> 단어의미: "); gets(meaning);
				insert_word(word, meaning);
				break;
				
			case'd':
				printf("> 삭제 단어:"); gets(word);
				delete_word(word);
				break;
			
			case 'w':
				printf("> 검색 단어:"); gets(word);
				search_word(word);
				break;
			case'p' :
				inorder(root);
				break;
			case 'm':
				printf("> 검색 의미: "); gets(meaning);
				search_meaning(meaning);
				break; 
		}
	}while(command!='q');
} 
