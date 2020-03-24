#include <stdio.h>
#define MAX 100

typedef struct{
	int high;
	float array[MAX];
}Polynomial;

Polynomial read_poly(){
	int i;
	Polynomial x;
	
	printf("다항식의 최고차수를 입력하세요:");
	scanf("%d", &x.high);
	printf("\n각 항의 계수를 입력하시오(총 %d개):", x.high+1);
	
	for(i=0;i<=x.high;i++){
		scanf("%f",&x.array[i]);
	}

	return x;
	
}

void print_poly(Polynomial a, char* str){
	int i;
	printf("%s", str);
	for(i=0; i<a.high; i++){
		printf("%.1f x^ %d +", a.array[i], a.high-i);
	}
	printf("%.1f", a.array[a.high]);
}

Polynomial add_poly(Polynomial a, Polynomial b){
	Polynomial c;
	int i;
	if (a.high > b.high){
		c = a;
		for(i=0; i<=b.high; i++){
			c.array[c.high-b.high+i] += b.array[i];
		}
	}
	else{
		c = b;
		for(i=0; i<=a.high; i++){
			c.array[c.high-a.high+i] += a.array[i];
		}
	}
	
	return c;
	
	
}

void main(){
	Polynomial a,b,c;
	a= read_poly();
	printf("\n");
	b= read_poly();
	printf("\n");
	print_poly(a, "A=");
	printf("\n");
	print_poly(b, "B=");
	printf("\n");
	
	c = add_poly(a, b);
	print_poly(c, "a+b =");
	
	
	 	
}
