#include <stdio.h>

void printStep(int list[], int n, int count){
	int i;
	printf("\tStep %d = ", count);
	
	for(i=0; i<n; i++){
		printf("%d ", list[i]);
	}
	printf("\n");
}

static void sortGapInsertion(int list[], int first, int last, int gap){
	int i, j, key;
	for(i=first+gap; i<=last; i=i+gap){
		key = list[i];
		for(j=i-gap; j>=first&&key<list[j]; j=j-gap)
			list[j+gap] = list[j];
		list[j+gap] = key;
	}
}

void shell_sort(int list[], int n){
	int i, gap, count =0;
	
	for(gap = n/2; gap>0; gap=gap/2){
		if ((gap%2)==0) gap++;
		for(i=0; i<gap; i++)
			sortGapInsertion(list, i, n-1, gap);
		printStep(list, n, ++count);
	}
}


void main(){
	int list[9] = {5,3,8,4,9,1,6,2,7};
	int i;
	printf("Original = ");
	for(i=0; i<9; i++){
		printf("%d ",list[i]);
	}
	printf("\n");
	
	shell_sort(list, 9);
	
	printf("Shell Sort =");
	for(i=0; i<9; i++){
		printf("%d ", list[i]);
	}
}
