//Pedro Henrique de Paula Barbosa
//11811EAU012

#include <stdio.h>

int Ack(int , int);

int main (){
	int m,n;
	printf("Digite dos parametros 'm' e 'n' nesta ordem: ");
	scanf("%d%d", &m,&n); getchar();
	printf("o resultado para os parametros %d e %d = %d", m,n,Ack(m,n));
	return 0;
}

int Ack(int m,int n){
	if(m==0){
		return n+1;
	}
	else if(m>0 && n==0){
		return Ack(m-1,1);
	}
	else 
		return Ack(m-1,Ack(m,n-1));
}
