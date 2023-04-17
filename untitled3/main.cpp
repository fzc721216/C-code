#include<iostream>
using namespace std;
 
int main()
{
    int a=400000, b = 5;
    int c, d;
    asm(".intel_syntax noprefix \n"
        "mov eax,_iCislo        \n"
        "inc eax                \n"
        "mov _iVysledok,eax     \n"
        ".att_syntax            \n");






    printf("c=%d,d=%d\n", c,d);
    return 0;
}