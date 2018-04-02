
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

int partition( int a[], int l, int r) {
   int pivot, i, j, t;
   pivot = a[l];
   i = l; j = r+1;
		
   while( 1)
   {
   	do ++i; while( a[i] <= pivot && i <= r );
   	do --j; while( a[j] > pivot );
   	if( i >= j ) break;
   	t = a[i]; a[i] = a[j]; a[j] = t;
   }
   t = a[l]; a[l] = a[j]; a[j] = t;
   return j;
}

void quickSort( int a[], int l, int r)
{
   int j;

   if( l < r ) 
   {
   	// divide and conquer
        j = partition( a, l, r);
       quickSort( a, l, j-1);
       quickSort( a, j+1, r);
   }
	
}



