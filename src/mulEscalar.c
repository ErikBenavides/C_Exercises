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

Matrix Mmul(Matrix A, int escalar){
	Matrix R;
	if(A.M != NULL){
		R = Mnew(A.m, A.n);
		for(int i = 0; i < R.m; i++){
			for(int j = 0; j < R.m; j++){
				R.M[i][j] = A.M[i][j] * escalar;
			}
		}
	}
	return R;
}

int main(){
	Matrix mat = Mnew(2,2);	
	int escalar = 4;
	Mrand(mat);
	Mprint(mat, "Matriz A");
	
	Matrix matC = Mmul(mat, escalar);
	Mprint(matC, "Matriz A por escalar");
	
	Mdelete(mat);	
	Mdelete(matC);

	getch();
	return 0;
}