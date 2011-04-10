#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 10
#define M 10
int main(int argc, const char *argv[])
{
    int array[N][M];
    int i=0;
    int tmp;
    int j=0;
    srand(time(NULL));

    for (i = 0; i < M*N; i++) 
    {
        array[0][i]= rand()%(M*N);
    }
    for (i = 0; i < M*N; i++) 
    {
         //for (i = 0; i < M; i++) 
         
            if (i%10==0) 
            {
                printf("\n");
            }       
       
            printf("%5d",array[0][i]);
       

       
     }
    getchar();
    printf("执行\n");
    getchar();

    

        for (i = 0; i < (M*N-1); i++) 
        {
            for (j = i+1; j < M*N; j++) 
            {
                if (array[0][i]>array[0][j]) 
                {
                    tmp = array[0][i];
                    array[0][i]= array[0][j];
                    array[0][j]=tmp;

                }
            }
        }



    for (i = 0; i < M*N; i++) 
    {
         //for (i = 0; i < M; i++) 
            if (i%10==0) 
            {
                printf("\n");
            }       
       
            printf("%5d",array[0][i]);
       

       
     }
     printf("\n");

        return 0;
}
