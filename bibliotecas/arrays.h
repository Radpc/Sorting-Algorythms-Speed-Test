#include <stdio.h>
//Copy array values into another

void copyArray(int array1[], int array2 [],int size){
	int i;
	for(i=0;i<size;i++){
		array2[i] = array1[i];		
	}
}


//Show how many itens of the array you want
void showArray(int array[], int many){
	int i;
	
	for(i=0;i<many;i++){
		printf("[%d] ",array[i]);
		}
	
}

//Lowest value of array

int lowestArray(int array[], int size){
	int i,k;
	k = array[0];
	
	for(i=0;i<size;i++){
		if(array[i] < k) k = array[i];
	}
	return k;	
}

//Highest value of array

int highestArray(int array[], int size){
	int i,k;
	k = array[0];
	
	for(i=0;i<size;i++){
		if(array[i] > k) k = array[i];
	}
	return k;	
}


//Average of the array

int avgArray(int array[], int size){
	int i;
	int avg;
	avg = 0;
	
	for(i=0;i<size;i++){
		avg = avg + array[i];		
	}
	
	avg = avg/size;
	return avg;
}