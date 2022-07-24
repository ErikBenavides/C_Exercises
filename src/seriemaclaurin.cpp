#include <stdio.h>
#include <conio.h>
#define PI 3.14159265358979323

float coseno(float anguloRad, int n){
    float ans = 1, temp = 1;
    for(int i = 1; i <= n; i+= 2){            
            temp = temp * (-1) * anguloRad * anguloRad / ( i * (i + 1));
            ans = ans + temp;
    } 
    return ans;
}

float seno(float anguloRad, int n){
    float ans = anguloRad, temp = anguloRad;
    
    for(int i=2;i<=n;i+=2)
	{
		temp = temp * (-1) * anguloRad * anguloRad / (i * (i + 1));
		ans = ans + temp;
	}
    return ans;
}


int main(){
    int n;
    float anguloDeg, anguloRad;
    
    printf("Introduce la precision\n");
    scanf("%d", &n);
    printf("Intoduce el angulo en grados\n");
    scanf("%f", &anguloDeg);
    
    if(anguloDeg < -180 || anguloDeg > 180){
        printf("El angulo debe estar entre -180 y 180");
        getch();
        return 0;
    }
    
    anguloRad = anguloDeg * PI / 180;
   
    
    printf("\nEl coseno es %f\n", coseno(anguloRad, n));
    printf("El seno es %f", seno(anguloRad, n));
   
    getch();
    return 0;
}
