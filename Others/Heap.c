#include <stdio.h>
#include <stdlib.h>
#define Key(n) (n)
#define Parent(n) (heap[n/2])
#define Left(n) (heap[n*2])
#define Right(n) (heap[n*2+1])
#define MAX_HEAP 100

typedef int HNode;
HNode heap[MAX_HEAP];
int heap_size;

void error(char* str){
	printf("%s\n", str);
	exit(1);
}

void init_heap(){ heap_size = 0;
}
int is_empty(){ return heap_size == 0;
}
int is_full(){ return heap_size == MAX_HEAP-1;
}
HNode find_heap(){ return heap[1];
}

void insert_heap(HNode node){

	if (is_full()) return ;
	int i = ++heap_size;
	while(i!=1 && Key(node)>Parent(i)){
		heap[i] = Parent(i);
		i /=2;
		}
	heap[i] = node;
}

HNode delete_heap(){
	HNode hroot, last;
	int parent = 1, child =2;
	
	if (is_empty()) error("공백 트리");
	
	hroot = heap[1];
	last = heap[heap_size--];
	
	while(child<=heap_size){
		if (child < heap_size && Left(parent) <Right(parent))
			child++;
		if (Key(last) >= Key(heap[child]))
			break;
		
		heap[parent] = heap[child];
		parent = child;
		child *=2;
	}
	heap[parent] = last;
	return hroot;
}

void print_heap(){
	int i, j;
	for(j = 1; j<heap_size; j*=2){
		for(i=j; i<=j*2-1;i++){
			printf("%d ", heap[i]);
		}
		printf("\n");
	}
	printf("\n---\n");
	
}

void main(){
	init_heap();
	insert_heap(2 ); insert_heap(5 );
	insert_heap(4 ); insert_heap(8 );
	insert_heap(9 ); insert_heap(3 );
	insert_heap(7 ); insert_heap(3 );
	print_heap();
	
	delete_heap(); print_heap();
}
