#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//구조체활용함 
typedef struct {
	int id;
	char name[MAX];
	char department[MAX];
}Student;
typedef Student Element;

Element data[MAX];
int top;

void error(char* str){
	printf("%s\n", str);
	exit(1);
}

void init_stack(){
	top = -1;
}

int is_empty(){
	return top == -1;
}

int is_full(){
	return top == MAX-1;
}
int size(){
	return top+1;
}

void push(Element e){
	if (is_full())
		error("가득 참.");
	else{
		top++;
		data[top] = e;
	}
}

Element pop(){
	if (is_empty())
		error("텅 비었음.");
	else{
		return data[top--];
	}
}

Element peek(){
	if (is_empty())
		error("텅 비었음.");
	else{
		return data[top-1];
	}
}

void print_stack(char *msg){
	int i;
	printf("%s [%d]\n", msg, size());
	for(i=0; i<size(); i++){
		printf("%d\t%s\t%s\n ", data[i].id, data[i].name, data[i].department);
	}
	printf("\n");
}

Student get_student(int id, char* name, char* department){
	Student s;
	s.id = id;
	strcpy(s.name, name);
	strcpy(s.department, department);
	return s;
}
void main(){
	int i; 
	Student s;
	init_stack();
	push(get_student(2015130007, "홍길동", "컴퓨터공학과"));
	push(get_student(2015130100, "이순신" , "기계공학과"));
	push(get_student(2015130135, "김연아", "체육과"));
	push(get_student(2015130135, "황희", "법학과"));
	print_stack("친구 4명 삽입 후");
	s= pop();
	print_stack("친구 1명 삭제 후");
	
	 
}
