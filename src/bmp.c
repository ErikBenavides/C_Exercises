#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>

//Estructura para controlar los colores por píxel
struct rgb{
	unsigned char blue;
	unsigned char green;
	unsigned char red;
};

typedef struct rgb RGB;

//Estrucura de un bitmap en memoria
struct bitmap{

	//Cabezera de control
	struct FileHeader{
		char bm[2];			//Indica que es un archivo BM de Windows
		int size;			//Indica el tamaño del archivo
		short reserved1;
		short reserved2;
		int offset ;		//'54' | Indica donde comienza los Datos de la imagen
	}fh;

	//Información de la imagen
	struct ImageHeader{
		int size;			//'40'
		int width;
		int height;
		short planes;		//Número de planos, '1'
		short pixels;		//Resolución [2,4,16,24,32]
		int compress;		//Tipo de compresión , '0'
		int imgsize;		//w*h*3
		int ppx;			//Píxeles por pulgada cuadrada en x, '2700'
		int ppy;			//Píxeles por pulgada cuadrada en y, '2700'
		int colors;			//'0'
		int colorsu;		//'0'
	}ih;

	//Sin paleta de colores

	//Datos de la imagen
	unsigned char *data;

	//Matriz de control
	RGB **img;
};

typedef struct bitmap Bitmap;

//Funciones

Bitmap *bmpnew (int, int);

void bmpsave (Bitmap*, char*);

void Circulo (Bitmap*, int, RGB);

void Linea (Bitmap *, int, int, int, int, RGB);

int sign (int);

char *strcat (char *, char *);

// -------------------------------------------------------------------
int main (){
	int i, j;
	char *user = strcat(getenv("USERPROFILE"), "\\Desktop\\mi_imagen.bmp");
	RGB color; color.red = 10; color.green = 10; color.blue = 10;
	Bitmap *bmp = bmpnew(512,512);
	for (i = 0; i<bmp->ih.height; i++){
		bmp->img[i][i] = color;
	}
	Linea(bmp, 0,0,50,50, color);
	Linea(bmp, 20,30,100,50, color);
	Circulo(bmp, 100, color);
	bmpsave (bmp, user);
	getch ();
	return 0;
}
// -------------------------------------------------------------------


Bitmap *bmpnew (int height, int width){
	Bitmap *bmp =(Bitmap*)malloc(sizeof(Bitmap));
	int w,h,i, j;
	h = (height < 100)? 100: height;
	if (width < 100)
		w = 100;
	else{
		w = width;
		w += (w%4 != 0)? (4 - w%4): 0;
	}
	// Datos del file header
	bmp->fh.bm[0] = 'B';
	bmp->fh.bm[1] = 'M';
	bmp->fh.size = h*w*3 + 54;
	bmp->fh.reserved1 = 0;
	bmp->fh.reserved2 = 0;
	bmp->fh.offset = 54;
	// Datos del image header
	bmp->ih.size = 40;
	bmp->ih.width = w;
	bmp->ih.height = h;
	bmp->ih.planes = 1;
	bmp->ih.pixels = 24;
	bmp->ih.compress = 0;
	bmp->ih.imgsize = h*w*3;
	bmp->ih.ppx = 2700;
	bmp->ih.ppy = 2700;
	bmp->ih.colors = 0;
	bmp->ih.colorsu = 0;
	// Imagen
	bmp->data = (unsigned char*)malloc(bmp->ih.imgsize);
	for (i = 0; i<bmp->ih.imgsize; i++)
		bmp->data[i] = 255;
	// Matriz de datos
	bmp->img = (RGB**)malloc(sizeof(RGB*)*h);
	for (i = 0, j = h-1; j>=0; i++, j--)
		bmp->img[i]=(RGB*)&bmp->data[j*w*3];
	return bmp;
}

void bmpsave (Bitmap *bmp, char *name){
	if (bmp != NULL){
		FILE *file;
		file = fopen(name, "wb");
		if (file != NULL){
			// Datos del file header
			fwrite (bmp->fh.bm, 1, 2, file);
			fwrite (&bmp->fh.size, 4, 1, file);
			fwrite (&bmp->fh.reserved1, 2, 1, file);
			fwrite (&bmp->fh.reserved2, 2, 1, file);
			fwrite (&bmp->fh.offset, 4, 1, file);
			// Datos del image header
			fwrite (&bmp->ih.size, 4, 1, file);
			fwrite (&bmp->ih.width, 4, 1, file);
			fwrite (&bmp->ih.height, 4, 1, file);
			fwrite (&bmp->ih.planes, 2, 1, file);
			fwrite (&bmp->ih.pixels, 2, 1, file);
			fwrite (&bmp->ih.compress, 4, 1, file);
			fwrite (&bmp->ih.imgsize, 4, 1, file);
			fwrite (&bmp->ih.ppx, 4, 1, file);
			fwrite (&bmp->ih.ppy, 4, 1, file);
			fwrite (&bmp->ih.colors, 4, 1, file);
			fwrite (&bmp->ih.colorsu, 4, 1, file);
			// Imagen
			fwrite (bmp->data, 1, bmp->ih.imgsize, file);
			fclose (file);
			printf("Imagen creada con exito!!\n");
		}
		else
			printf("NO SE PUDO GUARDAR EL ARCHIVO\n");
	}
	return;
}

void Circulo (Bitmap *bmp, int r, RGB c){
	int cx, cy, t, i, j;
	double y,x;
	cx = bmp->ih.width / 2;
	cy = bmp->ih.height / 2;
	for (t = 0; t<= 360; t++){
		x = cos(t)*r;
		y = sin(t)*r;
		i = cx - x;
		j = cy- y;
		bmp->img[i][j] = c;
		j = cy + y;
		bmp->img[i][j] = c;
	}
	return;
}

char *strcat (char *cat1, char *cat2){
	char *r;
	int i, j, k, l, z;

	for (i = 0; cat1[i] != 0; i++);
	for (j = 0; cat2[j] != 0; j++);
	i--; j--;
	z = i+j+1;
	r = (char *)malloc(sizeof(char)*z);
	for (k = 0; cat1[k] != 0; k++)
		r[k] = cat1[k];
	for (l = 0; cat2[l] != 0; l++)
		r[l+k] = cat2[l];
	r[l+k] = 0;
	return r;
}

void Linea (Bitmap *bmp, int x1, int y1, int x2, int y2, RGB color){
	// Algoritmo de Bresenham --------------------
	int s1, s2, x, y, ax, ay, m, aux, intercambio = 0, i, cx, cy, tmp;
	x = x1;
	y = y1;
	cx = bmp->ih.width / 2;
	cy = bmp->ih.height / 2;
	ax = x2 - x1;
	ax*= (ax<0)? -1: 1;
	ay = y2 - y1;
	ay*= (ay<0)? -1: 1;
	s1 = sign(x2 - x1);
	s2 = sign(y2 - y1);
	if (ay>ax){
		tmp = ax;
		ax = ay;
		ay = tmp;
		intercambio++;
	}
	m = 2*ay - ax;
	for (i = 0; i<ax; i++){
		bmp->img[cy - y][cx + x] = color;
		if (m>=0){
			if (intercambio == 1)
				x+=s1;
			else
				y+=s2;
			m-=2*ax;
		}
		if (intercambio == 1)
			y+=s2;
		else
			x+=s1;
		m+=2*ay;
	}
	return;
}

int sign(int c){
	if (c > 0)
		return 1;
	if (c < 0)
		return -1;
	if (c == 0)
		return 0;
}
