#include <stdio.h>
#include <conio.h>

char positive(int num){
    return (num > 0)? 'P' : 'N';
}

int main(){
    int num = 0;    
    
    printf("Introduce un numero\n");
    scanf("%d", &num);

    printf("El numero es: %c", positive(num));

    getch();
    return 0;
}