#include <stdio.h>
#include <conio.h>


int MCD(int a, int b, int c){
    int mcd, m1, m2, m3;
    
    for(int i = 2; ; i++){
         m1 = a%i;
         m2 = b%i;
         m3 = c%i;
         
         if(m1 == 0 && m2 == 0 && m3 == 0){
               return i;
         }
    }

}

int main(){
      printf("Maximo comun divisor");
      printf("\nRespuesta: %d", MCD(16,32,48));
      
      getch();
      return 0;
}


