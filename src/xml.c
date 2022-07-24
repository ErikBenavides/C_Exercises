#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Parent{
	char nombre[50];
	char apellido[50];
};

int findElement(char *cad1, char *cad2){
	int num = 0;
	int j = 0;
	int findBool = 0;
	for(int i = 0; cad1[i] != 62; i++){
		if(cad1[i] == cad2[0] && cad1[i - 1] != 47){
			for(j = 0; cad2[j] != 0; j++){				
				if(cad1[i + j] == cad2[j]){
					findBool = 1;
				} else{
					findBool = 0;
				}
			}
		}
	}
	//printf("%d\n",findBool);
	return findBool;
}

int find(char *cad1, char *cad2){
	int num = 0;
	int j = 0;
	for(int i = 0; cad1[i] != 62; i++){
		if(cad1[i] == cad2[0]){
			for(j = 0; cad1[i + j] != 62; j++){				
				num = i + j;
			}
		}
	}
	//return num + 1;
	num++;
	/*for(int i = num; cad1[i] != 62; i++){
		printf("%c", cad1[i]);
	}*/
	return num;
}

int main(){
	FILE *file;
	char c;
	char linea[200], linea2[200];
	char tem[100];
	int p = 0, child = 0;
	struct Parent parent;
	file = fopen ("prueba.xml", "rt");
	if(file != NULL){
		while(!feof(file)){			
			//printf("%s", fgets(linea, sizeof(linea), file));
			//parent = findElement(fgets(linea, sizeof(linea), file), "persona");			
			//printf("%s", fgets(linea2, sizeof(linea2), file));
			child = findElement(fgets(linea2, sizeof(linea2), file), "persona");
			//printf("%d",parent);
			printf("%d\n",child);
			/*if(child){
				int n = find(fgets(linea2, sizeof(linea2), file), "nombre");
				printf("%d\n", n);
				
			}*/
			
		}
		fclose(file);
	}

	/*char *cad1 = "<persona>";
	char *cad2 = "persona";
	char *cad3 = "";
	int num = 0;
	int j = 0;
	for(int i = 0; cad1[i] != 62; i++){
		if(cad1[i] == cad2[0]){
			for(j = 0; cad1[i + j] != 62; j++){
				printf("%c", cad1[i + j]);
				//cad3[j] = cad1[i + j];

				num = i + j;
			}
		}
		//printf("%c",cad1[i]);
	}
	printf("%d\n", num);*/

	

	getch();
	return 0;
}