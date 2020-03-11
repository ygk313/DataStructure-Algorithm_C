#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct LinkedNode{
	Element data;
	struct LinkedNode* prev;
	struct LinkedNode* next;
}Node;

Node* head = NULL;
void init_list(){ head.next = NULL;}
Node* get_head(){ return head.next;
}
int is_empty(){ return (head.next == NULL);
}
void error(char* msg){
	printf("%s\n", msg);
	exit(1);
}

Node* get_entry(int pos){
	Node* p = head;
	int i;
	if (pos == -1)
		return get_head;
	else if (is_empty())
		error("공백 에러");
	else {
		for(i=0; i<pos; i++, p=p->next){
			if (p != NULL)
				return p;
		}
	}	
}

void replace(int pos, Element e){
	Node* p = get_entry(pos);
	if (p!=NULL)
		p->data = e;	
}

int size(){
	int count = 0;
	Node* p;
	for(p=get_head();p!=NULL;p=p->next)
		count++;
	return count;
}

Node* find(Element e){
	Node* p;
	for(p=get_head(); p!=NULL; p=p->link)
		if (p->data == e)
			return p;
}

void insert_next(Node* p, Node* n){
	
	n->prev = prev;
	n->next = prev->next;
	if (p->next!=NULL){
		p->next->prev = n;
	}
	p->next = n;
}

void insert(int pos, Element e)}{
	Node* new_node, *prev;
	prev = get_entry(pos-1);
	
	if (prev != NULL){
		new_node = (Node*)malloc(sizeof(Node));
		new_node->data = e;
		new_node->prev = NULL;
		new_node->next = NULL;
		
		insert_next(prev, new_node);
	}
}

void remove_curr(Node* n){
	if (n->prev!=NULL)n->prev->next = n->next;
	if (n->next!=NULL)n->next->prev = n->prev;
	
}

void delete(int pos){
	Node* n = get_entry(pos);
	if (n!=NULL)
		remove_curr(n);
}
