#include <stdio.h>
#include<stdlib.h>
int main(int argc, const char *argv[])
{
    FILE *fp;
    char s[100] = "hello world\n"; 
    char d[100] ;
    int i = 0;
    //s[4] = 2;//不可打印字符
    //gets(d);
   //printf("%s\n",d);
    fp = fopen("text3","w+");
    if (fp == NULL) 
    {
        perror("open:");
        exit(0);
    }
    i = 0;
    //while(s[i] != '\0')
    {
        //putc(s[i++],fp);
    }
     while((d[i]=get(fp)!=EOF))
    {
        d[i]= getc(fp);
        i++;

    }
    d[i] = '\0';

    printf("%s\n",d);

    //putc(c,fp);
    //getc(d,fp);
     //printf("%c\n",d);
    //fputs(s,fp);
    //rewind(fp);//把指针移到行首！
    //fgets(d,99,fp);
    //printf("%s\n",d);
    fclose(fp);
    
    return 0;
}
