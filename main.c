//Bibliotecas comuns
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

//Bibliotecas próprias


#include "bibliotecas/organizers.h"
#include "bibliotecas/arrays.h"
#include "bibliotecas/utilities.h"



//Define's
#define SIZE 10000
#define TIMES 30

void main(){
	
	//Final
	int tempo_bolha[TIMES];
	int tempo_insDireta[TIMES];
	int tempo_quicksort[TIMES];
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
	int debug;
	int *array;
	int *arrayCopy;
	
	//User friendly?
	continuation = 0;
	
	//Debugging?
	debug = 1;
	if(debug) 
	
	
	//For loop para as vezes (turn) que os 3 algoritmos irao rodar no mesmo vetor
	for(turn=0;turn<TIMES;turn++){
		
		//Alocando espaço no array principal
		if(debug) printf("Vou alocar memoria do vetor principal\n");
		array = (int *) malloc(sizeof(int) * SIZE);
		if(debug) printf("Aloquei\n");
		if(!array){
			printf("oh no");
			pressButton();
		}
		
		//Preparando o srand()
		srand(time(NULL));
		
		//Pergunta de User Interface
		if(continuation){	
			printf("\nA seguir, o vetor de %d bytes. Sera preenchido com valores entre 0 e %d. Pressione enter para continuar\n",SIZE*8,RAND_MAX);
			pressButton();		
		}
		
		//Preencher o vetor
		printf("Irei preencher o vetor aleatoriamente\n");
		for(i=0;i<SIZE;i++){
			
			array[i] = rand();
		}
	
		//Verificação dos primeiros elementos
		if(continuation){
			printf("Preenchido. Deseja verificar os 10 primeiros numeros? (y/n): ");
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
		if(debug) printf("VOU ALOCAR\n");
		arrayCopy = (int *) malloc(sizeof(int) * SIZE);
			if(!arrayCopy){
			printf("oh no");
			pressButton();
		}
		if(debug) printf("ALOQUEI MEMORIA AQUI JA\n");
		copyArray(array,arrayCopy,SIZE);
		
		//Checar o tempo
		begin = clock();
		
		//Rodar o código
		bolha(arrayCopy,SIZE);
		
		//Checar o tempo /2
		end = clock();
		time_spent = difftime(end,begin) ;
		converted = time_spent; //Transforms double variable into MiliSeconds INTEGERS
		printf("\n%d Milisegundos..[BOLHA]\n",converted);
		
		
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
		
		
		if(debug) printf("VOU LIBERAR\n");
		free(arrayCopy);
		if(debug) printf("LIBEREI\n");
		
		///Ordenação Inserção Direta---------------------------------------------------------------------------------------------------------
		//Copiar o array
		if(debug) printf("VOU ALOCAR\n");
		arrayCopy = (int *) malloc(sizeof(int) * SIZE);
			if(!arrayCopy){
			printf("oh no");
			pressButton();
		}			
		if(debug) printf("ALOQUEI MEMORIA AQUI JA\n");
		copyArray(array,arrayCopy,SIZE);
		
		//Checar o tempo
		begin = clock();
		
		//Rodar o código
		insDireta(arrayCopy,SIZE);
		
		//Checar o tempo /2
		end = clock();
		time_spent = difftime(end,begin) ;
		converted = time_spent; //Transforms double variable into MiliSeconds INTEGERS
		printf("\n%d Milisegundos..[INSDIRETA]\n",converted);
		
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
		if(debug) printf("VOU LIBERAR\n");
		free(arrayCopy);
		if(debug) printf("LIBEREI\n");
		
		///Ordenação QuickSort---------------------------------------------------------------------------------------------------------
		//Copiar o array 
		if(debug) printf("VOU ALOCAR\n");
		arrayCopy = malloc(sizeof(int) * SIZE);
			if(!arrayCopy){
			printf("oh no");
			pressButton();
		}			
		if(debug) printf("ALOQUEI MEMORIA AQUI JA\n");
		copyArray(array,arrayCopy,SIZE);
		
		//Checar o tempo
		begin = clock();
		
		//Rodar o código
		quickSort(arrayCopy,0,SIZE);
		
		//Checar o tempo /2
		end = clock();
		time_spent = difftime(end,begin) ;
		converted = time_spent; //Transforms double variable into MiliSeconds INTEGERS
		printf("\n%d Milisegundos..[QUICKSORT]\n",converted);
		
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
		if(debug) printf("VOU LIBERAR\n");
		free(arrayCopy);
		if(debug) printf("LIBEREI\n");
		if(debug) printf("VOU LIBERAR A PRINCIPAL\n");
		free(array); 
		if(debug) printf("LIBEREI\n");
	
	} /*Fim de todos os testes, Aqui os vetores devem estar completos com os milisegundos que cada caso tomou para ordenar. 
	Os tempo_bolha[j] tempo_insDireta[j] e tempo_quicksort[j] tiveram o mesmo vetor como material, indo de 0 até #Define TIMES */	

	//Abertura do arquivo para escrita do resultado
	FILE *arq;
	arq = fopen("Resultado.txt","w"); //MUDA PRA INI DPS MATHEUS
	
	//Definição das médias
	float mediaBolha;
	mediaBolha = avgArray(tempo_bolha,SIZE);
	float mediaInsDireta;
	mediaInsDireta = avgArray(tempo_insDireta,SIZE);
	float mediaQuicksort;
	mediaQuicksort = avgArray(tempo_quicksort,SIZE);
	
	//Escrever os resultados
	fprintf(arq,"Tempo medio do bolha - [%f]miliSeg \nTempo medio do insercaoDireta - [%f]miliSeg \nTempo medio do quicksort - [%f]miliSeg\n\n",mediaBolha,mediaInsDireta,mediaQuicksort);
	
	for(i=0;i<TIMES;i++){
		fprintf(arq,"[%d] - Bolha(%d) | InsercaoDireta(%d) | Quicksort (%d)\n",i,tempo_bolha[i],tempo_insDireta[i],tempo_quicksort[i]);	
	}
	
	
	
	
	
	getchar();
}