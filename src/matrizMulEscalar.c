#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 4

void mul(int A[][TAM], int B[][TAM], int escalar){
	for(int i = 0; i < TAM; i++){
		for(int j = 0; j < TAM; j++){
			B[i][j] = A[i][j] * escalar;
		}
	}
}

void fill(int A[][TAM]){
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            A[i][j] = rand() % 10;
        }
    }
}

void pArray(int A[][TAM], char *name){
    printf("%s\n", name);
    for(int i = 0; i < TAM; i++){
        for(int j = 0; j < TAM; j++){
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
}

int main(){
    srand(time(NULL));
    int A[TAM][TAM];
	int B[TAM][TAM];
		
	fill(A);
    
	pArray(A, "A");
    mul(A, B, 4);
    pArray(B, "B");
    
    getch();
    return 0;
}