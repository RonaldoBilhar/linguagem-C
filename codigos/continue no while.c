#include<stdio.h>

void main(){
	int i;
	i=1;
	while (i<=20){
	
		if(i==10){
			i++;
			continue;
		}
		else
			printf("%d \n",i++);
			
    }
}
