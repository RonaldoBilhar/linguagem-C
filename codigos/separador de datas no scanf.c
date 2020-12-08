#include<stdio.h>

void main(){
	int dia, mes, ano;
	printf("Digite o dia, mes e ano. dd-mm-aaaa \n"); /* PEDE PRO USUARIO COLOCAR "-" COMO SEPARADOR DAS DATAS */
	scanf("%d-%d-%d",&dia,&mes,&ano); /* SCANF JA INTERPRETA QUAL E O CARACTERE SPARADOR */
	printf("%d/%d/%d\n",dia,mes,ano);
}
