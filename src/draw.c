#include <stdio.h>
#include <conio.h>

void lineTo(int x1, int y1, int x2, int y2, RGB color, Bitmap *bmp){
	double y = 0, x = 0;
	int max = 0, min = 0;
	int i = 0, j = 0;
	double m = (y2 - y1) / (x2 - x1);

	if(x1 > x2){
		max = x1;
		min = x2;
	}else{
		max = x2;
		min = x1;
	}

	if(x2 - x1 == 0){
		if(y1 > y2){
			max = y1;
			min = y2;
		} else{
			max = y2;
			min = y1;
		}

		for(int k = min; k < max; k++){
			i = x1;
			j = bmp->ih.height - i;
			bmp->img[i][j] = color;
		}
				
	}else{
		for(int x = min; x < max; x++){
			y = m * (x - x1) + y1;			
			i = x;
			j = bmp->ih.height - y;
			bmp->img[i][j] = color;
		}
	}
}

void circle(int radio, int posx, int posy, RGB color, Bitmap *bmp){
	int x = 0, y = 0;
	for(x = -radio; x < radio; x++){
		y = f(x, radio);
		lineTo(posx + x, posy + y, posx + x+1, posy + f(x+1, radio), color, bmp);
		lineTo(posx + x, posy - y, posx + x+1, posy - f(x+1, radio), color, bmp);
	}
}

double f(int x, int radio){
	double y = sqrt(radio * radio - x * x);
	return y;
}
int main(){

	getch();
	return 0;
}