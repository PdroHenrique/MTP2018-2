//Pedro Henrique de Paula Barbosa
//11811EAU012

#include <stdio.h>

typedef
unsigned long long int
Bytes8;
typedef
struct LCG { Bytes8 a, c, m, rand_max, atual; }
LCG;
void semente(LCG * r, Bytes8 seed) {
// constantes do POSIX [de]rand48, glibc [de]rand48[_r]
// ULL transforma a constante ’int’ em ’unsigned long long int’
r->a = 0x5DEECE66DULL;
r->c = 11ULL;
r->m = (1ULL << 48);
r->rand_max = r->m - 1;
r->atual = seed;
}
Bytes8 lcg_rand(LCG * r) {
r->atual = (r->a * r->atual + r->c) % r->m;
return r->atual;
}
double lcg_rand_01(LCG * r) {
return ((double) lcg_rand(r))/(r->rand_max);
}

void gera_numeros(float * vetor, int tam,float min, float max, LCG * r) {
int i;
for(i = 0; i < tam; i++)
vetor[i] = (max-min)*lcg_rand_01(r) + min;
}

float soma(float *inicio_vetor, float *fim_vetor){
	float S = 0;
	float * soma;
	for(soma=inicio_vetor; soma != fim_vetor; soma++){
		S += *soma;
	}
	return S;
}


float produto(float*inicio_vetor, float *fim_vetor){
	float P = 1 ;
	float * produto;
	for(produto = inicio_vetor; produto != fim_vetor; produto++){
		P *= *produto;	
	}
	return P;
}

int main(){
	LCG random; semente(&random,123456);
	int op;
	float Vet[50];
	do{
	printf("Serao gerados 50 numeros aleatorios!");
	printf("\nEscolha 1-Para calcular o somatorio. \n2-Para calcular o produto.");
	scanf("%d", &op); getchar();
	}while(op<=0 || op>=3);
	gera_numeros(Vet, 50, 0.5, 1.5, &random);
	if(op==1){
		printf("\nO resultado do somatorio e: %f", soma(Vet,Vet+50));
	}
	if(op==2){
		printf("\nO resultado do Produto e: %f", produto(Vet, Vet+50));
	}
}
