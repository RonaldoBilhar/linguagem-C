#include<stdio.h>

typedef struct data{int Dia, Mes, Ano;} DATA;		/*typedef faz com que "DATA" seja a mesma coisa que "strut data"*/

typedef struct pessoa{						
	char Nome[100];				/*"struct pessoa" é o mesmo que "PESSOA", por causa do typdef*/
	int Idade;
	float Salario;
	struct data Nasc;	/*poderiamos colocar a var Nasc como tipo "DATA"*/
}PESSOA;

void Mostrar(struct pessoa x){				/*poderiamos colocar como parametro "strust pessoa"*/
	printf("Nome: %s\n",x.Nome);		
	printf("Idade: %d\n",x.Idade);
	printf("Salario: %.2f\n",x.Salario);
	printf("Data de nasc.: %d-%d-%d\n",x.Nasc.Dia,x.Nasc.Mes,x.Nasc.Ano);
}

main(){
	PESSOA p={"Carlos",23,1823.54,{25,06,1999}};  /*poderiamos declarar a var p como sendo do tipo "struct pessoa"*/
	
	Mostrar(p);
}
