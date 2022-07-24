#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int rows = 4, cols = 10;
char **mMatriz(int rows, int cols){
	char **matriz;
	matriz = (char **)malloc(rows * sizeof(char *));
	for(int i = 0; i < cols; i++){
		matriz[i] = (char *)malloc(cols * sizeof(char));
	}

	return matriz;
}

int comp(char *str1, char *str2){
	int ret = 0;
	char *temp;
	/*for(int i = 0; str1[i] != 0; i++){
		for(int j = 0; str2[j] != 0; j++){
			if(srt1[i] > str2[j]){
				temp = str1;
				str1 = str2;
				str2 = temp;
			}
		}
	}*/
	if(str1[0] > str2[0]){
		/*temp = str1;
		str1 = str2;
		str2 = temp; 
		printf("%s, %s\n", str1, str2);*/
		return 1;
	} else if (str1[0] < str2[0]){		
		return -1;
	}
	return 0;
	//printf("%c, %c\n", str1[0], str2[0]);
			
	//return ret;
}

char **sort(char **str){
	char **sortR;
	char *temp;
	sortR = mMatriz(rows, cols);
	for(int i = 0; i < rows; i++){
		//for(int j = 0; j < str[i][j] != 0; j++){
			if(comp(str[i], str[i + 1]) > 0){
				temp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = temp;
			}
			//printf("%d\n", comp(str[i], str[i + 1 ]));

		//}
		//sortR[i] = str[i];
	}
	
	return str;
}

int main(){	
	char **str, **sortR;
	str = mMatriz(rows + 1, cols);

	str[0] = "escuela";
	str[1] = "superior";
	str[2] = "de";
	str[3] = "computo";
	str[4] = "";

	//comp(str[2], str[1]);
	sortR = sort(str);
	for(int i = 0; i < rows; i++){
		printf("%s\n", sortR[i]);
	}

	
	getch();
	return 0;
}