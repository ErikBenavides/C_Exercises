#include <stdio.h>
#include <conio.h>

int decToInt(float num){
    int res = num;
    long int fin = 0;
    for(int i = 0;num != 0; i++){
        if(i == 9) break;
        num *= 10;
        res = num;
        num = num - res;
        fin = (fin * 10) + res;        
    }
    return fin;
}

void ftoa(int num){
    int i, j, length;
    int res;
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

int main()
{    
    float num = 0.0, dec = 0.0;
    int integer = 0;
    printf("Introduce un numero con decimales\n");
    scanf("%f", &num);
    integer = num;
    dec = num - integer;  

    ftoa(integer);
    printf(".");
    ftoa(decToInt(dec));

    getch();
    return 0;
}