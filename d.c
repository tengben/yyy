#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 100
void init_array(int p[],int n);
void bubble_array(int p[],int n);
void print_array(int p[],int n);
void quick_sort(int p[],int x, int y);
int main(void)
{
    int array[N];

    init_array(array,N);
    //printf("original:\n");
    print_array(array,N);
    //printf("press enter to start...\n");
//getchar();
//    bubble_array(array,N);
//quick_sort(array,0,N-1);
//printf("finished,press enter to list:\n");
//getchar();
//print_array(array,N);
    return 0;

}
void init_array(int p[],int n)
{
        int i = 0;

        srand(time(NULL));
        for (i = 0; i < n; i++) 
        {
            p[i]=(rand()%100);
        }
}

void print_array(int p[],int n)
{
        int i =0;
        for (i = 0; i < n; i++) 
        {
            if((i%10)==0)
            {
                printf("\n");
            }

            printf("%5d",p[i]);
        }
        printf("\n");
}

void bubble_array(int p[],int n)
{
        int i =0;
        int j =0;
        int tmp =0;

        for (i = 0; i < n-1; i++) 
        {
            for (j = i+1; j < n; j++) 
            {
                    if (p[i]>p[j]) 
                    {
                            tmp = p[i];
                            p[i] = p[j];
                            p[j] = tmp;
                    }
            }
        }
}

void quick_sort(int p[],int x,int y)
{
        int i = x;
        int j = y;
        int tmp = 0;
        int mid = p[(x+y)/2];

        while(i <= j) 
        {
            while (p[i]<mid) i++;
            while(p[j]>mid) j--;

            if(i<=j)
            {
                    tmp = p[i];
                    p[i] = p[j];
                    p[j] = tmp;

                    i++;
                    j--;
            }
 
        }


if(x<j)
    {
        quick_sort(p,x,j);
    }
if(i<y)
    {   
        quick_sort(p,i,y);
        
    }

}
