#include <stdio.h>
#include <conio.h>

void itoa(int num){
     int res, i, j, length;
     bool signo = true;
     char cadena[80] = "";
     char temp;
     const char digit[] = "0123456789";
     
     if(num < 0){
            signo = false;
            num *= -1;
     }
     
     for(i = 0; num != 0; i++){             
             res = num % 10;
             cadena[i] = digit[res];
             num = num / 10;
     }
     
     if(signo == false){
              cadena[i] = '-';
              length = i + 1;
     } else {
              length = i;
     }
     cadena[i + 1] = 0;

     for(i = 0, j = length - 1; i < length / 2; i++, j--){
           temp = cadena[i];
           cadena[i] = cadena[j];
           cadena[j] = temp;
     }
     printf("%s", cadena);
}

int main(){
    itoa(-19065);
        
    getch();
    return 0;
}
