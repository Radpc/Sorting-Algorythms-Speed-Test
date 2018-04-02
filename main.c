//Bibliotecas comuns
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Bibliotecas próprias


#include "bibliotecas/organizers.h"
#include "bibliotecas/arrays.h"
#include "bibliotecas/utilities.h"



//Define's
#define SIZE 100000
#define TIMES 30

void main(){
	
	//Final
	int * tempo_bolha = malloc(sizeof(int) * TIMES);
	int * tempo_insDireta = malloc(sizeof(int) * TIMES);;
	int * tempo_quicksort = malloc(sizeof(int) * TIMES);;
	int turn;
	
	//Variaveis de tempo
	double time_spent;
	clock_t end;
	clock_t begin;
	int converted;
	
	//Declarações de variáveis
	int i;
	char answer;
	int continuation;
	int * array = malloc(sizeof(int) * SIZE);
	int * arrayCopy = malloc(sizeof(int) * SIZE); 
	
	//Medias
	int mBolha = 0;
	int mInsDireta = 0;
	int mQuicksort = 0;
	
	//User friendly?
	continuation = 1;
		
	//For loop para as vezes (turn) que os 3 algoritmos irao rodar no mesmo vetor
	for(turn=0;turn<TIMES;turn++){
		
		//Preparando o srand()
		srand(time(NULL));
		
		//Pergunta de User Interface
		if(continuation){	
			printf("\nA seguir, o vetor numero[%d] com %d bytes. Ele sera preenchido com valores entre 0 e %d. Pressione enter.\n",turn,SIZE*8,RAND_MAX);
			pressButton();		
		}
		
		//Preencher o vetor
		
		for(i=0;i<SIZE;i++){
			
			array[i] = rand();
		}
		printf("\n[Novo vetor] -- %d\n",turn+1);
	
		//Verificação dos primeiros elementos
		if(continuation){
			printf("Deseja verificar os 10 primeiros numeros? (y/n): ");
			scanf(" %c",&answer);
			if((answer == 'y') || (answer == 'Y')){
				showArray(array,10);
				printf("\n\nPressione enter.");
				pressButton();
			}else{
				
				printf("\nDeseja pular os textos? (y/n): ");
				scanf(" %c",&answer);
				if((answer == 'y') || (answer == 'Y')){
						continuation = 0;					
				}
				
			}
		}
	
		///Ordenação Bolha---------------------------------------------------------------------------------------------------------
		//Copiar o array 
		copyArray(array,arrayCopy,SIZE);
		printf("Rodando Bolha..............................");
		//Checar o tempo
		begin = clock();
		
		//Rodar o código
		bolha(arrayCopy,SIZE);
		
		//Checar o tempo /2
		end = clock();
		time_spent = difftime(end,begin) ;
		converted = time_spent; //Transforms double variable into MiliSeconds INTEGERS
		printf("%d Milisegundos..\n",converted);
		
		
		//Pergunta para o usuario sobre checar o resultado
		if(continuation){
			printf("Quer ver os primeiros numeros da organizacao?(y/n): ");
			scanf(" %c",&answer);
			if((answer == 'y') || (answer == 'Y')){
				showArray(arrayCopy,10);
				
				printf("\n\nPressione enter.");
				pressButton();
			}
			
		}
		
		//Enviar os milisegundos para o vetor de tempo
		tempo_bolha[turn] = converted; 
		
		
		
		///Ordenação Inserção Direta---------------------------------------------------------------------------------------------------------
		//Copiar o array
		copyArray(array,arrayCopy,SIZE);
		printf("Rodando InsDireta..........................");
		//Checar o tempo
		begin = clock();
		
		//Rodar o código
		insDireta(arrayCopy,SIZE);
		
		//Checar o tempo /2
		end = clock();
		time_spent = difftime(end,begin) ;
		converted = time_spent; //Transforms double variable into MiliSeconds INTEGERS
		printf("%d Milisegundos..\n",converted);
		
		//Pergunta para o usuario sobre checar o resultado
		if(continuation){
			printf("Quer ver os primeiros numeros da organizacao?(y/n): ");
			scanf(" %c",&answer);
			if((answer == 'y') || (answer == 'Y')){
				showArray(arrayCopy,10);
				
				printf("\n\nPressione enter.");
				pressButton();
			}
			
		}

		//Enviar os milisegundos para o vetor de tempo
		tempo_insDireta[turn] = converted;
		
		///Ordenação QuickSort---------------------------------------------------------------------------------------------------------
		//Copiar o array 
		copyArray(array,arrayCopy,SIZE);
		printf("Rodando Quicksort..........................");
		//Checar o tempo
		begin = clock();
		
		//Rodar o código
		quickSort(arrayCopy,0,SIZE);
		
		//Checar o tempo /2
		end = clock();
		time_spent = difftime(end,begin) ;
		converted = time_spent; //Transforms double variable into MiliSeconds INTEGERS
		printf("%d Milisegundos..\n",converted);
		
		//Pergunta para o usuario sobre checar o resultado
		if(continuation){
			printf("Quer ver os primeiros numeros da organizacao?(y/n): ");
			scanf(" %c",&answer);
			if((answer == 'y') || (answer == 'Y')){
				showArray(arrayCopy,10);
				
				printf("\n\nPressione enter.");
				pressButton();
			}
			
		}	

		//Enviar os milisegundos para o vetor de tempo
		tempo_quicksort[turn] = converted;		
	
	} /*Fim de todos os testes, Aqui os vetores devem estar completos com os milisegundos que cada caso tomou para ordenar. 
	Os tempo_bolha[j] tempo_insDireta[j] e tempo_quicksort[j] tiveram o mesmo vetor como material, indo de 0 até #Define TIMES */	
	
	

	//Abertura do arquivo para escrita do resultado
	FILE *arq;
	arq = fopen("Resultado.txt","w"); //MUDA PRA INI DPS MATHEUS
	
	//Calcula a média do resultado
	for(i=0;i<TIMES;i++){
		mBolha = mBolha + tempo_bolha[i];
		mInsDireta = mInsDireta + tempo_insDireta[i];
		mQuicksort = mQuicksort + tempo_quicksort[i];
	}
	
	//Opçoes de resultado
	
	//Imprime no arquivo a média dos tempos das ordenações
		fprintf(arq,"Tempo medio do bolha - [%d]miliSeg | Tempo medio do insercaoDireta - [%d]miliSeg  | Tempo medio do quicksort - [%d]miliSeg\n\n",mBolha/TIMES,mInsDireta/TIMES,mQuicksort/TIMES);	
	
	//Imprime no terminal a média dos tempos das ordenações
		printf("\nMedia do bolha - [%d]mSeg | Media da insercaodireta - [%d]mSeg  | Media do quicksort - [%d]mSeg",mBolha/TIMES,mInsDireta/TIMES,mQuicksort/TIMES);	
	
	//Imprime no arquivo uma lista com os resultados brutos
		for(i=0;i<TIMES;i++){
			fprintf(arq,"[%d] - Bolha(%d) | InsercaoDireta(%d) | Quicksort (%d)\n",i+1,tempo_bolha[i],tempo_insDireta[i],tempo_quicksort[i]);
		}
	
	
	//Caso tenha aberto o arquivo, feche-o
	fclose(arq); 

	
	pressButton();
	free(array);
	free(arrayCopy); 
}