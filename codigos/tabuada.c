#include <stdio.h>
#include <locale.h>
	
	
int multiplicador(int numero){
	int i, res;
	if(numero != 0){
		printf("\n A tabuada do número %d é:", numero);
		for(i=1; i<11; i++){
		
			res=i*numero;
		
			printf("\n %d * %d = %d", i,numero, res);
		};
	}else{
		printf("Digite um numero maior que 0 !!!!");
	};
}
	
int main(){
		setlocale(LC_ALL,"Portuguese");
	int num=0, resultado, resp;
	do{
		printf("\t --------------------------------\n");
		printf("\t -----------Tabuada--------------\n");
		printf("\t --------------------------------\n");
	
		printf("Digite um número para saber sua tabuada: ");
		scanf("%d", &num);
	
		resultado=multiplicador(num);
		
		printf("\n -----Digite 1 para sair ou outro número para continuar------\n");
		scanf("%d", &resp);
	}while
		(resp!=1);
	
	return 0;
}
