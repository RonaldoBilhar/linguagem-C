#include<stdio.h>
#include<string.h>

#define OP_SAIR "SAIR"

int strcountc(char *s, char ch){
	int i,cont;
	for(i=cont=0;s[i]!='\0';i++)
		if(s[i]==ch)
		cont++;
		return cont;
}

char *wordupr(char *s){
	int i;
	s[0]=toupper(s[0]);
	for(i=1;s[i-1]!='\0';i++)
		if(s[i]==' ')
			s[i]=toupper(s[i]);
		else
		s[i]=tolower(s[i]);
		return s;
}

void separa(char *nome, char *sobrenome){
	int i,j;
	if(strcountc(nome,' ')==0){
		sobrenome[0]='\0';
		return;
	}
	for(i=strlen(nome)-1,j=0; nome[i]!=' ' ; )
		sobrenome[j++] = nome[i--];
	sobrenome[j]='\0';
	nome[i]='\0';
	
	strrev(sobrenome);
}

main(){
	char nome[50], sobrenome[20];
	
	for(;;)	{		/* equivalente ao while(1) */
	printf("Nome completo: ");
	gets(nome);
	if(stricmp(nome,OP_SAIR)==0)
	break;
	separa(nome,sobrenome);
	printf("%s, %s\n",wordupr(sobrenome),wordupr(nome));
	}
}
