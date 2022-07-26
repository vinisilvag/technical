#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<time.h>

int tabuleiro[16][16], tabuleiroPC[16][16];

void zeraTabuleiro() {
	int i=0, j=0;

	for (i=0; i<16; i++) {
		for (j=0; j<16; j++) {
			tabuleiro[i][j] = 0;
			tabuleiroPC[i][j] = 0;
		}
	}
}

void zeraArmazenaPosicoes (int armazenaPosit[][4], int armazenaPositPC[][4]) {
	int i=0, j=0;

	for (i=0; i<10; i++) {
		for (j=0; j<4; j++) {
			armazenaPosit[i][j] = ' ';
			armazenaPositPC[i][j] = ' ';
		}
	}
}

void printaTabuleiro () {
	int i=0, j=0;
	
	printf(" PLAYER:\n");
	printf("\n     1   2   3   4   5   6   7   8   9  10  11  12  13  14\n");
	for(i=0 ; i<14 ; i++){
		printf("   |-------------------------------------------------------|\n");
		printf(" %c |", (char)i+65);
		for(j=0 ; j<14 ; j++){
			if (tabuleiro[i][j] == 0) {
				printf("   |");
			}
			if (tabuleiro[i][j] == 1 || tabuleiro[i][j] == 2 || tabuleiro[i][j] == 3 || tabuleiro[i][j] == 4 || tabuleiro[i][j] == 5 || tabuleiro[i][j] == 6 || tabuleiro[i][j] == 7 || tabuleiro[i][j] == 8 || tabuleiro[i][j] == 9 || tabuleiro[i][j] == 10) {
				printf(" O |");
			}
			if (tabuleiro[i][j] == 11) {
				printf("   |");
			}
			if (tabuleiro[i][j] == -1) {
				printf(" # |");
			}
			if (tabuleiro[i][j] == -2) {
				printf(" X |");
			}
		}
		printf("\n");
	}
	printf("   |-------------------------------------------------------|\n");
}

void printaTabuleiroPC() {
	int i=0, j=0;
	
	printf("\n MAQUINA:\n");
	printf("\n     1   2   3   4   5   6   7   8   9  10  11  12  13  14\n");
	for(i=0 ; i<14 ; i++){
		printf("   |-------------------------------------------------------|\n");
		printf(" %c |", (char)i+65);
		for(j=0 ; j<14 ; j++){
			if (tabuleiroPC[i][j] == 0) {
				printf("   |");
			}
			if (tabuleiroPC[i][j] == 1 || tabuleiroPC[i][j] == 2 || tabuleiroPC[i][j] == 3 || tabuleiroPC[i][j] == 4 || tabuleiroPC[i][j] == 5 || tabuleiroPC[i][j] == 6 || tabuleiroPC[i][j] == 7 || tabuleiroPC[i][j] == 8 || tabuleiroPC[i][j] == 9 || tabuleiroPC[i][j] == 10) {
				printf("   |");
			}
			if (tabuleiroPC[i][j] == 11) {
				printf("   |");
			}
			if (tabuleiroPC[i][j] == -1) {
				printf(" # |");
			}
			if (tabuleiroPC[i][j] == -2) {
				printf(" X |");
			}
		}
		printf("\n");
	}
	printf("   |-------------------------------------------------------|\n");
}

void iniciaJogo(char inicia[]) {
	
	printf("\t\t\t\t Batalha Naval!\n\n");
	do {
		printf("Deseja comecar a jogar? (S/N)\nResposta: ");
		fflush(stdin);
		scanf("%[^\n]s", inicia);
		strlwr(inicia);
		
		if (inicia[0] != 's' && inicia[0] != 'n') {
			printf("\nVoce digitou um caractere invalido!\n");
		}
	} while (inicia[0] != 's' && inicia[0] != 'n');
	printf("\n");
}

