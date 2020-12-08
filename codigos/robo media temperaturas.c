#include <stdio.h>
#include <locale.h>

float braco[10][5];
int j,i;

void ArmazenarCodigo(){
	int codigo=1000;
	for(i=0; i<10; i++){
		codigo=codigo + 10;
		braco[i][0]=codigo;
	}
}

void ArmazenarTemperatura(){
	ArmazenarCodigo();
	for(i=0; i<10; i++){
		printf("Digite as 3 temperaturas  do braço %.0f:\n", braco[i][0]);
		scanf("%f %f %f",&braco[i][1], &braco[i][2], &braco[i][3]);
		braco[i][4] = (braco[i][1]+ braco[i][2] +braco[i][3])/3;		
	}
	
}

void ExibirDados(){
	ArmazenarTemperatura();
	for(i=0; i<10; i++){
		printf("\n A média do braço %.0f é de: %.2f°C", braco[i][0], braco[i][4]);
	}
}

void main() {
	setlocale(LC_ALL,"Portuguese");
	ExibirDados();
}
