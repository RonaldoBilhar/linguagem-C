#include<stdio.h>
#include<locale.h>

#define DIM 3
#define ESPACO ' '

void inic(char s[DIM][DIM]){
	int i,j;
	for(i=0;i<DIM;i++)
		for(j=0;j<DIM;j++)
		s[i][j]=ESPACO;
}
void mostra(char s[DIM][DIM]){
	int i,j;
	for(i=0;i<DIM;i++){
		for(j=0;j<DIM;j++)
		printf("%c %C",s[i][j], j==DIM-1?' ':'|');
	if(i!=DIM-1)
		printf("\n---------");
		putchar('\n');
	}
}

 main(){
	setlocale(LC_ALL,"Portuguese");
	char velha[DIM][DIM];
	int posx, posy;
	char ch='o';  /* caractere para jogar */
	int n_jogadas=0;
	
	inic(velha);
	
	while(1){
		mostra(velha);
		
		printf("\n Introduza a posição de jogo linha e coluna: ");
		scanf("%d %d", &posx,&posy);
		posx --;
		posy --; /* pois os indices do vetor começam em zero */
		
		if(velha[posx][posy]==ESPACO){  /* casa livre */
		velha[posx][posy]=ch=(ch=='o')?'x':'o';
		n_jogadas++;
		}
		else
		printf("Posição já ocupada.\nJogue novamente! \n");
		if(n_jogadas==DIM*DIM){
			puts("\nFim do jogo!!!\n");
		break; /* acabar com o programa */
		}
	}
	mostra(velha);
}
