#include <stdio.h>
#include <stdlib.h>
 
#define NUM_BITS 8
 
int read(char num[][NUM_BITS]);
void sum(char num[][NUM_BITS], char result[]);
 
int main(void){
 
   char num[2][NUM_BITS], result[NUM_BITS+1];
   int i, j;
 
   if (read(num)){
 
      sum(num, result);
 
      //puts("");
      for (i = 0; i < 2; i++){
         printf(" ");
         for (j = 0; j < NUM_BITS; j++)
            printf("%c", '0' + num[i][j]);
         printf("\n");
      }
 
      for (j = 0; j < NUM_BITS+1; j++)
         printf("%c", '0' + result[j]);
      printf("\n");
 
      return EXIT_SUCCESS;
   }else{
      puts("Invalid input - binary numbers must contain between 1-8 characters");
 
      return EXIT_FAILURE;
   }
 
}
 
int read(char num[][NUM_BITS]){
 
   int c, i, j, k;
 
   for (i = 0; i < 2; i++){
      j = 0;
      while (j < NUM_BITS && (c = getchar()) != EOF && (c == '0' || c == '1'))
            num[i][j++] = c - '0';
 
      if (j == NUM_BITS)
         getchar();
 
      if (j == 0){
         return 0;
      }else{
         for (k = NUM_BITS; k > 0; k--)
            num[i][k-1] = (j >= 1) ? num[i][--j] : 0;
      }
   }
   return 1;
 
}
 
void sum(char num[][NUM_BITS], char result[]){
 
   int i, bit_1, bit_2, carry_flag = 0;
 
   for (i = NUM_BITS; i > 0; i--){
      bit_1 = num[0][i-1];
      bit_2 = num[1][i-1];
 
      result[i] = bit_1 ^ bit_2 ^ carry_flag;
      carry_flag = (bit_1 & bit_2) | (bit_1 & carry_flag) | (bit_2 & carry_flag);
   }
   result[i] = carry_flag;
 
}
