#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define dim 20  /* dimension maxima de la matriz */

/* Prototipo de funciones */
void visualiza_magico(int matrix[][dim],int n);
void ceros(int matrix[][dim],int n);

/* Procedimiento que genera el cubo magico */
void magico(int cubo[][dim],int n)
{  int key,i,j,k,r;
   if(n%2!=0){
      ceros(cubo,n);
      cubo[0][(n-1)/2]=1;
      key=2;
      i=0;
      j=(n-1)/2;
      while(key <= n*n){
	k=i-1;
	r=j-1;
	if(k<0) k=n-1;
	if(r<0) r=n-1;
	if(cubo[k][r]!=0) i=(i+1)%n;
	else { i=k;
	       j=r; }
	cubo[i][j]=key;
	key++;
      }
      visualiza_magico(cubo,n);
   }
   else printf(" La dimension no es impar\n");
}

/* Procedimiento que visualiza la matriz */
void visualiza_magico(int matrix[][dim],int n)
{  register int i,j;
   for(i=0;i< n;i++){
    for(j=0;j< n;j++){
       printf("%-3d " ,matrix[i][j]);
    }
    printf("\n");
   }
}
/* Procedimiento que cerea la matriz */
void ceros(int matrix[][dim],int n)
{  register int i,j;
   for(i=0;i< n;i++)
     for(j=0;j< n;j++)
       matrix[i][j]=0;
}

/* Funcion principal */
void main()
{
   int cubo[dim][dim];
   int n;   
   printf("Digite un valor:");
   scanf("%d",&n);
   printf("Cubo magico:\n\n");
   magico(cubo,n);
   getch();
}