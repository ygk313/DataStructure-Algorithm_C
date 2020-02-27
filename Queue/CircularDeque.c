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
		error("ť ��ȭ����");
	rear = (rear+1)%MAX;
	data[rear] = val;
}

Element dequeue(){
	if (is_empty())
		error("ť ���� ����");
	front = (front+1)%MAX;
	return data[front];
}
Element peek(){
	if (is_empty())
		error("ť ���� ����");
	return data[(front+1)%MAX];
}

void init_deque(){
	init_queue();
}
void add_rear(Element val){
	enqueue(val);
}
Element delete_front(){
	return dequeue();
}
Element get_front(){
	return peek();
}

void add_front(Element val){
	if (is_full()){
		error("�� ��ȭ ����");
	}
	data[front] = val;
	front = (front-1+MAX)%MAX
}

Element delete_rear(){
	int prev = rear;
	if (is_empty())
		error("�� ���� ����");
	rear = (rear-1+MAX)%MAX;
	return data[prev];
}

Element get_rear(){
	if (is_empty())
		error("�� ���� ����");
	return data[rear];
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
	print_queue("����ť enqueue 9ȸ");
	printf("\tdequeue->%d\n", dequeue());
	printf("\tdequeue->%d\n", dequeue());
	printf("\tdequeue->%d\n", dequeue());
	print_queue("����ť dequeue 3ȸ");
}
