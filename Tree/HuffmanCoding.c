#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 100
#define Key(n) (n)
#define Left(n) (heap[n*2])
#define Right(n) (heap[n*2+1])
#define Parent(n) (heap[n/2])

typedef int HNode;
HNode heap[MAX_HEAP];
int heap_size;

void error(char* msg){
	printf("%s\n", msg);
	exit(1);
}

void init_heap(){ heap_size =0;
}
int is_empty(){ return (heap_size == 0);
}
int is_full(){ return heap_size == MAX_HEAP-1;
}
HNode find_heap(){ return heap[1];
}

void insert_heap(HNode n){
	int i;
	if (is_full()) return ;
	i = ++(heap_size);
	
	while(i!=1&&Key(Parent(i))>Key(n)){
		heap[i] = Parent(i);
		i/=2;
	}
	heap[i] = n;
}

HNode delete_heap(){
	HNode hroot, last;
	int parent = 1, child = 2;
	
	if (is_empty()) return;
	
	hroot = heap[1];
	last = heap[heap_size];
	heap_size--;
	
	while(child <= heap_size){
		if (child < heap_size && Right(parent)<Left(parent))
			child++;
		
		if (Key(heap[child]) >= Key(last))
			break;
		
		heap[parent] = heap[child];
		parent = child;
		child *=2;
		
	}
	heap[parent] = last;
	
	return hroot;
	
}
void make_tree(int freq[], int n){
	HNode e1, e2;
	int i;
	
	for(i=0; i<n; i++)
		insert_heap(freq[i]);
		
	for(i=1; i<n; i++){
		
		e1 = delete_heap();
		e2 = delete_heap();
		insert_heap(e1+e2);
		printf(" (%d + %d)\n", e1, e2);

	}
}
void main(){
	init_heap();
	
	char label[] = {'A', 'B', 'C', 'D', 'E'};
	int freq[] = {15, 12, 8, 6, 4};
	make_tree(freq, 5);
	
	
}

