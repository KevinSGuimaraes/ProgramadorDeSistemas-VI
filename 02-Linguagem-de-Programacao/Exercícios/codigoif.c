#include<stdio.h>

int main()
{
	int numero = 0;
	
	printf("Informe um numero inteito\n");
	scanf("%d",&numero);
	if(numero > 5)
	{
		printf("O numero digitado e maior que 5\n");
	}
	else
	{
		printf("O numero digitado é menor que 5\n");
	}
	
	return(0);
}
