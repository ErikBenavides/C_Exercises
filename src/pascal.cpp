#include <stdio.h>
#include <conio.h>

int factorial(int num){
     int res = 1;
     for(int i = 1; i <= num; i++){
         res *= i;
     }
     return res;
}

int pascal(int tam){
    int num;
     for(int i = 0; i <= tam; i++){
         for(int j = 0; j <= i; j++){
             num = factorial(i) / (factorial(j) * factorial(i - j));
             printf("%5d", num);
         }
         printf("\n");
    }
}

int main(){
    int num;
    printf("introduce un numero entre 1 y 20\n");
    scanf("%d", &num);
    
    pascal(num);
    
    getch();
    return 0;
}
