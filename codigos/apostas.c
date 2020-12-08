#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<locale.h>

#define NUMS 49		/* total de n° do jogo */
#define MIN_APOSTA 6	/* n° mínimo de aposta */
#define NUM_LINE 7		/* n° de n° apresentado por linha no jogo */

	/* funções */
void inic_random();
void inic(int v[NUMS]);
int ler_ns_apostar();
void gerar(int *v, int n);
void apresentar(int res[]);

/* inicia o gerador de n° aleatórios com um número que depende da hora que se executa a aposta */
void inic_random(){
	long ultime;
	time(&ultime);
	srand((unsigned) ultime);
}
/* inicia com zero o vetor de controle dos números selecionados  */
void inic(int v[]){
	int i;
	for(i=0;i<NUMS;i++)
	v[i]=0;
}
/* lê a quantidade de números a apostar. aceita valores entre MIN_APOSTA e NUMS. aceita o valor zero para terminar o prog. */
int ler_ns_apostar(){
	int n;
	do{
		printf("Quantos números quer apostar? (0 = Sair) ");
		scanf("%d", &n);
	}
	while ((n<MIN_APOSTA || n>NUMS) && n!=0);
	return n;
}
/* gera n números aleat. e coloca a respectiva posição do vetor com valor 1 que indica que esse número foi selecionado */
void gerar(int *v,int n){
	int i, indice;
	for(i=1;i<=n;i++){
		indice= rand()%NUMS;  	/* devolve n° aleatório entre 0 e NUMS */
		if(v[indice]==0)		/* não foi selecionado */
		v[indice]=1;	/* este n° já tinha sido selecionado, logo      */
		else i--;		/* decrementa-se o contador para voltar a       */
	}					/* calcular mais uma vez o i-ésimo n° aleatório */
}
/* apresenta o formato do volante colocando 'xx' nos números selecionados para a aposta */
void apresentar(int res[]){
	int i;
	for(i=0;i<NUMS;i++){
		if(res[i]==0)
			printf(" %2d",i+1);
			else
				printf("xx");
			if((i+1)%NUM_LINE==0)
				putchar('\n');
	}
	putchar('\n');
}

				/* PROGRAMA */
main(){
	int vetor[NUMS];
	int n_nums; /* quantidade de números para jogar no jogo  6...50 */
	
	inic_random();
	while(1){
		inic(vetor);
		if((n_nums = ler_ns_apostar())==0)
		break;
		gerar(vetor,n_nums); /* gerar os números a apostar */
		apresentar(vetor);
	}
}
