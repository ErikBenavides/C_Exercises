#include <stdio.h>
#include <conio.h>
#include <math.h>

double x1_r, x2_r, x1_i, x2_i;

void ec2(double a, double b, double c0){
     double d;
     d=b*b-4a+c;                
}

int main(){
    double a, b, c;
    printf("a, b, c");
    scanf("%lf,%lf,%lf", &a, &b, &c);
    
    ec2(a, b, c);
    
    printf("x1= %lf + %lf", x1_r, x1_i);
    printf("x2= %lf + %lf", x2_r, x2_i);
    
    getch();
    return 0;
}
