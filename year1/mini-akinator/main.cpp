#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct node{
	char info[100];
	struct node *esq;
	struct node *dir;
}node;

node *getnode(){
	return (node*) malloc (sizeof(node));
}

node *insert(char inf[]){
	node* q;
	
	q = getnode();
	if(q != NULL){
		q->dir = NULL;
		q->esq = NULL;
		strcpy(q->info, inf);	
		return q;		
	}
}

node *roda_arvore(node *prev){
	int tam = strlen(prev->info);
	
	if(prev->info[tam-1] != '?'){	
		char opcao[3];
				
		do{		
			printf("\nO objeto que voce procurava eh %s?\nResposta: ", prev->info);
			fflush(stdin);
			scanf("%[^\n]s", opcao);
			strlwr(opcao);			
		}while(opcao[0] != 's' && opcao[0] != 'n');
				
		if(opcao[0] == 's'){		
			printf("\nGANHEI DE VOCE!\n");	
		}else{	
			char l[100], quest[100];
					
			printf("\nEntao o que eh?\nResposta: ");
			fflush(stdin);
			scanf("%[^\n]s", l);
					
			printf("\nInforme uma pergunta que sua resposta 'sim' seja %s e 'nao' seja %s: ", l, prev->info);
			fflush(stdin);
			scanf("%[^\n]s", quest);
					
			int ton = strlen(quest);
					
			if(quest[ton-1] != '?'){	
				quest[ton] = '?';
				quest[ton+1] = '\0';
			}
			
			quest[0] = toupper(quest[0]);
					
			node *q = insert(quest);
			node *resp = insert(l);
			node *aux = prev;
			
			q->dir = aux;
			q->esq = resp;
		
			printf("\nDessa vez eu fui derrotado... Mas na proxima quem ganha sou eu!\n");
			
			return q;
		}
	}else{
		char op[3];
			
		do{	
			printf("\n%s (S/N)\nResposta: ", prev->info);
			fflush(stdin);
			scanf("%[^\n]s", op);
			strlwr(op);	
			if(op[0] != 'n' && op[0] != 's'){
				printf("\nVoce digitou algo invalido!\n");
			}
		}while(op[0] != 'n' && op[0] != 's');
		
		if(op[0] == 's'){
			prev->esq = roda_arvore(prev->esq);
		}else{
			prev->dir = roda_arvore(prev->dir);
		}
	}
}

int conta_nos(node *r){
	if(r == NULL){
		return 0;
	}else{
		return 1 + conta_nos(r->esq) + conta_nos(r->dir);
	}
}

void escreve_arq(FILE *arq, node *r){
	node *aux = r;
	
	if(aux != NULL){
		if(aux->esq != NULL){
			fprintf(arq, "\t\"%s\" -> \"%s\" [label=\"sim\"];\n", aux->info, aux->esq->info);
		}
		escreve_arq(arq, aux->esq);
		
		if(aux->dir != NULL){
			fprintf(arq, "\t\"%s\"->\"%s\" [label=\"nao\"];\n", aux->info, aux->dir->info);
		}
		escreve_arq(arq, aux->dir);
	}
}

void salva_arq(FILE *arq, node *r){
	arq = fopen("dat.dot", "w");
	
	fprintf(arq, "digraph arvoro {\n");
	
	escreve_arq(arq, r);
	
	fprintf(arq, "}");
	
	fclose(arq);
}

int tem_arq(FILE *arq){
	arq = fopen("dat.dot", "r");
	
	char c = getc(arq);
	
	if(c == 'd'){
		return 1;
	}else{
		return 0;
	}
	
	fclose(arq);
}

void jump_line(FILE *arq){
	char c[500];
	
	c[0]='c';
	for(int i=1; c[i-1]!='\n'; i++){
		c[i] = getc(arq);	
	}
}

void jump_char(FILE *arq){
	char c = getc(arq);
}

void printa(node *r){
	if(r != NULL) {
		printf("%s\n", r->info);
		printa(r->esq);
		printa(r->dir);
	}
}

//procura a string na ávore
node *caca_arvore(node *r, char text[]){
	if(r != NULL) {
		if(strcmp(r->info, text) == 0){
			return r;
		}
		caca_arvore(r->esq, text);
		caca_arvore(r->dir, text);
	}
}

