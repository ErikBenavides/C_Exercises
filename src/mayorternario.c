#include <stdio.h>
#include <conio.h>

int main(){
    int a = 0;
    int b = 0;
    
    printf("Introduce dos numeros separados por comas\n");
    scanf("%d,%d", &a, &b);

    printf("mayor: %d\n", (a < b)? b: a);

    getch();
    return 0;
}