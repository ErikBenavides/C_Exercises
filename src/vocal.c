#include <stdio.h>
#include <conio.h>

#define BOOL int
#define TRUE 1
#define FALSE 0

BOOL vocal(char caracter){
    const char vocales[] = "AEIOUaeiou";

    for(int i = 0; vocales[i] != 0; i++){        
        if(caracter == vocales[i]){
            return TRUE;
        }
    }
    return FALSE;
}

int main(){
    char caracter;
    
    printf("Introduce un caracter\n");
    scanf("%c", &caracter);
   
    printf("El caracter es: %s\n", (vocal(caracter))? "true" : "false");

    getch();
    return 0;
}