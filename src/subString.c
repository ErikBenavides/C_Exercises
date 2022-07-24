#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


char *subString(char *str, int ini, int nchars){
    char *sub;
    sub = (char *)malloc(nchars* sizeof(char));
    for(int i = 0; i < nchars; i++){
        printf("%c", str[ini + i]);
        sub[i] = str[ini + i];   
    }
    
    return sub;
}
int main(){
    char *str = "escuela superior de computo";

    printf("\n%s\n", subString(str, 2, 10));
    getch();
    return 0;
}