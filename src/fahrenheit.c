#include <stdio.h>
#include <conio.h>

int main(){
    float grados = 0;
    
    printf("Introduce la temperatura en grados centigrados\n");
    scanf("%f", &grados);

    printf("fahrenheit: %f\n", (1.8 * grados) + 32);

    getch();
    return 0;
}