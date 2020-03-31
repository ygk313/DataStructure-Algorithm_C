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
int A[MAX][MAX];
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

void printA(){
	int i, j;
	printf("----------");
	for(i=0; i<vsize; i++){
		for(j=0; j<vsize; j++){
			if (adj[i][j] == INF) printf(" INF");
			else printf("%d", adj[i][j]);
		}
		printf("\n");
	}
}

void Floyd(){
	int i, j ,k;
	for(i=0;i<vsize; i++)
		for(j=0; j<vsize; j++)
			A[i][j] = adj[i][j];
			
	for(k=0; k<vsize; k++){
		for(i=0;i<vsize;i++){
			for(j=0; j<vsize; j++){
				if (A[i][k]+A[k][j]<A[i][j])
					A[i][j] = A[i][k]+A[k][j];
			}
		}
	
		printA();
	}
	
}

void main(){
	load_graph("wgraph.txt");
	Floyd();
}
