#include <stdio.h>
#include <conio.h>

void atoi(char cadena[]){
     bool signo = true;
     int i = 0;
     if(cadena[0] == '-'){
         signo = false;
         i = 1;
     }
     
     int integer = 0, temp = 0;
     for(i; cadena[i] != 0; i++){
             temp = cadena[i] - 48;
             integer = 10 * integer + temp - '\0';
     }
     integer *= (signo)? 1: -1;
     printf("%d\n", integer);
}

int main(){
    char cadena[] = "-459787";
    atoi(cadena);
        
    getch();
    return 0;
}
