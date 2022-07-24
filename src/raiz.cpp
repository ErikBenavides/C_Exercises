#include <stdio.h>
#include <conio.h>

int main(){
    int n = 25;
    int raiz = 0;
    
    for(int i = 0; i < n; i ++){
        if(i * i == n){
             raiz = i;
             break;
        }        
    }
    printf("Raiz cuadrada %d", raiz);
    getch();

}
