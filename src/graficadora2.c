#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>

void gotoxy(int x,int y){  
    HANDLE hcon;  
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
    COORD dwPos;  
    dwPos.X = x;  
    dwPos.Y= y;  
    SetConsoleCursorPosition(hcon,dwPos);  
}
double f(double x){
    return x;   
}
void cuadratica(){
    int x;
    double y = 0;
    for(x = 0; x < 79 && y < 25; x++){
        y = f(x);
        gotoxy(x + 39, 25 - y);
        printf("*");
        gotoxy(39 - x, 25 - y);
        printf("*");        
    }
}

void menu(){
    int i, j;
    for(i = 0; i < 79; i++){
        for(j = 0; j < 25; j++){
            printf("a");
        }
    }
}

int main(){
    char opc;
    do{
        system("cls");
        printf("Selecciona un tipo de funcion\n");
        printf("1) Lineal\n");
        printf("2) cuadratica\n");
        printf("3) trigonometrica\n");
        printf("4) salir\n");
        //scanf("%c", &opc);
        printf("%d", getch());
       /* if(opc==1){
            printf("opcion 1");
        } else{
            printf("Incorrecta\n");
        }*/
    }while(opc != 52);
    
    
    return 0;
}