void manualAleatorio (char inicia[]) {
	do {
		printf("Deseja marcar seus navios aleatoriamente ou manualmente? (A/M)\nResposta: ");
		fflush(stdin);
		scanf("%[^\n]s", inicia);
		strlwr(inicia);
		
		if (inicia[0] != 'm' && inicia[0] != 'a') {
			printf("\nVoce digitou um caractere invalido!\n");
		}
	} while (inicia[0] != 'm' && inicia[0] != 'a');
}

int jatemNavio(int tabuleiro[][16], int tamnavio, int linha, int coluna, int dir) {
	int i;
	
	if (dir == 1) {
		for (i=0; i<tamnavio; i++) {
			if (tabuleiro[linha][coluna+i] == 11 || tabuleiro[linha][coluna+i] == 1 || tabuleiro[linha][coluna+i] == 2 || tabuleiro[linha][coluna+i] == 3 || tabuleiro[linha][coluna+i] == 4 || tabuleiro[linha][coluna+i] == 5 || tabuleiro[linha][coluna+i] == 6 || tabuleiro[linha][coluna+i] == 7 || tabuleiro[linha][coluna+i] == 8 || tabuleiro[linha][coluna+i] == 9 || tabuleiro[linha][coluna+i] == 10) {
				return 0;
			}
		}	
	}
	if (dir == 2) {
		for (i=0; i<tamnavio; i++) {
			if (tabuleiro[linha][coluna-i] == 11 || tabuleiro[linha][coluna-i] == 1 || tabuleiro[linha][coluna-i] == 2 || tabuleiro[linha][coluna-i] == 3 || tabuleiro[linha][coluna-i] == 4 || tabuleiro[linha][coluna-i] == 5 || tabuleiro[linha][coluna-i] == 6 || tabuleiro[linha][coluna-i] == 7 || tabuleiro[linha][coluna-i] == 8 || tabuleiro[linha][coluna-i] == 9 || tabuleiro[linha][coluna-i] == 10) {
				return 0;
			}
		}	
	}
	if (dir == 3) {
		for (i=0; i<tamnavio; i++) {
			if (tabuleiro[linha-i][coluna] == 11 || tabuleiro[linha-i][coluna] == 1 || tabuleiro[linha-i][coluna] == 2 || tabuleiro[linha-i][coluna] == 3 || tabuleiro[linha-i][coluna] == 4 || tabuleiro[linha-i][coluna] == 5 || tabuleiro[linha-i][coluna] == 6 || tabuleiro[linha-i][coluna] == 7 || tabuleiro[linha-i][coluna] == 8 || tabuleiro[linha-i][coluna] == 9 || tabuleiro[linha-i][coluna] == 10) {
				return 0;
			}
		}	
	}
	if (dir == 4) {
		for (i=0; i<tamnavio; i++) {
			if (tabuleiro[linha+i][coluna] == 11 || tabuleiro[linha+i][coluna] == 1 || tabuleiro[linha+i][coluna] == 2 || tabuleiro[linha+i][coluna] == 3 || tabuleiro[linha+i][coluna] == 4 || tabuleiro[linha+i][coluna] == 5 || tabuleiro[linha+i][coluna] == 6 || tabuleiro[linha+i][coluna] == 7 || tabuleiro[linha+i][coluna] == 8 || tabuleiro[linha+i][coluna] == 9 || tabuleiro[linha+i][coluna] == 10) {
				return 0;
			}
		}	
	}
	
	return 1;
}

int checaValidez (int tamnavio, int linha, int coluna, int dir) {
	if (dir == 1) {
		if (coluna+tamnavio-1 > 13) {
			return 0;
		}
	}
	if (dir == 2) {
		if (coluna-tamnavio+1 < 0) {
			return 0;
		}
	}
	if (dir == 3) {
		if (linha-tamnavio+1 < 0) {
			return 0;
		}
	}
	if (dir == 4) {
		if (linha+tamnavio-1 > 13) {
			return 0;
		}
	}
	return 1;
}

