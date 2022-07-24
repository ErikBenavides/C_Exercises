#include <stdio.h>
#include <conio.h>

int main(){
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    
    printf("Introduce 4 numeros, separados por comas\n");
    scanf("%d,%d,%d,%d", &a, &b, &c, &d);
    printf("%d%d%d%d\n", a, b, c, d);
    if(a > b && a > c && a > d){
        printf("Mayor: %d\n", a);
    } else if(b > a && b > c && b > d){
        printf("Mayor: %d\n", b);
    } else if(c > a && c > b && c > d){
        printf("Mayor: %d\n", c);
    } else{
        printf("Mayor: %d\n", d);
    }

    return 0;
}