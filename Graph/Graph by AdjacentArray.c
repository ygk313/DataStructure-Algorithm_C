#include <stdio.h>
#define MAX_VTXS 100

typedef char VtxData;
int adj[MAX_VTXS][MAX_VTXS];
int vsize;
VtxData vdata[MAX_VTXS];

void error(char* msg){
	printf("%s\n", msg);
	exit(1);
}
void init_graph(){ 
	int i, j;
	vsize =0;
	for(i=0; i<MAX_VTXS; i++)
		for(j=0; j<MAX_VTXS; j++)
			adj[i][j] =0;
}

int is_full(){ return (vsize == MAX_VTXS-1);
}
int is_empty(){ return (vsize == 0);
}

void insert_vertex(VtxData name){
	if (is_full())
		error("그래프 정점의 개수 초과");
	else 
		vdata[vsize++] = name; 
}

//방향그래프 
void insert_edge(int u, int v, int val){
	adj[u][v] = val;
}
//무방향그래프 
void insert_edge2(int u, int v, int val){
	adj[u][v] = adj[v][u] = val;
}
//파일 입출력의 경우라면
void load_graph(char *filename){
	int i, j, val, n;
	char str[80];
	FILE *fp = fopen(filename, "r");
	
	if (fp!=NULL){
		init_graph();
		fscanf(fp, "%d", n);
		for(i=0; i<n; i++){
			fscanf(fp, "%s", str);
			insert_vertex(str[0]);
			for(j=0; j<n; j++){
				fscanf(fp, "%d", &val);
				if (val != 0)
					insert_edge(i, j, val); 
			}
		}
		fclose(fp);
	}
} 

void print_graph(char* msg){
	printf("%s", msg);
	printf("%d\n", vsize);
	int i, j;
	
	for(i=0; i<vsize; i++){
		printf("%c\t", vdata[i]);
		for(j=0; j<vsize; j++)
			printf("%d ", adj[i][j]);
		printf("\n");
	}
	
} 
void main(){
	init_graph();
	int i;
	for(i=0; i<4; i++)
		insert_vertex('A'+i);
	
	insert_edge2(0,1,1);
	insert_edge2(0,3,1);
	insert_edge2(1,2,1);
	insert_edge2(1,3,1);
	insert_edge2(2,3,1);
	print_graph("그래프 인접행렬\n");
}
