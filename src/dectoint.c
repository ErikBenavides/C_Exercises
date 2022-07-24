#include <stdio.h>
#include <conio.h>

int main(int argc,char args[])
{
    float num = 0.0;
    int res = num;
    long int fin = 0;
    printf("numero\n");
    scanf("%f", &num);

    /*while(num != 0){
        num *= 10;
        res = num;
        num = num - res;
        fin = (fin * 10) + res;
        printf("%d\n", res);
        printf("fin: %d\n", fin);
    }
    printf("\nfinal: %d", fin);*/
    for(int i = 0;num != 0; i++){
        if(i == 9) break;
        num *= 10;
        res = num;
        num = num - res;
        fin = (fin * 10) + res;        
    }
    printf("final: %d", fin);

    getch();
    return 0;
}