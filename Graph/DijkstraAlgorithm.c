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
		error("가득참");
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

int dist[MAX];
int found[MAX];
int path[MAX];

void print_step(int step){
	int i;
	
	printf("Step : %2d", step);
	
	for(i=0; i<vsize; i++)
		if (dist[i] == INF) printf(" INF");
		else printf("%5d", dist[i]);
	printf("\n");
}
int choose_vertex(){
	int i, min = INF, minpos= -1;
	
	for(i=0; i<vsize; i++)
		if (!found[i] && dist[i] < min){
			min = dist[i];
			minpos = i;
		}
	return minpos;
}

void shortest_path_dijkstra(int start){
	int i, u, w;
	for(i=0; i<vsize; i++){
		dist[i] = adj[start][i];
		found[i] = 0;
		path[i] = start;
	}
	found[start] =0;
	dist[start] =0;
	
	for(i=0; i<vsize; i++){
		print_step(i+1);
		u = choose_vertex();
		found[u] = 1;
		
		for(w=0; w<vsize; w++){
			if (!found[w]){
				if (dist[u]+adj[u][w] < dist[w])
					dist[w] = dist[u]+adj[u][w];
					path[w] =u;
			}
		}
	}
}

void print_shortest_path(int start, int end){
	printf("[최단 경로: %c -- %c] %c", vdata[end], vdata[start], vdata[end]);
	
	while(path[end] != start){
		printf("-%c", vdata[end]);
		end = path[end]
	}
	
	printf("-%c\n", vdata[path[end]]);
}

void main(){
	int i;
	
	load_wgraph("wgraph.txt");
	printf("Shortest Path By Dijkstra Algorithm");
	shortest_path_dijkstra(0);
	
	for(i=1; i<vsize; i++)
		print_shortest_path(0, i);
}
