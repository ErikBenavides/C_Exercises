#include <stdio.h>
#include <conio.h>
#include <math.h>

int fact(int n){
    int num = 1;
    for(int i = 1; i <= n; i++){
        num *= i;
    }
    return num;
}

int main(){
    int num;
    float angulo;
    printf("introduce la precision\n");
    scanf("%d", &num);
    printf("introduce el valor del angulo\n\n");
    scanf("%f", &angulo);    
       
    double seno = 0, coseno = 0;
    for(int k = 0; k < num; k++){
            seno += pow(-1, k) * pow(angulo, 2 * k + 1) / fact(2 * k + 1);
            coseno += pow(-1, k) * pow(angulo, 2 * k) / fact( 2 * k );
    }
    
    printf("El valor del seno es  %f\n", seno);
    printf("El valor del coseno es %f", coseno);
    
    getch();
    return 0;
}


