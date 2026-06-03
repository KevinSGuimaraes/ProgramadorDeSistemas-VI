#include <stdio.h>

int main()
{
	int num = 0;
	int num_2 = 0;
	int resp = 0;
	
	printf("Informe um valor que deseja somar\n");
	scanf("%d",&num);
	printf("Informe outro valor que deseja somar\n");
	scanf("%d",&num_2);
	resp = num+num_2;
	
	printf("O valor e: %d\n", resp);

	return(0);
}