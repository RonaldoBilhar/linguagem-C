#include<stdio.h>
#include<string.h>

#define SPACE ' '

int strcountc(char *s, char ch){		/* ir� contar quantos espa�os h� na string */
	int i,cont;
	for(i=cont=0;s[i]!='\0';i++)
		if(s[i]==ch)
		cont++;
		return cont;
}

char *xspace(char *s){
	int i=strlen(s);					/* i = n� de caracteres em S */
	int n_space=strcountc(s,SPACE);		/* n_space = n� de espa�os em S */
	int dim=2*i-n_space;				/* dimens�o total da string resultado,(dobro da strig S - os espa�os em branco )*/
	
	s[dim--]='\0';				/* come�a pelo fim, ent�o j� coloca o new line "\0" */
	for(--i;i>=0;i--)			/* j� come�a decrementando i, pois j� foi colocado "\0" */
		if(s[i]==SPACE)			
			s[dim--]=s[i];		/* se s[i] for um espa�o, apenas copia */
		else{
			s[dim--]=SPACE;		/* se n�o for espa�o, recebe space e depois o caractere de s[i] */
			s[dim--]=s[i];
		}
		return s;
}
main(){
	char str[]="abacate";
	printf("%s",xspace(str));
}
