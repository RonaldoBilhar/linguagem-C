#include<stdio.h>
int main()
{
int n, x;
unsigned long int fatorial;

printf("Digite um numero inteiro para saber seu fatorial:");
scanf("%d",&n);

for(x=1; x<=n; x++)
{
	(fatorial=fatorial*x);
	
}

printf("O fatorial de %d e %lu \n",n,fatorial);  /* usar "%lu" para a escrita ou leitura de unsigned long*/
return 0;
}
