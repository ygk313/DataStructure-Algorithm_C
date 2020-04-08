#include <stdio.h>
#define MAX 1024

int count = 1;

void print_step(int* list){
	printf("\nStep %d:", count++);
	int i;
	for(i=0; i<6; i++)
		printf("%d ", list[i]);
}

static void merge(int* list, int left, int mid, int right){
	int i, j, k = left, l;
	static int sorted[MAX];
	
	for(i=left, j = mid+1; i<=mid&&j<=right;){
		sorted[k++] = (list[i]<=list[j]) ? list[i++]:list[j++];
	}
	
	if (i>mid){
		for(l=j; l<=right; l++)
			sorted[k++] = list[l];
	}
	else{
		for(l=i; l<=mid; l++, k++)
			sorted[k] = list[l];
	}
	
	for(l=left; l<=right; l++){
		list[l] = sorted[l];
	}
}
void merge_sort(int* list, int left, int right){
	if (left < right ){
		int mid = (left+right)/2;
		merge_sort(list, left, mid);
		merge_sort(list, mid+1, right);
		merge(list, left, mid, right);
		print_step(list);
	}
}

void main(){
	int i, count =0;
	int list[6] ={1,3,8,7,2,4};
	
	printf("before Merge :");
	for(i=0; i<6; i++)
		printf("%d ", list[i]);
		
	merge_sort(list, 0, 5);
	
	printf("\nmerge_sort : ");
	for(i=0; i<6; i++)
		printf("%d ", list[i]);
}
