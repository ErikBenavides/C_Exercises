#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX 30

void gotoxy(int x,int y){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y= y;
	SetConsoleCursorPosition(hcon,dwPos);
 }

void count(char **cad,int rows){
	int a = 0, e = 0, ii = 0, o = 0, u = 0;

	for(int i = 0; i < rows; i++){
		for(int j = 0; cad[i][j] != 0; j++){
			if(cad[i][j] == 'a'){
				a++;
			} else if(cad[i][j] == 'e'){
				e++;
			} else if(cad[i][j] == 'i'){
				ii++;
			} else if(cad[i][j] == 'o'){
				o++;
			} else if(cad[i][j] == 'u'){
				u++;
			}
		}        
	}

	system("cls");
	gotoxy(25, 24);
	printf("A");
	gotoxy(30, 24);
	printf("E");
	gotoxy(35, 24);
	printf("I");
	gotoxy(40, 24);
	printf("O");
	gotoxy(45, 24);
	printf("U");

	for(int i = 0; i < a; i++){
		gotoxy(25, 22 - i);
		printf("%c", 219);
	}
	gotoxy(25, 22 - a); printf("%d", a);

	for(int i = 0; i < e; i++){
		gotoxy(30, 22 - i);
		printf("%c", 219);
	}
	gotoxy(30, 22 - e); printf("%d", e);

	for(int i = 0; i < ii; i++){
		gotoxy(35, 22 - i);
		printf("%c", 219);
	}
	gotoxy(35, 22 - ii); printf("%d", ii);

	for(int i = 0; i < o; i++){
		gotoxy(40, 22 - i);
		printf("%c", 219);
	}
	gotoxy(40, 22 - o); printf("%d", o);

	for(int i = 0; i < u; i++){
		gotoxy(45, 22 - i);
		printf("%c", 219);
	}
	gotoxy(45, 22 - u); printf("%d", u);

}

int main(){
	int rows = 0,i;
	char **cad;
	printf("Introduce cuantas linas de texto vas a introducir\n");
	scanf("%d", &rows);

	cad = (char **)malloc(rows * sizeof(char *));

	for(i = 0; i < rows; i++){
		cad[i] = (char *)malloc(MAX * sizeof(char));
	}
	
	for(i = 0; i < rows; i++){        
		printf("Introduce la cadena( %d )\n", i + 1);
		fflush(stdin);
		gets(cad[i]);
		int k;
		for(k = 0; cad[i][k] != 0; k++);
		if(k > 30){
			printf("introduce una oracion menor a 30\n");
			getch();
			return 0;
		}
	}
	
	count(cad, rows);

	getch();
	return 0;
}