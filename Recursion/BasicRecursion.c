#include<stdio.h>
#include <time.h>
#include <stdlib.h>

int factorial(int n){
	if (n == 0 || n==1) return 1;
	else return factorial(n-1)*n;
}

int factorial_iter(int n){
	int k, result = 1;
	for(k=n; k>0; k--){
		result *= k;
	}
	return result;
}

double slow_pow(int num, int time){
	int k;
	double result = 1.0;
	for(k=0; k<time; k++)
		result *= num;
	return result;
	}

double fast_pow(int num, int time){
	if (num == 0) return 1;
	else if (num%2==0) return fast_pow(num*num, time/2);
	else return num*fast_pow(num*num, (time-1)/2);
}

int fib(int n){
	if (n==0) return 0;
	if (n==1) return 1;
	return fib(n-2)+fib(n-1);
}

int fib_iter(int n){
	int i, last, current, tmp;
	if (n<2) return n;
	else{
		last = 0;
		current = 1;
		for(i = 2; i<=n; i++){
			tmp = current;
			current += last;
			last = tmp;
		}
		return current;
	}
}

void hanoi_tower(int n, char from , char tmp, char to){
	if (n==1) printf("원판 1을 %c에서 %c로 옮겼습니다.\n", from, to);
	else{
		hanoi_tower(n-1, from, to, tmp);
		printf("원판 %d를 %c에서 %c로 옮긴다.\n", n, from , to);
		hanoi_tower(n-1, tmp, from , to);
	}
}
void main(){
	int m=5;
	printf("%d의 순환활용 팩토리얼은 ? %d", m, factorial(m));  
	printf("\n%d의 반복활용 팩토리얼은? %d", m, factorial_iter(m));
	
	clock_t begin, end;
	double duration;
	begin = clock();
	fast_pow(2,10);
	end = clock();
	duration = (double)(end-begin)/CLOCKS_PER_SEC;
	
	printf("\nFast Power ... %f", duration);
	
	hanoi_tower(3, 'A', 'B', 'C');
}
