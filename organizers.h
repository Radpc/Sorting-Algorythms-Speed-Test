//Método bolha
void bolha(int vet[],int tam){
	int i,k,n;

	for(n=1;n<tam;n++){
		for(i=0;i<tam-n;i++){
			if(vet[i] > vet[i+1]){
				k = vet[i];
				vet[i] = vet[i+1];
				vet[i+1] = k;			
			}		
		}
	}
}


//Método Direct Insertion

void insDireta(int vet[], int tam){
	
	int p,x,temp;
	
	for(p=1;p<tam;p++){
		x = p;
		while((vet[x]<vet[x-1]) && (x>0) ){
			temp = vet[x];
			vet[x] = vet[x-1];
			vet[x-1] = temp;
			x = x-1;
		}		
	}	
}

//Método QuickSort


#include <stdio.h>

void quickSort(int *a, int left, int right) {
    int i, j, x, y;
     
    i = left;
    j = right;
    x = a[(left + right) / 2];
     
    while(i <= j) {
        while(a[i] < x && i < right) {
            i++;
        }
        while(a[j] > x && j > left) {
            j--;
        }
        if(i <= j) {
            y = a[i];
            a[i] = a[j];
            a[j] = y;
            i++;
            j--;
        }
    }
     
    if(j > left) {
        quickSort(a, left, j);
    }
    if(i < right) {
        quickSort(a, i, right);
    }
}