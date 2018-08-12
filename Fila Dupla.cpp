#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

int main() {
	
	struct n{
		char nome1[20];
		int idade1 = 0;
	};
	
	struct v{
		char nome2[20];
		int idade2 = 0;
	};
	
	struct n novo[5];
	struct v velho[5];
	int e1=0;
	int e2=0;
	int s1=0;
	int s2=0;
	int op;
	int i;
	int j;
	int x=0;
	char nome[20];
	int idade;
	int vey=0;
	int v=0;
	int n=0;
	
	printf("FILA DUPLA");
	while(1){
		x:
		label:
		printf("\n\n1 - Inserir na fila\n");
		printf("2 - Retirar da fila\n");
		printf("3 - Imprimir\n");
		printf("4 - Sair\n");
		scanf("%d", &op);
		system("cls");
		
		if(op == 1){
			if(n<5 || v<5){
				printf("Digite o nome que deseja inserir: ");
				scanf("%s", &nome);
				printf("Digite a idade da pessoa: ");
				scanf("%d", &idade);
					if(idade >= 60){
						if(v==5){
							printf("Fila preferencial cheia!");
							goto label;
						} else if(v<5){
							if(e2>4){
							e2=0;
							}
							strcpy(velho[e2].nome2, nome);
							velho[e2].idade2 = idade;
							e2++;
							printf("\nInserido na fila dos idosos!\n\n");
							system("pause");
							system("cls");
							vey++;
							v++;
						}	
					}else if(idade < 60 && idade > 0){
						if(n==5){
							printf("Fila normal cheia!");
							goto label;
						}else if(n<5){
							if(e1>4){
							e1=0;
							}
							strcpy(novo[e1].nome1, nome);
							novo[e1].idade1 = idade;
							e1++;
							printf("\nInserido na fila normal!\n\n");
							system("pause");
							system("cls");
							n++;
					}
					else{
						printf("Idade invalida!\n");
						system("pause");
						goto x;
					}
				}
			}
		} else if(op == 2){
			if(n == 0 && v == 0){
				printf("Fila vazia!\n");
				system("pause");
				system("cls");
				goto label;
			} else if(n>0 || v>0 ){
				if(s1>4){
					s1=0;
				}
				if(vey == 0){
					novo[s1].idade1 = 0;
					n--;
					s1++;
					printf("\nFila normal andou!\n");
					system("pause");
					system("cls");
				} else if(vey != 0){
					velho[s2].idade2 = 0;
					v--;
					s2++;
					vey--;
					printf("\nFila preferencial andou!\n");
					system("pause");
					system("cls");
				}
			};
		} else if(op == 3){
			printf("\nFila dos jovens:\n");
			for(i=0;i<5;i++){
				if(novo[i].idade1 != 0){
				printf("Nome: %s -  ", novo[i].nome1);
				printf("Idade:%d\n", novo[i].idade1);
				}
			}
		
		printf("\nFila dos idosos:\n");
			for(j=0;j<5;j++){
				if(velho[j].idade2 != 0){
					printf("Nome: %s - ", velho[j].nome2);
					printf("Idade:%d\n", velho[j].idade2);
				}
			}	
		printf("\n\n");
		system("pause");
		system("cls");
		} else if(op == 4){
			printf("Finalizando");
			Sleep(600);
			printf(".");
			Sleep(600);
			printf(".");
			Sleep(600);
			printf(".");
			Sleep(600);
			break;
		} else {
			printf("Invalido!");
			goto label;
		}
		
	}
		

	return 0;
}
