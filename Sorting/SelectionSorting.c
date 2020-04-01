#include <stdio.h>
#define SWAP(x,y,t) ((t) = (x), (x) = (y), (y)=(t))

void printStep(int list[], int n, int level){
	int i;
	printf("\tStep %d = ");
	for(i=0; i<n; i++)
		printf("%d ", list[i]);
	printf("\n");
}
void selection_sort(int list[], int n){
	int i, j, least, tmp;
	
	for(i=0; i<n-1; i++){
		least = i;
		for(j=i+1; j<n; j++){
			if (list[j] < list[least]) least= j;
		}
		SWAP(list[i], list[least], tmp);
		printStep(list, n, i+1);
	}
	
}
void printArray(int list[], int n, char* string ){
	int i;
	printf("%s = ", string);
	for(i=0; i<n;i++){
		printf("%d ", list[i]);
	}
	printf("\n");
}
void main(){
	int list[9] = {5,3,8,4,9,1,6,2,7};
	printArray(list, 9, "Orginal");
	selection_sort(list, 9);
	printArray(list, 9, "Selection");
}
