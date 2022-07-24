#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

char **cad;

char **split(char *str, char *sep){
    char **cads;
    cads = (char **)malloc(4 * sizeof(char *));
    /*for(int k = 0; k < 4; k++){
        cads[k] = (char *)malloc(15 * sizeof(char));
    }*/

    int i, j, m = 0;
    for(i = 0; str[i] != 0; i++){
        for(j = 0; sep[j] != 0; j++){
            if(sep[j] != str[i + j]){
                j = -1;
                break;
            }
        }
            if(j == -1){
                cads[i] = str;
                printf("%c", str[i]);
            }else{
                i += j -1;
                printf("\n");
            }
    }

    return cads;
}

int main(){
    char *str = "Escuela superior de computo";
    char *sep = " ";

    cad = split(str, sep);

    for(int i = 0; i < 4; i++){
        printf("%s\n", cad[0]);
    }

    getch();
    return 0;
}