void direcao (int tabuleiro[][16], int tamnavio, int linha, int coluna, int dir, int navios, int contorno) {
	int i;
	
	//DIREITA
	if (dir == 1) {
		if (coluna != 13) {
			if (linha != 0) {
				tabuleiro[linha-1][coluna-1] = contorno;
			}
			tabuleiro[linha][coluna-1] = contorno;
			if (linha != 13) {
				tabuleiro[linha+1][coluna-1] = contorno;
			}
		}
		for (i=0; i<tamnavio; i++) {
			if (linha != 0) {
				tabuleiro[linha-1][coluna+i] = contorno;
			}
			tabuleiro[linha][coluna+i] = navios;
			if (linha != 13) {
				tabuleiro[linha+1][coluna+i] = contorno;
			}
		}
		if (coluna+i != 0) {
		    if (linha != 0) {
		        tabuleiro[linha-1][coluna+i] = contorno;
		    }
		    tabuleiro[linha][coluna+i] = contorno;
		    if (linha != 13) {
		        tabuleiro[linha+1][coluna+i] = contorno;
		    }
		}
	}
	
	//ESQUERDA
	if (dir == 2) {
		if (coluna <= 13) {
			if (linha >= 0) {
				tabuleiro[linha-1][coluna+1] = contorno;
			}
			tabuleiro[linha][coluna+1] = contorno;
			if (linha <= 13) {
				tabuleiro[linha+1][coluna+1] = contorno;
			}
		}
		for (i=0; i<tamnavio; i++) {
			if (linha >= 0) {
				tabuleiro[linha-1][coluna-i] = contorno;
			}
			tabuleiro[linha][coluna-i] = navios;
			if (linha <= 13) {
				tabuleiro[linha+1][coluna-i] = contorno;
			}
		}
		if (coluna-i >= 0) {
		    if (linha >= 0) {
		        tabuleiro[linha-1][coluna-i] = contorno;
		    }
		    tabuleiro[linha][coluna-i] = contorno;
		    if (linha <= 13) {
		        tabuleiro[linha+1][coluna-i] = contorno;
		    }
		}
	}
	
	//CIMA
	if (dir == 3) {
		if (linha <= 13) {
			if (coluna >= 0) {
				tabuleiro[linha+1][coluna-1] = contorno;
			}
			tabuleiro[linha+1][coluna] = contorno;
			if (coluna <= 13) {
				tabuleiro[linha+1][coluna+1] = contorno;
			}
		}
		for (i=0; i<tamnavio; i++) {
			if (coluna >= 0) {
				tabuleiro[linha-i][coluna-1] = contorno;
			}
			tabuleiro[linha-i][coluna] = navios;
			if (coluna <= 13) {
				tabuleiro[linha-i][coluna+1] = contorno;
			}
		}
		if(linha-i >= 0) {
		    if(coluna >= 0) {
		        tabuleiro[linha-i][coluna-1] = contorno;
		    }
		    tabuleiro[linha-i][coluna] = contorno;
		    if(coluna <= 13) {
		        tabuleiro[linha-i][coluna+1] = contorno;
		    }
		}
	}
	
	//BAIXO
	if (dir == 4) {
		if (linha <= 13) {
			if (coluna <= 13) {
				tabuleiro[linha-1][coluna+1] = contorno;
			}
			tabuleiro[linha-1][coluna] = contorno;
			if (coluna >= 0) {
				tabuleiro[linha-1][coluna-1] = contorno;
			}
		}
		for (i=0; i<tamnavio; i++) {
			if (coluna >= 0) {
				tabuleiro[linha+i][coluna-1] = contorno;
			}
			tabuleiro[linha+i][coluna] = navios;
			if (coluna <= 13) {
				tabuleiro[linha+i][coluna+1] = contorno;
			}
		}
		if (linha+i <= 13) {
		    if (coluna >= 0) {
		        tabuleiro[linha+i][coluna-1] = contorno;
		    }
		    tabuleiro[linha+i][coluna] = contorno;
		    if (coluna <= 13) {
		        tabuleiro[linha+i][coluna+1] = contorno;
		    }
		}
	}
}

