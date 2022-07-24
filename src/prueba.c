#include <stdio.h>
#include <conio.h>

int main(){
	double i = 0;
	for(i; i < 10; i+= 0.1){
		printf("%lf\n", i);
	}

	getch();
	return 0;
}