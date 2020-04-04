#include <stdio.h>
#define SWAP(x, y, z) ((z)=(x), (x)=(y), (y)=(z))

void print_step(int list[], int i, int n){
	int k;
	printf("\tStep %d = ", i);
	
	for(k=0; k<n; k++){
		printf("%d ", list[k]);
	}
	printf("\n");
}

void bubbleSort(int* list, int n){
	int i, j, changed, tmp;
	for(i=n-1; i>0; i--){
		changed = 0;
		for(j=0; j<i; j++){
			if (list[j]>list[j+1])
				SWAP(list[j], list[j+1], tmp);
				changed = 1;
		}
		if (!changed) break;
		print_step(list, n-i, n);
	}
}

void main(){
	int i;
	int list[9] ={5,3,8,4,9,1,6,2,7};
	
	printf("Original = ");
	for(i=0; i<9; i++)  3
		printf("%d ", list[i]);
	printf("\n");
	
	bubbleSort(list, 9);
	
	printf("Bubble = ");
	for(i=0; i<9; i++)
		printf("%d ", list[i]);
	printf("\n");
}
