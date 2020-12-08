#include<stdio.h>
#include<string.h>

#define SPACE ' '

int strcountc(char *s, char ch){		/* irá contar quantos espaços há na string */
	int i,cont;
	for(i=cont=0;s[i]!='\0';i++)
		if(s[i]==ch)
		cont++;
		return cont;
}

char *xspace(char *s){
	int i=strlen(s);					/* i = n° de caracteres em S */
	int n_space=strcountc(s,SPACE);		/* n_space = n° de espaços em S */
	int dim=2*i-n_space;				/* dimensão total da string resultado,(dobro da strig S - os espaços em branco )*/
	
	s[dim--]='\0';				/* começa pelo fim, então já coloca o new line "\0" */
	for(--i;i>=0;i--)			/* já começa decrementando i, pois já foi colocado "\0" */
		if(s[i]==SPACE)			
			s[dim--]=s[i];		/* se s[i] for um espaço, apenas copia */
		else{
			s[dim--]=SPACE;		/* se não for espaço, recebe space e depois o caractere de s[i] */
			s[dim--]=s[i];
		}
		return s;
}
main(){
	char str[]="abacate";
	printf("%s",xspace(str));
}
