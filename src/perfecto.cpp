#include <stdio.h>
#include <conio.h>

void perfecto(int numero){
	int res = 1;
	for(int i = 2; i < numero; i ++){
		if(numero % i == 0){
			res = res + i;
		}
	}
	if (res == numero){
		printf("El numero es perfecto: %d\n", res);
	} 
}

int main(){
	int numero = 0;
	printf("Intoduce un numero ");
	scanf("%d", &numero);
	
	for(int i = 1; i < numero; i++){
		perfecto(i);		
	}

	
	getch();
	return 0;
}


