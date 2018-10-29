#include <stdio.h>
#include <stdlib.h>

struct grafo{
	int id;
	char cor;
};

struct grafo g[8];
int i = 0;
int j = 0;
int liga = 0;
int matriz[8][8];
int ncores = 0;
int vet[8];
char cores[8];
int colorir(int local);
int aux;

int main(){

	int op;
	for(i=0;i<8;i++){
		g[i].id = i;
		g[i].cor = NULL;
		for(;;){
			printf("Digite -1 para passar para o proximo grafo\n");
			printf("Ligacoes do grafo de numero %i: ",i+1);
			scanf("%i",&liga);
			
			if(liga == -1){
				break;
			}else{
				matriz[i][liga] = 1;
				matriz[liga][i] = 1;
			}	
		}
		system("cls");
	}
	
	for(;;){
		system("cls");
		printf("Digite a opcao desejada\n");
		printf("1 - Colorir o grafo\n");
		printf("2 - Sair\n");
		scanf("%i", &op);
		
		if(op == 2){
			break;
		}else if(op == 1){
			aux = 0;
			while(aux <= 7){
				colorir(aux);
				aux++;
			}
			printf("\n%i cores foram utilizadas para colorir o grafo\n\n",ncores+1);
			system("pause");
		}else{
			printf("\n\nOpcao invalida!\n\n");
			system("pause");
		}
	}	
}

int colorir(int local){
	if(g[local].cor != NULL){
		return 0;
	}else{	
		i = 0;
		g[aux].cor = cores[0];
		liga = 0;
		for(j=0; j<8;j++){
			if(matriz[aux][j] == 1 && aux != j){
				vet[i] = j;
				i++;
			}
		}
		for(j=0;j<i;j++){
			if(g[aux].cor == g[(vet[j])].cor){
				liga++;
				g[aux].cor = cores[liga];
				
			}
		}
		if(liga > ncores){
			ncores = liga;
		}
	}
	return 0;
}


