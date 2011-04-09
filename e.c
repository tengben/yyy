#include <stdio.h>

void hanoi(char a,char b,char c,int n);

int main(int argc, const char *argv[])
{
    int n;
    printf("please input the num:\n");
    scanf("%d",&n);

    hanoi('A','B','C',n);
    return 0;

}

void hanoi(char a,char b,char c,int n)
{       if(n==1)
        {
                printf("%c---->%c\n",a,c);
                return ;
        }
        hanoi(a,c,b,n-1);
        printf("%c---->%c\n",a,c);
        hanoi(b,a,c,n-1);
        return ;
}
