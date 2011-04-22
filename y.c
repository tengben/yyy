#include <stdio.h>
#include<stdlib.h>

int main(int argc, const char *argv[])
{
    FILE *fp;
    char str[100]="hello world";
    char str_1[100];
    int num = 78;
    int r_num = 0;
    if (fp == NULL) 
    {
        perror("open:");
        exit(0);
    }

    fp = fopen("text1","w+");
    //fprintf(fp, "%d %d\n",num,num+1);
    fscanf(fp,"%d %d",&num,&r_num);
    printf("num =%d r_num=%d\n",num,r_num);
    fclose(fp);
    return 0;
}
