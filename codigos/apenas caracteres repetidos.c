#include<stdio.h>

int strcountc(char *s, char ch){
	int i,cont;
	for(i=cont=0;s[i]!='\0';i++)
		if(s[i]==ch)
		cont++;
		return cont;
}


char *rep(char *s){
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
		if(strcountc(s,s[i])>1)
		s[j++]=s[i];
	s[j]='\0';
	return s;
}

main(){
	char vet[]="alta fidelidade";
	printf("%s", rep(vet));
	
	
}

