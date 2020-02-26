#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//배열을 활용한 스택 구현 
typedef char Element;
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

int check_matching(char expr[]){
	int i =0, prev;
	char ch;
	
	init_stack();
	while(expr[i]!='\0'){
		ch = expr[i++];
		if (ch=='('||ch=='{'||ch=='[')
			push(ch);
		else if (ch==')'||ch=='}'||ch==']'){
			if (is_empty())
				return 2;
			prev = pop();
			if (ch == ']'&&prev!='['||ch == ')'&&prev!='('||ch == '}'&&prev!='{')
				return 3;
		}
	}
	
	if (is_empty()==0) return 1;
	return 0;
}
void print_stack(char *msg){
	int i;
	printf("%s [%d]", msg, size());
	for(i=0; i<size(); i++){
		printf("%2d ", data[i]);
	}
	printf("\n");
}

void main(){
	char expr[4][80] = {"{A[(i+1)]=0;}", "if((i==0)&&(j==0)", "A[(i+1])=0;", "A[i]=f)(;)"};
	int i, error;
	for(i=0; i<4; i++){
		error = check_matching(expr[i]);
		if (error == 0)
			printf("정상: %s\n", expr[i]);
		else
			printf("오류: %s (조건 %d위반)\n", expr[i], error);
	}
	 
}
