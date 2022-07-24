#include <stdio.h>
#include <conio.h>

void atoi(char cadena[]){
     int integer = 0, temp = 0;
     for(int i = 0; cadena[i] != 0; i++){
             temp = cadena[i] - 48;
             integer = 10 * integer + temp - '\0';
     }
     printf("%d\n", integer);
}

int main(){
    char cadena[] = "3587";
    atoi(cadena);
        
    getch();
    return 0;
}
