#include<stdio.h>
int main(){
	int a,b,c;
	printf("Digite as medidas das laterais do triangulo\n");
	scanf("%d %d %d",&a,&b,&c);
	
	if (a<b+c && b<a+c && c<a+b)
		{	
			if (a==b && b==c)
			{
				printf("Este e um triangulo Equilatero");
					}
			else  if (a!=b && b!=c)
			{
				printf("Este e um triangulo Escaleno");
					}
			else 
				printf("Este e um Isosceles");
		}
	else 
	printf("Estas medidas nao correspondem a um triangulo");	
	
	return 1;	
}
