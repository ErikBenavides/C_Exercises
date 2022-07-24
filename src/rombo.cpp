#include <stdio.h>
#include <conio.h>

void rombo(int n){
     int tam = (n * 2) -1;
     for(int i = 1; i <= tam; i++){
             for(int j = 1; j <= tam; j++){
                     if( j == n && j == 1 ){
                         printf("*");
                     }else if(j==n-(i-1) || j==n+(i-1)){
                           printf("*");
                     }else if(i > n && j == (i-n) + 1 || j == tam - (i-n)){
                           printf("*");
                     }else{
                           printf(" ");
                     }
             }
             printf("\n");
     }
}

int main(){
    int numero;
    printf("Introduce un valor\n");
    scanf("%d", &numero);
    
    if (numero > 0 && numero <= 30){
       rombo(numero);   
    } else {
      printf("El valor debe de estar entre 1 y 30");
    }
    
    
    getch();
    return 0;
}