void jogadaRand(int tabuleiro[][16], int tamnavio, int navios, int contorno, int *armazenaPosit) {
	int linha, coluna, dir, i;
	
	srand(time(NULL));
	do {
		linha = rand () % 14;
		coluna = rand() % 14;
		dir = rand () % 4+1;
			
	} while (checaValidez(tamnavio, linha, coluna, dir) == 0 || jatemNavio(tabuleiro, tamnavio, linha, coluna, dir) == 0);
	
	armazenaPosit[0] = linha;
	armazenaPosit[1] = coluna;
	armazenaPosit[2] = tamnavio;
	armazenaPosit[3] = dir;
	
	direcao(tabuleiro, tamnavio, linha, coluna, dir, navios, contorno);
			
}

void jogada(int tamnavio, int navios, int contorno, int *armazenaPosit) {
	int linhaInt, coluna, dir, i, aviso=0;
	char posicao[1];
	
	do {
		system("cls");
		printaTabuleiro();
		do {
			if (aviso == 1) {
				printf("\nJa existe um navio nesse rumo!");
			}
			if (checaValidez(tamnavio, linhaInt, coluna, dir) == 0) {
				printf("\nVoce digitou uma posicao incompativel ao tamanho do seu navio!");
			}
			printf("\nDigite a posicao onde voce deseja marcar o seu navio:\n");
			printf("Linha: ");
			fflush(stdin);
			scanf("%[^\n]s", posicao);
			strupr(posicao);
			linhaInt = (int)posicao[0]-65;
			
			printf("Coluna: ");
			scanf("%i", &coluna);
			coluna--;
		
			if (linhaInt < 0 || linhaInt > 13 || coluna < 0 || coluna > 13) {
				printf("\nVoce digitou uma posicao invalida!");
			}
			
			if (tabuleiro[linhaInt][coluna] == 11 || tabuleiro[linhaInt][coluna] == 1 || tabuleiro[linhaInt][coluna] == 2 || tabuleiro[linhaInt][coluna] == 3 || tabuleiro[linhaInt][coluna] == 4 || tabuleiro[linhaInt][coluna] == 5 || tabuleiro[linhaInt][coluna] == 6 || tabuleiro[linhaInt][coluna] == 7 || tabuleiro[linhaInt][coluna] == 8 || tabuleiro[linhaInt][coluna] == 9 || tabuleiro[linhaInt][coluna] == 10) {
				printf("\nVoce digitou uma posicao ja ocupada!");
			}
		} while (linhaInt < 0 || linhaInt > 13 || coluna < 0 || coluna > 13 || tabuleiro[linhaInt][coluna] == 11 || tabuleiro[linhaInt][coluna] == 1 || tabuleiro[linhaInt][coluna] == 2 || tabuleiro[linhaInt][coluna] == 3 || tabuleiro[linhaInt][coluna] == 4 || tabuleiro[linhaInt][coluna] == 5 || tabuleiro[linhaInt][coluna] == 6 || tabuleiro[linhaInt][coluna] == 7 || tabuleiro[linhaInt][coluna] == 8 || tabuleiro[linhaInt][coluna] == 9 || tabuleiro[linhaInt][coluna] == 10);
	
		do {
			printf("\nDigite a direcao para onde deseja expandir o seu navio:\n1 - Direita\n2 - Esquerda\n3 - Cima\n4 - Baixo\n\nResposta: ");
			scanf("%i", &dir);
			
			if (dir < 1 || dir > 4) {
				printf("\nVoce digitou um numero invalido!\n");
			}
		} while (dir < 1 || dir > 4);
		
		if (jatemNavio(tabuleiro, tamnavio, linhaInt, coluna, dir) == 0) {
			aviso = 1;
		}
	} while (checaValidez(tamnavio, linhaInt, coluna, dir) == 0 || jatemNavio(tabuleiro, tamnavio, linhaInt, coluna, dir) == 0);
	
	armazenaPosit[0] = linhaInt;
	armazenaPosit[1] = coluna;
	armazenaPosit[2] = tamnavio;
	armazenaPosit[3] = dir;
	
	direcao (tabuleiro, tamnavio, linhaInt, coluna, dir, navios, contorno);
}

