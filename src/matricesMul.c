#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct matrix{
	double **M;
	int m;
	int n;
};

typedef struct matrix Matrix;

Matrix Mnew(int m1, int n1){
	Matrix A;
	A.m = m1;
	A.n = n1;
	A.M = (double **)malloc(m1 * sizeof(double *));
	for(int i = 0; i < m1; i++){
		A.M[i] = (double *)malloc(m1 * sizeof(double));
		for(int j = 0; j < m1; j++){
			A.M[i][j] = 0.0;
		}
	}
	return A;
}

void Mdelete(Matrix A){
	for(int i = 0; i < A.m; i++){
		free(A.M[i]);
	}
	free(A.M);
}

void Mprint(Matrix A, char *name){
	printf("\n%s\n", name);
	if(A.M != NULL){
		for(int i = 0; i < A.m; i++){
			for(int j = 0; j < A.n; j++){
				printf("%2lf\t", A.M[i][j]);
			}
			printf("\n");
		}
	}
}

void Mrand(Matrix A){	
	for(int i = 0; i < A.m; i++){
		for(int j = 0; j < A.n; j++){
			A.M[i][j] = rand() / (double)(rand() + 1);
		}		
	}
}

Matrix Mresta(Matrix A, Matrix B){
	Matrix R;
	if(A.m == B.m && A.n == B.n){
		R = Mnew(A.m, A.n);		
		 for(int i = 0; i < R.m; i++){
    	    for(int j = 0; j < R.n; j++){
            	R.M[i][j] = 0;
           	 	for(int k = 0; k < R.n; k++){                
            		R.M[i][j] = R.M[i][j] + A.M[i][k] * B.M[k][j];
            	}
        	}
    	}
	}
	return R;
}

int main(){	
	Matrix mat = Mnew(2,2);
	Matrix matB = Mnew(2, 2);
	Mrand(mat);
	Mrand(matB);
	Mprint(mat, "Matriz A");
	Mprint(matB, "Matriz B");

	Matrix matC = Mresta(mat, matB);
	Mprint(matC, "Matriz C");
	
	Mdelete(mat);
	Mdelete(matB);
	Mdelete(matC);

	getch();
	return 0;
}