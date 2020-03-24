#include <stdio.h>
#define MAX 100

typedef struct{
	int expon;
	float coeff;
}Term;

typedef struct{
	int nTerm;
	Term term[MAX];
}Spoly;

Spoly read_poly(){
	Spoly x;
	int i;
	printf("입력할 계수의 양은?:");
	scanf("%d", &x.nTerm);
	
	for(i=0; i<x.nTerm; i++){
		printf("차수, 계수 입력하기:");
		scanf("%d %f", &x.term[i].expon, &x.term[i].coeff);
	}
	
	return x; 
}

void print_poly(Spoly a, char* str){
	printf("%s", str);
	int i;
	
	for(i=0; i<a.nTerm-1;i++){
		printf("%.1f x^ %d+", a.term[i].coeff, a.term[i].expon);
	}
	
	printf("%f", a.term[a.nTerm-1].coeff);
	
	printf("\n");
}

Spoly add_poly(Spoly a, Spoly b){
	Spoly c;
	int i, j, k=1;
	
	if (a.term[0].expon>b.term[0].expon){
		c.term[0] = a.term[0];
		for(i=1;i<=a.nTerm-1;i++){
			for(j=0; j<b.nTerm;j++){
				if (a.term[i].expon<b.term[j].expon)
					c.term[k] = b.term[j];
				else if (a.term[i].expon == b.term[j].expon){
					c.term[k].expon = b.term[j].expon;
					c.term[k].coeff = b.term[j].coeff+a.term[i].coeff;
				}
				else{
					c.term[k] = a.term[i];
				}
				k++;
			}
		}
		
	}
	c.nTerm = k;
		
	return c;
	

	
}
void main(){
	Spoly a, b ,c;
	
	a = read_poly();
	b = read_poly();
	
	print_poly(a, "A=");
	print_poly(b, "B=");
	
	c = add_poly(a,b);
	
	print_poly(c, "C=");
	


	
}

