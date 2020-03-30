#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 999

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

int selected[MAX];
int dist[MAX];
int getMinVertex(){
	int v, minv = 0, mindist = INF;
	for(v=0; v<vsize; v++){
		if (!selected[v]&&dist[v]<mindist){
			mindist = dist[v];
			minv = v;
			}
	}
	return minv;
}
void Prim(){
	int i, u, v;
	
	for(i=0; i<vsize; i++){
		dist[i] = INF;
		selected[i] = 0;
	}
	dist[0] = 0;
	
	for(i=0; i<vsize; i++){
		u = getMinVertex();
		selected[u]=1;
		if (dist[u] == INF) return;
		printf("%c", vdata[u]);
		
		for(v =0; v<vsize; v++)
			if (adj[u][v] != INF)
				if (!selected[v]&&adj[u][v]<dist[v])
					dist[v] = adj[u][v]; 
	}
	printf("\n");
}

void main(){
	load_graph("graph.txt");
	printf("MST by Prim Algorithm\n");
	Prim();
}
