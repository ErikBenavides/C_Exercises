#include <stdio.h>
#include <conio.h>

int main(){
    int hr = 0, min = 0;    
       
    printf("Introduce una hora en sistema de 24hrs\n");
    scanf("%d:%d", &hr, &min);
    
    if(hr > 0 && hr < 24 && min > 0 && min < 60){
          printf("La hora en sistema de 12hrs es: %d:%d", hr - 12, min);
    }else{
          printf("La hora no es valida");
    }
    
    getch();
    return 0;
}
