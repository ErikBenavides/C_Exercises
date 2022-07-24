#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100000
int array[TAM];

void quickSort( int[], int, int);
int partition( int[], int, int);


int main(){	
	int i;
	srand(time(NULL));
	for(i = 0; i < TAM; ++i){
        array[i] = rand()%TAM;
    }
		

	quickSort( array, 0, TAM);

	printf("\n\nSorted array is:  ");
	for(i = 0; i < TAM; ++i){
		printf(" %d ", array[i]);
    }

    getch();
    return 0;
}



void quickSort( int x[], int p, int r){
   int q;

   if( p < r ){   	
        q = partition( x, p, r);
        quickSort( x, p, q - 1);
        quickSort( x, q + 1, r);
   }
	
}



int partition( int x[], int p, int r) {
   int pivot, i, j, t;
   pivot = x[p];
   i = p; j = r+1;
		
    while( 1){
   	    do ++i; while( x[i] <= pivot && i <= r );
        do --j; while( x[j] > pivot );
        if( i >= j ) break;
        t = x[i]; 
        x[i] = x[j]; 
        x[j] = t;
    }
        t = x[p]; 
        x[p] = x[j]; 
        x[j] = t;
   return j;
}