#include<stdio.h>

int main(){
	char ch1, ch2;
	
	printf("digite um caracter: ");
	scanf("%c", &ch1);
	
	printf("digite outro: ");
	scanf(" %c", &ch2);		/* espaço em branco antes do %c para limpar o buffer de memória */
	
		/* caso contrário após o primeiro scanf o programa irá ler a tecla <enter> como um
		caracter*/
		
		/* também poderiamos usar a função fflush(stdin); para fazer limpeza de buffer*/
	
	printf(" os caracteres sao '%c' e '%c'.", ch1, ch2);
	
	
}
