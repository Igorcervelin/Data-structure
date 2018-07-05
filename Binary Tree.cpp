#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int tamanho=0; //Variavel global para definir o tamanho da árvore (utilizado para impressão)

struct no{
	int valor;
	no *dir;
	no *esq;
	no *cima;
};

void inserirnull(no **atual){
	no *novo;
	int aux;
	
	printf("\nDigite um valor inteiro:");
	scanf("%d", &aux);

	novo = ((no*)malloc(sizeof(no)));
	novo->valor = aux;
	novo->cima = NULL;
	novo->dir = NULL;
	novo->esq = NULL;
	*atual = novo; // Define como atual
	
	tamanho++;
	
	printf("\nValor inserido!\n\n");
	system("pause");
}

int inserir(no **atual){
	no *novo;
	no *atualaux; //Auxiliar para armazenar o valor atual antes da árvore se mover para fazer as verificações e modificar o valor atual
	int aux;
	
	printf("\nDigite um valor inteiro:");
	scanf("%d", &aux);

	while((*atual)->cima != NULL){
		*atual = (*atual)->cima;
	}
	
	novo = ((no*)malloc(sizeof(no)));
	novo->valor = aux;

	while(*atual != NULL){	
		if((*atual)->valor > aux){	
			atualaux = *atual;
  			*atual = (*atual)->esq;
		} else if((*atual)->valor < aux){
			atualaux = *atual;
			*atual = (*atual)->dir;
		} else if((*atual)->valor == aux){
			printf("\nO valor ja existe na arvore!\n");
			system("pause");
			return 0;
		}
	}
		
	if(atualaux->valor > aux){
		atualaux->esq = novo;
	} else if(atualaux->valor < aux){
		atualaux->dir = novo;
	}
	novo->cima = atualaux;
	novo->esq = NULL;
	novo->dir = NULL;
	
	*atual = novo;

	tamanho++;
	
	printf("\nValor inserido!\n\n");
	system("pause");
}


void removeraiz(no **atual){
	no *aux;
	no *raiz;
	no *auxatual;
	int m1;
	int m2; //flags pra saber o metodo usado
	
	m1 = 0;
	m2 = 0;
	aux = *atual;
	raiz = *atual;
	auxatual = aux;
	
			
	while(raiz->cima != NULL){
		raiz = raiz->cima;
	}
	
	if(raiz->dir == NULL && raiz->esq == NULL){
		free(aux);
	} else {
		if(aux->dir != NULL){	
			auxatual = aux;
			aux = aux->dir;
			m1++;
			while(aux->esq != NULL){
				auxatual = aux;
				aux = aux->esq;
			}
		}else{
			auxatual = aux;
			aux = aux->esq;
			m2++;
			while(aux->dir != NULL){
				auxatual = aux;
				aux = aux->dir;
		}	
	}
		
		raiz->valor = aux->valor;
		if(aux->dir == NULL && aux->esq == NULL){			
			if(m1 > 0){
				aux->cima->esq = NULL;
			} else {
				aux->cima->dir = NULL;
			}
			*atual = raiz;
			free(aux);
		} else if(aux->dir != NULL){
			aux->dir->cima = auxatual;
			auxatual->esq = aux->dir;
			*atual = raiz;
			free(aux);
		} else if(aux->esq != NULL){
			aux->esq->cima = auxatual;
			auxatual->dir = aux->esq;
			*atual = raiz;
			free(aux);
		}

	}
	tamanho--;
}

void removefolha(no **atual){
	no *aux;
	aux = *atual;
	
	if(aux->valor > aux->cima->valor){
		aux->cima->dir = NULL;
	} else {
		aux->cima->esq = NULL;
	}
	
	*atual = aux->cima;
	free(aux);
	tamanho--;
}

void removergalho(no **atual){
	no *aux;
	no *raiz;
	
	raiz = *atual;
	
	while(raiz->cima != NULL){
		raiz = raiz->cima;
	}
	
	aux = *atual;
	
	if(aux->valor > raiz->valor){
		if(aux->dir == NULL){
			aux->cima->dir = aux->esq;
			aux->esq->cima = aux->cima;
		} else {
			aux->cima->dir = aux->dir;
			aux->dir->cima = aux->cima;
		}
	} else if(aux->valor < raiz->valor){
		if(aux->dir == NULL){
			aux->cima->esq = aux->esq;
			aux->esq->cima = aux->cima;	
		} else {
			aux->cima->esq = aux->dir;
			aux->dir->cima = aux->cima;
		}
	}
		
	*atual = aux->cima;
	free(aux);
	tamanho--;
}

