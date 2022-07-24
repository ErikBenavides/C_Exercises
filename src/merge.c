#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#define TAM 100000

int arr[TAM];

int merge(int arr[],int p,int q,int r)
{
  int arr1[TAM],arr2[TAM];  
  int n1,n2,i,j,k;
  n1=q-p+1;
  n2=r-q;

  for(i=0; i<n1; i++)
    arr1[i]=arr[p+i];
  for(j=0; j<n2; j++)
    arr2[j]=arr[q+j+1];

  arr1[i]=0x7FFFFFFF;
  arr2[j]=0x7FFFFFFF;

  i=0;
  j=0;
  for(k=p; k<=r; k++) {
    if(arr1[i]<=arr2[j])
      arr[k]=arr1[i++];
    else
      arr[k]=arr2[j++];
  }
  
  return 0;
}

int merge_sort(int arr[],int p,int r)
{
  int q;
  if(p<r) {
    q=(p+r)/2;    
    merge_sort(arr,p,q);
    merge_sort(arr,q+1,r);    
    merge(arr,p,q,r);
  }  
  return 0;
}

int main()
{
  int i;

  for(i=0; i<TAM; i++)
    arr[i] = rand() % TAM;
  for(i=0; i<TAM;i++)
    printf("%d, ", arr[i]);

  merge_sort(arr,0,TAM-1);

  printf("\nArreglo ordenado:\n");
  for(i=0; i<TAM; i++)
    printf("%d, ",arr[i]);

  return 0;
}

