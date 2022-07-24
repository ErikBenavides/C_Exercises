#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char *matriz;
char n;
int cuad;
 
void saveValue(int lin,int col,int valor) {
    int pos = ((lin-1)*n) + (col-1);
    matriz[pos] = valor;
}
void show() {
    int cont;
    for(cont = 1; cont <= cuad; cont++) {
        printf("%d\t",matriz[cont-1]);
        if ( cont%n == 0 ) {
            printf("\n");
        }
    }
}
int main() {
    int cont, posL, posC;
    printf("Introduce un numero impar\n");
    scanf("%d", &n);
    if(n % 2 == 0){
        printf("El numero es par\n");
        getch();
        return 0;
    }
    
    cuad = n*n;
    matriz = (char *)malloc(cuad*sizeof(char));
    for(cont = 0; cont < cuad; cont++){
        matriz[cont] = 0;
    } 
 
    cont = 1;
    posL = 1;
    posC = n/2+1;
    while ( cont <= cuad ) {
        saveValue(posL,posC,cont);
        if ( cont%n == 0 ) {
            posL++;
        } else {
            posL--;
            if ( posL < 1 ){
              posL = n;   
            } 
            posC++;
            if ( posC > n ){
                posC = 1;
            } 
        }
        cont++;
    }
    show();
    free(matriz);

    getch();
    return 0;
}
 