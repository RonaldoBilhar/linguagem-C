#include<stdio.h>

void main(){
	int horas;
	long int res;
	char tipo;
	
	printf("Digitem uma hora inteira:\n");
	scanf("%d",&horas);
	
	printf("O que deseja saber? M=minutos, S=segundos, D=decimos de segundo\n");
	fflush(stdin);
	tipo=getchar();
	
	switch (tipo)
	{
		case 'M': res=horas<0 ? 0 :horas*60L; break;
		case 'S': res=horas<0 ? 0 :horas*3600L; break;
		case 'D': res=horas<0 ? 0 :horas*36000L; break;
		default : printf("Tipo incorreto!");	
	}
	printf("%dh tem %li/%c",horas,res,tipo);
}
