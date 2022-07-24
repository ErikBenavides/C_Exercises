#include <stdio.h>

int main(void)
{
	unsigned char *var = "0101";
	unsigned int contador, inicio = 128; // 2^(8-1) = 128

	for(contador = inicio; contador > 0; contador >>= 1) // El contador se desplaza un bit a la derecha cada ciclo
		if(contador & var[contador]) // Si contador AND var == 1
			printf("1");
		else
			printf("0");
	return 0;
}