//função que "passa os dados do arquivo para a raiz da árvore"
void pega_dat(FILE *arq, node *r){
	jump_char(arq);
	jump_char(arq);
	
	char text[100];
	
	int i=-1;
	do{
		i++;
		text[i] = getc(arq);
	}while(text[i] != '"');
	text[i] = '\0';
	
	for(int j=0; j<5; j++){
		jump_char(arq);
	}
	
	node *aux = NULL;
	aux = insert(text);
	
	char text2[100];
	i=-1;
	do{
		i++;
		text2[i] = getc(arq);
	}while(text2[i] != '"');
	text2[i] = '\0';
	
	node *aux2 = NULL;
	aux2 =  insert(text2);
	
	for(int j=0; j<9; j++){
		jump_char(arq);
	}
	
	char c = getc(arq);
	
	do{
		if(r == NULL){
			r = aux;
			if(c == 's'){
				r->esq = aux2;
				for(int j=0; j<6; j++){
					jump_char(arq);
				}
			}else{
				r->dir = aux2;
				for(int j=0; j<6; j++){
					jump_char(arq);
				}
			}
		}else{
			node *q = caca_arvore(r, aux->info);
			if(c == 's'){
				q->esq = aux2;
				for(int j=0; j<6; j++){
					jump_char(arq);
				}
			}else{
				q->dir = aux2;
				for(int j=0; j<6; j++){
					jump_char(arq);
				}
			}
		}
		pega_dat(arq, r);
	}while(getc(arq) != '}');
}

void carrega_arq(FILE *arq, node *r){
	arq = fopen("dat.dot", "r");
	
	jump_line(arq);
	pega_dat(arq, r);
	
	fclose(arq);
}

int main(){
	char op[3];
	
	printf(">> Bem-Vindo ao Akinator! <<\n");
	
	do{
		printf("\nDeseja iniciar o jogo? (S/N)\nResposta: ");
		fflush(stdin);
		scanf("%[^\n]s", op);
		strlwr(op);
		if(op[0] != 's' && op[0] != 'n'){
			printf("\nVoce digitou algo invalido!\n");
		}
	}while(op[0] != 's' && op[0] != 'n');
	
	if(op[0] == 'n'){
		return 0;
	}
	
	node *r;
	r = NULL;
	
	FILE *arq;
	
	char select[3];
	
	//função que carrega não funciona e faz o programa crashar
	/*if(tem_arq(arq)){
		carrega_arq(arq, r);
	}*/
	
	while(1){
		int tam;
		
		if(r != NULL){
			tam = strlen(r->info);
		}
		
		if(r == NULL){
			char inf[100];
			
			printf("\nNunca nem vi as informacao!\n");
			
			printf("Informe um objeto: ");
			fflush(stdin);
			scanf("%[^\n]s", inf);
			
			r = insert(inf);
		}else if(r->info[tam-1] != '?'){
				char opcao[3];
				
				do{
					printf("O objeto que voce procurava eh %s?\nResposta: ", r->info);
					fflush(stdin);
					scanf("%[^\n]s", opcao);
					strlwr(opcao);
					if(opcao[0] != 's' && opcao[0] != 'n'){
						printf("\nVoce digitou algo invalido!\n");
					}
				}while(opcao[0] != 's' && opcao[0] != 'n');
				
				if(opcao[0] == 's'){
					printf("\nGANHEI DE VOCE!\n");
				}else{
					char l[100], quest[100];
					
					printf("\nEntao o que eh?\nResposta: ");
					fflush(stdin);
					scanf("%[^\n]s", l);
					
					printf("\nInforme uma pergunta que sua resposta 'sim' seja %s e 'nao' seja %s: ", l, r->info);
					fflush(stdin);
					scanf("%[^\n]s", quest);
					
					int ton = strlen(quest);
					
					if(quest[ton-1] != '?'){
						quest[ton] = '?';
						quest[ton+1] = '\0';
					}
					
					quest[0] = toupper(quest[0]);
					
					node *q = insert(quest);
					node *resp = insert(l);
					node *aux = r;
					
					r = q;
					r->dir = aux;
					r->esq = resp;
					
					printf("\nDessa vez eu fui derrotado... Mas na proxima quem ganha sou eu!\n");
				}
			}else{
				r = roda_arvore(r);
			}
		
		do{
			printf("\nDeseja rodar o programa novamente? (S/N)\nResposta: ");
			fflush(stdin);
			scanf("%[^\n]s", select);
			strlwr(select);
			if(select[0] != 'n' && select[0] != 's'){
				printf("\nVoce digitou algo invalido!\n");
			}
		}while(select[0] != 'n' && select[0] != 's');
		
		if(select[0] == 'n'){
			break;
		}
		system("cls");
	}

	salva_arq(arq, r);
	
	return 0;
}
