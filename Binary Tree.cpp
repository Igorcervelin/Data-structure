#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int tamanho=0; //Variavel global para definir o tamanho da árvore (utilizado para impressão)
int desdir = 0;
int desesq = 0;

struct no{ //Struct de navegação
	int valor;
	no *dir;
	no *esq;
	no *cima;
};

void init(no **atual){ //Função para inicialização (Define tudo como NULL)
	*atual = NULL;
}


void inserirnull(no **atual){ //Inserir o primeiro valor (Raiz)
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

int inserir(no **atual){ // Insersão de valores
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


void removeraiz(no **atual){ //Função para remover a raiz
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
		if(m1 > 0){
			if(aux->dir == NULL){
				if(aux->cima->cima != NULL){
					aux->cima->esq = NULL;
				} else {
					aux->cima->dir = NULL;
				}
				aux = NULL;
			} else {
				aux->dir->cima = aux->cima;
				if(aux->cima->cima != NULL){
					aux->cima->esq = aux->dir;
				} else {
					aux->cima->dir = aux->dir;
				}	
				aux = NULL;
			}
			
		} else if (m2 > 0){
				if(aux->esq == NULL){
				if(aux->cima->cima != NULL){
					aux->cima->dir = NULL;
				} else {
					aux->cima->esq = NULL;
				}
				} else {
					aux->esq->cima = aux->cima;
					if(aux->cima->cima != NULL){
						aux->cima->dir = aux->esq;
					} else {
						aux->cima->esq = aux->esq;
					}
					aux = NULL;
				}
			}
			*atual = raiz;
			free(aux);
	}
	tamanho--;
}

void removefolha(no **atual){ //Remover folha (Quando não há nenhuma ligação na esquerda/direita)
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

void removergalho(no **atual){  //Remover galho (Quando só há uma ligação na esquerda ou na direita)
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

void removerno(no **atual){ // Remover nó (Quando há duas ligações, na esquerda e na direita)
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
				if(aux->dir == NULL){ //verifica se o valor a ser trocado não tem filhos
					trocar->valor = aux->valor;
					aux->cima->dir = NULL;
				} else if(aux->dir != NULL){ //caso tiver filho pra direita
					trocar->valor = aux->valor;
					aux->cima->dir = aux->dir;
					aux->dir->cima = aux->cima;
				}
			}else{
				if(aux->dir == NULL){ //verifica se o valor a ser trocado não tem filhos
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
				if(aux->esq == NULL){ //verifica se o valor a ser trocado não tem filhos
					trocar->valor = aux->valor;
					aux->cima->esq = NULL;
				} else if(aux->esq != NULL){ //caso tiver filho pra esquerda
					trocar->valor = aux->valor;
					aux->cima->esq = aux->esq;
					aux->esq->cima = aux->cima;
				}
			}else {
				if(aux->esq == NULL){ //verifica se o valor a ser trocado não tem filhos
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

int altura(no **atual){ //Verificar altura da árvore (Raiz = 0)
	
   if(*atual == NULL){
   	 return -1;
   }else{
   		
   		int alturaesquerda = altura(&(*atual)->esq);
   		int alturadireita = altura(&(*atual)->dir);
   		if(alturaesquerda >= alturadireita){
   		return alturaesquerda +1;
		}else {
		return alturadireita +1;
		}
   }
}

void preordem(no **atual){ // Imprimir em pré-ordem
	

	if(*atual == NULL){
		printf("\nA arvore esta vazia!\n\n");		
	} else{
	
		if(*atual != NULL){
			printf("%d ", (*atual)->valor);	
		}
		
		if((*atual)->esq != NULL){
			preordem(&(*atual)->esq);
		}
		
		if((*atual)->dir != NULL){
			preordem(&(*atual)->dir);	
		}			
	}
}

void emordem(no **atual){ // Imprimir em ordem
	
	if(*atual == NULL){
		printf("\nA arvore esta vazia!\n\n");
	} else {
		
		if((*atual)->esq != NULL){
			emordem(&(*atual)->esq);
		}
		
		if(*atual != NULL){
			printf("%d ", (*atual)->valor);	
		}
		
		if((*atual)->dir != NULL){
        	emordem(&(*atual)->dir);
		}
	}
}

void posordem(no **atual){ // Imprimir em pós-ordem
	
	if(*atual == NULL){
		printf("\nA arvore esta vazia!\n\n");
	} else {
		if((*atual)->esq != NULL){
			posordem(&(*atual)->esq);
		}
		
		if((*atual)->dir != NULL){
        	posordem(&(*atual)->dir);
		}
		
		if(*atual != NULL){
			printf("%d ", (*atual)->valor);	
		}
		
	}
}

int desbal(no **atual){
	
	no *aux;
	
	aux = *atual;
	
	if(aux->dir != NULL){
		desdir = altura(&aux->dir);
	}
	
	if(aux->esq != NULL){
		desesq = altura(&aux->esq);
	}
	
	return(desesq - desdir);
}

// Função main
int main(){ 
	
	no *atual = NULL;
	no *raiz = NULL;
	int i = 0;
	int op;
	
	init(&atual);
	
//Menu principal	
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
		printf("\n6 - Altura");
		printf("\n7 - Pre-ordem");
		printf("\n8 - Em ordem");
		printf("\n9 - Pos-ordem");
		printf("\n10 - Desbalanceamento");
		printf("\n0 - Sair");
		printf("\nOpcao:");
		scanf("%d", &op);
		
		if(op == 1){ //Inserir
			if(tamanho == 0){
				inserirnull(&atual);
			} else {
				inserir(&atual);
			}	
			
		}else if(op == 2){ //Remover
			if(tamanho == 0){
				printf("\nArvore vazia!\n\n");
				system("pause");
			} else {
				if(atual->esq == NULL && atual->dir == NULL && atual->cima != NULL){
					removefolha(&atual);
				} else if(atual->esq != NULL && atual->dir == NULL && atual->cima != NULL){
					removergalho(&atual);	
				}else if(atual->esq == NULL && atual->dir != NULL && atual->cima != NULL){	
					removergalho(&atual);		
				} else if(atual->esq != NULL && atual->dir != NULL && atual->cima != NULL){
					removerno(&atual);	
				} else if (atual->cima == NULL){
					removeraiz(&atual);
				}
				printf("\nValor removido!\n");
				system("pause");
			}
			
		}else if(op == 3){ //Subir
			if(atual->cima != NULL && atual->valor != NULL){
				atual = atual->cima;
			} else {
				printf("\nVoce ja esta no topo da arvore!\n");
				system("pause");	
			}
			
		}else if(op == 4){	//Esquerda
			if(atual->esq != NULL){
				atual = atual->esq;
			} else {
				printf("\nNao existe nada a sua esquerda!\n");
				system("pause");	
			}
			
		}else if(op == 5){	//Direita	
			if(atual->dir != NULL && atual->valor != NULL){
				atual = atual->dir;	
			} else 
			if(atual->dir == NULL || atual->valor == NULL) {
				printf("\nNao existe nada a sua direita!\n");
				system("pause");
			}
			
		}else if(op == 6){ // Altura
			if(atual == NULL){
				printf("\nArvore vazia!\n\n");
				system("pause");
			} else {
			while(atual->cima != NULL){ //sobe até a raiz
				atual = atual->cima;
			}
			printf("\nAltura: %i\n\n", altura(&atual));
			system("pause");
			}
		}else if(op == 7){	 //Pré-ordem

			while(atual->cima != NULL){ //sobe até a raiz
				atual = atual->cima;
			}
			printf("\n");
			preordem(&atual);
			printf("\n\n");	
			system("pause");
			
		}else if(op == 8){	 // Em ordem
			while(atual->cima != NULL){ //sobe até a raiz
				atual = atual->cima;
			}
			printf("\n");
			emordem(&atual);
			printf("\n\n");	
			system("pause");

		}else if(op == 9){ // Pós-ordem
			while(atual->cima != NULL){ //sobe até a raiz
				atual = atual->cima;
			}
			printf("\n");
			posordem(&atual);
			printf("\n\n");	
			system("pause");
		
		}else if(op == 10){
			if(atual == NULL){
				printf("\nArvore vazia!\n\n");
				system("pause");
			} else {
				while(atual->cima != NULL){ //sobe até a raiz
					atual = atual->cima;
				}
				printf("\n\nO desbalanceamento da arvore e %i \n\n", desbal(&atual));
				system("pause");
				}
						
		}else if(op == 0){ // Sair
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
