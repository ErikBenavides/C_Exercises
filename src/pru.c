#include <stdio.h>
int  main()
{
    char inputstr[] = "-.45";
    float result= 0.0f;
    int len = sizeof(inputstr)-1;
    int dotpos=0;
    int n;
    if (inputstr[0]=='-'||inputstr[0]=='+')   //Added line to check sign.If the number is signed,
        n=1;                 //set n to position 1.
    else                     //(number is not signed)
        n=0;                 //set n to position 0.
/*If the number was signed,then we set n to 1,so that we start with inputstr[1],and at the end if the number was negative we will multiply by -1.*/
    for (n; inputstr[n] != 0; n++){       //n is already set to the position of the fisrt number.
        if (inputstr[n] == '.')
            dotpos = len - n  - 1;
        else
            result = result * 10.0f + (inputstr[n]-'0');            
    while (dotpos--)
        result /= 10.0f;
    if (inputstr[0]=='-')  //If inputstr[] is "negative",
        result*=(-1);      //multiply the number by -1,making it also negative.
    printf("%f\n",result);
    return 0;
}
