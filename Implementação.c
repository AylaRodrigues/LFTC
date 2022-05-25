//Ayla Rodrigues, Kelly Ohana e Marina Bulhosa
//Implementação - Verificar Gramática

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

int flagT1=0;
int flagT2=0;
int flagT3=0;
int linhas=0;

void imprimir(){
  printf("Gramática:\nTipo 0\n");
		if(flagT1==linhas){
			printf("Tipo 1\n");
		}
		if(flagT2==linhas){
			printf("Tipo 2\n");
		}
		if(flagT3==linhas){
			printf("Tipo 3\n");
		}
		printf("\n\n");
}

void VerificarGramatica(char *esq, char *dir){

int tamesq = strlen(esq);
int tamdir = strlen(dir);
	  
		if(tamesq <= tamdir && dir[0]==64 ){
			flagT1++;
		}
		else if(dir[0]==64){
			char *letra;
			strcpy(letra,esq);
			for(int i; i<=tamdir; i++){
				if(strcmp(&dir[tamdir],letra)){
					flagT1++;
				}
			}
		}
		
		if(tamesq == 1){
      if(esq[0]>64 && esq[0]<91)
      {
        flagT2++;// tipo 2
        if(tamdir == 1){
          if((dir[0]>96 && dir[0]<123) || dir[0]==64){
            flagT3++;
          }
        }
        else if(tamdir == 2){
          if(dir[0]>96 && dir[0]<123){
            if(dir[1]>64 && dir[1]<91){
              flagT3++;
            }
          }
        }
      }
    }   
}

void Dividir(char *ler){
	char *esq;
	char *dir;
	
	esq = strtok(ler,"-");
	dir = strtok('\0',">");
  
	VerificarGramatica(esq, dir);

}

void LerArq(char nomeArq[100]){
	FILE *arq;
	arq = fopen(nomeArq, "r");
	
	char *ler;

	if(arq == NULL){
		printf("Problemas na leitura do arquivo\n");
	}
	else {
		while(fscanf(arq, "%[^\n]s", ler) > 0){ 
			linhas++;
			fgetc(arq);
			Dividir(ler);
		}
	}
	imprimir();
	fclose(arq);
  
}

void showMenu(){

	int opcao=0;
  
	char nomeArq[100];

	while(opcao!=2)
	{
		printf("O que deseja fazer?\n 1.Verificar gramática\n 2.Sair\n");
		scanf("%d", &opcao);
		if (opcao==1){
			printf("Qual o nome do arquivo que deseja ler?\n");
			scanf("%s", nomeArq);
			printf("\n\n");
			LerArq(nomeArq);
			//imprimir(flagT1, flagT2, flagT3, linhas);
		}
		if(opcao==2){
			printf("O usuário saiu!\n");
		}
	}
}

int main() {
	setlocale(LC_ALL, "");

	showMenu();
	
	return 0;
}