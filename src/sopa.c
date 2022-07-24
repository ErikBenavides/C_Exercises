#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <stdlib.h>
#define XTAM 50
#define YTAM 25
#define PALTAM 10

void fillRand(char sopa[][YTAM]){
	for(int i = 0; i < XTAM; i++){
		for(int j = 0; j < YTAM; j++){
			if(sopa[i][j] == ' '){
				char r = (rand() % 25) + 97;
				sopa[i][j] = r;
			}
		}        
	}
}

void fill(char sopa[][YTAM]){
	for(int i = 0; i < XTAM; i++){
		for(int j = 0; j < YTAM; j++){
			sopa[i][j] = ' ';
		}        
	}
}

void show(char sopa[][YTAM]){
	for(int i = 0; i < YTAM; i++){
		for(int j = 0; j < XTAM; j++){
			printf("%c", sopa[i][j]);
		}
		printf("\n");
	}
}

int main(){
	char sopa[XTAM][YTAM];
	char palabras[][PALTAM] = {"gato", "perro", "manzana", "pelota", "sandia", "lapiz", "raton", "naranja", "perico", "leon"};
	srand(time(NULL));
	int ran = 0;
	char *pal;
	int tam = 0, ranX, ranY, palN = 0, fit = 0;
	fill(sopa);
		
	while(palN < PALTAM){
		palN++;
		pal = palabras[ran];
		ran = rand() % PALTAM;
		ranX = rand() % XTAM;
		ranY = rand() % YTAM;
		for(tam = 0; pal[tam++] != 0;){};
		tam--;

		if((tam + ranY) < XTAM && (tam + ranX) < YTAM){
			for(int i = 0; i < tam; i++){
				if(sopa[ranY][ranX + i] == ' '){
					sopa[ranY][ranX + i] = pal[i];
				}
			}
		}

		pal = palabras[ran];
		ran = rand() % PALTAM;
		ranX = rand() % XTAM;
		ranY = rand() % YTAM;
		for(tam = 0; pal[tam++] != 0;){};
		tam--;

		if((tam + ranX) < XTAM && (tam + ranY) < YTAM){
			for(int i = 0; i < YTAM; i++){			
				for(int j = 0; j < XTAM; j++){
					if(sopa[i][j] == pal[0]){
						fit = 0;
						for(int k = 0; k < tam; k++){
							if(sopa[i + k][j] == ' '){
								fit = 1;
							}
						}						
						if(fit){
							for(int k = 0; k < tam; k++){
								sopa[i + k][j] = pal[k];
							}	
						}
					}
				}
				
			}
		}
	}
	fillRand(sopa);
	show(sopa);
	getch();
	return 0;
}