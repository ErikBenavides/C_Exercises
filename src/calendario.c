#include <stdio.h>
#include <conio.h>

int main(){
    int mes = 0;
    int tam = 0;
    printf("Introduce un numero de mes\n");
    scanf("%d", &mes);
    if(mes > 12 || mes < 1){
        printf("Introduce un valor de 1 y 12\n");
        return 0;
    }

    if(mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12){
        tam = 31;
    } else if(mes == 2){
        tam = 28;
    } else{
        tam = 30;
    }

    for(int i = 1;i <= tam;i++){
        printf("%3d", i);        
        if(i == 7 || i == 14 || i == 21 || i == 28)
            printf("\n");
    }

    getch();
    return 0;
}