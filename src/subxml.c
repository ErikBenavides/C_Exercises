#include <stdio.h>
#include <conio.h>

void inita(char *cad){
	int in = 0;
	int flag = 0;
	for(int i = 0; cad[i] != 0; i++){
		if(cad[i] == 62 && flag == 0){
			for(int j = 1; cad[i + j] != '<'; j++){
				printf("%c", cad[i + j]);
				flag = 1;
			}
		}
	}
}
/*int end(char *cad){
	int en = 0;
	for(int i = 0; cad[i] != 0; i++){
		if(cad[i] == 60){
			en = i;
		}
	return en;
}*/
int main(){
	char *parent = "<hola>hola mundo</hola>";
	/*for(int i = 0; parent[i] != 0; i++){
		
	}*/
	inita(parent);
	getch();
	return 0;
}