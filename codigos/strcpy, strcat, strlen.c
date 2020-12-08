#include<stdio.h>
#include<string.h>



#define DIM 20
#define SEP_NOME ","
/*
int strlen(char*);
char *strcpy(char *dest,char *orig);
char *strcat(char *dest,char *orig);
*/
main(){
	char Nome[DIM+1], Sobrenome[DIM+1], Completo[2*DIM+1];
	while(1){
		printf("Nome: "); gets(Nome);
		if(strlen(Nome)==0) break;  /* termina o programa caso inserido um nome vazio */
		printf("Sobrenome: "); gets(Sobrenome);
		
		strcpy(Completo,Sobrenome);		/* copia Sobrenome p/ Completo */
		strcat(Completo,SEP_NOME);		/* concatena SEP_NOME p/ final de Completo */
		strcat(Completo,Nome);			/* concatena Nome p/ final de Completo + SEP_NOME */
		puts(Completo);				/* imprime o vetor 'Completo' */
	}
}
