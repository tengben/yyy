#include<stdio.h>
int main(void)
{
   int i =0;
   int j =0;
   unsigned int mask = 0x0f;
   int t = 0;
   char c ; 
   int d = 0;
   char str_h[20] = "0123456789abcdef";

   printf("Please input a num:\n");
   scanf("%d",&d);
   j = sizeof(int)*8 - 4;
   for(i=0;i<sizeof(int)*2;i++,j = j-4)
   {
        t = (d>>j) & mask;
   }
   if(t<=9)
   {
    printf("%d",t);
   }
   else
   {
            switch(t)
            {
                case 10 : c = 'a';break;
                case 11 : c = 'b';break;
                case 12 : c = 'c';break;
                case 13 : c = 'd';break;
                case 14 : c = 'e';break;
                case 15 : c = 'f';break;
                default : break;
                printf("%c",c);
            }
   }
   printf("\n");
   return 0;
   
}
