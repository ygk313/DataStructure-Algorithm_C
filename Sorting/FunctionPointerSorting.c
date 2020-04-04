#include <stdio.h>

int ascend(int x, int y) { return y-x;
}
int descend(int x, int y){ return x-y;
}

void print_step(int list[], int i, int n){
	int k;
	printf("\tStep %d = ", i);
	
	for(k=0; k<n; k++){
		printf("%d ", list[k]);
	}
	printf("\n");
}

void insert_sorting_fn(int list[], int n, int(*f)(int, int)){
	int i, j, key;
	for(i=1; i<n; i++){
		key = list[i];
		for(j=i-1; j>=0&&f(list[j], key)<0; j--)
			list[j+1] = list[j];
		list[j+1] = key;
	print_step(list, i, n);
	}
}


void main(){
	int i;
	int list[9] ={5,3,8,4,9,1,6,2,7};
	
	printf("Original = ");
	for(i=0; i<9; i++)  
		printf("%d ", list[i]);
	printf("\n");
	
	insert_sorting_fn(list, 9, ascend);
	
	printf("Bubble = ");
	for(i=0; i<9; i++)
		printf("%d ", list[i]);
	printf("\n");
}
