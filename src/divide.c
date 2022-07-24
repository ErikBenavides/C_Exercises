#include <stdio.h>
#include <conio.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

BOOL divide(int num1, int num2){
    return ((num1 % num2) == 0)? TRUE : FALSE;
}

int main(){
    int num1 = 0;
    int num2 = 0;
    
    printf("Introduce dos numeros, separados por comas\n");
    scanf("%d,%d", &num1, &num2);

    printf("%s", (divide(num1, num2))? "true": "false");

    getch();
    return 0;
}