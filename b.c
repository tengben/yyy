#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 16
int a[N];
void init_array(int l,int r)
{
    int i;
    srand(time(NULL));
    for(i=l;i<=r;i++)a[i]=rand()%100;
}
void show_array(int l,int r)
{
    int i;
    for(i=l;i<=r;i++)printf("%3d",a[i]);
    printf("\n");
}
void swap(int i,int j)
{
    int tmp=a[i];a[i]=a[j];a[j]=tmp;
}
void bubble(int l,int r)
{
    int i,j;
    for(i=l;i<r;i++)
    for(j=r;j>i;j--)
        if(a[j]<a[j-1])swap(j,j-1);
}
    int main(int argc,char*argv[])
    {
        init_array(0,N-1);
        bubble(0,N-1);
        show_array(0,N-1);
        return 0;
    }
