#include<stdio.h>
#include<locale.h>

void main(){
	setlocale(LC_ALL,"Portuguese");
	
	int d, m, a;
	
	printf("Digite uma data (dd/mm/aaaa): ");
	scanf("%d/%d/%d",&d,&m,&a);
	
	switch(m){
		case 2: if(d>=1 && d<=28 + ((a%4==0 && a%100!=0) || a%400==0)) /* se o ano for bissexto devolve 1 se n�o 0 */
					printf("Data v�lida!!");						   /* depois soma com o n�mero de dias */
				else
					printf("Data inv�lida!!");
			break;
		case 4:
		case 6:
		case 9:
		case 11: if (d>=1 && d<=30)
					printf("Data v�lida!!");
				 else
				 	printf("Data inv�lida!!");
		    break;
		default : if (m<1 || m>12)
					printf("Data inv�lida!!");
				  else
				  	if(d>1 || d<31)
				  		printf("Data v�lida!!");
				  		else
				  			printf("Data inv�lida!!");
					  	
	}
}
