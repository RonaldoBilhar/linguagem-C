#include<stdio.h>
#include<locale.h>
#define MAX 3

void apresenta(int v[MAX][MAX]){
	int i,j;
	
	for(i=0;i<MAX;i++){
		for(j=0;j<MAX;j++)
		printf("%d",v[i][j]);
		putchar('\n');
	}
}

void inverte(int v[MAX][MAX]){
	int i,j,rev;
	for(i=0;i<MAX;i++)
		for(j=i+1;j<MAX;j++){
		    rev=v[i][j];
			v[i][j]=v[j][i];
			v[j][i]=rev;
		}
	
}

main(){
	setlocale(LC_ALL,"Portuguese");
	int vet[MAX][MAX]={{1,2,3},{4,5,6},{7,8,9}};
	puts("\t Vetor normal");
	apresenta(vet);
	puts("\t Vetor invertido");
	inverte(vet);
	apresenta(vet);
}
