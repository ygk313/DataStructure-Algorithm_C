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

//DFS
int visited[MAX];
void reset_visited(){
	int i;
	for(i=0; i<MAX; i++)
		visited[i]  = 0;
}

void DFS(int start){
	GNode* p;
	visited[start] = 1;
	printf("%c ", vdata[start]);
	
	for(p=adj[start]; p!=NULL; p=p->link){
		if (visited[p->id]==0)
			DFS(p->id);
	}
}


void main(){
	int i;
	for(i=0; i<8; i++)
		insert_vertex('A'+i);
	insert_edge(0,1); insert_edge(0,2);
	insert_edge(1,0); insert_edge(1,3); 
	insert_edge(2,0); insert_edge(2,3);	insert_edge(2,4);
	insert_edge(3,5); insert_edge(3,1); insert_edge(3,2);
	insert_edge(4,2); insert_edge(4,6); insert_edge(4,7);
	insert_edge(5,3);
	insert_edge(6,4); insert_edge(6,7);
	insert_edge(7,4); insert_edge(7,5);
	
	print_graph("DFS 그래프");
	
	printf("\nDFS-->");
	DFS(0);
}
