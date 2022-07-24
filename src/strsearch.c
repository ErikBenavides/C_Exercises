#include <stdio.h>
#include <conio.h>

void strsearch(char str1[], char str2[]){
    int equal = 0;
    for(int i = 0; str1[i] != 0; i++){
        if(str1[i] == str2[0]){
            for(int j = 0; str2[j] != 0; j++){
                if(str1[i + j] == str2[j]){
                    equal = i;
                }
            }            
            printf("%d\n", equal);
        }
    }    
}

int main(){
    char str1[80] = "";
    char str2[80] = "";
    printf("Introduce la primer cadena\n");
    gets(str1);
    printf("Introduce la segunda cadena\n");
    gets(str2);

    strsearch(str1, str2);

    getch();
    return 0;
}
