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
		return data[top];
	}
}

int checking_op(char op){
	if (op =='(' || op ==')') return 0;
	else if (op =='/'||op =='*') return 2;
	else if (op == '+'||op=='-') return 1;
	else return -1;
}

void infix_into_postfix(char expr[]){
	init_stack();
	
	char ch, val;
	int i=0;
	
	while(expr[i]!='\0'){
		ch = expr[i++];
		if (('0'<=ch)&&(ch<='9')){
			printf("%c",ch);
		}
		else if (ch == '(')
			push(ch);
			
		else if (ch==')'){
			while(!is_empty()){
				val = pop();
				if (val=='(') break;
				else printf("%c", val);
			}
		}
		else if (ch =='+'||ch=='/'||ch=='*'||ch=='-'){
			while (is_empty()==0){
				val = peek();
				if (checking_op(val)>=checking_op(ch)){
					printf("%c",val);
					pop();
				}
				else break;
			}
			push(ch);
		}
	}
	printf("%c",pop());
}
void main(){
	char expr[2][MAX] = {"8 / 2 + 3 + ( 3 * 2 )", "1/2*4*(1/4)"};
	int i;
	printf("중위수식 %s ==>", expr[0]);
	printf("후위수식");
	infix_into_postfix(expr[0]);
	printf("\n");
	
}
