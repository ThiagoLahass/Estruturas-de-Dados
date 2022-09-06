#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define PI 3.14159265

void calc_esfera (float r, float* area, float* volume);

int raizes (float a, float b, float c, float* x1, float* x2);

int pares (int n, int* vet);

void inverte (int n, int* vet);

double avalia (double* poli, int grau, double x);

int main(){
	
	// QUESTÃO 1
	printf("----------QUESTÃO 1------------\n\n");
	float r, area, volume;
	r = 10;
	calc_esfera( r, &area, &volume);
	printf("r = %.2f\narea = %.2f\nvolume = %.2f\n\n", r, area, volume);
	
	
	// QUESTÃO 2
	printf("------------QUESTÃO 2-----------\n\n");
	float a = 2, b = 3, c = -5, x1, x2;
	int quant_raizes;
	
	quant_raizes = raizes(a, b, c, &x1, &x2);
	printf("Equacao = %.2fx² + %.2fx + %.2f\n", a, b, c);
	
	if( quant_raizes == 0 ){
		printf("A equacao nao possui raizes reais\n");
	}
	else {
		printf("x1 = %.2f\nx2 = %.2f\n\n", x1, x2);
	}
	
	// QUESTÃO 3
	printf("------------QUESTÃO 3-----------\n\n");
	
	int tamanho_vet = 10, quant_pares;
	
	int *vet = (int*) calloc( tamanho_vet, sizeof(int));
	
	printf("Vet = {");
	for( int i = 0; i < tamanho_vet; i++){
		vet[i] = i;
		
		if( i != tamanho_vet - 1)
			printf("%d, ", vet[i]);
		else
			printf("%d}\n\n", vet[i]);
	}
	
	quant_pares = pares(tamanho_vet, vet);
	
	printf("Quantidade de pares = %d\n", quant_pares);

	// QUESTÃO 4
	printf("------------QUESTÃO 4-----------\n\n");
	inverte( tamanho_vet, vet);

	printf("Vet invertido = {");
	for( int i = 0; i < tamanho_vet; i++){
		if( i != tamanho_vet - 1)
			printf("%d, ", vet[i]);
		else
			printf("%d}\n\n", vet[i]);
	}

	// QUESTÃO 5
	printf("------------QUESTÃO 5-----------\n\n");
	double resultado, x = 10;
	double *poli = (double*) calloc(3, sizeof(double));
	poli[0] = 12;
	poli[1] = 2;
	poli[2] = 4;

	resultado = avalia( poli, 2, x );
	printf("polinomio = (%.2lf)x² + (%.2lf)x + (%.2lf)\n", poli[2], poli[1], poli[0]);
	printf("x = 10\n");
	printf("resultado = %.2lf\n\n", resultado);

	free(poli);
	free(vet);
	return 0;
}

void calc_esfera (float r, float* area, float* volume) {
	*area = 4 * PI * (pow(r,2));
	*volume = (4 * PI * (pow(r,3))) / 3;
}

int raizes (float a, float b, float c, float* x1, float* x2) {

	int delta = pow(b,2) - 4 * a * c;
	
	if( delta < 0 ) {
		return 0;
	}
	else if( delta == 0 ) {
		*x1 = (-b + sqrt(delta)) / (2 * a);
		*x2 = *x1;
		
		return 1; 
	}
	else {
		*x1 = (-b + sqrt(delta)) / (2 * a);
		*x2 = (-b - sqrt(delta)) / (2 * a);
		
		return 2;
	}
}


int pares (int n, int* vet){
	
	int quant_pares = 0;
	
	for(int i = 0; i < n; i++ ) {
		if( vet[i]%2 == 0) {
			quant_pares++;
		}
	}

	return quant_pares;
}

void inverte (int n, int* vet) {
	int *newVet = (int*) calloc( n, sizeof(int));

	for( int i = 0; i < n; i++ ) {
		newVet[i] = vet[n-1 - i];
	}
	for( int i = 0; i < n; i++ ) {
		vet[i] = newVet[i];
	}

	free(newVet);
}


double avalia (double* poli, int grau, double x) {

	double resultado = 0;
	for( int i = 0; i <= grau; i++ ) {
		resultado += poli[i] * pow(x, i);
	}

	return resultado;
}