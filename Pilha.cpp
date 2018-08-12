#include <stdio.h>
#include <stdlib.h>

int main() {
	int op;
	int pilha[5];
	int ponto = 0;
	
	while(1){
		X: 		
		printf("\nDigite 1 para inserir na pilha");
		printf("\nDigite 2 para retirar da pilha");
		printf("\nDigite 3 para sair\n");
		scanf("%d", &op);
		system("cls");
		
		if(op == 1){
			if(ponto>4){
				printf("\nVetor cheio!\n");
				goto X;
			} else{
				printf("\nDigite o numero a ser inserido:");
				scanf("%d", &pilha[ponto]);
				ponto++;
			}
		}else if(op == 2){
			if(ponto == 0){
				printf("\nO ponto esta zerado!\n");
			} else{
			pilha[ponto] = 0;
			ponto--;
			}
		}else if(op == 3){
			printf("\nEncerrado!\n\n");
			break;
		}
	
		int i;
		
		for(i=(ponto-1);i>=0;i--){
			printf("\n%d", pilha[i]);
		}
	}

	return 0;

}

