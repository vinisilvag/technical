#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<conio.h>

int main ()
{	
	int escolha, opcao, valorGerado;
	
	do {
	
		srand(time(NULL));
	
		printf("_____________ _____________ _____________\n");
		printf("|           | |           | |           |\n");
		printf("|   | 1 |   | |   | 2 |   | |   | 3 |   |\n");
		printf("|           | |           | |           |\n");
		printf("|           | |           | |           |\n");
		printf("|           | |           | |           |\n");
		printf("|           | |           | |           |\n");
		printf("|       [*] | |       [*] | |       [*] |\n");
		printf("|           | |           | |           |\n");
		printf("|           | |           | |           |\n");
		printf("|           | |           | |           |\n");
		printf("|___________| |___________| |___________|\n\n");
	
		printf("QUE A SORTE ESTEJA SEMPRE AO SEU FAVOR...\n");
		printf("Qual das portas voce deseja abrir?\n");
		scanf("%d", &escolha);
	
		while (escolha<=0 || escolha>3) {
			printf("O numero que voce digitou eh invalido.\n");
			printf("Digite somente um dos numeros: 1, 2 ou 3.\n\n");
			scanf("%d", &escolha);
			}
	
		for (int i=0; i<1; i++) {
			valorGerado = 1+rand() % 3;
			}
		
		switch (valorGerado) {
			case 1: printf("              _____________              \n");
					printf("              |           |              \n");
					printf("              |   | R$ |  |              \n");
					printf("              |           |              \n");
					printf("              |           |              \n");
					printf("              |           |              \n");
					printf("              |           |              \n");
					printf("              |       [*] |              \n");
					printf("              |           |              \n");
					printf("              |           |              \n");
					printf("              |           |              \n");
					printf("              |___________|              \n\n");
					printf("Esta com sorte amigo(a), voce acabou de ganhar um Premio!!! Parabens :-)\n\n");
				break;
			case 2: printf("              _____________              \n");
					printf("              |           |              \n");
					printf("              | | MICAO | |              \n");
					printf("              |           |              \n");
					printf("              |           |              \n");
					printf("              |           |              \n");
					printf("              |           |              \n");
					printf("              |       [*] |              \n");
					printf("              |           |              \n");
					printf("              |           |              \n");
					printf("              |           |              \n");
					printf("              |___________|              \n\n");
					printf("Acordou com o pe esquerdo?! Voce tera que pagar uma PRENDA! :-( \n\n");
				break;
			case 3: printf("              ______________              \n");
					printf("              |            |              \n");
					printf("              |  | NADA |  |              \n");
					printf("              |            |              \n");
					printf("              |            |              \n");
					printf("              |            |              \n");	
					printf("              |            |              \n");
					printf("              |       [*]  |              \n");
					printf("              |            |              \n");
					printf("              |            |              \n");
					printf("              |            |              \n");
					printf("              |____________|              \n\n");
					printf("Nao ha NADA dentro dessa porta! Que pena :-/ \n\n");
				break;
			default: printf("O valor que voce digitou eh invalido!\n");
			}
		printf("Deseja jogar novamente?\n");
		printf("Digite 1 (para SIM) e 0 (para NAO)!\n");
		scanf("%d", &opcao);
			if(opcao==0){
				printf("        FIM\n\n");
			}
			system("cls");
		
		while (opcao!=0 && opcao!=1) {
			printf("O numero que voce digitou eh invalido.\n");
			printf("Digite somente um dos numeros: 0 (para NAO) ou 1 (para SIM).\n");
			scanf("%d", &opcao);
			system("cls");	
			}
		
	} while (opcao==1);
	
		system("cls");
		return 0;
}
