#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void error(char* msg){
	printf("%s\n", msg);
	exit(1);
}
typedef struct GraphNode{
	int id;
	struct GraphNode* link;
}GNode;
GNode* adj[MAX];
int vsize;
typedef char VtxData;
VtxData vdata[MAX];

void init_graph(){
	vsize = 0;
	int i;
	for(i=0; i<MAX; i++)
		adj[i] = NULL;
}
int is_empty_graph(){ return vsize == 0;
}
int is_full_graph(){ return vsize == MAX-1;
}
void reset_graph(){
	int i;
	GNode* n;
	for(i=0; i<MAX; i++){
		while(adj[i] != NULL){
			n = adj[i];
			adj[i] = n->link;
			free(n);
		}
	}
	vsize = 0;
}

void insert_vertex(char name){
	if (!is_full_graph())
		vdata[vsize++] = name;
}

void insert_edge(int u, int v){
	GNode* n  = (GNode*)malloc(sizeof(GNode));
	n->id = v;
	n->link = adj[u];
	adj[u] = n;
}
//---------------Stack------------------
typedef int Element;
Element data[MAX];
int top;

void init_stack(){ top =-1;
}
int is_empty(){ return top==-1;
}
int is_full(){ return top == MAX-1;
}
int size(){ return top+1;
}
void push(Element val){
	if (is_full())
		error("스택이 가득참\n");
	data[++top] = val; 
}
Element pop(){
	if (is_empty())
		error("스택이 비었음\n");
	return data[top--]; 
}
Element peek(){
	if (is_empty())
		error("스택이 비어있음");
	return data[top-1];
}
void topological_sort(){
	GNode* p;
	int i, u, w, inDeg[MAX];
	
	for(i=0; i<vsize; i++) inDeg[i] = 0;
	for(i=0; i<vsize; i++){
		p = adj[i];
		while(p!=NULL){
			inDeg[p->id]++;
			p = p->link;
		}
	}
	
	init_stack();
	for(i=0;i<vsize;i++){
		if (inDeg[i] == 0) push(i);
	}
	
	while(!is_empty()){
		w = pop();
		printf("%c ", vdata[w]);
		for(p= adj[w]; p!=NULL; p=p->link){
			u = p->id;
			inDeg[u]--;
			if (inDeg[u]==0) push(u);
		}
	}
	printf("\n");
}

void main(){
	int i;
	init_graph();
	for(i=0; i<6; i++)
		insert_vertex('A'+i);
	
	insert_edge(0,2);insert_edge(0,3);insert_edge(1,3);
	insert_edge(1,4);insert_edge(2,3);insert_edge(2,5);
	insert_edge(3,5);insert_edge(4,5);
	
	printf("Topological Sort->");
	topological_sort();
}
