#include <stdio.h>
#define LONGCAD 80

/* PROTOTIPOS */ 
int buscar_subcadena(char *, char *);

void main()
{
/* DECLARACIONES */
char cadena[LONGCAD];
char subcadena[LONGCAD];
int encontrada = 0;

/* PETICION DE DATOS */
printf("\nIntroduzca una cadena: ");
gets(cadena);

printf("\nIntroduzca la subcadena a buscar: ");
gets(subcadena);

/* CALCULOS */ 
encontrada = buscar_subcadena(cadena,subcadena);

/* RESULTADOS */
if(encontrada == 1)
printf("\nSubcadena %s encontrada", subcadena);
else
printf("\nSubcadena %s no encontrada", subcadena);

}


int buscar_subcadena(char *cad,char *subcad)
{
int i,j;

i = 0;
j = 0;
while(cad != '\0')
{
if(subcad[j] == cad)
{
subcad[j] = cad;
j++;
i++;
return(1);
}
else
i++;
}

return(0);

}