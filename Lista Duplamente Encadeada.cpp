#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int tamanho=0; //Variavel global para definir o tamanho da lista (utilizado para impressão)


typedef struct lista{
	int valor;
	lista *prox;
	lista *ant;
}lst;

void inserirnull(lst **atual){
	lst *novo;
	int aux;
	printf("\nDigite um valor inteiro:");
	scanf("%d", &aux);
	
	novo = ((lst*)malloc(sizeof(lst)));
	novo->valor=aux;
	novo->prox=novo;
	novo->ant=novo;
	*atual=novo;
	tamanho++;
}

void inserir(lst **atual){
	lst *novo;
	int aux;
	
//	novo = new lst;
	novo = (lst*) malloc(sizeof(lst));
	printf("\nDigite um valor inteiro:");
	scanf("%d", &aux);
	
	novo->valor = aux; // Valor recebe o numero armazenado no aux
	novo->ant = *atual; // Anterior do numero novo vai ser o atual
	novo->prox = (*atual)->prox; //proximo do novo vai ser o proximo do atual (será inserido no meio)
	(*atual)->prox = novo; // proximo do atual será o novo valor
	novo->prox->ant = novo; // amarração final
	*atual = novo;
	tamanho++;
}

void remover(lst **atual){
	lst *aux;
	
	aux = *atual;
	aux->prox->ant = aux->ant; // amarra o anterior ao proximo
	aux->ant->prox = aux->prox; // amarra o proximo ao anterior
	if(aux->prox != aux){ // Condição para saber se for o ultimo valor, definir como null
		*atual = aux->ant; 	//se não for o ultimo valor, atual rece
	} else{
		*atual = NULL;
	}
	free(aux);
	printf("\nValor deletado\n");
	tamanho--;
}

void imprimir(lst **atual){
	lst *aux;
	int i;
	
	if(tamanho == 0){
		printf("Lista Vazia!\n\n");
	} else {
		aux = *atual;
			for(i=0;i<tamanho;i++){
				printf("\n%d", aux->valor);
				aux = aux->prox;
		}
	}
}

int main(){
	
	lst *atual = NULL; //definindo o numero atual como nulo
	int i = 0;
	int op;
	
	while(1){
		system("color 06");
		x:
		system("cls");
		printf("LISTA DUPLAMENTE ENCADEADA:\n");
		if(atual != NULL){
			printf("\nValor Atual: %d", atual->valor);
		}
		printf("\n\n1 - Inserir");
		printf("\n2 - Remover");
		printf("\n3 - Listar");
		printf("\n4 - Proximo");
		printf("\n5 - Anterior");
		printf("\n6 - Sair");
		printf("\nOpcao:");
		scanf("%d", &op);
	
		
		if(op == 1){
			if(atual == NULL){
				inserirnull(&atual);
			}else{
				inserir(&atual);
			}
			printf("\nValor inserido!\n\n");
			system("pause");
			
		}else if(op == 2){
			if(atual == NULL){
				printf("\nLista vazia!\n\n");
				system("pause");
				goto x;
			} else	
				remover(&atual);
				system("pause");
		}else if(op == 3){
			printf("\nLista: ");
			imprimir(&atual);
			printf("\n\n");
			system("pause");
		}else if(op == 4){	
			if(atual != NULL){
				atual = atual->prox;
			}
		}else if(op == 5){	
			if(atual != NULL){
				atual = atual->ant;
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
			goto x;
		}
	}
	
	return 0;
}
