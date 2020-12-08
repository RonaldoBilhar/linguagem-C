#include<stdio.h>


char *strpack(char *s){
	int i,j;
	for(i=j=0;s[i]!='\0';i++)
		if(s[i]!=s[j])
			s[++j]=s[i];
	s[++j]='\0';
	return s;
}

main(){
	char str[20+1]="rroonnaaalddo";
	
	printf("%s",strpack(str));
}