void tiro (int tabuleiro[][16], int tabuleiroPC[][16], int indicador) {
	char posicao[1];
	int coluna, linhaInt, linha;
	
	if (indicador == 1) {
		do {
			printf("\nDigite onde deseja atirar:\nLinha: ");
			fflush(stdin);
			scanf("%[^\n]s", posicao);
			strupr(posicao);	
			linhaInt = (int)posicao[0]-65;
			
			printf("Coluna: ");
			scanf("%i", &coluna);
			coluna--;
			
			if (linhaInt < 0 || linhaInt > 13 || coluna < 0 || coluna > 13) {
				printf("\nVoce digitou uma posicao invalida!");
			}
			if (tabuleiroPC[linhaInt][coluna] == -1 || tabuleiroPC[linhaInt][coluna] == -2) {
				printf("\nVoce ja tentou atirar nessa posicao!");
			}
		} while (linhaInt < 0 || linhaInt > 13 || coluna < 0 || coluna > 13 || tabuleiroPC[linhaInt][coluna] == -1 || tabuleiroPC[linhaInt][coluna] == -2);
		
		if (tabuleiroPC[linhaInt][coluna] == 1 || tabuleiroPC[linhaInt][coluna] == 2 || tabuleiroPC[linhaInt][coluna] == 3 || tabuleiroPC[linhaInt][coluna] == 4 || tabuleiroPC[linhaInt][coluna] == 5 || tabuleiroPC[linhaInt][coluna] == 6 || tabuleiroPC[linhaInt][coluna] == 7 || tabuleiroPC[linhaInt][coluna] == 8 || tabuleiroPC[linhaInt][coluna] == 9 || tabuleiroPC[linhaInt][coluna] == 10) {
			tabuleiroPC[linhaInt][coluna] = -1;
		}
		if (tabuleiroPC[linhaInt][coluna] == 0 || tabuleiroPC[linhaInt][coluna] == 11) {
			tabuleiroPC[linhaInt][coluna] = -2;
		}
			
	} else {
		srand(time(NULL));
		
		do {
			linha = rand () % 14;
			coluna = rand () % 14;
			
		} while (tabuleiro[linha][coluna] == -1 || tabuleiro[linha][coluna] == -2);
		
		if (tabuleiro[linha][coluna] == 1 || tabuleiro[linha][coluna] == 2 || tabuleiro[linha][coluna] == 3 || tabuleiro[linha][coluna] == 4 || tabuleiro[linha][coluna] == 5 || tabuleiro[linha][coluna] == 6 || tabuleiro[linha][coluna] == 7 || tabuleiro[linha][coluna] == 8 || tabuleiro[linha][coluna] == 9 || tabuleiro[linha][coluna] == 10) {
			tabuleiro[linha][coluna] = -1;
		}
		if (tabuleiro[linha][coluna] == 0 || tabuleiro[linha][coluna] == 11) {
			tabuleiro[linha][coluna] = -2;
		}
	}
}

