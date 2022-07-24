#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 100000
int array[TAM];

int main(){
  srand(time(NULL));
  int c, d, temp;
  for(int i = 0; i < TAM; i++){
	  array[i] = rand()%TAM;
  }
 
  for (c = 0 ; c < ( TAM - 1 ); c++){
	for (d = 0 ; d < TAM - c - 1; d++){
	  if (array[d] > array[d+1]){
		temp       = array[d];
		array[d]   = array[d+1];
		array[d+1] = temp;
	  }
	}
  }
 
  printf("Numeros ordenados:\n");
 
  for ( c = 0 ; c < TAM ; c++ ){
	  printf("%d, ", array[c]);
  }
 
  return 0;
}