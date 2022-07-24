#include <stdio.h>
#include <conio.h>

int mcd (int a, int b);

int main()
{
		int a = 15;
		int b = 20;
		int c = 30;

		printf ("MCD :%d\n", mcd ( mcd(a,b), c));
		getch();

		return 0;
}

int mcd (int a, int b)
{
		if ((a % b) == 0)
				return b;
		else
				return mcd (b, a % b);
}
