#include<stdio.h>

int main()
{
	int dia = 0;
	
	printf("Favor informe um numero\n");
	scanf("%d",&dia);
	
	switch (dia)
	{
		case 1:
			printf("O numero informado representa Domingo\n");
		break;
		case 2:
			printf("O numero informado representa Segunda-Feira\n");
		break;
		case 3:
			printf("O numero informado representa Terca-Feira\n");
		break;
		case 4:
			printf("O numero informado representa Quarta-Feira\n");
		break;
		case 5:
			printf("O numero informado representa Quinta-Feira\n");
		break;
		case 6:
			printf("O numero informado representa Sexta-Feira\n");
		break;
		case 7:
			printf("O numero informado representa Sabado\n");
		break;
		default:
			printf("O numero informado nao representa um dia da semana\n");
	}
	
	return(0);
}

