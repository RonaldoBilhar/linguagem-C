#include<stdio.h>
#include<string.h>
#include<locale.h>


float testarunidade(char unidade[20], float totalconvertido){
	if(strcmp(unidade,"Km")==0){
		return totalconvertido;
	}else if (strcmp(unidade,"mts")==0){
		return totalconvertido/1000;
	}else if (strcmp(unidade,"milhas")==0){
		return totalconvertido/0.621371;
	}else printf("Unidade de medida inválida \n");
}

int main(){
	setlocale(LC_ALL, "Portuguese");
	float distancia[15];
	char unidadeusada[20];
	float total, totalconvertidoKm;
	int i;
	
	for(i=0; i<15; i++){
		printf("Digite a distancia percorrida pelo carro %d: ",i);
		scanf("%f", &distancia[i]);
		total=total+distancia[i];
	}
	printf("Digite a unidade de medida(Km-mts-milhas): ");
	scanf("%s", &unidadeusada);
	totalconvertidoKm = testarunidade(unidadeusada, total);
	printf("A distancia total foi de %.3f Km.", totalconvertidoKm);
	return 0;
}
