#include<stdio.h>
#include<string.h>

int strcountc(char *s, char ch){
	int i, conta;
	for(i=conta=0;s[i]!='\0';i++)
		if(s[i]==ch)
		conta++;
		return conta;
}

main(){
	char nomes[20], carac;
	
	printf("Nome: "); gets(nomes);
	printf("Caractere: ");
	fflush(stdin);
	carac=getchar();

	printf("%d",strcountc(nomes,carac));
}
