#include <stdio.h>
#include <conio.h>
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
    return x * x;   
}

int main(){
    double x;
    double y = 0;
    for(x = 0; x < 79 && y < 25; x+=0.1){ //.6
        y = f(x);
        gotoxy(x + 39, 25 - y);
        printf("*");
        gotoxy(39 - x, 25 - y);
        printf("*");        
    }
    
    getch();
    return 0;
}