#include<stdio.h>

int main(){
	char ch1, ch2;
	
	printf("digite um caracter: ");
	scanf("%c", &ch1);
	
	printf("digite outro: ");
	scanf(" %c", &ch2);		/* espa�o em branco antes do %c para limpar o buffer de mem�ria */
	
		/* caso contr�rio ap�s o primeiro scanf o programa ir� ler a tecla <enter> como um
		caracter*/
		
		/* tamb�m poderiamos usar a fun��o fflush(stdin); para fazer limpeza de buffer*/
	
	printf(" os caracteres sao '%c' e '%c'.", ch1, ch2);
	
	
}
