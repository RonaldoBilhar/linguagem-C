#include<stdio.h>

int main(){
	float potencia[24];
	float maiorpot=0, menorpot;
	int i=0, resp, hora, horamenor;
	
	do{
	printf("Digite a potencia na hora %d: ",i);
	scanf("%f",&potencia[i]);
		
	
		if(potencia[i]>maiorpot)
		{
			maiorpot=potencia[i];
			hora=i;
		}
		
	i++;
	
	printf("Digite 1 para continuar ou 2 para sair! ");
	scanf("%d",&resp);
	
	} while (resp==1);
	printf("A maior potencia foi de %.2f watt na hora %d.\n",maiorpot, hora);
	printf("A menor potencia foi de %.2f watt na hora %d.",menorpot, horamenor);
	return 0;
	
}
