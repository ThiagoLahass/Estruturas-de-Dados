#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct aluno{
	char* nome;
	int matricula;
	float p1;
	float p2;
	float p3;
}Aluno;

void Aloca_aluno (Aluno* aluno);
char* Le_nome ();
void Imprime_aluno (Aluno* aluno);
float media_aluno( Aluno* aluno);
void desaloca_turma(int n, Aluno** turma);

void imprime_aprovados (int n, Aluno** turma);
float media_turma (int n, Aluno** turma);

int main(){
	int n = 0;
	
	printf("Digite o  numero de alunos:\n");
	scanf("%d", &n);
	printf("n = %d\n", n);
	Aluno** turma = (Aluno**) malloc (n * sizeof(Aluno*));
	
	
	for(int i = 0; i < n; i++) {
		turma[i] = (Aluno*) malloc( sizeof(Aluno));
		Aloca_aluno(turma[i]);
	}
	
	
	for(int i = 0; i < n; i++) {
		Imprime_aluno(turma[i]);
	}
	
	
	imprime_aprovados(n, turma);
	
	
	float media = 0.0;
	media = media_turma(n, turma);
	
	printf("Media da turma: %.2f\n", media);
	
	
	desaloca_turma(n, turma );
	
	return 0;
}


void Aloca_aluno (Aluno* aluno){
	
	int matricula = 0;
	float nota = 0.0;
	char nome[101];
	
	printf("Digite o nome do aluno(a):\n");
	scanf(" %100[^\n]", nome);
	aluno->nome = strdup(nome);
	
	//printf("%s\n", aluno->nome);
	
	printf("Digite a matricula do aluno(a):\n");
	scanf("%d", &matricula);
	aluno->matricula = matricula;
	
	printf("Digite a nota da p1:\n");
	scanf("%f", &nota);
	aluno->p1 = nota;
	
	printf("Digite a nota da p2:\n");
	scanf("%f", &nota);
	aluno->p2 = nota;
	
	printf("Digite a nota da p3:\n");
	scanf("%f", &nota);
	aluno->p3 = nota;
}


void Imprime_aluno (Aluno* aluno) {
	printf("Nome: %s\n", 		aluno->nome);
	printf("Matricula: %d\n", 	aluno->matricula);
	printf("Nota p1: %.2f\n", 	aluno->p1);
	printf("Nota p2: %.2f\n", 	aluno->p2);
	printf("Nota p3: %.2f\n\n", aluno->p3);
}


void imprime_aprovados (int n, Aluno** turma) {
	
	printf("Aprovados:\n");
	
	int media = 0;
	for(int i = 0; i < n; i++) {
		media = media_aluno( turma[i] );
		if(media >= 5){
			printf("%s\n", turma[i]->nome);
		}
	}
}


float media_aluno( Aluno* aluno) {
	
	float media = (aluno->p1 + aluno->p2 + aluno->p3)/3;
	return media;
}

float media_turma (int n, Aluno** turma) {
	float somatorio_medias = 0.0;
	float media_turma = 0.0;
	
	for(int i = 0; i < n; i++) {
		somatorio_medias += ((turma[i]->p1 + turma[i]->p2 + turma[i]->p3)/3);
	}
	
	media_turma = somatorio_medias/n;
	
	return media_turma;
}


void desaloca_turma(int n, Aluno** turma) {

	for(int i = 0; i < n; i++) {
		free(turma[i]->nome);
		free(turma[i]);
	}
	free(turma);
}






