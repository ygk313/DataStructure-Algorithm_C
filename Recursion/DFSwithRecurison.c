#include <stdio.h>
#define MAX 6

char map[MAX][MAX] ={
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'},
	};
	
int xExit = 5, yExit = 4, done = 0;

int is_valid(int x, int y){
	if (x<0||y<0||x>=MAX||y>=MAX) return 0;
	else return map[y][x] =='0' || map[y][x] == 'x';
}
void search_recur(int x, int y){
	if (done) return;
	printf("(%d,%d)", x, y);
	
	if (xExit==x&&yExit==y){
		done = 1;
		return; 
	}
	
	map[y][x] = '5';
	if (is_valid(x-1, y)) search_recur(x-1, y);
	if (is_valid(x+1, y)) search_recur(x+1, y);
	if (is_valid(x, y-1)) search_recur(x, y-1);
	if (is_valid(x, y+1)) search_recur(x, y+1);
	//���� ���߿� ���� �ٲ㼭 BFS�� ������ ���� 
} 
void main(){
	search_recur(0,1);
	if (done) printf("\n�ⱸ�� Ž���Ǿ����ϴ�.\n");
	else printf("\n �ⱸ�� ã�� ���߽��ϴ�.");
	int i, k;
	for(i=0; i<MAX; i++){
		for(k=0; k<MAX; k++)
			printf("%c", map[i][k]);
		printf("\n");
	}
}
