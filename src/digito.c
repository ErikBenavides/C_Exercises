#include <stdio.h>
#include <conio.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

BOOL digito(char caracter){
    const char numeros[] = "0123456789";

    for(int i = 0; numeros[i] != 0; i++){        
        if(caracter == numeros[i]){
            return TRUE;
        }
    }
    return FALSE;
}

int main(){
    char caracter;
    
    printf("Introduce un caracter\n");
    scanf("%c", &caracter);
   
    printf("El caracter es: %s\n", (digito(caracter))? "true" : "false");

    getch();
    return 0;
}