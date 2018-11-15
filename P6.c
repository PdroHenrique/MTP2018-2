//Pedro Henrique de Paula Barbosa
//11811EAU012

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef double Coordenada;
typedef struct { Coordenada X, Y; } Ponto;

Ponto * gera_pontos(int N) {
    Ponto * pontos = (Ponto *) calloc(N,sizeof(Ponto));
    int i;
    for(i = 0; i < N; i++){
        pontos[i].X = cos(i*2.0*M_PI/(N-1));
		pontos[i].Y = sin(i*2.0*M_PI/(N-1));
	}
    return pontos;
}

void mostra_pontos(Ponto * p_ini, Ponto * p_fim) {
    if(p_ini < p_fim) {
        printf("(%.3lf, %.3lf) \n", p_ini->X, p_ini->Y);
        mostra_pontos(p_ini+1, p_fim);
    }
}

int main() {
    unsigned int N;
    Ponto * pontos;
    printf("Qual o numero de pontos desejados: ");
    scanf("%u", &N); getchar();
    pontos = gera_pontos(N);
    mostra_pontos(pontos, pontos + N);
    free(pontos);
    return 0;
}
