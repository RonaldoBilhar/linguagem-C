#include<stdio.h>
int main(){
	struct fichaManutencao{
		int codigo;
		char equipamento[30];
		float valor;
	};
	
	struct fichaManutencao ordemdeservico;
	
	printf("Digite o codigo da ordem de servico: ");
	scanf("%d",&ordemdeservico.codigo);
	
	printf("Digite o equipamento: ");
	fflush(stdin);
	fgets(ordemdeservico.equipamento,30,stdin);
	
	printf("Digite o valor: ");
	scanf("%f",&ordemdeservico.valor);
	
	getchar();
	}
	
