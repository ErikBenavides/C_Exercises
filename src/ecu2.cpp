#include<stdio.h>
#include<math.h>
#include<conio.h>

int main(int argc, char** args){
    float a, b, c, disc, x1, x2, xi, xr;
    printf("Introduce el valor de a, b, c\n");
    scanf("%f, %f, $f", &a, &b, &c);
    
    disc=b*b-4*a*c;
    if(disc>0){
        printf("Las dos raices son reales\n");
        x1=((-b+sqrt(disc))/(2.0*a));
        x2=((-b-sqrt(disc))/(2.0*a));
        printf("x1=%.2f   x2=%.2f", x1, x2);
    } 
    else{
        if(disc==0){
            x1=(-b)/(2*a);
            printf("La ecuacion solo tiene una raiz %.2f\n", x1); 
        }
        else{
            xr=(-b/(2*a));
            xi=(sqrt(-disc)/(2.0*a));
            printf("La raiz real es %.2f y la imaginaria es %.2f\n", xr, xi);
        }
    }
    
    getch();
    return 0;
} 
