#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 999
#define Key(n) (n.key)
#define Parent(n) (heap[n/2])
#define Left(n) (heap[n*2])
#define Right(n) (heap[n*2+1])

void error(char* msg){
	printf("%s\n", msg);
	exit(1);
}

typedef char VtxData;
int adj[MAX][MAX];
VtxData vdata[MAX];
int vsize;

int is_empty(){ return (vsize == 0);
}
int is_full(){ return (vsize == MAX-1);
}
void init_graph(){
	vsize = 0;
	int i, j;
	
	for(i=0; i<MAX;i++){
		for(j=0; j<MAX; j++)
			adj[i][j] = 0;
	}
}
void insert_vertex(char name){
	if (is_full())
		error("°¡µæÂü");
	else
		vdata[vsize++] = name;
}

void load_graph(char* filename){
	int n, i, j, val;
	char str[80];
	FILE* fp = (filename, "r");
	if(fp!=NULL){
		init_graph();
		fscanf(fp, "%d", &n);
		for(i=0; i<n; i++){
			fscanf(fp, "%s", str);
			insert_vertex(str[0]);
			for(j=0; j<n; j++){
				fscanf(fp, "%d", &val);
				if (i!=j&&val==0)
					adj[i][j] = INF;
				else adj[i][j] = val; 
			}
		}
	}
	fclose(fp);
}
int parent[MAX];
int set_size;

void init_set(int nSets){
	int i;
	set_size = nSets;
	for(i=0; i<nSets; i++){
		parent[i] = -1;
	}
}

void union_set(int s1, int s2){
	parent[s1] = s2;
	set_size--;
}

int find_set(int id){
	while(parent[id]>0) id = parent[id];
	return id;
}

typedef struct HeapNode{
	int key; 
	int v1;
	int v2;
}HNode;
HNode heap[MAX];
int heap_size;

void init_heap(){ heap_size = 0;
}
int is_empty_heap(){ return (heap_size == 0);
}
int is_full_heap(){ return (heap_size == MAX-1);
}
HNode find_heap(){ return heap[1];
}
void insert_heap(HNode n){
	if (is_full_heap())
		error("ÈüÀÌ °¡µæÂü");
	int i;
	heap_size++;
	i = heap_size;
	
	while(i!=1&&Key(n)<Key(Parent(i))){
		heap[i] = Parent(i);
		i/=2;
	}
	
	heap[i] = n;
}

HNode delete_heap(){
	HNode hroot, last;
	hroot = heap[1];
	last = heap[heap_size--];
	int parent =1, child = 2;
	
	while(child<=heap_size){
		if (child<heap_size&&Key(Left(parent))>Key(Right(parent)))
			child++;
		if (Key(last)<=Key(heap[child]))
			break;
		heap[parent] = heap[child];
		parent = child;
		child *=2;
	}
	heap[parent] = last;
	return hroot;
}

void Kruskal(){
	int i, j, edgeAccepted = 0, uset, vset;
	HNode e;
	
	init_heap();
	init_set( vsize);
	
	for(i=0; i<vsize; i++)
		for(j=0; j<vsize; j++){
			if(adj[i][j] < INF){
				e.key = adj[i][j];
				e.v1 = i;
				e.v2 = j;
				insert_heap(e);
			}
		}
	
	while(edgeAccepted<vsize-1){
		e = delete_heap();
		uset = find_set(e.v1);
		vset = find_set(e.v2);
		
		if (uset!=vset){
			printf("°£¼± Ãß°¡ : %c - %c ºñ¿ë:%d\n", vdata[e.v1], vdata[e.v2], e.key);
			union_set(uset, vset);
			edgeAccepted++;
		}
	}
}

void main(){sz
	load_graph("Graph.txt");
	printf("MST by Kruskal Algorithm");
	Kruskal(); 
}