void removerno(no **atual){
	no *aux;
	no *trocar;
	no *auxatual;
	int m1;
	int m2;
	int i = 0;
	
	m1 = 0;
	m2 = 0;
	
	trocar = *atual;
	aux = *atual;
	auxatual = *atual;	

	if(aux->dir != NULL){
		auxatual = aux;
		aux = aux->dir;
		i = 1;
		while(aux->esq != NULL){
			auxatual = aux;
			aux = aux->esq;
			i = 0;
		}
		m1++; //metodo 1 utilizado
	} else {
		auxatual = aux;
		aux = aux->esq;
		i = 1;
		while(aux->dir != NULL){
			auxatual = aux;
			aux = aux->dir;
			i = 0;
		}		
		m2++;//metodo 2 utilizado
	}

		if(m1 != 0){
			if(i == 1){
				if(aux->dir == NULL){ //verifica se o valor a ser trocado n tem filhos
					trocar->valor = aux->valor;
					aux->cima->dir = NULL;
				} else if(aux->dir != NULL){ //caso tiver filho pra direita
					trocar->valor = aux->valor;
					aux->cima->dir = aux->dir;
					aux->dir->cima = aux->cima;
				}
			}else{
				if(aux->dir == NULL){ //verifica se o valor a ser trocado n tem filhos
					trocar->valor = aux->valor;
					aux->cima->esq = NULL;
				} else if(aux->dir != NULL){ //caso tiver filho pra direita
					trocar->valor = aux->valor;
					aux->cima->esq = aux->dir;
					aux->dir->cima = aux->cima;
				}
			}
		}else if(m2 != 0){
			if(i == 1){
				if(aux->esq == NULL){ //verifica se o valor a ser trocado n tem filhos
					trocar->valor = aux->valor;
					aux->cima->esq = NULL;
				} else if(aux->esq != NULL){ //caso tiver filho pra esquerda
					trocar->valor = aux->valor;
					aux->cima->esq = aux->esq;
					aux->esq->cima = aux->cima;
				}
			}else {
				if(aux->esq == NULL){ //verifica se o valor a ser trocado n tem filhos
					trocar->valor = aux->valor;
					aux->cima->dir = NULL;
				} else if(aux->esq != NULL){ //caso tiver filho esquerda
					trocar->valor = aux->valor;
					aux->cima->dir = aux->esq;
					aux->esq->cima = aux->cima;
				}
			}
	}
		free(aux);
		tamanho--;
}

int main(){
	
	no *atual = NULL;
	no *raiz = NULL;
	int i = 0;
	int op;
	
	while(1){
		system("color 06");
		system("cls");
		printf("ARVORE BINARIA:\n");
		if(tamanho != 0){
			printf("\nValor atual: %d", atual->valor);
		} else {
			printf("\nValor atual: Arvore vazia!");	
		}
		printf("\n\n1 - Inserir");
		printf("\n2 - Remover");
		printf("\n3 - Subir");
		printf("\n4 - Esquerda");
		printf("\n5 - Direita");
		printf("\n6 - Sair");
		printf("\nOpcao:");
		scanf("%d", &op);
	
		
		if(op == 1){
			if(tamanho == 0){
				inserirnull(&atual);
			} else {
				inserir(&atual);
			}	
		}else if(op == 2){
			if(tamanho == 0){
				printf("\nArvore vazia!\n\n");
				system("pause");
			} else {
				if(atual->esq == NULL && atual->dir == NULL && atual->cima != NULL){
					removefolha(&atual);
				} else if(atual->esq != NULL && atual->dir == NULL && atual->cima != NULL){
					removergalho(&atual);	
				}else if(atual->esq == NULL && atual->dir != NULL && atual->cima != NULL){	
					removergalho(&atual);;		
				} else if(atual->esq != NULL && atual->dir != NULL && atual->cima != NULL){
					removerno(&atual);	
				} else if (atual->cima == NULL){
					removeraiz(&atual);
				}
				printf("\nValor removido!\n");
				system("pause");
			}
		}else if(op == 3){
			if(atual->cima != NULL && atual->valor != NULL){
				atual = atual->cima;
			} else {
				printf("\nVoce ja esta no topo da arvore!\n");
				system("pause");	
			}
		}else if(op == 4){	
			if(atual->esq != NULL){
				atual = atual->esq;
			} else {
				printf("\nNao existe nada a sua esquerda!\n");
				system("pause");	
			}
			
		}else if(op == 5){	
			if(atual->dir != NULL){			
				atual = atual->dir;
			}else{
				printf("\nNao existe nada a sua direita!\n");
				system("pause");	
			}
				
		}else if(op == 6){
			printf("\nFinalizando");
			for(i=0;i<3;i++){
			Sleep(600);
			printf(".");
			}
			break;
			
		}else{
			printf("\nOpcao invalida, tente novamente!\n");
			system("pause");
		}
	}
	
	return 0;
}