void testaNavios (int tabuleiro[][16], int armazenaPosit[][4]) {
	int vit1=0, vit2=0, vit3=0, vit4=0, vit5=0, vit6=0, vit7=0, vit8=0, vit9=0, vit10=0;
	
	for (int i=0; i<14; i++) {
		for (int j=0; j<14; j++) {
			if (tabuleiro[i][j] == 1) {
				vit1++;
			}
			if (tabuleiro[i][j] == 2) {
				vit2++;
			}
			if (tabuleiro[i][j] == 3) {
				vit3++;
			}
			if (tabuleiro[i][j] == 4) {
				vit4++;
			}
			if (tabuleiro[i][j] == 5) {
				vit5++;
			}
			if (tabuleiro[i][j] == 6) {
				vit6++;
			}
			if (tabuleiro[i][j] == 7) {
				vit7++;
			}
			if (tabuleiro[i][j] == 8) {
				vit8++;
			}
			if (tabuleiro[i][j] == 9) {
				vit9++;
			}
			if (tabuleiro[i][j] == 10) {
				vit10++;
			}
		}
	}
	
	if (vit1 == 0) {
		direcao(tabuleiro, armazenaPosit[0][2], armazenaPosit[0][0], armazenaPosit[0][1], armazenaPosit[0][3], -1, -2);
	}
	if (vit2 == 0) {
		direcao(tabuleiro, armazenaPosit[1][2], armazenaPosit[1][0], armazenaPosit[1][1], armazenaPosit[1][3], -1, -2);
	}
	if (vit3 == 0) {
		direcao(tabuleiro, armazenaPosit[2][2], armazenaPosit[2][0], armazenaPosit[2][1], armazenaPosit[2][3], -1, -2);
	}
	if (vit4 == 0) {
		direcao(tabuleiro, armazenaPosit[3][2], armazenaPosit[3][0], armazenaPosit[3][1], armazenaPosit[3][3], -1, -2);
	}
	if (vit5 == 0) {
		direcao(tabuleiro, armazenaPosit[4][2], armazenaPosit[4][0], armazenaPosit[4][1], armazenaPosit[4][3], -1, -2);
	}
	if (vit6 == 0) {
		direcao(tabuleiro, armazenaPosit[5][2], armazenaPosit[5][0], armazenaPosit[5][1], armazenaPosit[5][3], -1, -2);
	}
	if (vit7 == 0) {
		direcao(tabuleiro, armazenaPosit[6][2], armazenaPosit[6][0], armazenaPosit[6][1], armazenaPosit[6][3], -1, -2);
	}
	if (vit8 == 0) {
		direcao(tabuleiro, armazenaPosit[7][2], armazenaPosit[7][0], armazenaPosit[7][1], armazenaPosit[7][3], -1, -2);
	}
	if (vit9 == 0) {
		direcao(tabuleiro, armazenaPosit[8][2], armazenaPosit[8][0], armazenaPosit[8][1], armazenaPosit[8][3], -1, -2);
	}
	if (vit10 == 0) {
		direcao(tabuleiro, armazenaPosit[9][2], armazenaPosit[9][0], armazenaPosit[9][1], armazenaPosit[9][3], -1, -2);
	}
}

int testaVitoria(int tabuleiro[][16]) {
	int vit1=0, vit2=0, vit3=0, vit4=0, vit5=0, vit6=0, vit7=0, vit8=0, vit9=0, vit10=0;
	
	for (int i=0; i<14; i++) {
		for (int j=0; j<14; j++) {
			if (tabuleiro[i][j] == 1) {
				vit1++;
			}
			if (tabuleiro[i][j] == 2) {
				vit2++;
			}
			if (tabuleiro[i][j] == 3) {
				vit3++;
			}
			if (tabuleiro[i][j] == 4) {
				vit4++;
			}
			if (tabuleiro[i][j] == 5) {
				vit5++;
			}
			if (tabuleiro[i][j] == 6) {
				vit6++;
			}
			if (tabuleiro[i][j] == 7) {
				vit7++;
			}
			if (tabuleiro[i][j] == 8) {
				vit8++;
			}
			if (tabuleiro[i][j] == 9) {
				vit9++;
			}
			if (tabuleiro[i][j] == 10) {
				vit10++;
			}
		}
	}
	
	if (vit1 == 0 && vit2 == 0 && vit3 == 0 && vit4 == 0 && vit5 == 0 && vit6 == 0 && vit7 == 0 && vit8 == 0 && vit9 == 0 && vit10 == 0) {
		return 1;
	} else {
		return 0;
	}
}

