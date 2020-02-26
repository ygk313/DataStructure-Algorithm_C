#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//배열을 활용한 스택 구현 
typedef double Element;
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

Element postfix(char expr[]){
	init_stack();
	int i;
	char ch;
	double val, val1, val2;
	i=0;
	while(expr[i]!='\0'){
		ch = expr[i++];
		if('0'<=ch&&ch<='9'){
			val = ch -'0';
			push(val);
		}
		else if (ch =='/'||ch =='*'||ch =='+'||ch =='-'){
				val2 = pop();
				val1 = pop();
				switch(ch){
					case '+': push(val1+val2); break;
					case '-': push(val1-val2); break;
					case '/': push(val1/val2); break;
					case '*': push(val1*val2); break;
				}
			}
		}
	return pop();
}
void print_stack(char *msg){
	int i;
	printf("%s [%d]", msg, size());
	for(i=0; i<size(); i++){
		printf("%2f ", data[i]);
	}
	printf("\n");
}

void main(){
	char expr[2][80] = {"82/3-32*+", "12/4*14/*"};
	printf("수식: %s = %f\n", expr[0], postfix(expr[0]));
	printf("수식: %s = %f", expr[1], postfix(expr[1]));	
	 
}
