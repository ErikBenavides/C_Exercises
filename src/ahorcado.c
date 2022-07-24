#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int main(){
    char palabras[][10] = {"gato", "perro", "manzana", "pelota", "sandia", "lapiz", "raton", "naranja", "perico", "leon"};
    srand(time(NULL));
    int ran = rand() % 10;
    int i, tam, error = 0, correcta = 0, val;
    char letra;    
    char *pal = palabras[ran];
    for(i=0; pal[i++] != 0;){};
    tam = i - 1;
    char palCor[tam];

    for(i=0; i < tam; i++){
        palCor[i] = '_';
    }
    
    do{        
        for(i = 0; i < tam; i++){
            printf("%c ", palCor[i]);
        }

        if(correcta == tam){
            printf("\nGanaste!");
            getch();
            return 0;
        }
        
        printf("\nIntroduce una letra\n");
        fflush(stdin);
        scanf("%c", &letra);
        val = 0;        

        for(i = 0; i < tam; i++){
            if(pal[i] == letra){
                palCor[i] = letra;
                val = 1;
                correcta++;
            }
        }

        if(val == 0){
            error++;
        }
        if(error == 5){ 
            printf("\nHas perdido");
            getch();
            return 0; 
        }
        system("cls");
    }while(letra != 48);
    return 0;  
}  