#include<stdio.h>
#include<string.h>
#include<ctype.h>

int strcounta(char *s);

int strcounta(char *s){
	int i,conta;
	for(i=conta=0;s[i]!='\0';i++)
		if(isalpha(s[i]))
		conta++;
		return conta;
}

main(){
	char pala[50];
	
	puts("digite uma palavra:"); gets(pala);
	
	printf("essa palavra contem %d letras.",strcounta(pala));
}
