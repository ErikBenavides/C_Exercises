#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int row = 0;
int col = 0;
int rowB = 0;
int colB = 0;

void mul(int A[][col], int B[][colB], int C[][colB]){
    int tem = 0;
    for(int i = 0; i < row; i++){
        for(int j = 0; j < colB; j++){
            C[i][j] = 0;
            for(int k = 0; k < col; k++){                
                C[i][j] = C[i][j] + A[i][k] * B[k][j];
            }
        }
    }

    
    printf("C\n");
    for(int i = 0; i < row; i++){
        for(int j = 0; j < colB; j++){
            printf("%4d", C[i][j]);
        }
        printf("\n");
    }
}

void pArrayA(int A[][col], char *name){
    printf("%s\n", name);
    
    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("%4d", A[i][j]);
        }
        printf("\n");
    }
    
}

void pArrayB(int B[][colB], char *name){
    printf("%s\n", name);
    for(int i = 0; i < rowB; i++){
        for(int j = 0; j < colB; j++){
            printf("%4d", B[i][j]);
        }
        printf("\n");
    }
}

int main(){
    printf("Multiplicar matrices\nIntroduce el numero de filas de la matriz\n");
    scanf("%d", &row);
    printf("Introduce el numero de columnas\n");
    scanf("%d", &col);

    int A[row][col];
    int tem = 0;

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            printf("Introduce el valor de i= %d, j= %d\n", i , j);
            scanf("%d", &tem);
            A[i][j] = tem;
            system("cls");
        }
    }

    printf("Introduce el numero de filas de la segunda matriz\n");
    scanf("%d", &rowB);
    printf("Introduce el numero de columnas de la segunda matriz\n");
    scanf("%d", &colB);
    int B[rowB][colB];

    if(col != rowB){
        printf("No se puede multiplicar\n");
        getch();
        return 0;
    }

    for(int i = 0; i < rowB; i++){
        for(int j = 0; j < colB; j++){
            printf("Introduce el valor de i= %d, j= %d\n", i , j);
            scanf("%d", &tem);
            B[i][j] = tem;
            system("cls");
        }
    }

    int C[row][colB];
    pArrayA(A, "A");    
    pArrayB(B, "B");

    mul(A, B, C);

    getch();
    return 0;
}