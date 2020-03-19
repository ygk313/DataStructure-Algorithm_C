#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

typedef struct Line{
	char str[MAX];
}Line;

typedef Line Element;
typedef struct LinkedNode{
	Element data;
	struct LinkedNode* link;
}Node;

Node* head = NULL;

void init_list(){ head = NULL;
}
int is_empty(){ return (head==NULL);
}

Node* get_entry(int pos){
	Node* p = head;
	int i=0;
	for(i=0; i<pos; i++, p=p->link){
		if (p==NULL) return NULL;
	}
	return p;
}

int size(){
	Node* p;
	int count =0;
	for(p=head; p!=NULL; p=p->link)
		count++;
	return count;
}

Node* find(Element e){
	Node*p;
	for(p=head; p!=NULL; p=p->link){
		if (p->data.str == e.str) return p;
	}
	return NULL;
}

void replace(int pos, Element e){
	Node * get = get_entry(pos);
	if (get!=NULL)
		get->data = e;
}
void insert_next(Node* before, Node* node){
	if (node!=NULL){
		node->link = before->link;
		before->link = node;
	}
}
void insert(int pos, Element e){
	Node* new_node, *prev;
	new_node = (Node*)malloc(sizeof(Node));
	new_node->data =e;
	new_node->link = NULL;
	
	if (pos == 0){
		new_node->link = head;
		head = new_node;
	}
	else{
		prev = get_entry(pos-1);
		if (prev !=NULL)
			insert_next(prev, new_node);
		else free(new_node);
	}
	
}
Node* remove_next(Node* prev){
	Node* node = prev->link;
	if (node != NULL){
		prev->link = node->link;
	}
	return node;
}

void del(int pos){
	Node* prev, *removed;
	
	if (pos ==0 && is_empty()==0){
		removed = head;
		head = head->link;
		free(removed);
	}
	else{
		prev = get_entry(pos-1);
		if (prev!=NULL){
			removed = remove_next(prev);
			free(removed);
		}
	}
}
void clear_list(){
	
	while(is_empty())
		del(0);
}


void my_fflush(){ while(getchar()!='\n');
}

void display(FILE* fp){
	int i=0;
	Node*p;
	for(p=head; p!=NULL; p=p->link, i++){
		fprintf(stderr, "%3d: ", i);
		fprintf(fp, "%s", p->data.str);
	}
}
void main(){
	init_list();
	
	int pos;
	Line content;
	FILE *fp;
	char command;
	
	do{
		printf("[메뉴선택] i-삽입 d-삭제 r-변경 p-출력 l-파일읽기 s-저장 q-종료 ->");
		command = getchar();
		
		switch(command){
			case 'i':
				printf("입력행 번호:");
				scanf("%d", &pos);
				printf("입력행 내용:");
				my_fflush();
				fgets(content.str, MAX, stdin);
				insert(pos, content);
				break;
			case 'd':
				printf("삭제행 번호:");
				scanf("%d", &pos);
				del(pos);
				break;
			case 'r':
				printf("변경행 번호:");
				scanf("%d", &pos);
				printf("변경행 내용:");
				my_fflush();
				fgets(content.str, MAX, stdin);
				replace(pos, content);
				break;
	
			case 'l':
				fp = fopen("Test.txt", "r");
				if (fp!=NULL){
					while(fgets(content.str, MAX, fp))
						insert(size(), content);
					fclose(fp);
				}
				break;
			case 's':
				fp = fopen("Test.txt", "w");
				if (fp!=NULL){
					display(fp);
					fclose(fp);
				}
			case 'p':
				display(stdout);
		}
		my_fflush();
	}while(command!='q');
	
}
