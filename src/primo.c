#include <stdio.h>
#include <conio.h>

int main(){
    int num = 0;
    printf("Introduce un numero\n");
    scanf("%d", &num);

    if((num % 2) == 0){
        printf("El numero no es primo\n");
    }else{
        printf("El numero es primo\n");
    }

    getch();
    return 0;
}