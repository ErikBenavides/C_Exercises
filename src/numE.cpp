#include <stdio.h>
#include <conio.h>
#include <math.h>



void e_function(int n){
     float e, producto;
        producto=1;
        e=1;
 
        for (int i =1; i <= n; i++)
        {
             producto*=i;
             e+=1/producto;
         }
       printf("El numero e es: %f\n",e);
       printf("El margen de error es de %f", ((exp(1)-e)/exp(1))*100);    
}
     
     
int main(){
    float aprox;
    printf("Valor de e\n");
    printf("introduce la aproximacion que quieres\n");
    scanf("%f", &aprox);
    
    e_function(aprox);

    getch();
    return 0;
}
