#include<stdio.h>

typedef struct{
	int Dia, Mes, Ano;
}DATA;

typedef struct pessoa{
	char Nome[100];
	int Idade;
	float Salario;
	DATA Nasc;
}PESSOA;

/* Carrega a estrutura passada por parametro */

void Ler(PESSOA *ptr){
	printf("Qual o nome:"); 
		gets(ptr->Nome);
	printf("Qual a idade:");
		scanf("%d",&ptr->Idade);    					/* &(*ptr).Nasc     é equivalente a    &ptr->Nasc  */
	printf("Qual o salario:");
		scanf("%f",&ptr->Salario);
	printf("Qual a data de nascimento:");
	/*	scanf("%d/%d/%d",&ptr->Nasc.Dia,&ptr->Nasc.Mes,&ptr->Nasc.Ano);*/
		scanf("%d/%d/%d",&(*ptr).Nasc.Dia,&(*ptr).Nasc.Mes,&(*ptr).Nasc.Ano);
}

/*Mostrar a estrutura passada por parametro*/

void Mostrar(struct pessoa x){
	printf("Nome: %s\n",x.Nome);
	printf("Idade: %d\n",x.Idade);
	printf("Salario: %.2f\n",x.Salario);
	printf("Data de nascimento: %d/%d/%d",x.Nasc.Dia,x.Nasc.Mes,x.Nasc.Ano);
}

main(){
	struct pessoa p={"Carlos",23,1234.45,{25,06,1997}};
	Mostrar(p);
	puts("\n");
	Ler(&p);
	puts("\n");
	Mostrar(p);
}
