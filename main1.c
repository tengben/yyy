#include<stdio.h>
int main(void)
{
    int d = 0;
    int i = 0;
    unsigned int mask = 0x80000000;
    puts("Please intut a number:'");
    scanf("%d",&d);
    puts("result:");
    for(i=0;i<32;i++)
    {
        printf("%d",((d & mask) !=0?1:0));
        mask >>=1;
    }
 
    printf("\n");
    return 0;


}
