#include <stdio.h>
#include <conio.h>

void itoa(int num){
     int res, i, j, length;
     char cadena[80] = "";
     char temp;
     const char digit[] = "0123456789";
     
     for(i = 0; num != 0; i++){             
             res = num % 10;
             cadena[i] = digit[res];
             num = num / 10;
     }
     cadena[i] = 0;
     length = i;
     
     for(i = 0, j = length - 1; i < length / 2; i++, j--){
           temp = cadena[i];
           cadena[i] = cadena[j];
           cadena[j] = temp;
     }
     printf("%s", cadena);
}

int main(){
    itoa(165);
        
    getch();
    return 0;
}
