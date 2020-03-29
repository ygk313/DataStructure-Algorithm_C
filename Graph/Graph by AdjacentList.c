#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef char VtxData;
typedef struct LinkedNode{
	int id;
	struct LinkedNode* link;
}GNode;
GNode* adj[MAX];
int vsize;
VtxData vdata[MAX];

void init_graph(){
	int i;
	vsize = 0;
	
	for(i=0; i<MAX; i++){
		adj[i] = NULL;
	}
}
int is_empty(){ return (vsize == 0);
}
int is_full(){ return (vsize == MAX-1);
}
//동적으로 해제 
void reset_graph(){
	int i;
	GNode* n;
	for(i=0; i<vsize; i++){
		while(adj[i]!=NULL){
			n= adj[i];
			adj[i] = n->link;
			free(n);
		}
	}
}

void insert_vertex(char val){
	vdata[vsize++] = val; 
}

void insert_edge(int u, int v){
	GNode* n = (GNode*)malloc(sizeof(GNode));
	n->id = v;
	n->link = adj[u];
	adj[u] = n;
}

void print_graph(char* msg){
	int i;
	GNode* v;
	
	printf("%s\n", msg);
	printf("%d\n", vsize);
	
	for(i=0; i<vsize; i++){
		printf("%c\t", vdata[i]);
		for(v=adj[i]; v!=NULL; v=v->link){
			printf("%c\t", vdata[v->id]);
		}
		printf("\n");
	}
	
}

void main(){
	int i;
	for(i=0; i<4; i++)
		insert_vertex('A'+i);
	insert_edge(0,1); insert_edge(0,3);
	insert_edge(1,0); insert_edge(1,2); insert_edge(1,3);
	insert_edge(2,1); insert_edge(2,3);
	insert_edge(3,0); insert_edge(3,1); insert_edge(3,2);
	
	print_graph("그래프 인접리스트");
	
}
