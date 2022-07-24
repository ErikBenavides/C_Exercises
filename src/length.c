#include <stdio.h>
#include <conio.h>

int main(){
    char cadena[] = "gatoloco como estas";
    int i = 0;
    for(i; cadena[i] != 0; i++){
    }
    printf("%d", i);

    char str[] = "content";
    int charcount = 0;
    charcount =  sizeof str - 1;
    printf("%d\n", charcount);
    getch();
    return 0;

}