int main () {
	char resp[1], condicao[1], novamente[3];
	int i, j, vitoria, armazenaPosit[10][4], armazenaPositPC[10][4];
	
	do {
		system("cls");
		system("color 3F");
		
		keybd_event ( VK_MENU, 0x36, 0, 0 ); 
	    keybd_event ( VK_RETURN, 0x1C, 0, 0 ); 
	    keybd_event ( VK_RETURN, 0x1C, KEYEVENTF_KEYUP, 0 ); 
	    keybd_event ( VK_MENU, 0x38, KEYEVENTF_KEYUP, 0 );
		
		zeraTabuleiro();
		zeraArmazenaPosicoes(armazenaPosit, armazenaPositPC);
		
		//GERA TABULEIRO DO PC
		
		jogadaRand(tabuleiroPC, 5, 1, 11, armazenaPositPC[0]);
		
		jogadaRand(tabuleiroPC, 4, 2, 11, armazenaPositPC[1]);
		jogadaRand(tabuleiroPC, 4, 3, 11, armazenaPositPC[2]);
		
		jogadaRand(tabuleiroPC, 3, 4, 11, armazenaPositPC[3]);
		jogadaRand(tabuleiroPC, 3, 5, 11, armazenaPositPC[4]);
		jogadaRand(tabuleiroPC, 3, 6, 11, armazenaPositPC[5]);
			
		jogadaRand(tabuleiroPC, 2, 7, 11, armazenaPositPC[6]);
		jogadaRand(tabuleiroPC, 2, 8, 11, armazenaPositPC[7]);
		jogadaRand(tabuleiroPC, 2, 9, 11, armazenaPositPC[8]);
		jogadaRand(tabuleiroPC, 2, 10, 11, armazenaPositPC[9]);
		
		iniciaJogo(condicao);
		if (condicao[0] == 'n') {
			return 0;
		}
		
		manualAleatorio(resp);
		
		if (resp[0] == 'm') {
			jogada(5, 1, 11, armazenaPosit[0]);
			
			jogada(4, 2, 11, armazenaPosit[1]);
			jogada(4, 3, 11, armazenaPosit[2]);
			
			jogada(3, 4, 11, armazenaPosit[3]);
			jogada(3, 5, 11, armazenaPosit[4]);
			jogada(3, 6, 11, armazenaPosit[5]);
			
			jogada(2, 7, 11, armazenaPosit[6]);
			jogada(2, 8, 11, armazenaPosit[7]);
			jogada(2, 9, 11, armazenaPosit[8]);
			jogada(2, 10, 11, armazenaPosit[9]);
			
		} else {
			jogadaRand(tabuleiro, 5, 1, 11, armazenaPosit[0]);
		
			jogadaRand(tabuleiro, 4, 2, 11, armazenaPosit[1]);
			jogadaRand(tabuleiro, 4, 3, 11, armazenaPosit[2]);
		
			jogadaRand(tabuleiro, 3, 4, 11, armazenaPosit[3]);
			jogadaRand(tabuleiro, 3, 5, 11, armazenaPosit[4]);
			jogadaRand(tabuleiro, 3, 6, 11, armazenaPosit[5]);
			
			jogadaRand(tabuleiro, 2, 7, 11, armazenaPosit[6]);
			jogadaRand(tabuleiro, 2, 8, 11, armazenaPosit[7]);
			jogadaRand(tabuleiro, 2, 9, 11, armazenaPosit[8]);
			jogadaRand(tabuleiro, 2, 10, 11, armazenaPosit[9]);
		}
			
		while (1) {
			system("cls");
			printaTabuleiro();
			printaTabuleiroPC();
			tiro (tabuleiro, tabuleiroPC, 1);
			
			testaNavios (tabuleiroPC, armazenaPositPC);
			
			if (testaVitoria(tabuleiroPC) == 1) {
				vitoria = 1;
				break;
			}
			tiro (tabuleiro, tabuleiroPC, 2);
			
			testaNavios (tabuleiro, armazenaPosit);
			
			if (testaVitoria(tabuleiro) == 1) {
				vitoria = 0;
				break;
			}
		}
		
		if (vitoria == 1) {
			system("color 2F");
			system("cls");
			printf("O PLAYER GANHOU!!\n");
		} else if (vitoria == 0) {
			system("color 4F");
			system("cls");
			printf("A CPU GANHOU!!\n");
		}
		
		printf("\n\nDeseja jogar novamente? (S/N)\nResposta: ");
		fflush(stdin);
		scanf("%[^\n]s", novamente);
		strlwr(novamente);
		
	} while (novamente[0] == 's');
	
	return 0;
}
