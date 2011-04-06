#include<stdio.h>
int main(void)
{
    int d = 0;
    int j = 0;
    int i = 0;
    puts("Please intut a number:'");
    scanf("%d",&d);
    puts("result:");
    j = 31;
    for(i=0;i<32;i++,j--)
    {
        printf("%d",((d>>j) & 0x01));
         
    }
 
    printf("\n");
    return 0;


}
