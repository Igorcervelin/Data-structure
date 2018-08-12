#include<stdlib.h>
#include<stdio.h>
#include<windows.h>

int main(){
	
	int vet1[5];
	int vet2[5];
	int i;
	int j;
	int aux;
	
	for(i=0;i<5;i++){
		printf("Digite um numero inteiro: ");
		scanf("%d", &vet1[i]);
	}
	
	for(i=0;i<5;i++){
		vet2[i] = vet1[i];
	}
	
	for(i=0;i<5;i++){
		for(j=0;j<4;j++){
			if(vet1[j]>vet1[j+1]){
				aux = vet1[j];
				vet1[j] = vet1[j+1];
				vet1[j+1] = aux;		
			}
		}
	}
	
	FILE *f = fopen("Bolha.txt", "w");
	fprintf(f,"\nVetor anterior: ");
	for(i=0;i<5;i++){
		fprintf(f,"%d ", vet2[i]);
	}
	
	fprintf(f,"\n\nVetor organizado: ");
	for(j=0;j<5;j++){
		fprintf(f,"%d ", vet1[j]);
	}
	fclose(f);
	
	return 0;
}
