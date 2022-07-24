#include <stdio.h>
#include <conio.h>


int len(char cadena[]){
    int i = 0;    
    for(i; cadena[i] != 0; i++){}
    return i;
}
int main(){
    char cadena[80];
    float res = 0.0;
    int punto = 0;
    int i = 0;
    printf("Introduce un numero con decimales\n");
    gets(cadena);
    int length = len(cadena);

    for(i; i < length; i++){
        if(cadena[i] == '.'){
            punto = length - i - 1;            
        } else {
            res = res * 10.0 + (cadena[i] - '0');            
        }
    }
    while(punto--){
        res /= 10.0;
    }
    printf("%f\n", res);
    return 0;
    
}