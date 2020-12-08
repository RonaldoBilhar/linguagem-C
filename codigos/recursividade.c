#include <stdio.h>
#include <stdlib.h>
#include <locale.h> /* para poder acentuar as palavras */

int somar(int valor){
	if(valor != 0){
		return valor + somar(valor - 1);
	}
	else{
		return valor;
	}
}

int main() {
	setlocale(LC_ALL,"Portuguese"); /* para poder acentuar as palavras */
	
	int n, resultado;
	
	printf("\n Digite um número inteiro: ");
	scanf("%d", &n);
	
	resultado = somar(n);
	
	printf("\n Resultado da soma =%d", resultado);
	
	return 0;
}
