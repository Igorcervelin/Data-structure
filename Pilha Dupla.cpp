#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	
	struct p{
		char pile1[20];
		char pile2[20];
	};
	
	struct p piles[5];
	int op;
	int op2;
	int p1 = 0;
	int p2 = 0;
	char food[20];
	int op3; 
	int i;
	int j;

	while(1){
		printf("\n\nType 1 for insert a food on the pile");
		printf("\nType 2 for pop the last food of the pile");
		printf("\nType 3 for exit\n");
		scanf("%d", &op);
		system("cls");
		
		if(op == 1){
			printf("\nThis food have peanut? (1 for yes/2 for no)");
			scanf("%d", &op3);
				if(op3 == 1){
					printf("\nType the food to be insert on pile:");
					scanf("%s", &piles[p1].pile1);
					fflush(stdin);
					p1++;
				} else if(op3 == 2){
					printf("\nType the food to be insert on pile:");
					scanf("%s", &piles[p2].pile2);
					fflush(stdin);
					p2++;
				} else if(op3 > 2 && op3 <1) {
					printf("Invalid option!\n\n");
					break;
				}		
		}else if(op == 2){
			printf("De qual pilha deseja remover?\n");
			printf("1 - Peanut\n");
			printf("2 - No peanut\n");
			scanf("%d", &op2);
				if(op2 == 1){
					p1--;
				} else if(op2 == 2){
					p2--;
				} else{
					printf("Invalid option!");
					break;
				}
				
		}else if(op == 3){
			printf("\nProgram Finished!\n\n");
			break;
		}

		printf("\nPilha com amendoim:\n");
		for(i=(p1-1);i>=0;i--){
			printf("\n%s", piles[i].pile1);
		}
		
		printf("\nPilha sem amendoim:\n");	
		for(i=(p2-1);i>=0;i--){
			printf("\n%s", piles[i].pile2);
		}
	}

	return 0;
}
