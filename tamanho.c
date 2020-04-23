#include <stdio.h>

int tamanho(int escolha)
{
	switch(escolha){
		case 1: return(sizeof(int));
		case 2: return(sizeof(long));
		case 3: return(sizeof(long long));
		case 4: return(sizeof(double));
		case 5: return(sizeof(long double));
		case 6: return(sizeof(float));
		case 7: return(sizeof(char));
	}
	
	return -1;
}


int main()
{
	printf("Pra saber o tamanho das variáveis, pressione:\n1) inteiro\n2) inteiro longo\n3) inteiro long long\n4) double\n5) long double\n6) float\n7) char\n");
	int escolha;
	scanf("%d",&escolha);
	while (escolha<1 || escolha>7){printf("\nEscolha algo VÁLIDO por favor:\n\nPra saber o tamanho das variáveis, pressione:\n1) inteiro\n2) inteiro longo\n3) inteiro long long\n4) double\n5) long double\n6) float\n7) char\n"); scanf("%d",&escolha);} 
	printf("O tamanho é %d bytes",tamanho(escolha));
	return 0;
}
