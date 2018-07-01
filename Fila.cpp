#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variáveis globais
	int fila[5];
	int e=0 ;
	int s=0 ;
	int i;
	
void Mostrafila(){
	printf("\nEntrada %d\n", e);
	printf("Saida %d\n\n", s);
	printf("Fila: ");
	
	for(i=0;i<5;i++){
		if(fila[i]==0){
			printf("x ");
		}else if(fila[i]!=0){
			printf("%d ", fila[i]);
		}
	}
}

int main() {	

	int op;
	int x=0; //aux
	
	for(i=0;i<5;i++){
		fila[i] = 0;
	}
	
	while(1){	
		Mostrafila();
		printf("\n\n1 - Inserir na fila\n");
		printf("2 - Retirar da fila\n");
		printf("3 - Sair\n");
		scanf("%d", &op);
		system("cls");
		
		if(op == 1){
			if(x<5){
				printf("Digite o numero que deseja inserir: ");
					if(e>4){
						e=0;
					}
				scanf("%d", &fila[e]);
				e++;
				x++;
				}else if(x=5){
				printf("Fila cheia!\n");
				system("pause");
			}
			
		} else if(op == 2){
			if(x == 0){
				printf("Fila vazia!\n");
				system("Pause");
			} else if(x>0){
				if(s>4){
					s=0;
				}
			fila[s] = 0;
			x--;
			s++;	
			}
			
		} else if(op == 3){
			break;
			
		} else {
			printf("Invalido!\n");
			system("Pause");
		}

	
	}
	return 0;
}
