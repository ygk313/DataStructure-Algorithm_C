#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct LinkedNode{
	Element data;
	struct LinkedNode* prev;
	struct LinkedNode* next;
}Node;
Node org;

void init_list(){ org.next = NULL;
}
Node* get_head(){ return org.next;
}
int is_empty(){ return org.next == NULL;
}

Node* get_entry(int pos){
	Node* n = &org;
	int i =-1;
	for(i=-1; i<pos;i++, n=n->next)
		if (n==NULL) break;
	return n;
}
void replace(int pos, Element e){
	Node* node = get_entry(pos);
	if(node!=NULL)
		node->data = e;
}

int size(){
	int count = 0;
	Node* n;
	for(n=get_head(); n!=NULL; n=n->next)
		count++;
	return count;
}
Node* find(Element e){
	Node* n;
	for(n=get_head(); n!=NULL; n=n->next)
		if (n->data == e)
			return n;
	return ;
}

void print_list(char* msg){
	Node* n;
	printf("%s [%d]: ",msg, size());
	for(n=get_head();n!=NULL; n=n->next)
		printf("%d ", n->data);
	printf("\n");
}
void insert_next(Node* before, Node* n){
	n->prev = before;
	n->next = before->next;
	if (before->next !=NULL) before->next->prev = n;
	before->next = n;
}
void insert(int pos, Element e){
	Node* prev, *new;
	prev = get_entry(pos-1);
	new = (Node*)malloc(sizeof(Node));
	new->data = e;
	new->prev = NULL;
	new->next = NULL;
	
	insert_next(prev, new);
	
}
void remove_curr(Node* n){
	if (n->next!=NULL) n->next->prev = n->prev;
	if (n->prev!=NULL) n->prev->next = n->next;
}
void delete(int pos){
	Node* n = get_entry(pos);
	if (n!=NULL)
		remove_curr(n);
}

void clear_list(){
	while(is_empty()==0)
		delete(0);
}

void main(){
	init_list();
	insert(0,10);
	insert(0,20);
	insert(1,30);
	insert(size(),40);
	insert(2, 50);
	print_list("이중 연결 리스트로 구현한 List삽입");
	
	replace(2,90);
	print_list("이중연결리스트로 구현한 List 교체");
	
	delete(0);
	delete(1);
	print_list("이중연결리스트로 구현한 List 삭제");
	
	clear_list(); 
}
