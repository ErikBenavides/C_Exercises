#include<stdio.h>
#include<conio.h>
#define pi 3.1415
int main()
{
	float ans,temp,degree;
	int i;
	printf("Enter the angle of SIN :\n");
	scanf("%f",&degree);
	float radian=degree*pi/180;
	int acc=5;
	ans=radian;
	temp=radian;
	for(i=2;i<=2*acc;i+=2)
	{
		temp=temp*(-1)*radian*radian/(i*(i+1));
		ans=ans+temp;
	}
	printf("\nsin(%f)=%f",degree,ans);
	getch();
	return 0;
}
