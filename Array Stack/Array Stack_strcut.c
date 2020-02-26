#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

//����üȰ���� 
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
		error("���� ��.");
	else{
		top++;
		data[top] = e;
	}
}

Element pop(){
	if (is_empty())
		error("�� �����.");
	else{
		return data[top--];
	}
}

Element peek(){
	if (is_empty())
		error("�� �����.");
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
	push(get_student(2015130007, "ȫ�浿", "��ǻ�Ͱ��а�"));
	push(get_student(2015130100, "�̼���" , "�����а�"));
	push(get_student(2015130135, "�迬��", "ü����"));
	push(get_student(2015130135, "Ȳ��", "���а�"));
	print_stack("ģ�� 4�� ���� ��");
	s= pop();
	print_stack("ģ�� 1�� ���� ��");
	
	 
}
