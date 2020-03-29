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
int visited[MAX];
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
void reset_graph(){
	GNode* n;
	int i;
	for(i=0; i<vsize; i++){
		while(adj[i]!=NULL){
			n = adj[i];
			adj[i] = n->link;
			free(n);
		}
	}
}
void insert_vertex(char val){
	if (is_full()==0)
		vdata[vsize++] = val;
}

void insert_edge(int u, int v){
	GNode* n = (GNode*)malloc(sizeof(GNode));
	n->id = v;
	n->link = adj[u];
	adj[u] = n;
}
void reset_visited(){
	int i;
	for(i=0; i<MAX;i++)
		visited[i] = 0;
}
//--------------queue
typedef int Element;
Element data[MAX];
int front, rear;

void error(char *msg){
//	printf("%s\n", msg);
	exit(1);
	
}

void init_queue(){ front = rear = 0;
}
int is_empty_queue(){ return (front == rear);
}
int is_full_queue(){ return (front == (rear+1) % MAX);
}
int size(){ return (rear-front+MAX)%MAX;
}

void enqueue(Element val){
	if (is_full_queue())
		error("큐가 가득참");
		
	rear = (rear+1)%MAX;
	data[rear] = val;
}

Element dequeue(){
	if (is_empty_queue())
		error("큐가 비어있음");
		
	front = (front+1)%MAX;
	return data[front];
}
Element peek(){
	if (is_empty_queue())
		error("큐가 비어있음");
	return data[(front+1)%MAX];
}

void BFS(int u){
	int w;
	GNode* n;
	init_queue();
	
	visited[u] = 1;
	printf("%c ", vdata[u]);
	enqueue(u);
	
	while(!is_empty_queue()){
		w = dequeue();
		for(n=adj[w]; n!=NULL; n=n->link){
			if (!visited[n->id])
				printf("%c ", vdata[n->id]);
				visited[n->id] = 1;
				enqueue(n->id);
		}
	}
	
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
	
//	print_graph("BFS 그래프");
//	
	printf("\nBFS-->");
	BFS(0);
}
