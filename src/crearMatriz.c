#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char **mMatriz(int rows, int cols){
    char **matriz;
    matriz = (char **)malloc(rows * sizeof(char *));
    for(int i = 0; i < cols; i++){
        matriz[i] = (char *)malloc(cols * sizeof(char));
    }

    return matriz;
}

int main(){
    int rows = 0, cols = 0;
    printf("Introduce el numero de filas de la Matriz\n");
    scanf("%d", &rows);
    printf("Introduce el numero de columnas de la Matriz\n");
    scanf("%d", &cols);

    char **mat = mMatriz(rows, cols);
    
    getch();
    return 0;
}