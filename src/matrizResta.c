#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#define TAM 4

void suma(int A[][TAM], int B[][TAM], int C[][TAM]){
	for(int i = 0; i < TAM; i++){
		for(int j = 0; j < TAM; j++){
			C[i][j] = A[i][j] - B[i][j];
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
	int C[TAM][TAM];
	
	fill(A);
    fill(B);

	pArray(A, "A");
	pArray(B, "B");
	suma(A, B, C);
	pArray(C, "C");

    getch();
    return 0;
}