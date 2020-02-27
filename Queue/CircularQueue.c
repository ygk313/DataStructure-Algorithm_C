#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef int Element;
Element data[MAX];
int front, rear;

void error(char* msg){
	printf("%s", msg);
	exit(1);
}

void init_queue(){
	front = rear =0;
}

int is_empty(){ return front == rear;
}
int is_full(){ return front%MAX == (rear+1)%MAX;
}
int size(){ return (rear-front+MAX)%MAX;
} 

void enqueue(Element val){
	if (is_full())
		error("큐 포화에러");
	rear = (rear+1)%MAX;
	data[rear] = val;
}

Element dequeue(){
	if (is_empty())
		error("큐 공백 에러");
	front = (front+1)%MAX;
	return data[front];
}
Element peek(){
	if (is_empty())
		error("큐 공백 에러");
	return data[(front+1)%MAX];
}

void print_queue(char* msg){
	int i, maxi = rear;
	if (front >= rear) maxi+=MAX;
	printf("%s[%2d]", msg, size());
	for(i=front+1; i<=maxi; i++){
		printf("%2d", data[i%MAX]);
	}
	printf("\n");
}

void main(){
	int i;
	init_queue();
	for(i=1;i<10;i++)
		enqueue(i);
	print_queue("선형큐 enqueue 9회");
	printf("\tdequeue->%d\n", dequeue());
	printf("\tdequeue->%d\n", dequeue());
	printf("\tdequeue->%d\n", dequeue());
	print_queue("선형큐 dequeue 3회");
}
