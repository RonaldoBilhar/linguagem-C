#include<stdio.h>

main(){
	int num1, num2, rev,i;
	
	printf("Digite dois N° inteiro entre 0 e 255:...");
	scanf("%d %d",&num1,&num2);
	
	while(num1<0 || num1>255 || num2<0 || num2>255){
		printf("Digite dois N° dentro da faixa especificada:...");
			scanf("%d %d",&num1, &num2);
	}
	
	if (num1>num2){
		rev=num2;
		num2=num1;
		num1=rev;
	}
	for(i=num1;i<=num2;i++)
	printf("%3d --> %c \n",i, (char)i);
}

